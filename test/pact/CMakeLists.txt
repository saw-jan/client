cmake_minimum_required(VERSION 3.16)

# project name
project(ClientContractTesting LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(EXECUTABLE_NAME tests)

set(TEST_SRCS
  example.cpp
)

add_executable(${EXECUTABLE_NAME} ${TEST_SRCS})

# link libraries
target_link_libraries(${EXECUTABLE_NAME} ${CONAN_LIBS})