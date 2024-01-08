file(GLOB FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

foreach(FILE IN LISTS FILES)
    get_filename_component(NAME_ ${FILE} "NAME_WLE")
    MESSAGE(STATUS ${NAME_})
    add_executable(${NAME_} ${NAME_}.cpp)
endforeach()