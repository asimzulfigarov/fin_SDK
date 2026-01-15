enable_testing()
add_executable(tests RiskServiceTest.cpp FunctionalTest.cpp)
target_link_libraries(tests sdk_lib domain_lib adapter_lib service_lib api_lib)
add_test(NAME AllTests COMMAND tests)
