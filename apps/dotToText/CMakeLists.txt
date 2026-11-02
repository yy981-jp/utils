utils_add_app(dotToText dotToText.cpp)
find_package(OpenCV REQUIRED COMPONENTS core imgcodecs)
target_include_directories(dotToText PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(dotToText PRIVATE ${OpenCV_LIBS})
