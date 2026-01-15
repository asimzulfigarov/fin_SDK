#pragma once
#include <string>

namespace domain{

    struct RiskResult{
        int tradeId;
        double riskValue;
        bool success;
        std::string errorMessage;
    };
}