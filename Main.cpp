#include "PolynomMainWidget.h"


int main() {

  Monom a(1, CharacterMonom('a', 2), CharacterMonom('b', 1), CharacterMonom('t', 22));
  Monom b(1, CharacterMonom('b', 2), CharacterMonom('c', 1), CharacterMonom('d', 22));
  Monom c(1, CharacterMonom('c', 1));

  Polynom abc( b, c);


  // std::string tmp = "Polynomian";
  //std::vector<WidgetComponent*> components;
  //vec2<unsigned int> window_size = { 1200, 800 };
  PolynomMainWidget Window({ 1200, 800 }, "Polynomian", new  std::vector<WidgetComponent*>);

  /*
  vec2<float> textfield_size = { 0.75f, 1.5f };
  components.push_back(new TextField({ -1, -0.5 }, textfield_size, new std::vector <std::string*>{}));
  */
  Window.render();
  glfwTerminate();
  /*
  std::string tmp = "Polynomian";
  
  vec2<float> vec1 = { -1, -1 };
  
  
  vec2<float> vec4 = { 0.5, 0.8 };
  vec2<float> vec5 = { 0.5, 0.2 };
  vec2<float> vec13 = { 0.5, -0.8 };
  vec2<float> vec14 = { 0.5, -1 };
  std::string str = "text";
  std::string strr = "text dvazdi";
 
  Widget test(size, "123", &a);
  std::string str1 = "HIHIHIHIHIIHIHIHIHIH";

  a.push_back(new TextField(vec1, textfield_size, new std::vector <std::string*>{ &str, &strr }));
  a.push_back(new Button(vec4, vec5, FuncOne, new TextField(vec4, vec5, new std::vector <std::string*>{ &str1 })));



  test.render();
  glfwTerminate();
   

  MyList<int> list;
  int* asd = new int(123);
  int* asda = new int(321);
  list.get_size();
  list.instToTail(asd);
  list.instToTail(asda);
  */
  return 0;
}
