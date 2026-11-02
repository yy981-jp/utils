utils_add_app(danger_thg2 danger_thg2.cpp)
utils_use_qt(danger_thg2)
target_sources(danger_thg2 PRIVATE "${PROJECT_SOURCE_DIR}/shared/ui/thg2.ui")
utils_enable_automoc(danger_thg2)
