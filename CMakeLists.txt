cmake_minimum_required(VERSION 3.27)
project(zixuecpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(zixuecpp main.cpp

                ex2_42.h
        Chapter6.h
        fact.cpp
        Sales_data.h
        avg_price.cpp
        avg_price.h
        Screen.cpp
        Screen.h
        #        data/maimai.cpp
)

add_executable(test test.cpp)