set(DEMO_NAME LoginDemo)
cmake_minimum_required(VERSION 3.5)
project(${DEMO_NAME} VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# -----------------------------------------------------------------------------
file(GLOB inc_files ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

qt_wrap_ui(UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/LoginWindow.ui)

# add resource
SET(RCC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/login.qrc)
qt_add_resources(RCC_SOURCES ${RCC_FILES})

add_executable(${DEMO_NAME} ${src_files} ${inc_files} ${UI_FILES} ${RCC_SOURCES})
include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Widgets QFluentWidgets::Widgets FramelessHelper::Core FramelessHelper::Widgets)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../framelesshelper/include
)