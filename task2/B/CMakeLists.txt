project(lib)
set(SOURCES lib.cpp)
set(HEADERS lib.h)
add_library(lib SHARED ${SOURCES} ${HEADERS})
