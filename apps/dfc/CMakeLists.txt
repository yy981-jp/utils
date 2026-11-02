utils_add_app(dfc dfc.cpp)

find_package(OpenSSL REQUIRED COMPONENTS Crypto)
target_link_libraries(dfc PRIVATE OpenSSL::Crypto)
