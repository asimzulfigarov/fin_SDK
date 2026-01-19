using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using RiskApiGateway.Models;

[ApiController]
[Route("[controller]")]
public class RiskController : ControllerBase
{
    [HttpPost]
    public IActionResult Post([FromBody] List<TradeDto> trades)
    {
        var results = new List<RiskResultDto>();

        foreach (var trade in trades)
        {
            var process = new Process();
            process.StartInfo.FileName = "/home/vboxuser/Documents/finProject/build/risk_service"; // 🔴 CHANGE THIS
            process.StartInfo.Arguments =
                $"{trade.TradeId} {trade.Instrument} {trade.Notional} {trade.Price}";
            process.StartInfo.RedirectStandardOutput = true;
            process.StartInfo.RedirectStandardError = true;
            process.StartInfo.UseShellExecute = false;

            process.Start();

            string output = process.StandardOutput.ReadToEnd();
            string error = process.StandardError.ReadToEnd();

            process.WaitForExit();

            if (process.ExitCode == 0)
            {
                results.Add(new RiskResultDto
                {
                    TradeId = trade.TradeId,
                    RiskValue = ExtractRisk(output),
                    Success = true,
                    ErrorMessage = ""
                });
            }
            else
            {
                results.Add(new RiskResultDto
                {
                    TradeId = trade.TradeId,
                    RiskValue = 0,
                    Success = false,
                    ErrorMessage = error
                });
            }
        }

        return Ok(results);
    }

    private double ExtractRisk(string output)
    {
        // Example: "Trade 101 risk value: 123.4"
        var parts = output.Split(':');
        return double.Parse(parts.Last().Trim());
    }
}
