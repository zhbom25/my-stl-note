cmake_minimum_required(VERSION 3.17.3)
project(stl)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(stl
        test.cpp
        config10.h
        my_alloc.h
        test_1_9_2.h
        test_1_9_4.h
        test_1_9_6.h
        test_alloc.h
        zballoc.h
        mlist.h mitem.h mfind.h miter.h list_test.cpp test_8_1.cpp test_8_4.cpp test_8_4_2.cpp test_8_8.cpp test_8_3_3.cpp test_8_3_2.cpp)