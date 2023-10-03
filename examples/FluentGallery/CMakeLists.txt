set(DEMO_NAME FluentGallery)
cmake_minimum_required(VERSION 3.5)
project(${DEMO_NAME} VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

file(GLOB_RECURSE inc_files ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# add resource
SET(RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Resource/gallery.qrc)
qt_add_resources(RCC_SOURCES ${RCC_FILES})

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${DEMO_NAME} ${src_files} ${inc_files} ${RCC_SOURCES} main.cpp icon.rc)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets QFluentWidgets FramelessHelperCore64 FramelessHelperWidgets64)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/include
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/src/core
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/src/widgets
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/qmake/inc/core
)