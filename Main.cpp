#include "PolynomMainWidget.h"
#include "InputHandler.h"

int main() {
  PolynomMainWidget Window({ 1200, 800 }, "Polynomian", new  std::vector<WidgetComponent*>);
  Window.render();
  glfwTerminate();
  return 0;
}
