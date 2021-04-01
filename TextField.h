#pragma once

#include "WidgetComponent.h"
#include <ft2build.h>
#include FT_FREETYPE_H  

struct Character;

class TextField : 
   public WidgetComponent
{
public:
  TextField(vec2<float> pos, vec2<float> size, std::vector<std::string*>* str, vec3<float> textColor = { 0.129f, 0.129f, 0.129f },
    vec3<float> color = { 0.403f, 0.227f, 0.717f }, WidgetComponent* Decorator = nullptr);
  void render(GLFWwindow* window);
  std::vector<std::string*> *_text;
  void rec();
  void dec(GLFWwindow* window);
  int shaderProgramText;
private:
  int64_t stringLenght = 30;
  vec3<float> textColor;
  std::map<char, Character> _Characters;
  unsigned int VAO_, VBO_;
  void _renderText(float scale, vec3<float> color, GLFWwindow* window);
  void __renderText(std::string text, float x, float y, float scale, vec3<float> color, GLFWwindow* window);
};


struct Character {
  unsigned int TextureID; // ID текстуры глифа
  vec2<int> Size; // размер глифа
  vec2<int> Bearing; // смещение от линии шрифта до верхнего/левого угла глифа
  unsigned int Advance; // смещение до следующего глифа
};
