#include <iostream>
#include <string>
#include <cstdlib>
#include "domain/Trade.h"
#include "service/RiskService.h"

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: ./risk-service <tradeId> <instrument> <notional> <price>\n";
        return 1;
    }

    // Parse CLI args
    domain::Trade trade;
    trade.tradeId = std::stoi(argv[1]);
    trade.instrument = argv[2];
    trade.notional = std::stod(argv[3]);
    trade.price = std::stod(argv[4]);

    // Call business service
    service::RiskService riskService;
    domain::RiskResult result = riskService.calculateRisk(trade);

    // Print output
    if (result.success) {
        std::cout << "Trade " << result.tradeId
                  << " risk value: " << result.riskValue << "\n";
    } else {
        std::cout << "Trade " << result.tradeId
                  << " failed: " << result.errorMessage << "\n";
    }

    return 0;
}