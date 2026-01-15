add_library(service_lib RiskService.cpp)
target_link_libraries(service_lib PUBLIC adapter_lib)
target_include_directories(service_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
