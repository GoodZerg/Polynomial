#pragma once
#include "RenderInterface.h"
class WidgetComponent :
  public RenderInterface
{
public:
  WidgetComponent(vec2<float> pos, vec2<float> size, vec3<float> color = { 0.1f, 0.1f, 0.1f, } , WidgetComponent* Decorator = nullptr);
  void render(GLFWwindow* window) override;
  vec2<float> _pos;
  vec2<float> _size;
  WidgetComponent* _Decorator = nullptr;
  unsigned int _VAO;
  int __shaderProgram;
  vec3<float> color;
private:
  void _error(std::string error, char infoLog[512] = 0);
  void _compileShaderProgram();
  void _makeBuffers();

  static const char* __vertexShaderSource;
  static const char* __fragmentShaderSource;
  
};

