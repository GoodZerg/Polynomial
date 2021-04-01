#include "Polynom.h"

inline Polynom::Polynom(std::vector<Monom*>& arr) {
	for (int64_t i = 0; i < arr.size(); ++i) {
		this->nominals.instToTail(arr[i]);
	}
}



Polynom::~Polynom()
{
}

