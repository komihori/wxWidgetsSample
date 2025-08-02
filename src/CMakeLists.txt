add_library(mainSource
    SHARED
    MyFrame.cpp
    MyApp.cpp
)

target_include_directories(mainSource
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_executable(${BinaryFileName} main.cpp)

target_compile_features(${BinaryFileName} PUBLIC cxx_std_14)
target_link_libraries(${BinaryFileName} mainSource)
target_link_libraries(${BinaryFileName} ${wxWidgets_LIBRARIES})