set(DEMO_NAME LoginDemo)
cmake_minimum_required(VERSION 3.5)
project(${DEMO_NAME} VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED)

# -----------------------------------------------------------------------------
file(GLOB inc_files ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

qt5_wrap_ui(UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/LoginWindow.ui)

# add resource
SET(RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/login.qrc)
qt5_add_resources(RCC_SOURCES ${RCC_FILES})

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${DEMO_NAME} ${src_files} ${inc_files} ${UI_FILES} ${RCC_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets QFluentWidgets FramelessHelperCore FramelessHelperWidgets)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/include
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/src/core
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/src/widgets
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/qmake/inc/core
)