#include "Button.h"
#include "TextField.h"

Button::Button(vec2<float> pos, vec2<float> size, std::function<void(GLFWwindow*)> func, vec3<float> color,WidgetComponent* Decorator)
  : WidgetComponent(pos, size, color, Decorator)
{
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
  glUniform4f(vertexColorLocation, color.x, color.y, color.z, 1.0f);
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
