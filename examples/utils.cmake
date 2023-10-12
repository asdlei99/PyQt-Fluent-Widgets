cmake_minimum_required(VERSION 3.5)
project(${DEMO_NAME} VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# -----------------------------------------------------------------------------
file(GLOB inc_files ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB shared_inc_files ${CMAKE_SOURCE_DIR}/examples/Shared/*.h)
file(GLOB shared_src_files ${CMAKE_SOURCE_DIR}/examples/Shared/*.cpp)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${DEMO_NAME} ${src_files} ${inc_files} ${shared_inc_files} ${shared_src_files})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets QFluentWidgets FramelessHelperCore64 FramelessHelperWidgets64)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/QFluentWidgets/include
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/include
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/src/core
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/src/widgets
        ${CMAKE_SOURCE_DIR}/include/framelesshelper/qmake/inc/core
        ${CMAKE_SOURCE_DIR}/examples/Shared
)