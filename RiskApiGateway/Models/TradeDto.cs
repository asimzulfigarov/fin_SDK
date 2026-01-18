namespace RiskApiGateway.Models
{
    public class TradeDto
    {
        public int TradeId { get; set; }
        public string Instrument { get; set; } = string.Empty;
        public double Notional { get; set; }
        public double Price { get; set; }
    }
}