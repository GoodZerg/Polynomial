#include "Button.h"
#include "TextField.h"

Button::Button(vec2<float> pos, vec2<float> size, std::function<void(GLFWwindow*)> func, vec3<float> color,WidgetComponent* Decorator)
  : WidgetComponent(pos, size, color, Decorator)
{
  this->color = { 0.37f, 0.21f, 0.69f };
  this->addOnClikedDynamic(func);
}

void Button::OnClicked(GLFWwindow* w)
{
  std::cout << "ButtonCliked\n";
  _ClikedDynamic(w);
}

void Button::addOnClikedDynamic(std::function<void(GLFWwindow*)> function)
{
  this->_ClikedDynamic = function;
}

void Button::render(GLFWwindow* window)
{
  int vertexColorLocation = glGetUniformLocation(__shaderProgram, "Color");
  glUseProgram(__shaderProgram);
  glUniform4f(vertexColorLocation, this->color.x, this->color.y, this->color.z, 1.0f);
  glBindVertexArray(_VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  if (_Decorator != nullptr) {
    if (dynamic_cast<TextField*>(_Decorator) != nullptr) {
      dynamic_cast<TextField*>(_Decorator)->dec(window);
    } else {
      _Decorator->render(window);
    }
   
  }
}
