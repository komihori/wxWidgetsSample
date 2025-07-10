cmake_minimum_required(VERSION 3.1)
project(FirstApp)

find_package(wxWidgets COMPONENTS core base)
include(${wxWidgets_USE_FILE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./Build)

set(src
  MyFrame/MyFrame.hpp
  MyFrame/MyFrame.cpp
  MyApp/MyApp.hpp
  MyApp/MyApp.cpp
  main.cpp
)

add_executable(${PROJECT_NAME}
  ${src}
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})