#pragma once

#include <iostream>
#include <vector>
#include "Character.h"

class Monom {
public:

	Monom(std::vector<Character*>&, int64_t = 1);

	template<typename ...Args>
	Monom(Args..., int64_t = 1);

	~Monom();

	template<typename T>
	void pushToElements(T first) noexcept;

	template<typename T, typename ...Args>
	void pushToElements(T first, Args... args) noexcept;

private:

	int64_t factor;

	std::vector<Character*> elements;
};

inline Monom::Monom(std::vector<Character*>& arr, int64_t factor) {
	this->elements = arr;
	this->factor = factor;
}

template<typename ...Args>
inline Monom::Monom(Args... elements, int64_t factor) {
	pushToElements(elements);
	this->factor = factor;
}

Monom::~Monom() {
}

template<typename T>
inline void Monom::pushToElements(T first) noexcept {
	this->elements.push_back(first);
}

template<typename T, typename ...Args>
inline void Monom::pushToElements(T first, Args... args) noexcept {
	this->elements.push_back(first);
	this->pushToElements(args...);
}