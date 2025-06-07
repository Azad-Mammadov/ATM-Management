cmake_minimum_required(VERSION 3.25)
project(ATM_Management VERSION 1.0)

# Enable C++23 and modules
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add module implementation
add_library(bank_lib
    src/bank.cpp
    src/bank.cppm
)

# Set module properties
set_target_properties(bank_lib PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Add the test executable
add_executable(bank_test
    src/bank_tester.cpp
)

# Link the test executable with the library
target_link_libraries(bank_test PRIVATE bank_lib)

# MSVC specific settings
if(MSVC)
    target_compile_options(bank_lib PRIVATE /W4 /WX)
    target_compile_options(bank_test PRIVATE /W4 /WX)
endif()