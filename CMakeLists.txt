set(CMAKE_EXPORT_COMPILE_COMMANDS on)
project(GryphnUtils)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "utils/*.c")
add_library(GryphnUtils STATIC ${SOURCE_FILES})
