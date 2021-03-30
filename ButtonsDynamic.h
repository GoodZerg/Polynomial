#pragma once
#include "Header.h"
#include "Widget.h"
void CloseWindow(GLFWwindow* window);

void CloseWindow(GLFWwindow* window) {
  glfwSetWindowShouldClose(window, true);
  glfwDestroyWindow(window);
}
