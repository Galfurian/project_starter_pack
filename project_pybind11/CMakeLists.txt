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
# Documentation target.
# -----------------------------------------------------------------------------
add_subdirectory(doc)

# -----------------------------------------------------------------------------
# External projects.
# -----------------------------------------------------------------------------
# We need this in order to import external projects.
include(FetchContent)
message(STATUS "Retrieving pybind11...")
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY "https://github.com/pybind/pybind11.git"
    GIT_SHALLOW    TRUE
    GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(pybind11)

# -----------------------------------------------------------------------------
# Set the compilation flags.
# -----------------------------------------------------------------------------
# Set C++ Standard.
set(CMAKE_CXX_STANDARD 17)

# Set the actual flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")

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
pybind11_add_module(
    approximath
    ${CMAKE_SOURCE_DIR}/src/approximath.cpp
)

# -----------------------------------------------------------------------------
# Inlcude header directories and set the library.
# -----------------------------------------------------------------------------
target_include_directories(
    approximath PUBLIC
    # Include project directories.
    ${CMAKE_SOURCE_DIR}/include/
    # Inlcude directories coming from external libraries.
    # e.g., ${EIGEN_INCLUDE_DIRS}
)

# -----------------------------------------------------------------------------
# Add the target for generating the python interface.
# -----------------------------------------------------------------------------
set(STUBGEN ${PROJECT_SOURCE_DIR}/doc/pybind11-stubgen.py)
add_custom_target(
        stubs
        DEPENDS ${STUBGEN}
        DEPENDS approximath
)
add_custom_command(
        TARGET stubs
        COMMAND echo "Generating python stubs..."
        COMMAND cp ${STUBGEN} ${PROJECT_BINARY_DIR}
        COMMAND ${PYTHON_EXECUTABLE} pybind11-stubgen.py ${PROJECT_NAME} --output-dir="." --root-module-suffix="" --no-setup-py --log-level=DEBUG
        COMMAND echo "Generating python stubs... done!"
        DEPENDS ${STUBGEN}
        DEPENDS approximath
)

# -----------------------------------------------------------------------------
# Add linked libraries (if required).
# -----------------------------------------------------------------------------
#target_link_libraries(
#    approximath
#    Eigen3::Eigen
#)

# -----------------------------------------------------------------------------
# Add tests.
# -----------------------------------------------------------------------------
# CMake has support for adding tests to a project:
enable_testing()
# Add the subdirectory containing the tests (which imports also their target).
add_subdirectory(test)
