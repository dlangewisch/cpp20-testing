cmake_minimum_required(VERSION 3.19)

project(cpp20-testing
  DESCRIPTION "Code for experimenting with BGL in C++"
  LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)

# This ensures that the build directory is ignored by Git
file(WRITE ${CMAKE_BINARY_DIR}/.gitignore "*")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}"
      CACHE PATH "setting default install dir" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

## Enable assertions for RelWithDebInfo build
string(REGEX REPLACE " ?[-/]DNDEBUG" "" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

set(CMAKE_INSTALL_RPATH $ORIGIN $ORIGIN/../lib)
set(CMAKE_BUILD_RPATH $ORIGIN $ORIGIN/../lib)

add_subdirectory(src)
