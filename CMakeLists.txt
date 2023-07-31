cmake_minimum_required(VERSION 3.10)
project(unitpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(pmm.cmake)
pmm(VCPKG REVISION 2023.04.15 REQUIRES catch2)

find_package(Catch2 CONFIG REQUIRED)

include(CTest)
include(Catch)

set(SOURCES
    "include/unitpp/internal/unit.h"
    "include/unitpp/internal/mass.h"
    "include/unitpp/internal/length.h"

    "include/unitpp/units/imperial/mass.h"
    "include/unitpp/units/imperial/length.h"
    
    "include/unitpp/units/si/mass.h"
    "include/unitpp/units/si/length.h"
    "include/unitpp/units/length.h"
    "include/unitpp/units/mass.h"
    "include/unitpp/units.h"
)

set(TEST_SOURCES
    "test/length_casting.cpp"
    "test/mass_casting.cpp"
)

add_library(unitpp STATIC ${SOURCES})
target_include_directories(unitpp PUBLIC "include")
set_target_properties(unitpp PROPERTIES LINKER_LANGUAGE CXX)

add_executable(unitpp-test ${TEST_SOURCES})
target_link_libraries(unitpp-test PRIVATE unitpp Catch2::Catch2 Catch2::Catch2WithMain)
catch_discover_tests(unitpp-test)

add_executable(mass-example "examples/mass_example.cpp")
target_link_libraries(mass-example PRIVATE unitpp)
add_test(NAME mass_example COMMAND mass-example)

add_executable(length-example "examples/length_example.cpp")
target_link_libraries(length-example PRIVATE unitpp)
add_test(NAME length_example COMMAND length-example)
