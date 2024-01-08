cmake_minimum_required(VERSION 3.22)
project(helloCpp LANGUAGES CXX)

set(TARGETS "containers_library;design_patterns;expression;memory")

foreach(TARGET IN LISTS TARGETS)
    MESSAGE(STATUS ${TARGET})
    add_subdirectory(${TARGET} ${TARGET})
endforeach()