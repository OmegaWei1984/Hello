cmake_minimum_required(VERSION 3.22)
project(helloCpp LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR})

set(TARGETS "built-in_types;compiling;containers_library;design_patterns;expression;memory")

foreach(TARGET IN LISTS TARGETS)
    MESSAGE(STATUS ${TARGET})
    add_subdirectory(${TARGET} ${TARGET})
endforeach()