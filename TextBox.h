#pragma once
#include "TextField.h"
#include "ClikedInterface.h"

class TextBox :
  public TextField, ClikedInterface
{
public:
  TextBox(vec2<float> pos, vec2<float> size, std::vector<std::string*>* str, vec3<float> textColor = { 1.f, 1.f, 1.f },
    vec3<float> color = { 0.21f, 0.21f, 0.21f }, WidgetComponent* Decorator = nullptr);
  void OnClicked(GLFWwindow*) override;
  void render(GLFWwindow* window);
};