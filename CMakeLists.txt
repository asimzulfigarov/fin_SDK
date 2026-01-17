cmake_minimum_required(VERSION 3.16)
project(risk_service VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------
# Dependencies
# --------------------
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

# --------------------
# Project libraries
# --------------------
add_subdirectory(sdk)
add_subdirectory(domain)
add_subdirectory(adapter)
add_subdirectory(service)
add_subdirectory(api)

# --------------------
# Main executable
# --------------------
add_executable(risk_service main.cpp)

target_link_libraries(risk_service PRIVATE
    sdk_lib
    domain_lib
    adapter_lib
    service_lib
    api_lib
)

# --------------------
# Enable testing
# --------------------
enable_testing()

# --------------------
# Add tests directory
# --------------------
add_subdirectory(tests)