cmake_minimum_required(VERSION 3.5)
project(QFluentWidgetsDemo LANGUAGES CXX)

add_subdirectory(examples)

configure_file(${CMAKE_SOURCE_DIR}/lib/libFramelessHelperCore64.dll ${CMAKE_SOURCE_DIR}/build/bin/libFramelessHelperCore64.dll COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/libFramelessHelperWidgets64.dll ${CMAKE_SOURCE_DIR}/build/bin/libFramelessHelperWidgets64.dll COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/libQFluentWidgets.dll ${CMAKE_SOURCE_DIR}/build/bin/libQFluentWidgets.dll COPYONLY)