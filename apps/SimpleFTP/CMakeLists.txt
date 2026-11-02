utils_add_app(SimpleFTP SimpleFTP.cpp)
find_package(CURL REQUIRED)
target_link_libraries(SimpleFTP PRIVATE CURL::libcurl)
