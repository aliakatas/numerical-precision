cmake_minimum_required(VERSION 3.16)

project(test-numerical-precision VERSION 1.0.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build options
option(BUILD_DEBUG "Build debug version" OFF)
option(DLL_BUILD "Build as a DLL/shared library" OFF)

# Set compiler flags based on the compiler and build type
if(MSVC)
    # MSVC compiler flags
    set(COMMON_FLAGS "/W4")
    set(DEBUG_FLAGS "/Od /Zi")
    set(RELEASE_FLAGS "/O2")
else()
    # GCC, Clang, and other compiler flags
    set(COMMON_FLAGS "-Wall -Wextra")
    set(DEBUG_FLAGS "-O0 -g")
    set(RELEASE_FLAGS "-O3")
endif()

# Create the binary (executable/shared library)
if (DLL_BUILD)
   set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
   add_library(${PROJECT_NAME} SHARED "${CMAKE_SOURCE_DIR}/src/test_numerical_precision.cxx")
else()
   add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/src/test_numerical_precision.cxx")
endif()

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC 
    "${CMAKE_SOURCE_DIR}/src"
)

# Link the standard libraries and Boost in a platform-independent way
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        ${CMAKE_CXX_STANDARD_LIBRARIES}
)

# Determine debug mode: either BUILD_DEBUG option or CMAKE_BUILD_TYPE=Debug (case-insensitive)
string(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE_UPPER)
if(BUILD_DEBUG OR CMAKE_BUILD_TYPE_UPPER STREQUAL "DEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${DEBUG_FLAGS}")
    target_compile_definitions(${PROJECT_NAME} PRIVATE "_DEBUG")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${RELEASE_FLAGS}")
endif()
