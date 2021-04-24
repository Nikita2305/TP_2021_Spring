cmake_minimum_required(VERSION 3.10)
project(TP_project)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
# set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH} /usr/share/cmake-3.10/Modules/FindThreads.cmake")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(SOURCES C/main.cpp)
set(HEADERS C/main.h A/index.h)
set(TEST_SOURCE C/main_test.cpp)

add_subdirectory(B)
include_directories(.)
include_directories(${GTEST_INCLUDE_DIRS})

set_target_properties(lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(C ${SOURCES} ${HEADERS})
add_executable(CTest ${TEST_SOURCE})
target_link_libraries(C lib)
target_link_libraries(CTest lib)
target_link_libraries(CTest ${GTEST_LIBRARIES} Threads::Threads)

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
