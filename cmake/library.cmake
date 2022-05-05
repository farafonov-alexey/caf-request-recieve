project(library CXX)
set(SRCS
        library/caf_system.cpp
        library/caf_system_config.cpp
        library/library_manager.cpp

        library/interface.cpp
        library/library.cpp
        library/sender_actor.cpp
        library/reciever_actor.cpp
        )
add_library(${PROJECT_NAME} SHARED ${SRCS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
if (WIN32)
    add_compile_definitions(LIB_LIBRARY)
endif()
set(DEPS
        # Qt5Core
        caf_core
        fruit
        # caf_io
        ${CAF_EXTRA_LDFLAGS}
        )
target_link_libraries(${PROJECT_NAME} ${DEPS})