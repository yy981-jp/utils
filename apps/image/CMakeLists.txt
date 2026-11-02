utils_add_app(image image.cpp)
utils_use_qt(image)
find_package(Boost REQUIRED)
target_include_directories(image PRIVATE ${Boost_INCLUDE_DIRS})
