set(DEMO_NAME FluentGallery)
cmake_minimum_required(VERSION 3.5)
project(${DEMO_NAME} VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# -----------------------------------------------------------------------------
file(GLOB_RECURSE inc_files ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# add resource
SET(RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Resource/gallery.qrc)
qt_add_resources(RCC_SOURCES ${RCC_FILES})

add_executable(${DEMO_NAME} ${src_files} ${inc_files} ${RCC_SOURCES} main.cpp icon.rc)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets QFluentWidgets::Widgets FramelessHelper::Core FramelessHelper::Widgets)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../framelesshelper/include
)