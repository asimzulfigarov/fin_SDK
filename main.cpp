#include <iostream>
#include <fstream>
#include <vector>
#include "domain/Trade.h"
#include "service/RiskService.h"
#include <nlohmann/json.hpp>


int main(int argc, char* argv[]) {
    /*
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
    adapter::SummitAdapter summitAdapter;
    service::RiskService riskService(summitAdapter);
    domain::RiskResult result = riskService.calculateRisk(trade);

    // Print output
    if (result.success) {
        std::cout << "Trade " << result.tradeId
                  << " risk value: " << result.riskValue << "\n";
    } else {
        std::cout << "Trade " << result.tradeId
                  << " failed: " << result.errorMessage << "\n";
    }
*/

 if (argc != 2) {
        std::cerr << "Usage: ./risk-service <trades.json>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << "\n";
        return 1;
    }

    nlohmann::json jsonData;
    file >> jsonData;

    std::vector<domain::Trade> trades;
    for (const auto& t : jsonData) {
        domain::Trade trade;
        trade.tradeId = t["tradeId"].get<int>();
        trade.instrument = t["instrument"].get<std::string>();
        trade.notional = t["notional"].get<double>();
        trade.price = t["price"].get<double>();
        trades.push_back(trade);
    }

    adapter::SummitAdapter summitAdapter;
    service::RiskService riskService(summitAdapter);
    for (const auto& trade : trades) {
        domain::RiskResult result = riskService.calculateRisk(trade);
        if (result.success) {
            std::cout << "Trade " << result.tradeId << " risk value: " << result.riskValue << "\n";
        } else {
            std::cout << "Trade " << result.tradeId << " failed: " << result.errorMessage << "\n";
        }
    }

    return 0;
}