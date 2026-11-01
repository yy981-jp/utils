utils_add_app(conca3 conca3.cpp)
find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs highgui videoio)
target_include_directories(conca3 PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(conca3 PRIVATE ${OpenCV_LIBS})
