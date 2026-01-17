#include "RiskService.h"

namespace service {

domain::RiskResult RiskService::calculateRisk(const domain::Trade& trade) {

    domain::RiskResult result = _adapter.calculateRisk(trade);

    
    
    return result;
}

RiskService::RiskService(adapter::SummitAdapter& adapter) : _adapter(adapter){}

}