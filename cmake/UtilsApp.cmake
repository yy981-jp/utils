function(utils_add_app target source)
	add_executable(${target} ${source})
	target_compile_features(${target} PRIVATE cxx_std_23)
	set_target_properties(${target} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
		LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
		ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build"
	)
	set(_utils_app_flags ${ARGN})
	if(NOT "NO_CP932" IN_LIST _utils_app_flags)
		target_compile_options(${target} PRIVATE $<$<CXX_COMPILER_ID:GNU>:-fexec-charset=cp932>)
	endif()
	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/yy981")
		target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/external")
	endif()
endfunction()

function(utils_use_qt target)
	# Qt's deploy-support path calculation assumes a native Windows or Unix path
	# layout. It is not needed by these targets during configure/build on MSYS2.
	if(MINGW OR MSYS)
		set(QT_SKIP_SETUP_DEPLOYMENT ON)
	endif()
	find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets ${ARGN})
	target_link_libraries(${target} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
	foreach(_component IN LISTS ARGN)
		target_link_libraries(${target} PRIVATE Qt6::${_component})
	endforeach()
endfunction()
