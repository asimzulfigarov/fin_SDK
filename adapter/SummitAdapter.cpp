#include "SummitAdapter.h"
#include <stdexcept>

namespace adapter{
    domain::RiskResult SummitAdapter::calculateRisk(const domain::Trade& trade){
        domain::RiskResult result;
        result.tradeId = trade.tradeId;

        try{
            summit::SummitSDK sdk;
            result.riskValue = sdk.calculateRisk(
                trade.tradeId,
                trade.instrument,
                trade.notional,
                trade.price
            );
            result.success = true;
            result.errorMessage = "";
        } catch (const std::exception& e){
            result.success = false;
            result.errorMessage = e.what();
            result.riskValue = 0.0;
        }
        return result;
    }
}