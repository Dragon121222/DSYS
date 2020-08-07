cmake_minimum_required(VERSION 3.8.2)
project(DEMO0)
set(CMAKE_CXX_STANDARD 17)

add_executable(DEMOEXE APP/DEMOMAIN.cpp 
					   SRC/DEMOCLASS.h SRC/DEMOCLASS.cpp)

target_link_libraries(DEMOEXE)