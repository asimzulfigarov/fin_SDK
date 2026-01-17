#include <catch2/catch_test_macros.hpp>
#include "../domain/Trade.h"
#include "../domain/RiskResult.h"
#include "../adapter/SummitAdapter.h"
#include "../service/RiskService.h"


class MockAdapter : public adapter::SummitAdapter {
    public:
        domain::RiskResult calculateRisk (const domain::Trade& trade) override{
                domain::RiskResult result;
                result.tradeId = trade.tradeId;
                result.riskValue = 123.45;
                result.success = true;
                result.errorMessage = "";
                return result;
        }
};


 TEST_CASE("RiskService returns correct result"){
            domain::Trade trade{101, "BOND", 1000000, 98.5};
            MockAdapter mock;
            service::RiskService riskService(mock);

            domain::RiskResult result = riskService.calculateRisk(trade);

            REQUIRE(result.tradeId == 101);
            REQUIRE(result.success == true);
            REQUIRE(result.riskValue == 123.45);
        }

TEST_CASE("SummitAdapter handles SDK success and failure") {
            adapter::SummitAdapter adapter;
            domain::Trade trade{101, "BOND", 1000000, 98.5};

            domain::RiskResult result = adapter.calculateRisk(trade);

            REQUIRE(result.tradeId == 101);
            if(result.success) {
                REQUIRE(result.riskValue >= 0);
            } else {
                REQUIRE(!result.errorMessage.empty());
}
}
