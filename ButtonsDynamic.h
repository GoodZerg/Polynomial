#pragma once
#include "Header.h"
#include "Widget.h"
#include "InputHandler.h"

void CloseWindow(GLFWwindow* window);
void Save(GLFWwindow* window);
void AddPolynom(GLFWwindow* window);
void Differencial(GLFWwindow* window);
void PointNumber(GLFWwindow* window);
void Sum(GLFWwindow* window);
void Multiply(GLFWwindow* window);
void Div(GLFWwindow* window);
void Solve(GLFWwindow* window);


Polynom* answer = nullptr;



void CloseWindow(GLFWwindow* window) {
  glfwSetWindowShouldClose(window, true);
  glfwDestroyWindow(window);
}

inline void Save(GLFWwindow* window) {
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  if (answer != nullptr) {
    Polynom* ans = answer;
    answer = nullptr;
    dynamic_cast<TextField*>((wid->getWidgetComponent())->at(16))->_text->at(0) = new std::string("answer");
    static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->polynoms.instToTail(ans);
    for (size_t i = 9; (9 - i) < wid->polynoms.get_size() && i >= 0; i--) {
      std::vector<std::string*>* stttr = new std::vector<std::string*>(2, new std::string());
      std::string* ss = new std::string(" " + std::to_string(10 - i));
      stttr->operator[](0) = ss;
      stttr->operator[](1) = wid->polynoms[9 - i]->polynomReade;

      dynamic_cast<TextField*>(wid->getWidgetComponent()->at(i))->_text = stttr;
    }
  }
}

inline void AddPolynom(GLFWwindow* window) {
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  TextBox* tb = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(10));
  std::string ans;
  for (int64_t i = 0;i < tb->_text->size();++i) {
    ans += *tb->_text->at(i);
  }
  InputHandler ih(&ans);
  if (ans != "") {
    ih.check(&ans);
    if (ih.is_valid) {
      ih.pol->normalize();
      ih.pol->makeString();
      static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->polynoms.instToTail(ih.pol);
    }
  }
  if (tb->_text->size() != 0) {
    for (int64_t i = tb->_text->size() - 1; i > 0; --i)
      tb->_text->pop_back();
  }
  
  tb->_text->at(0)->clear();
  //static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->polynoms[0];
  //std::cout << "asd\n";
  
  for (size_t i = 9; (9  - i)< wid->polynoms.get_size() && i >= 0; i--) {
    std::vector<std::string*>* stttr = new std::vector<std::string*>(2, new std::string());
      std::string* ss = new std::string(" " + std::to_string(10 - i));
      stttr->operator[](0) = ss;
      stttr->operator[](1) = wid->polynoms[9-i]->polynomReade;
     
      dynamic_cast<TextField*>(wid->getWidgetComponent()->at(i))->_text = stttr;
  }
  

}

inline void Differencial(GLFWwindow* window) {
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  TextBox* tb_1 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(12));
  TextBox* tb_2 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(14));
  std::string pol_num, var;
  for (int64_t i = 0; i < tb_1->_text->size(); ++i) {
    pol_num += *tb_1->_text->at(i);
  }
  for (int64_t i = 0; i < tb_2->_text->size(); ++i) {
    var += *tb_2->_text->at(i);
  }
  int64_t pol_num_int = std::stoi(pol_num);
  pol_num_int--;
  char var_ch;
  if (var.size() == 1) {
    var_ch = var[0];
  } else {
    return;
  }
  Polynom* ans = new Polynom();
  if (pol_num_int >= 0 && var_ch >= 'a' && var_ch <= 'z' && wid->polynoms.get_size() > pol_num_int) {
    Polynom* num = wid->polynoms[pol_num_int];
    MyList<Monom*> nom = *(num->getNominals());
    for (size_t i = 0; i < nom.get_size(); i++) {
      int64_t tmp_factor = nom[i]->getFactor();
      std::vector<CharacterMonom*> ch_vec = nom[i]->getElements();
      std::vector<CharacterMonom*> ch_vec_ans;
      bool f = 0;
      for (size_t j = 0; j < ch_vec.size(); j++) {
        CharacterMonom* ch = new CharacterMonom(*ch_vec[j]);
        ch_vec_ans.push_back(ch);
        if (ch->variable == var_ch && ch->power != 0) {
          tmp_factor *= ch->power;
          ch->power--;
          f = 1;
        }
      }
      if (f) {
        ans->pushToNominals(new Monom(ch_vec_ans, tmp_factor));
      }
    }
  }
  if (ans->getNominals()->get_size() != 0) {
    ans->normalize();
    ans->makeString();
    answer = ans;
    dynamic_cast<TextField*>((wid->getWidgetComponent())->at(16))->_text->at(0) = ans->polynomReade;
  }
}

