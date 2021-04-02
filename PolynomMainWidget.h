#pragma once

#include "Polynom.h"

class PolynomMainWidget :
    public Widget
{
public:
  MyList<Polynom*> polynoms;
  PolynomMainWidget(vec2<unsigned int> size, std::string name_window, std::vector<WidgetComponent*>* components, GLFWwindow* main_window = nullptr);
};

