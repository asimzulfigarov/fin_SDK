#pragma once
#include <string>

namespace summit{


    class SummitSDK{
    public:
        double calculateRisk(int tradeId,
                            const std::string& instrument,
                            double notional,
                            double price);
    };
}