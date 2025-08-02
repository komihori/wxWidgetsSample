cmake_minimum_required(VERSION 3.1)
project(FirstApp)

find_package(wxWidgets COMPONENTS core base)
include(${wxWidgets_USE_FILE})
set(BinaryFileName ${PROJECT_NAME}.out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Build)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
