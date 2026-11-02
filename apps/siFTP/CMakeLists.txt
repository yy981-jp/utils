utils_add_app(siFTP siFTP.cpp)
find_package(CURL REQUIRED)
target_link_libraries(siFTP PRIVATE CURL::libcurl)
