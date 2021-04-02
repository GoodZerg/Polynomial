#include "Polynom.h"

inline Polynom::Polynom(std::vector<Monom*>& arr) {
	for (int64_t i = 0; i < arr.size(); ++i) {
		this->nominals->instToTail(arr[i]);
	}
	this->sort();
}

Polynom::Polynom() {}

Polynom::~Polynom()
{
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

