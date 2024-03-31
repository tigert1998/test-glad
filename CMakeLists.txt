project(tiger-game-engine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory("third_party")

file(GLOB_RECURSE engine_srcs "engine/src/*.cc")
add_library(engine "${engine_srcs}")
target_link_libraries(engine glfw glad glm fmt nvgl)
target_include_directories(engine PUBLIC "engine/include")
target_compile_options(engine PUBLIC "$<$<C_COMPILER_ID:MSVC>:/utf-8>")
target_compile_options(engine PUBLIC "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
if(USE_GLAD)
    target_compile_definitions(engine PUBLIC USE_GLAD)
endif()
if(USE_NVGL)
    target_compile_definitions(engine PUBLIC USE_NVGL)
endif()

add_executable(test-glad "apps/test-glad/src/main.cc")
target_link_libraries(test-glad engine)
