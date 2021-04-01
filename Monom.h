#pragma once

#include <iostream>
#include <vector>
#include "Character.h"

class Monom {
public:

	Monom(std::vector<CharacterMonom*>&, int64_t = 1);

	template<typename ...Args>
	Monom(int64_t = 1, Args&&...);

	~Monom();

	template<typename T>
	void pushToElements(T&& first) noexcept;

	template<typename T, typename ...Args>
	void pushToElements(T&& first, Args&&... args) noexcept;

	void sortMonom() noexcept;

private:

	bool isNormalized = 0;

	int64_t factor;

	std::vector<CharacterMonom*> elements;

	std::vector<int64_t> elementsAfterNormalize = std::vector<int64_t>(26, 0);

	void normaizeElements();
};

inline Monom::Monom(std::vector<CharacterMonom*>& arr, int64_t factor) {
	this->elements = arr;
	this->factor = factor;
	
	this->normaizeElements();
}

template<typename ...Args>
inline Monom::Monom(int64_t factor, Args&&... elements) {
	pushToElements(elements...);
	this->factor = factor;

	this->normaizeElements();
}

Monom::~Monom() {
}

inline void Monom::normaizeElements() {
	for (auto i : this->elements) {
		this->elementsAfterNormalize[static_cast<int64_t>(i->variable) - 'a'] = i->power;
	}
	this->isNormalized = 1;
}

template<typename T>
inline void Monom::pushToElements(T&& first) noexcept {
	this->elements.push_back(&first);
}

template<typename T, typename ...Args>
inline void Monom::pushToElements(T&& first, Args&&... args) noexcept {
	this->elements.push_back(&first);
	this->pushToElements(args...);
}