project(JwPack)

include_directories(".")
file(GLOB_RECURSE srcfiles "*.cpp" "*.h")

if (MINGW)
    include_directories("./ext/mingw_std_threads")
    add_definitions(-D__MINGW__)
endif ()

add_library(JwPack SHARED ${srcfiles})



