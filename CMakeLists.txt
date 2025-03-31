cmake_minimum_required(VERSION 3.16)
project(ANTHILL VERSION 0.1 LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define directories for sources, headers, and resources
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/Sources")
set(HEADER_DIR "${CMAKE_SOURCE_DIR}/Headers")

# Debug output to verify paths
message(STATUS "Source directory: ${SOURCE_DIR}")
message(STATUS "Header directory: ${HEADER_DIR}")

# Automatically collect all .cpp and .hpp files
file(GLOB_RECURSE PROJECT_SOURCES 
    "${SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/main.cpp"
)
file(GLOB_RECURSE PROJECT_HEADERS "${HEADER_DIR}/*.hpp")


# Add executable target
add_executable(ANTHILL ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# Include header directories and link libraries
target_include_directories(ANTHILL PRIVATE 
${CMAKE_SOURCE_DIR}
${HEADER_DIR} 
)
