#pragma once
#include "../domain/Trade.h"
#include "../domain/RiskResult.h"
#include "../sdk/summit_sdk.h"


namespace adapter{
    class SummitAdapter{
        public:
            virtual domain::RiskResult calculateRisk(const domain::Trade& trade);
            virtual ~SummitAdapter() = default;
    };
}


