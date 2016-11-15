cmake_minimum_required(VERSION 3.6)
project(COMP_3270)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/AbstractStrategy.cpp src/AbstractStrategy.h src/strat_1/Strat1.cpp src/strat_1/Strat1.h src/strat_2/Strat2.cpp src/strat_2/Strat2.h src/strat_3/Strat3.cpp src/strat_3/Strat3.h src/FileHandler.cpp src/FileHandler.h src/ArgParser.cpp src/ArgParser.h src/err_codes.h src/err_codes.cpp)
add_executable(COMP_3270 ${SOURCE_FILES})