cmake_minimum_required(VERSION 3.14)
project(lw4.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(run_tests
    shapes/CCircle.cpp
    shapes/CLineSegment.cpp
    shapes/CPoint.cpp
    shapes/CRectangle.cpp
    shapes/CTriangle.cpp
    tests/CCircle_tests.cpp
    tests/CLineSegment_tests.cpp
    tests/CPoint_tests.cpp
    tests/CRectangle_tests.cpp
    tests/CTriangle_tests.cpp)
target_link_libraries(run_tests GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)

add_executable(main
    shapes/CCircle.cpp
    shapes/CLineSegment.cpp
    shapes/CPoint.cpp
    shapes/CRectangle.cpp
    shapes/CTriangle.cpp
    CShapeParser.cpp
    Program.cpp
    main.cpp)
