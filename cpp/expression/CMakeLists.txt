SET(TARGETS "cast")

foreach(TARGET IN LISTS TARGETS)
    MESSAGE(STATUS expression/${TARGET})
    add_executable(${TARGET} ${TARGET}.cpp)
endforeach()