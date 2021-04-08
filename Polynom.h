#pragma once

#include "Monom.h"


template<typename... Args>
std::string toString(Args&&... args) noexcept;

class Polynom {
public:

	Polynom();

	Polynom(std::vector<Monom*>&);

	template<typename T>
	Polynom(T&&);

	template<typename ...Args>
	Polynom(Args&&...);

	~Polynom();

	template<typename T>
	void pushToNominals(T&& first) noexcept;

	template<typename T, typename ...Args>
	void pushToNominals(T&& first, Args&&... args) noexcept;

	void makeString() noexcept;

	std::string *polynomReade = new std::string("");

	void sort();

	void normalize();

private:

	MyList<Monom*> *nominals = new MyList<Monom*>();
};




template<typename T>
inline Polynom::Polynom(T&& argw) {
	this->pushToNominals(&argw);
}

template<typename ...Args>
inline Polynom::Polynom(Args&&... args) {
	this->pushToNominals(args...);
}

template<typename T>
inline void Polynom::pushToNominals(T&& first) noexcept {
	this->nominals->instToTail(first);
	this->sort();
	this->makeString();
}


template<typename T, typename ...Args>
inline void Polynom::pushToNominals(T&& first, Args&&... args) noexcept {
	this->nominals->instToTail(&first);
	this->pushToNominals(args...);
	this->sort();
	this->makeString();
}

