cmake_minimum_required(VERSION 3.10)
project(unitpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    "include/unitpp/unit.h"
    "include/unitpp/si/mass.h"
)

add_library(unitpp STATIC ${SOURCES})
target_include_directories(unitpp PUBLIC "include")
set_target_properties(unitpp PROPERTIES LINKER_LANGUAGE CXX)

add_executable(mass "examples/mass.cpp")
target_link_libraries(mass PRIVATE unitpp)
