project(qt_app)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
qt5_wrap_ui(QT_UI_WRAPPED qt_app/about_dialog.ui)
qt5_wrap_cpp(QT_SRCS_WRAPPED qt_app/about_dialog.h)
add_executable(${PROJECT_NAME} 
                qt_app/main.cpp
                qt_app/about_dialog.cpp
                qt_app/about_dialog.ui
                qt_app/about_dialog.h
                ${QT_UI_WRAPPED} 
                ${QT_SRCS_WRAPPED}
                )
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets library)