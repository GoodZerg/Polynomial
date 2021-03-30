#pragma once
#include "TextField.h"
#include "ClikedInterface.h"

class TextBox :
  public TextField, ClikedInterface
{
public:
  TextBox(vec2<float> pos, vec2<float> size, std::vector<std::string*>* str, vec3<float> textColor = { 0.129f, 0.129f, 0.129f },
    vec3<float> color = { 0.317f, 0.176f, 0.658f }, WidgetComponent* Decorator = nullptr);
  void OnClicked(GLFWwindow*) override;
  void render(GLFWwindow* window);
};