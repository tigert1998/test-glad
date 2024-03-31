project(third-party)

# glfw
add_subdirectory("glfw")

# glad
set(glad_dir "glad")
add_library(glad STATIC "${glad_dir}/src/glad.c")
target_include_directories(glad PUBLIC "${glad_dir}/include")

# glm
set(glm_dir "glm")
add_library(glm INTERFACE)
target_include_directories(glm INTERFACE "${glm_dir}")

# fmt
add_subdirectory(fmt)

# nvgl
set(nvgl_dir "nvpro_core/nvgl")
file(GLOB_RECURSE nvgl_srcs "${nvgl_dir}/*.cpp")
add_library(nvgl STATIC "${nvgl_srcs}")
target_include_directories(nvgl PUBLIC "${nvgl_dir}/.." "${nvgl_dir}/../nvp")
target_link_libraries(nvgl fmt glfw)
target_compile_definitions(nvgl PUBLIC NOMINMAX)
find_package(OpenGL REQUIRED)
target_link_libraries(nvgl ${OPENGL_LIBRARIES})
