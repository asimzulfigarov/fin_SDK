#pragma once
#include "../domain/Trade.h"
#include "../domain/RiskResult.h"
#include "../sdk/summit_sdk.h"


namespace adapter{
    class SummitAdapter{
        public:
            domain::RiskResult calculateRisk(const domain::Trade& trade);
    };
}