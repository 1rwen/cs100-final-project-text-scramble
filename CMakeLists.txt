CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)
project(BenchmarkTests)

ADD_EXECUTABLE(BenchmarkTests
    BenchmarkTest.cpp
    Benchmark.cpp


)


TARGET_LINK_LIBRARIES(BenchmarkTests gtest)
TARGET_COMPILE_DEFINITIONS(BenchmarkTests PRIVATE gtest_disable_pthreads=ON)