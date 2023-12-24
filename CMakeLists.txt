cmake_minimum_required(VERSION 3.22)
project(apps)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(LIBDIR ${CMAKE_SOURCE_DIR}/libs-windows/)
    set(SHFL_LIBS ${LIBDIR}/appmgr.lib ${LIBDIR}/commandmgr.lib ${LIBDIR}/suggestion.lib ${LIBDIR}/utils.lib ${LIBDIR}/workspace.lib
            ${LIBDIR}/jsoncpp.lib ${LIBDIR}/kubazip.lib ${LIBDIR}/libcurl.lib ${LIBDIR}/zlib.lib)
elseif(UNIX)
    set(LIBDIR ${CMAKE_SOURCE_DIR}/libs-linux/)
    set(SHFL_LIBS ${LIBDIR}/libappmgr.a ${LIBDIR}/libcommandmgr.a ${LIBDIR}/libsuggestion.a ${LIBDIR}/libutils.a ${LIBDIR}/libworkspace.a)
elseif(APPLE)
    set(LIBDIR ${CMAKE_SOURCE_DIR}/libs-linux/)
    set(SHFL_LIBS ${LIBDIR}/libappmgr.a ${LIBDIR}/libcommandmgr.a ${LIBDIR}/libsuggestion.a ${LIBDIR}/libutils.a ${LIBDIR}/libworkspace.a)
else()
    MESSAGE(FATAL_ERROR "your system is not supported")
endif()

add_subdirectory(filesystem)
add_subdirectory(textutilities)
add_subdirectory(dateandtime)