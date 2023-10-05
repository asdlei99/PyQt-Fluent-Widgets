cmake_minimum_required(VERSION 3.5)
project(QFluentWidgetsDemo LANGUAGES CXX)

add_subdirectory(examples)

set(DLL_SUFFIX ".so")
if(WIN32)
    set(DLL_SUFFIX ".dll")
elseif(APPLE)
    set(DLL_SUFFIX ".dylib")
endif()

configure_file(${CMAKE_SOURCE_DIR}/lib/libFramelessHelperCore${DLL_SUFFIX} ${CMAKE_SOURCE_DIR}/build/bin/libFramelessHelperCore${DLL_SUFFIX} COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/libFramelessHelperWidgets${DLL_SUFFIX} ${CMAKE_SOURCE_DIR}/build/bin/libFramelessHelperWidgets${DLL_SUFFIX} COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/lib/libQFluentWidgets${DLL_SUFFIX} ${CMAKE_SOURCE_DIR}/build/bin/libQFluentWidgets${DLL_SUFFIX} COPYONLY)