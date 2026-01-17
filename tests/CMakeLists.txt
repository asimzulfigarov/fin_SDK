# tests/CMakeLists.txt

# Define test executable
add_executable(risk_service_tests
    RiskServiceTest.cpp
)

# Link Catch2 + your project libraries
target_link_libraries(risk_service_tests PRIVATE
  Catch2::Catch2WithMain
  service_lib
  adapter_lib
  domain_lib
  sdk_lib
)

# Register tests with CTest
include(Catch)
catch_discover_tests(risk_service_tests)
