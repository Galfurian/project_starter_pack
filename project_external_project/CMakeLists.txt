# -----------------------------------------------------------------------------
# @brief  : Root cmake file.
# @author : Enrico Fraccaroli
# @create : 23/03/2021
# @update : 23/03/2021
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Set the minimum CMake version, the project name and default build type.
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.1...3.18)

# Set the project name.
project(approximath)

# Set the default build type to Debug.
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
endif()

# -----------------------------------------------------------------------------
# External projects.
# -----------------------------------------------------------------------------
# We need this in order to import external projects.
include(ExternalProject)

# First try to find the one installed on the system.
#find_package (Eigen3 3.3 REQUIRED NO_MODULE)

if (Eigen3_FOUND)

    message(STATUS "Eigen3 found. No need to build our own copy...")

else(Eigen3_FOUND)

    message(STATUS "Eigen3 not found. Forcing to build own copy...")

    # Set the build directory and the output directory.
    set(eigen_OUTPUT_PATH "${CMAKE_BINARY_DIR}/eigen")
    set(eigen_BUILD_PATH  "${CMAKE_BINARY_DIR}/eigen-build/")

    message(STATUS "Downloading Eigen3 and building...")
    # Add an external project, this example is using eigen.
    ExternalProject_Add(eigen
        PREFIX         "${eigen_BUILD_PATH}"
        GIT_REPOSITORY "https://gitlab.com/libeigen/eigen.git"
        GIT_TAG        3.4
        INSTALL_DIR    ${eigen_OUTPUT_PATH}
        CMAKE_ARGS     -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    )

    # Set Eigen3 include directory.
    set(EIGEN3_INCLUDE_DIR "${eigen_OUTPUT_PATH}/include/eigen3")

endif(Eigen3_FOUND)

# -----------------------------------------------------------------------------
# Documentation target.
# -----------------------------------------------------------------------------
add_subdirectory(doc)

# -----------------------------------------------------------------------------
# Set the compilation flags.
# -----------------------------------------------------------------------------
# Set C++ Standard.
set(CMAKE_CXX_STANDARD 17)

# Set the actual flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")

    message(STATUS "Disabling optimizations.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

elseif (CMAKE_BUILD_TYPE STREQUAL "Release")

    message(STATUS "Enabling optimizations.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

# -----------------------------------------------------------------------------
# Add the C++ Executable.
# -----------------------------------------------------------------------------
add_executable(
    approximath
    ${CMAKE_SOURCE_DIR}/src/approximath.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

# If the desired library is not installed system-wide, add the dependency
# w.r.t. the external source.
if (NOT Eigen3_FOUND)
    add_dependencies(approximath eigen)
endif(NOT Eigen3_FOUND)

# -----------------------------------------------------------------------------
# Inlcude header directories and set the library.
# -----------------------------------------------------------------------------
target_include_directories(
    approximath PRIVATE
    # Include project directories.
    ${CMAKE_SOURCE_DIR}/include/
    # Inlcude directories coming from external libraries.
    ${EIGEN3_INCLUDE_DIR}
)

# -----------------------------------------------------------------------------
# Add executable libraries (if required).
# -----------------------------------------------------------------------------
#target_link_libraries( 
#    approximath
#    ${Eigen3_LIBRARY}
#)

# -----------------------------------------------------------------------------
# Add tests.
# -----------------------------------------------------------------------------
# CMake has support for adding tests to a project:
enable_testing()

# -----------------------------------------------------------------------------
# TEST 1 (This one uses the dataset from file)
# -----------------------------------------------------------------------------
add_test(test_1 approximath ../data/dataset_0.txt)
