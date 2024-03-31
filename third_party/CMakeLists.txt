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