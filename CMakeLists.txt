# =============================================================================
# tcxLua - TrussC Lua binding addon
# =============================================================================

cmake_minimum_required(VERSION 3.16)

set(ADDON_NAME tcxLua)
option(USE_LUAJIT "Enable building with LuaJIT" OFF)

if(USE_LUAJIT)
    message(FATAL_ERROR "USE_LUAJIT is not implemented now.")
endif()

file(GLOB ADDON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB ADDON_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

add_library(${ADDON_NAME} STATIC ${ADDON_SOURCES} ${ADDON_HEADERS})

target_include_directories(${ADDON_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${ADDON_NAME} PUBLIC TrussC)
