cmake_minimum_required(VERSION 3.5)
project(${DEMO_NAME} VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# -----------------------------------------------------------------------------
file(GLOB inc_files ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB shared_inc_files ${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/*.h)
file(GLOB shared_src_files ${CMAKE_CURRENT_SOURCE_DIR}/../../Shared/*.cpp)

add_executable(${DEMO_NAME} ${src_files} ${inc_files} ${shared_inc_files} ${shared_src_files})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets QFluentWidgets::Widgets FramelessHelper::Core FramelessHelper::Widgets)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../framelesshelper/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../Shared
)