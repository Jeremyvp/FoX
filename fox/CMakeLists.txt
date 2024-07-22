file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")

find_package(raylib REQUIRED)

add_compile_options("-Wall" "-Werror" "-std=c++20")

add_executable(fox ${SOURCES} ${HEADERS})

target_compile_features(fox PRIVATE cxx_std_20)
target_include_directories(fox PRIVATE ".")
target_include_directories(fox PRIVATE ${RAYGUI_INCLUDE_DIRS})
target_link_libraries(fox PRIVATE raylib)
