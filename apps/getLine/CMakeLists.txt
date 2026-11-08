utils_add_app(getLine getLine.cpp NO_CP932)
find_path(RAPIDJSON_INCLUDE_DIR rapidjson/document.h REQUIRED)
target_include_directories(getLine PRIVATE ${RAPIDJSON_INCLUDE_DIR})
