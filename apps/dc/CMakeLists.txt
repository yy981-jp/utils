utils_add_app(dc dc.cpp)

find_package(OpenSSL REQUIRED COMPONENTS Crypto)
target_link_libraries(dc PRIVATE OpenSSL::Crypto)
