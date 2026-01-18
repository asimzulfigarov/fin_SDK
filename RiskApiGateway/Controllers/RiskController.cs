using Microsoft.AspNetCore.Mvc;
using RiskApiGateway.Models; // your existing DTOs
using System.Collections.Generic;

namespace RiskApiGateway.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class RiskController : ControllerBase
    {
        [HttpPost]
        public IActionResult Post([FromBody] List<TradeDto> trades)
        {
            if (trades == null || trades.Count == 0)
            {
                Console.WriteLine("No trades received.");
                return BadRequest("No trades provided.");
            }

            Console.WriteLine($"Received {trades.Count} trades:");
            foreach (var trade in trades)
            {
                Console.WriteLine($"TradeId={trade.TradeId}, Instrument={trade.Instrument}, Notional={trade.Notional}, Price={trade.Price}");
            }

            var results = new List<RiskResultDto>();
            foreach (var trade in trades)
            {
                // Mock risk calculation
                results.Add(new RiskResultDto
                {
                    TradeId = trade.TradeId,
                    RiskValue = 123.45, // replace later with real calculation
                    Success = true,
                    ErrorMessage = ""
                });
            }

            return Ok(results);
        }
    }
}