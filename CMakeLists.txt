cmake_minimum_required(VERSION 3.16)
project(risk_service VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source directories
add_subdirectory(sdk)
add_subdirectory(domain)
add_subdirectory(adapter)
add_subdirectory(service)
add_subdirectory(api)

# Add the executable
add_executable(risk_service main.cpp)

# Link libraries (adjust if you create libraries in subfolders)
target_link_libraries(risk_service
    sdk_lib
    domain_lib
    adapter_lib
    service_lib
    api_lib
)
