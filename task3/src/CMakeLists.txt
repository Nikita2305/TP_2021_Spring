add_library(buffer SHARED buffer.cpp)

install(FILES ${PROJECT_SOURCE_DIR}/include/buffer.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install(TARGETS buffer LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
