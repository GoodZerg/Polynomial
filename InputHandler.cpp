#include"InputHandler.h"

#define MAKEMONOM \
num += num == 0;\
std::vector<CharacterMonom*> vec;\
for (size_t i = 0; i < arr.size(); i++) {\
  if (arr[i] != 0) {\
    vec.push_back(new CharacterMonom(i + 'a', arr[i]));\
  }\
}\
Monom* jj = new Monom(vec, (sign ? -1 : 1) * num);\
pol->pushToNominals(jj);\
sign = str->at(i) == '-' ? true : false;\
arr = std::vector<int64_t>(26, 0);\
num = 0;\





InputHandler::InputHandler(std::string* str) {
  this->str = str;
  this->pol = new Polynom();
}

InputHandler::~InputHandler() {
}

void InputHandler::check(std::string* str) {
  this->str = str;
  this->pol = new Polynom();
  try {
    startState(0);
  } catch (int a) {
    std::cout << "hihihiihih\n";
    is_valid = 0;
  }
}

bool InputHandler::isInt(int64_t i) {
  if (str->at(i) >= '0' && str->at(i) <= '9') {
    return true;
  }
  return false;
}

bool InputHandler::isSign(int64_t i) {
  if (str->at(i) == '+' || str->at(i) == '-') return true;
  return false;
}

bool InputHandler::isChar(int64_t i) {
  if (str->at(i) >= 'a' && str->at(i) <= 'z') return true;
  return false;
}

bool InputHandler::isPower(int64_t i) {
  if (str->at(i) == '^') return true;
  return false;
}

void InputHandler::startState(int64_t i) {
  if (isChar(i)) {
    ++arr[str->at(i) - 'a'];
    if (str->size() > i + 1) {
      secondState(i + 1);
    } else {
      MAKEMONOM;
    }

  } else if (isInt(i)) {
    num *= 10;
    num += str->at(i) - '0';
    if (str->size() > i + 1) {
      thirdState(i + 1);
    } else {
      MAKEMONOM;
    }
  } else if (isSign(i)) {
    sign = str->at(i) == '-' ? true : false;
    if (str->size()> i + 1)
      firstState(i + 1);
  } else {
    throw 2;
  }
}

void InputHandler::firstState(int64_t i) {
  if (isChar(i)) {
    ++arr[str->at(i) - 'a'];
    if (str->size() > i + 1) {
      secondState(i + 1);
    } else {
      MAKEMONOM;
    }
  } else if (isInt(i)) {
    num *= 10;
    num += str->at(i) - '0';
    if (str->size() > i + 1) {
     thirdState(i + 1);
    } else {
      MAKEMONOM;
    }
  } else {
    throw 2;
  }
}

void InputHandler::secondState(int64_t i) {
  if (isChar(i)) {
    ++arr[str->at(i) - 'a'];
    if (str->size() > i + 1) {
      secondState(i + 1);
    } else {
      MAKEMONOM;
    }
  } else if (isPower(i)) {
    --arr[str->at(i - 1) - 'a'];
    if (str->size() > i + 1) {
      fourthState(i + 1);
    } else {
      throw 2;
    }
  } else if (isSign(i)) { 
    MAKEMONOM;
    sign = str->at(i) == '-' ? true : false;
    if (str->size()> i + 1)
    firstState(i + 1);
  } else {
    throw 2;
  }
}

void InputHandler::thirdState(int64_t i) {
  if (isChar(i)) {
    ++arr[str->at(i) - 'a'];
    if (str->size() > i + 1) {
      secondState(i + 1);
    } else {
      MAKEMONOM;
    }
  } else if (isInt(i)) {
    num *= 10;
    num += str->at(i) - '0';
    if (str->size() > i + 1) {
      thirdState(i + 1);
    } else {
      MAKEMONOM;
    }
  } else if (isSign(i)) {
    MAKEMONOM;
    sign = str->at(i) == '-' ? true : false;
    if (str->size() > i + 1)
      firstState(i + 1);
  } else {
    throw 2;
  }
}

void InputHandler::fourthState(int64_t i) {
  if (isInt(i)) {
    std::string asd("");
    asd += str->at(i);////////////////////////////////////
    if (str->size() > i + 1) {
      fithState(i + 1, str->at(i - 2), asd);
    } else {
      arr[str->at(i - 2) - 'a'] += std::stoi(asd);
      MAKEMONOM;
    }
  } else {
    throw 2;
  }
}

void InputHandler::fithState(int64_t i, char& a, std::string& pow) {
  if (isInt(i)) {
    pow += str->at(i); //////////////////////////////////
    if (str->size() > i + 1) {
      fithState(i + 1, a, pow);
    } else {
      arr[a - 'a'] += std::stoi(pow);
      MAKEMONOM;
    }
  } else if (isChar(i)) {
    //arr[a - 'a']--;
    arr[a - 'a'] += std::stoi(pow);
    ++arr[str->at(i) - 'a'];
    if (str->size() > i + 1) {
      secondState(i + 1);
    } else {
      MAKEMONOM;
    }
  } else if (isSign(i)) {
    arr[a - 'a'] += std::stoi(pow);
    MAKEMONOM;
    sign = str->at(i) == '-' ? true : false;
    if (str->size() > i + 1)
      firstState(i + 1);
  } else {
    throw 2;
  }
}

void InputHandler::cring() {
  //std::cout << "hihihiihih\n";
  throw 2;
}
