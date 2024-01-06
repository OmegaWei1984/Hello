SET(TARGETS "invalid_iterator")

foreach(TARGET IN LISTS TARGETS)
    MESSAGE(STATUS containers_library/${TARGET})
    add_executable(${TARGET} ${TARGET}.cpp)
endforeach()