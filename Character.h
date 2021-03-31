#pragma once
#include <iostream>


struct Character {
  char variable;
  int64_t power;
  Character(char = ' ', int64_t = 0);
};

Character::Character(char var, int64_t pow) {
  this->variable = var;
  this->power = pow;
}
