# ApproxiMath
This project shows how to structure a simple CMake project with the following features:
 - CMake compilation (Debug, Release);
 - Automatic documentation (Doxygen);
 - Unit test (ctest);

for **executable** development.

# The project structure
```console
project_executable
├── CMakeLists.txt
├── GUIDELINE.md
├── README.md
├── approximath
│   ├── inc
│   │   └── approximath.hpp
│   └── src
│       ├── approximath.cpp
│       └── main.cpp
├── data
│   └── dataset_0.txt
└── doc
    ├── CMakeLists.txt
    └── Doxyfile
```

## The executable folder
```console
approximath
├── inc
│   └── approximath.hpp
└── src
    ├── approximath.cpp
    └── main.cpp
```
The executable folder contains two subfolders `inc` and `src`. In the `inc` directory we include all the header files, like `approximath.hpp`. In the `src` directory we include all the source files like `approximath.cpp` and the main file of the executable `main.cpp`.

## The data folder

The `data` folder contains data for testing purposes. A good practice for test data is to use `git lfs` to track large files.

## The doc folder

The `doc` folder contains any documentation file, including the automatic documentation generated using Doxygen. 

# The CMake project structure

The CMake project is composed by two files. The first `CMakeList.txt` file is in the root directory and the second file is in the `doc` directory.

The first `CMakeList.txt` file is organized as follows:

The first step is to set the minimum `cmake` version, the project name, and the default build type as `Debug`.

```cmake
cmake_minimum_required(VERSION 3.1...3.18)

# Set the project name.
project(approximath)

# Set the default build type to Debug.
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
endif()
```

Then we visit the doc subdirectory using
```cmake
add_subdirectory(doc)
```
this command search for the `CMakeList.txt` file in the `doc` directory and execute it, which generate the documentation with Doxygen.

```cmake
# Find the doxygen tool.
find_package(Doxygen)

# If we have found doxygen, then we can add the target.
if (DOXYGEN_FOUND)
    # Set input and output files.
    set(DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # Request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # Add the actual target.
    add_custom_target(doc_doxygen
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
```

After generating the documentation, we set the compiler flags
```cmake
# Set C++ Standard.
set(CMAKE_CXX_STANDARD 17)

# Set the actual flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")

    message("Disabling optimizations.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

elseif (CMAKE_BUILD_TYPE STREQUAL "Release")

    message("Enabling optimizations.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

```
We set different flags according to the `CMAKE_BUILD_TYPE` variable which is set as the `Debug` value as default. It is possible to enable the `Release` mode when invoking the `cmake` including the flag `-DCMAKE_BUILD_TYPE=Release`.

We then incude the project directories and add the C++ executable
```cmake
include_directories(
        # Include project directories.
        ${CMAKE_SOURCE_DIR}/inc/
)

add_executable(approximath
    ${CMAKE_SOURCE_DIR}/src/approximath.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
```

We then enable the tests and add the test for our application which can be executed using `make test` from the build directory.
```cmake
enable_testing()

add_test(test_1 approximath ../data/dataset_0.txt)
```