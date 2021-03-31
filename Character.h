#pragma once
#include <iostream>


struct Character {

  char variable;

  int64_t power;

  Character(char = ' ', int64_t = 0);

  friend bool operator> (const Character&, const Character&);
};

Character::Character(char var, int64_t pow) {
  this->variable = var;
  this->power = pow;
}

bool operator>(const Character& first, const Character& second) {
  if (first.power == second.power) {
    return first.variable < second.variable;
  } else {
    return first.power > second.power;
  }
}