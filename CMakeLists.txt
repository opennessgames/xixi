#
#    FileName : CMakeLists.txt
#    By :  xixi_
#    MakeTime : 2024-10-21 16:59:41
#    Copyright (C) 2023-2024 openGames
#
cmake_minimum_required(VERSION 3.10)
project(xixi VERSION 1.0.0)

# 头文件和库的安装路径
set(CMAKE_INSTALL_INCLUDEDIR "include")
set(CMAKE_INSTALL_SHARELIB "lib")

# 库的输出路径
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/debian/xixi/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/debian/xixi/lib")

# 查找所有源文件和头文件
file(GLOB_RECURSE SOURCES "src/*/*.c")
file(GLOB_RECURSE HEADERS "src/*/*.h")

# 创建库
# add_library(xixia STATIC ${SOURCES})
add_library(xixi SHARED ${SOURCES})

# 将头文件目录添加到目标属性
target_include_directories(xixi PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# 链接数学库
target_link_libraries(xixi m)

# 安装规则，仅安装头文件和库
install(TARGETS xixi
    EXPORT xixiTargets
    # ARCHIVE DESTINATION ${CMAKE_INSTALL_SHARELIB}
    LIBRARY DESTINATION /lib
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/xixi)

# CPack 配置
include(CPack)

# 包信息
set(CPACK_PACKAGE_NAME "xixi")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT "youremail@example.com")
set(CPACK_GENERATOR "DEB")

# Debian 控制文件
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "xixi_") # 维护者信息
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.29)") # 依赖
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "C语言基础库，包含栈、JSON、基本视频操作等基本接口")
set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")

# 卸载
if(NOT TARGET xixi_uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
        IMMEDIATE @ONLY
    )
    add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake")
endif()
