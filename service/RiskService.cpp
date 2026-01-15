#include "RiskService.h"

namespace service {

domain::RiskResult RiskService::calculateRisk(const domain::Trade& trade) {
    adapter::SummitAdapter adapter;

    
    domain::RiskResult result = adapter.calculateRisk(trade);

    
    
    return result;
}

}