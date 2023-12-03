CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)
project(BenchmarkTest)

ADD_EXECUTABLE(BenchmarkTest
    maintest.cpp
)


TARGET_LINK_LIBRARIES(BenchmarkTest gtest)
TARGET_COMPILE_DEFINITIONS(BenchmarkTest PRIVATE gtest_disable_pthreads=ON)