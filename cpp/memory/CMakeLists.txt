SET(TARGETS "size")

foreach(TARGET IN LISTS TARGETS)
    MESSAGE(STATUS memory/${TARGET})
    add_executable(${TARGET} ${TARGET}.cpp)
endforeach()