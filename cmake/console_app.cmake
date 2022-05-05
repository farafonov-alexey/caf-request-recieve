project(console_app)
add_executable(${PROJECT_NAME} console_app/main.cpp)
target_link_libraries(${PROJECT_NAME} library)