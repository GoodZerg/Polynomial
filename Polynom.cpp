#include "Polynom.h"

inline Polynom::Polynom(std::vector<Monom*>& arr) {
	for (int64_t i = 0; i < arr.size(); ++i) {
		this->nominals->instToTail(arr[i]);
	}
	this->sort(); 
	this->makeString();
}

Polynom::Polynom() {}

Polynom::~Polynom()
{
}

void Polynom::makeString() noexcept {
	std::string *tmp = new std::string("");
	for (size_t i = 0; i < nominals->get_size(); i++) {
		if (i != 0 && nominals->operator[](i)->getFactor() > 0)
			*tmp += "+";
		*tmp += std::to_string(nominals->operator[](i)->getFactor());
		for (size_t j = 0; nominals->operator[](i)->sortedElementIndex[j] != -1; j++) {
			*tmp += nominals->operator[](i)->sortedElementIndex[j] + 'a';
			*tmp += '^';
			*tmp += std::to_string(nominals->operator[](i)->getPowerElementByIndex(nominals->operator[](i)->sortedElementIndex[j]));
		}
	}
	*polynomReade = *tmp;
}

void Polynom::sort() {
	for (size_t i = 0; i < nominals->get_size(); i++) {
		for (size_t j = 0; j < nominals->get_size(); j++) {
			if (nominals->operator[](i)->getSeniorCoefficient() > nominals->operator[](j)->getSeniorCoefficient()) {
				std::swap(nominals->operator[](i), nominals->operator[](j));
			}
		}
	}
}

void Polynom::normalize() {
	int64_t seniorFactor = nominals->operator[](0)->getFactor();
	for (size_t i = 0; i < nominals->get_size(); i++) {
		nominals->operator[](i)->setFactor(nominals->operator[](i)->getFactor()/seniorFactor);
	}
}


template<typename ...Args>
std::string toString(Args && ...args) noexcept {
	std::ostringstream oss;
	(oss << ... << std::forward<Args>(args));
	return oss.str();
}
