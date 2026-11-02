utils_add_app(getLan4 getLan4.cpp)
if(WIN32)
	target_link_libraries(getLan4 PRIVATE ws2_32 iphlpapi)
endif()
