cmake_minimum_required(VERSION 3.1)

project(firstapp)

find_package(wxWidgets COMPONENTS core base)
include(${wxWidgets_USE_FILE})

set(src
  MyFrame/MyFrame.hpp
  MyFrame/MyFrame.cpp
  MyApp/MyApp.hpp
  MyApp/MyApp.cpp
  main.cpp
)

add_executable(FirstApp WIN32
  ${src}
)

target_compile_features(FirstApp PUBLIC cxx_std_14)

target_link_libraries(FirstApp ${wxWidgets_LIBRARIES})
