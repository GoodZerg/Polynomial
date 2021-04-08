#include "PolynomMainWidget.h"
#include "ButtonsDynamic.h"

PolynomMainWidget::PolynomMainWidget(vec2<unsigned int> size, std::string name_window, std::vector<WidgetComponent*>* components, GLFWwindow* main_window)
  :Widget(size, name_window, components, main_window)
{
  vec2<float> textfield_size = { 0.75f, 0.15f };
  vec2<float> buttom_size = { 0.15f, 0.15f };
  vec2<float> subbuttom_size = { 0.1f, 0.1f };
  vec3<float> button_color = { 0.878f, 0.250f, 0.984f };

  // data base
  components->push_back(new TextField({ -1, -0.50 }, textfield_size, new std::vector <std::string*>{ new std::string(" 10") }));         // 0
  components->push_back(new TextField({ -1, -0.35 }, textfield_size, new std::vector <std::string*>{ new std::string(" 9") }));          // 1
  components->push_back(new TextField({ -1, -0.20 }, textfield_size, new std::vector <std::string*>{ new std::string(" 8") }));          // 2
  components->push_back(new TextField({ -1, -0.05 }, textfield_size, new std::vector <std::string*>{ new std::string(" 7") }));          // 3
  components->push_back(new TextField({ -1,  0.10 }, textfield_size, new std::vector <std::string*>{ new std::string(" 6") }));          // 4
  components->push_back(new TextField({ -1,  0.25 }, textfield_size, new std::vector <std::string*>{ new std::string(" 5") }));          // 5
  components->push_back(new TextField({ -1,  0.40 }, textfield_size, new std::vector <std::string*>{ new std::string(" 4") }));          // 6
  components->push_back(new TextField({ -1,  0.55 }, textfield_size, new std::vector <std::string*>{ new std::string(" 3") }));          // 7  
  components->push_back(new TextField({ -1,  0.70 }, textfield_size, new std::vector <std::string*>{ new std::string(" 2") }));          // 8
  components->push_back(new TextField({ -1,  0.85 }, textfield_size, new std::vector <std::string*>{ new std::string(" 1") }));          // 9

  // input polynom
  components->push_back(new TextBox({ -1.00,  -1.00 }, textfield_size, new std::vector <std::string*>{ new std::string(" polynom") }));  // 10
  components->push_back(new Button({ -0.10,  -0.95 }, subbuttom_size, AddPolynom, button_color,                                         // 11
    new TextField({ -0.10,  -0.95 }, subbuttom_size, new std::vector <std::string*>{ new std::string("  add") })
  ));

  // take diffirencial
  components->push_back(new TextBox({ -0.10,  0.85 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));      // 12
  components->push_back(new TextField({ 0.1,  0.85 }, subbuttom_size, new std::vector <std::string*>{ new std::string("    d") }));    // 13
  components->push_back(new TextBox({ 0.3,  0.85 }, subbuttom_size, new std::vector <std::string*>{ new std::string("") }));           // 14
  components->push_back(new Button({ 0.5,  0.85 }, subbuttom_size, Differencial, button_color,                                         // 15
    new TextField({ 0.5,  0.85 }, subbuttom_size, new std::vector <std::string*>{ new std::string("   ok") })
  ));

  // answers
  components->push_back(new TextField({ -1, -0.75 }, textfield_size, new std::vector <std::string*>{ new std::string(" answer") }));    // 16
  components->push_back(new Button({ -0.10,  -0.70 }, subbuttom_size, Save, button_color,                                              // 17
    new TextField({ -0.10,  -0.70 }, subbuttom_size, new std::vector <std::string*>{ new std::string(" save") })));

  // point namber
  components->push_back(new TextBox({ -0.10,  0.65 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));      // 18
  components->push_back(new TextField({ 0.1,  0.65 }, subbuttom_size, new std::vector <std::string*>{ new std::string("    x=") }));   // 19
  components->push_back(new TextBox({ 0.3,  0.65 }, subbuttom_size, new std::vector <std::string*>{ new std::string("point") }));      // 20
  components->push_back(new Button({ 0.5,  0.65 }, subbuttom_size, PointNumber, button_color,                                          // 21
    new TextField({ 0.5,  0.65 }, subbuttom_size, new std::vector <std::string*>{ new std::string("   ok") })
  ));

  // sum
  components->push_back(new TextBox({ -0.10,  0.45 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));      // 22
  components->push_back(new TextField({ 0.1,  0.45 }, subbuttom_size, new std::vector <std::string*>{ new std::string("     +") }));   // 23
  components->push_back(new TextBox({ 0.3,  0.45 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));        // 24
  components->push_back(new Button({ 0.5,  0.45 }, subbuttom_size, Sum, button_color,                                                  // 25
    new TextField({ 0.5,  0.45 }, subbuttom_size, new std::vector <std::string*>{ new std::string("   ok") })
  ));

  // multiply
  components->push_back(new TextBox({ -0.10,  0.25 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));      // 26
  components->push_back(new TextField({ 0.1,  0.25 }, subbuttom_size, new std::vector <std::string*>{ new std::string("     *") }));   // 27
  components->push_back(new TextBox({ 0.3,  0.25 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));        // 28
  components->push_back(new Button({ 0.5,  0.25 }, subbuttom_size, Multiply, button_color,                                             // 29
    new TextField({ 0.5,  0.25 }, subbuttom_size, new std::vector <std::string*>{ new std::string("   ok") })
  ));

  // Division
  components->push_back(new TextBox({ -0.10,  0.05 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));      // 30
  components->push_back(new TextField({ 0.1,  0.05 }, subbuttom_size, new std::vector <std::string*>{ new std::string("     /") }));   // 31
  components->push_back(new TextBox({ 0.3,  0.05 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));        // 32
  components->push_back(new Button({ 0.5,  0.05 }, subbuttom_size, Div, button_color,                                                  // 33
    new TextField({ 0.5,  0.05 }, subbuttom_size, new std::vector <std::string*>{ new std::string("   ok") })
  ));
  components->push_back(new TextField({ -0.10, -0.15 }, textfield_size, new std::vector <std::string*>{ new std::string("mod") }));    // 34

   // Solutions
  components->push_back(new TextBox({ -0.10,  -0.35 }, subbuttom_size, new std::vector <std::string*>{ new std::string("num") }));      // 35
  components->push_back(new TextField({ 0.1,  -0.35 }, subbuttom_size, new std::vector <std::string*>{ new std::string("     x") }));   // 36
  components->push_back(new TextBox({ 0.3, -0.35 }, subbuttom_size, new std::vector <std::string*>{ new std::string("var") }));         // 37
  components->push_back(new Button({ 0.5,  -0.35 }, subbuttom_size, Solve, button_color,                                                  // 38
    new TextField({ 0.5,  -0.35 }, subbuttom_size, new std::vector <std::string*>{ new std::string("   ok") })
  ));
}
