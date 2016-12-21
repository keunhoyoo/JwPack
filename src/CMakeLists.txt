project(JwPack)

include_directories(".")
file(GLOB_RECURSE srcfiles "*.cpp" "*.h")

add_library(JwPack SHARED ${srcfiles})



