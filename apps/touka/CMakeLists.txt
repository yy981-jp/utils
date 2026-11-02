utils_add_app(touka touka.cpp)
find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs)
target_include_directories(touka PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(touka PRIVATE ${OpenCV_LIBS})
