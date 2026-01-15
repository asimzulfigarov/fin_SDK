#include "summit_sdk.h"
#include <stdexcept>
#include <cstdlib>

namespace summit{
    double SummitSDK::calculateRisk(int tradeId,
                                    const std::string& instrument,
                                    double notional,
                                    double price){
                                        //if (std::rand() % 4 == 0){
                                            //throw std::runtime_error("summit SDK failure");
                                        //}
                                        
                                        return (std::rand() % 1000) / 10.0;
                                    }
}