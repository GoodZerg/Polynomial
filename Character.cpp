#include "Character.h" 

CharacterMonom::CharacterMonom(char var, int64_t pow) {
  this->variable = var;
  this->power = pow;
}

bool operator>(const CharacterMonom& first, const CharacterMonom& second) {
  if (first.power == second.power) {
    return first.variable < second.variable;
  }
  else {
    return first.power > second.power;
  }
}