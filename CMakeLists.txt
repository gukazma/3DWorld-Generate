cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(Generate3DWorld VERSION 0.1.0)

# just for qt
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/tools.cmake)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

set(${PROJECT_NAME}_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_INSTALL_PREFIX "${PROJECT_NAME}_ROOT_DIR/bin")
set(BINARY_ROOT_DIR "${CMAKE_INSTALL_PREFIX}/")
# static library output dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_ROOT_DIR}/out/lib)
# dynamic library output dir
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_ROOT_DIR}/out/lib)
# executalbe dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_ROOT_DIR}/out/bin)
# vendors dir
set(VENDORS_DIR ${CMAKE_SOURCE_DIR}/src/Vendors)


add_subdirectory(src)