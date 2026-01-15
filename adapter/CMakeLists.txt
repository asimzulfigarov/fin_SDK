add_library(adapter_lib SummitAdapter.cpp)
target_link_libraries(adapter_lib PUBLIC sdk_lib)
target_include_directories(adapter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
