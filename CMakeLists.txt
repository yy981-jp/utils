cmake_minimum_required(VERSION 3.25)
project(utils LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/shared/ui")

include(cmake/UtilsApp.cmake)

file(GLOB APP_DIRS CONFIGURE_DEPENDS LIST_DIRECTORIES true "${PROJECT_SOURCE_DIR}/apps/*")
set(_utils_app_names)
foreach(APP_DIR IN LISTS APP_DIRS)
	if(EXISTS "${APP_DIR}/CMakeLists.txt")
		get_filename_component(APP_NAME "${APP_DIR}" NAME)
		list(APPEND _utils_app_names "${APP_NAME}")
	endif()
endforeach()
list(SORT _utils_app_names)

set(UTILS_APP "ALL" CACHE STRING "Application to configure (ALL or an app directory name)")
set_property(CACHE UTILS_APP PROPERTY STRINGS ALL ${_utils_app_names})

if(UTILS_APP STREQUAL "ALL")
	foreach(APP_DIR IN LISTS APP_DIRS)
		if(EXISTS "${APP_DIR}/CMakeLists.txt")
			add_subdirectory("${APP_DIR}")
		endif()
	endforeach()
elseif(UTILS_APP IN_LIST _utils_app_names)
	add_subdirectory("${PROJECT_SOURCE_DIR}/apps/${UTILS_APP}")
else()
	message(FATAL_ERROR
		"Unknown UTILS_APP='${UTILS_APP}'. Choose ALL or one of: ${_utils_app_names}"
	)
endif()
