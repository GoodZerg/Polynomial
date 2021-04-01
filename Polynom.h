#pragma once

#include "Monom.h"


template<typename... Args>
std::string __stdcall toString(Args&&... args) noexcept;

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

	std::string polynomReade;

private:

	MyList<Monom> nominals;
};

template<typename ...Args>
inline Polynom::Polynom(Args&&... args) {
	this->pushToNominals(args...);
}

template<typename T>
inline void Polynom::pushToNominals(T&& first) noexcept {
	this->nominals.instToTail(&first);
}


template<typename T, typename ...Args>
inline void Polynom::pushToNominals(T&& first, Args&&... args) noexcept {
	this->nominals.instToTail(&first);
	this->pushToNominals(args...);
}

template<typename ...Args>
std::string __stdcall toString(Args && ...args) noexcept {
	std::ostringstream oss;
	(oss << ... << std::forward<Args>(args));
	return oss.str();
}