#pragma once
#include "Header.h"
#include "Widget.h"


void CloseWindow(GLFWwindow* window);
void Save(GLFWwindow* window);
void AddPolynom(GLFWwindow* window);
void Differencial(GLFWwindow* window);




void CloseWindow(GLFWwindow* window) {
  glfwSetWindowShouldClose(window, true);
  glfwDestroyWindow(window);
}

inline void Save(GLFWwindow* window) {

}

inline void AddPolynom(GLFWwindow* window) {
}

inline void Differencial(GLFWwindow* window) {
}
