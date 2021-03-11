cmake_minimum_required(VERSION 3.10)
project(TP_project)

set(SOURCES C/main.cpp)
set(HEADERS C/main.h A/index.h)

add_subdirectory(B)
include_directories(.)
set_target_properties(lib PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(C ${SOURCES} ${HEADERS})

target_link_libraries(C lib)

add_custom_target(
    run_target ALL
	DEPENDS ${CMAKE_SOURCE_DIR}/A/index.h
)

add_custom_command(
		PRE_BUILD
		OUTPUT ${CMAKE_SOURCE_DIR}/A/index.h
		COMMAND python3 ${CMAKE_SOURCE_DIR}/A/preparing.py
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/A/
)
