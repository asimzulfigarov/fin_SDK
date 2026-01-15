#pragma once
#include "../domain/Trade.h"
#include "../domain/RiskResult.h"
#include "../adapter/SummitAdapter.h"

namespace service {

class RiskService {
public:
    domain::RiskResult calculateRisk(const domain::Trade& trade);
};

}