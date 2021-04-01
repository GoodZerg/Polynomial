#pragma once

#include "Monom.h"

class Polynom {
public:

	Polynom(std::vector<Monom*>&);

	template<typename ...Args>
	Polynom(Args&&...);

	~Polynom();

	template<typename T>
	void pushToNominals(T&& first) noexcept;

	template<typename T, typename ...Args>
	void pushToNominals(T&& first, Args&&... args) noexcept;

private:

	std::vector<Monom*> nominals;
};

inline Polynom::Polynom(std::vector<Monom*>& arr) {
	this->nominals = arr;
}

template<typename ...Args>
inline Polynom::Polynom(Args&&... args) {
	this->pushToNominals(args...);
}

Polynom::~Polynom()
{
}

template<typename T>
inline void Polynom::pushToNominals(T&& first) noexcept {
	this->nominals.push_back(&first);
}

template<typename T, typename ...Args>
inline void Polynom::pushToNominals(T&& first, Args&&... args) noexcept {
	this->nominals.push_back(&first);
	this->pushToNominals(args...);
}