inline void PointNumber(GLFWwindow* window) {
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  TextBox* tb_1 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(18));
  TextBox* tb_2 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(20));
  std::string pol_num, var;
  for (int64_t i = 0; i < tb_1->_text->size(); ++i) {
    pol_num += *tb_1->_text->at(i);
  }
  for (int64_t i = 0; i < tb_2->_text->size(); ++i) {
    var += *tb_2->_text->at(i);
  }
  int64_t pol_num_int = std::stoi(pol_num);
  pol_num_int--;
  int64_t point = std::stoi(var);
  Polynom* num = wid->polynoms[pol_num_int];
  MyList<Monom*>* nom = num->getNominals();
  int64_t ans_ = 0;
  for (size_t i = 0; i < num->getNominals()->get_size(); i++) {
    ans_ += nom->operator[](i)->getFactor() * std::pow(point, nom->operator[](i)->getPowerElementByIndex('x' - 'a'));
  }
  std::string* ans__ = new std::string(std::to_string(ans_));
  answer = nullptr;
  dynamic_cast<TextField*>((wid->getWidgetComponent())->at(16))->_text->at(0) = ans__;
}

inline void Sum(GLFWwindow* window) {
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  TextBox* tb_1 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(22));
  TextBox* tb_2 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(24));
  std::string first_pol_num, second_pol_num;
  for (int64_t i = 0; i < tb_1->_text->size(); ++i) {
    first_pol_num += *tb_1->_text->at(i);
  }
  for (int64_t i = 0; i < tb_2->_text->size(); ++i) {
    second_pol_num += *tb_2->_text->at(i);
  }

  int64_t first_pol_num_int = std::stoi(first_pol_num);
  first_pol_num_int--;

  int64_t second_pol_num_int = std::stoi(second_pol_num);
  second_pol_num_int--;

  Polynom* first = wid->polynoms[first_pol_num_int];
  Polynom* second = wid->polynoms[second_pol_num_int];


  Polynom* answ = new Polynom();
  *answ = *first + *second;
  if (answ->getNominals()->get_size() != 0) {
    answ->makeString();
    answer = answ;
    dynamic_cast<TextField*>((wid->getWidgetComponent())->at(16))->_text->at(0) = answ->polynomReade;
  }
}

