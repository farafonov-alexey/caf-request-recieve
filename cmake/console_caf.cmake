project(console_caf)
add_executable(${PROJECT_NAME} console_caf/main.cpp)
target_link_libraries(${PROJECT_NAME}
        caf_core
        ${CAF_EXTRA_LDFLAGS}
)