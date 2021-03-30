#pragma once
#include "WidgetComponent.h"
#include "ClikedInterface.h"
class Button :
  public WidgetComponent, ClikedInterface
{
public:
  Button(vec2<float> pos, vec2<float> size, std::function<void(GLFWwindow*)> func, vec3<float> color = { 0.878f, 0.250f, 0.984f }, WidgetComponent * Decorator = nullptr);
  void OnClicked(GLFWwindow*) override;
  void addOnClikedDynamic(std::function<void(GLFWwindow*)>);
  void render(GLFWwindow* window);
private:
  std::function<void(GLFWwindow*)> _ClikedDynamic = nullptr;
};

