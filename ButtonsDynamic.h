#pragma once
#include "Header.h"
#include "Widget.h"


void CloseWindow(GLFWwindow* window);
void Save(GLFWwindow* window);
void AddPolynom(GLFWwindow* window);
void Differencial(GLFWwindow* window);
void PointNumber(GLFWwindow* window);
void Sum(GLFWwindow* window);
void Multiply(GLFWwindow* window);
void Div(GLFWwindow* window);
void Solve(GLFWwindow* window);




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

inline void PointNumber(GLFWwindow* window)
{
}

inline void Sum(GLFWwindow* window)
{
}

inline void Multiply(GLFWwindow* window)
{
}

inline void Div(GLFWwindow* window)
{
}

inline void Solve(GLFWwindow* window)
{
}
