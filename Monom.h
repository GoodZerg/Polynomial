#pragma once

#include "Character.h"

class Monom {
public:

	Monom(int64_t = 1);

	Monom(std::vector<CharacterMonom*>&, int64_t = 1);

	template<typename ...Args>
	Monom(int64_t = 1, Args&&...);

	~Monom();

	int64_t getPowerElementByIndex(int64_t) const noexcept;

	int64_t getFactor() noexcept;

	void setFactor(int64_t) noexcept;

	void setPowerElementByCh(CharacterMonom&&) noexcept;

	int64_t getSeniorCoefficient() noexcept;

	template<typename T>
	void pushToElements(T&& first) noexcept;

	template<typename T, typename ...Args>
	void pushToElements(T&& first, Args&&... args) noexcept;

	void sortMonom() noexcept;



	friend Monom operator*(const Monom&, const Monom&);


	std::vector<int64_t> sortedElementIndex = std::vector<int64_t>(26, -1);

private:

	bool isNormalized = 0;

	int64_t factor;

	std::vector<CharacterMonom*> elements;

	std::vector<int64_t> elementsAfterNormalize = std::vector<int64_t>(26, 0);


	void normaizeElements() noexcept;
};


template<typename ...Args>
inline Monom::Monom(int64_t factor, Args&&... elements) {
	pushToElements(elements...);
	this->factor = factor;

	this->normaizeElements();
	this->sortMonom();
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