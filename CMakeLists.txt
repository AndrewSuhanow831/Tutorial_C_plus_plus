cmake_minimum_required(VERSION 3.5)

# set the project name
project(Tutorial)

set(SOURCES
    main.cpp
    supp.cpp
)

set(HEADERS
    supp.hpp
)

# add the executable
add_executable(Tutorial ${SOURCES} ${HEADERS})

set_target_properties(
    Tutorial PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)