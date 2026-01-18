namespace RiskApiGateway.Models
{
    public class RiskResultDto
    {
        public int TradeId { get; set; }
        public double RiskValue { get; set; }
        public bool Success { get; set; }
        public string ErrorMessage { get; set; } = string.Empty;
    }
}