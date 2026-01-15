#pragma once 
#include <string>

namespace domain{

    struct Trade {
        int tradeId;
        std::string instrument;
        double notional;
        double price;
    };
}