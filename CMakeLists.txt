
cmake_minimum_required(VERSION 3.20)
project("Zephyrous" LANGUAGES CXX)

# 启用 vcpkg 依赖
if (DEFINED ENV{VCPKG_ROOT})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{VCPKG_ROOT}/installed/x64-windows-static")
endif()

# 标准配置
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件路径
set(HEADER_INCLUDE "${PROJECT_SOURCE_DIR}/src/include")

# 查找 SFML（通过 vcpkg）
find_package(SFML COMPONENTS Graphics Window System Network Audio CONFIG REQUIRED)

# 查找 EnTT
set(ENTT_DIR "${PROJECT_SOURCE_DIR}/third/entt/include")
find_package(EnTT 3.14.0 CONFIG REQUIRED)

# 源文件
set(SOURCES
    "${PROJECT_SOURCE_DIR}/src/Main.cpp"
)

# 头文件列表（保持原样）
set(HEADERS
    # ...（原有头文件路径）
    "${HEADER_INCLUDE}/Component/BlockComponent/BlockDifficulty.h"
    "${HEADER_INCLUDE}/Component/BlockComponent/BlockKind.h"
    "${HEADER_INCLUDE}/Component/BlockComponent/BlockPosition.h"
    
    "${HEADER_INCLUDE}/Component/BlockComponent/BlockSquare.h"

    "${HEADER_INCLUDE}/Component/PersonComponent/Stata.h"

    "${HEADER_INCLUDE}/Component/Tool/Debug.h"

    "${HEADER_INCLUDE}/Component/ViewComponent/ViewSize.h"
    "${HEADER_INCLUDE}/Component/ViewComponent/ViewMove.h"
    "${HEADER_INCLUDE}/Component/ViewComponent/ViewRuntime.h"

    "${HEADER_INCLUDE}/Component/WindowComponent/WindowConfig.h"
    "${HEADER_INCLUDE}/Component/WindowComponent/WindowRuntime.h"
    "${HEADER_INCLUDE}/Component/WindowComponent/WindowConfigBuilder.h"
    "${HEADER_INCLUDE}/Component/WindowComponent/WindowFactory.h"
    "${HEADER_INCLUDE}/Component/WindowComponent/WindowVisitor.h"

    "${HEADER_INCLUDE}/System/MapSystem.h"
    "${HEADER_INCLUDE}/System/PlayerSystem.h"
    "${HEADER_INCLUDE}/System/WindowSystem.h"
    "${HEADER_INCLUDE}/System/ViewSystem.h"
    "${HEADER_INCLUDE}/System/BlockSystem.h"
    "${HEADER_INCLUDE}/System/RenderSystem.h"
    "${HEADER_INCLUDE}/System/CreateSystem.h"
)

# 生成可执行文件
add_executable(Zephyrous ${SOURCES} ${HEADERS} )

# 链接库
target_link_libraries(Zephyrous PRIVATE
    EnTT::EnTT
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Network
    SFML::Audio
)

# 包含目录
target_include_directories(Zephyrous PUBLIC
    ${HEADER_INCLUDE}
    "${ENTT_DIR}"
    "${HEADER_INCLUDE}/Component"
)
