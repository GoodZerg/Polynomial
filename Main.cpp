#include "PolynomMainWidget.h"
#include "InputHandler.h"

int main() {
  std::string bb("x^2");
  InputHandler a(&bb);
  /*
  Monom a(1, CharacterMonom('a', 2), CharacterMonom('b', 1), CharacterMonom('t', 25));
  Monom b(1, CharacterMonom('b', 2), CharacterMonom('c', 1), CharacterMonom('d', 22));
  Monom c(1, CharacterMonom('c', 1));

  Polynom abc( &b, &c, &a);
  /*
  PolynomMainWidget Window({ 1200, 800 }, "Polynomian", new  std::vector<WidgetComponent*>);
  Window.render();
  glfwTerminate();
  */
  return 0;
}
