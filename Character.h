#pragma once

#include "Header.h"
#include "Widget.h"



struct CharacterMonom {

  char variable;

  int64_t power;

  CharacterMonom(char = ' ', int64_t = 0);

  friend bool operator> (const CharacterMonom&, const CharacterMonom&);
};