inline void Multiply(GLFWwindow* window) {
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  TextBox* tb_1 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(26));
  TextBox* tb_2 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(28));
  std::string first_pol_num, second_pol_num;
  for (int64_t i = 0; i < tb_1->_text->size(); ++i) {
    first_pol_num += *tb_1->_text->at(i);
  }
  for (int64_t i = 0; i < tb_2->_text->size(); ++i) {
    second_pol_num += *tb_2->_text->at(i);
  }

  int64_t first_pol_num_int = std::stoi(first_pol_num);
  first_pol_num_int--;

  int64_t second_pol_num_int = std::stoi(second_pol_num);
  second_pol_num_int--;

  Polynom* first = wid->polynoms[first_pol_num_int];
  Polynom* second = wid->polynoms[second_pol_num_int];

  Polynom* answ = new Polynom();

  for (size_t i = 0; i < first->getNominals()->get_size(); i++) {
    for (size_t j = 0; j < second->getNominals()->get_size(); j++) {
      std::vector<CharacterMonom*> ch_vec;

      for (size_t ii = 0; ii < first->getNominals()->operator[](i)->getElements().size(); ii++) {
        ch_vec.push_back(new CharacterMonom(*first->getNominals()->operator[](i)->getElements()[ii]));
      }

      for (size_t ii = 0; ii < second->getNominals()->operator[](j)->getElements().size(); ii++) {
        ch_vec.push_back(new CharacterMonom(*second->getNominals()->operator[](j)->getElements()[ii]));
      }

      answ->pushToNominals(new Monom(
        ch_vec,

        first->getNominals()->operator[](i)->getFactor() *
        second->getNominals()->operator[](j)->getFactor()
      ));

    }
  }

  answ->sort();
  answ->normalize();
  answ->makeString();

  for (size_t i = 0; i < answ->getNominals()->get_size(); i++) {
    for (size_t j = i + 1; j < answ->getNominals()->get_size(); j++) {

      bool f = 1;
      for (size_t ii = 0; ii < 26; ++ii) {
        if (answ->getNominals()->operator[](i)->getPowerElementByIndex(ii) !=
          answ->getNominals()->operator[](j)->getPowerElementByIndex(ii)) {
          f = 0;
          break;
        }
      }
      if (f) {
        answ->getNominals()->operator[](i)->setFactor(answ->getNominals()->operator[](i)->getFactor() + answ->getNominals()->operator[](j)->getFactor());
        answ->getNominals()->destroyItemByIndex(j);
        if (answ->getNominals()->operator[](i)->getFactor() == 0) {
          answ->getNominals()->destroyItemByIndex(i);
          i--;
          break;
        }
        j--;
      }

    } 
  }

  answ->sort();
  answ->normalize();
  answ->makeString();


  if (answ->getNominals()->get_size() != 0) {
    answ->makeString();
    answer = answ;
    dynamic_cast<TextField*>((wid->getWidgetComponent())->at(16))->_text->at(0) = answ->polynomReade;
  }
}

inline void Div(GLFWwindow* window)
{
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  ////ahhahhahhahahahahahhahahaaaaaaaaaaaaaaaaaaaaaaaaaahahahahahhahahahhhahaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

}

inline void Solve(GLFWwindow* window) {
  PolynomMainWidget* wid = static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window));
  TextBox* tb_1 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(35));
  TextBox* tb_2 = dynamic_cast<TextBox*>((static_cast<PolynomMainWidget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())->at(37));
  std::string pol_num, var;
  for (int64_t i = 0; i < tb_1->_text->size(); ++i) {
    pol_num += *tb_1->_text->at(i);
  }
  for (int64_t i = 0; i < tb_2->_text->size(); ++i) {
    var += *tb_2->_text->at(i);
  }
  int64_t pol_num_int = std::stoi(pol_num);
  pol_num_int--;

  char var_ch;
  if (var.size() == 1) {
    var_ch = var[0];
  }
  else {
    return;
  }

  int64_t x = wid->polynoms[pol_num_int]->getNominals()->operator[](wid->polynoms[pol_num_int]->getNominals()->get_size() - 1)->getFactor();

  std::string* answerr = new std::string(" ");


  std::vector<int64_t> factors;

  factors.push_back(0);
  factors.push_back(1);
  factors.push_back(-1);

  for (int64_t i = 2; i <= std::sqrt(x); i++) {
    while (x % i == 0) {
      factors.push_back(i);
      factors.push_back(-1*i);
      x /= i;
    }
  }

  if (x != 1) {
    factors.push_back(x);
  }

  Polynom* num = wid->polynoms[pol_num_int];
  MyList<Monom*>* nom = num->getNominals();
 
  for (size_t j = 0; j < factors.size(); j++) {
    int64_t ans_ = 0;
    for (size_t i = 0; i < num->getNominals()->get_size(); i++) {
      ans_ += nom->operator[](i)->getFactor() * std::pow(factors[j], nom->operator[](i)->getPowerElementByIndex(var_ch - 'a'));
    }
    if (ans_ == 0) {
      *answerr += " ";
      *answerr += std::to_string(factors[j]);
    }
  }

  answer = nullptr;
  dynamic_cast<TextField*>((wid->getWidgetComponent())->at(16))->_text->at(0) = answerr;
}
