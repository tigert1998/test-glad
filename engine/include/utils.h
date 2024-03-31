#ifndef UTILS_H_
#define UTILS_H_

#include <chrono>
#include <filesystem>
#include <glm/glm.hpp>
#include <iomanip>
#include <ostream>
#include <source_location>
#include <string>

template <size_t W, size_t H, typename T, glm::qualifier Q>
std::ostream &operator<<(std::ostream &os, const glm::mat<W, H, T, Q> &mat) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      os << std::setprecision(12) << mat[j][i] << ", ";
    }
    os << "\n";
  }
  return os;
}

template <size_t N, typename T, glm::qualifier Q>
std::ostream &operator<<(std::ostream &os, const glm::vec<N, T, Q> &vec) {
  os << "(";
  for (int i = 0; i < N; i++) {
    os << std::setprecision(12) << vec[i];
    if (i < N - 1) {
      os << ", ";
    }
  }
  os << ")";
  return os;
}

std::string SnakeToPascal(const std::string &name);

#define CHECK_OPENGL_ERROR()                                           \
  do {                                                                 \
    auto err = glGetError();                                           \
    if (err != GL_NO_ERROR) {                                          \
      std::string err_str;                                             \
      switch (err) {                                                   \
        case GL_INVALID_ENUM:                                          \
          err_str = "GL_INVALID_ENUM";                                 \
          break;                                                       \
        case GL_INVALID_VALUE:                                         \
          err_str = "GL_INVALID_VALUE";                                \
          break;                                                       \
        case GL_INVALID_OPERATION:                                     \
          err_str = "GL_INVALID_OPERATION";                            \
          break;                                                       \
        case GL_OUT_OF_MEMORY:                                         \
          err_str = "GL_OUT_OF_MEMORY";                                \
          break;                                                       \
        case GL_INVALID_FRAMEBUFFER_OPERATION:                         \
          err_str = "GL_INVALID_FRAMEBUFFER_OPERATION";                \
          break;                                                       \
        default:                                                       \
          err_str = std::to_string(err);                               \
      }                                                                \
      auto location = std::source_location::current();                 \
      fmt::print(stderr, "[{}({}), error] {}\n", location.file_name(), \
                 location.line(), err_str);                            \
      exit(1);                                                         \
    }                                                                  \
  } while (0)

std::string ReadFile(const std::filesystem::path &file_path, bool binary);

std::string ToLower(const std::string &str);

std::string StringToHex(const std::string &input);

#endif