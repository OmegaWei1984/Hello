cmake_minimum_required(VERSION 3.22)
project(helloCpp LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR})

set(TARGETS
algorithms_library
built-in_types
class_and_struct
compiling
containers_library
declaration
design_patterns
exceptions
expression
functions
iterator_library
memory
paradigms
pointers
strings_library
)

foreach(TARGET IN LISTS TARGETS)
    MESSAGE(STATUS ${TARGET})
    add_subdirectory(${TARGET} ${TARGET})
endforeach()