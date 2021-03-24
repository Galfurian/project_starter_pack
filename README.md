# Project starter pack
This repository is ment to provide guidelines to setup a new C/C++ project in different circumstances, e.g., if your new project is an executable project, or a library project.

The repository is structured as follows. Each project type has its own project directory. Each project directory is self contained and can be compiled. The project directory also contains a `GUIDELINE.md` file where we explain the project organization and the technologies used.

# Source
The directories contain:
 - project_executable : An example of project for generating an executable.
 - project_library    : An example of project for generating a library.
 ...

# How to use this repository

You can copy the project folder of the type of project you need to develop, and use it as a template. You can also combine technologies from more than one project folder, and integrate them in your project.

# Technologies

In this repository we apply different technologies such as:
* `git`
* `CMake`
    * `ExternalProject` (Coming soon)
    * `FetchContent` (Coming soon)
* `Doxygen`
* `ctest`


# Authors

* [Enrico Fraccaroli](https://github.com/Galfurian)
* [Massimiliano Rossi](https://github.com/maxrossi91)

Specal thanks to the **room 1.71** group at the University of Verona.

# Placeholder

List of useful links that should be included inside the documentation:

 * https://leimao.github.io/blog/CMake-Public-Private-Interface/