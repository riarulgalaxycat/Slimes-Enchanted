cmake_minimum_required(VERSION 3.20)
project(Slimes_Enchanted)

set(CMAKE_CXX_STANDARD 17)

#find_package(OpenGL REQUIRED)

#include(FetchContent)
#FetchContent_Declare(
#        glfw
#        GIT_REPOSITORY https://github.com/glfw/glfw.git
#        GIT_TAG        3.5.1
#)

#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)

#FetchContent_MakeAvailable(glfw)

add_executable(Slimes_Enchanted
        run/main/net/Runner.cpp
        run/main/net/slimes_enchanted/game_renderer.h
        run/main/net/slimes_enchanted/resources/menu/settings/World/Optimations/Opti.h
        run/main/net/slimes_enchanted/resources/menu/settings/others.h
        run/main/net/slimes_enchanted/resources/menu/SinglePlayer/World_Creation/World_Settings/world_settings.h
        run/main/net/slimes_enchanted/game/functions/functions.h
        run/main/net/slimes_enchanted/game/functions/functions_list.h
        run/main/net/slimes_enchanted/resources/menu/settings/Controls/controls.h
        run/main/net/slimes_enchanted/resources/menu/settings/Controls/controls.h
        run/main/net/slimes_enchanted/resources/menu/settings/general.h
        run/main/net/slimes_enchanted/resources/time.h
        run/main/net/slimes_enchanted/se.h
)

#target_link_libraries(
#        Slimes_Enchanted PRIVATE
#        glfw
#        OpenGL::GL
#)
#target_include_directories(Slimes_Enchanted PUBLIC include)
