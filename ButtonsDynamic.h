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
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  TextBox* tb = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(10));
  std::string ans;
  for (int64_t i = 0;i < tb->_text->size();++i) {
    ans += *tb->_text->at(i);
  }
  InputHandler ih(&ans);
  if (ans != "") {
    ih.check(&ans);
    if (ih.is_valid) {
      static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->polynoms.instToTail(ih.pol);
    }
  }
  if (tb->_text->size() != 0) {
    for (int64_t i = tb->_text->size() - 1; i > 0; --i)
      tb->_text->pop_back();
  }
  
  tb->_text->at(0)->clear();
  //static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->polynoms[0];
  //std::cout << "asd\n";
  
  for (size_t i = 0; i < wid->polynoms.get_size() && i < 10; i++) {
    std::vector<std::string*>* stttr = new std::vector<std::string*>(2, new std::string());
      std::string* ss = new std::string(std::to_string(i + 1));
      stttr->operator[](0) = ss;
      stttr->operator[](1) = wid->polynoms[i]->polynomReade;
     
      dynamic_cast<TextField*>(wid->getWidgetComponent()->at(i))->_text = stttr;
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
