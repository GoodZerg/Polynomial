#pragma once
#include "Header.h"
#include "Widget.h"
#include "InputHandler.h"


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
  TextBox* tb = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(10));
  std::string ans;
  for (int64_t i = 0;i < tb->_text->size();++i) {
    ans += *tb->_text->at(i);
  }
  InputHandler ih(&ans);
  if (ih.is_valid) {
    static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->polynoms.instToTail(ih.pol);
  }
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
