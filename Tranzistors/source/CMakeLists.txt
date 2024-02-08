cmake_minimum_required(VERSION 3.5)

project(mslast VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Users/spudi/Desktop/boost_1_82_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/Users/spudi/Desktop/boost_1_82_0/stage/lib")
find_package(Boost 1.71 REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Charts)
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        tranz.h
        exc.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(mslast
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET mslast APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(mslast SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(mslast
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(mslast PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(mslast PRIVATE Qt6::Charts)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(mslast PRIVATE ${Boost_LIBRARIES})
endif()
set_target_properties(mslast PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS mslast
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(mslast)
endif()
