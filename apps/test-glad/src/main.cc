// clang-format off
#include <glad/glad.h>
// clang-format on

#include <GLFW/glfw3.h>
#include <fmt/core.h>

#include <iostream>
#include <memory>

#include "shader.h"

GLFWwindow *window = nullptr;

void Init(uint32_t width, uint32_t height) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(width, height, "Test GLAD", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  Shader::include_directories = {"./shaders"};

  std::unique_ptr<Shader> shader;
  shader.reset(new Shader(
      {
          {GL_VERTEX_SHADER, "test.vert"},
          {GL_GEOMETRY_SHADER, "test.geom"},
          {GL_FRAGMENT_SHADER, "test.frag"},
      },
      {}));
}

int main(int argc, char *argv[]) {
  try {
    Init(1920, 1080);
  } catch (const std::exception &e) {
    fmt::print(stderr, "[error] {}\n", e.what());
    exit(1);
  }

  return 0;
}