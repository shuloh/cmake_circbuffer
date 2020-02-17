cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CircularBuffer VERSION 0.1.0)

configure_file(circbuffer.h.in circbuffer.h)

#circbuffer.cpp is entrypoint of program
add_executable(CircularBuffer circbuffer.cpp)
#add binary tree to search path for include files to find circbuffer.h
target_include_directories(CircularBuffer PUBLIC "${PROJECT_BINARY_DIR}")
install(TARGETS CircularBuffer DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/CircBuffer.h" DESTINATION include)
#add libraries
add_subdirectory(DS_CircularBuffer)
list(APPEND EXTRA_LIBS DS_CircularBuffer)
target_link_libraries(CircularBuffer PUBLIC ${EXTRA_LIBS})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

include(CTest)
enable_testing()