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
	/*
	int64_t seniorFactor = nominals->operator[](0)->getFactor();
	for (size_t i = 0; i < nominals->get_size(); i++) {
		if (nominals->operator[](i)->getFactor() / seniorFactor == 0) {
			nominals->operator[](i)->setFactor(1);
		} else {
			nominals->operator[](i)->setFactor(nominals->operator[](i)->getFactor() / seniorFactor);
		}
	}
	*/ // ahahahahhahahahahahahahhahahahahahahahha
}

MyList<Monom*>* Polynom::getNominals()
{
	return nominals;
}


template<typename ...Args>
std::string toString(Args && ...args) noexcept {
	std::ostringstream oss;
	(oss << ... << std::forward<Args>(args));
	return oss.str();
}

Polynom operator+(const Polynom& first, const Polynom& second) {
	Polynom* answ = new Polynom();

	MyList<Monom*> nom = *(first.nominals);
	for (size_t i = 0; i < nom.get_size(); i++) {
		std::vector<CharacterMonom*> ch_vec = nom[i]->getElements();
		std::vector<CharacterMonom*> ch_vec_ans;
		for (size_t j = 0; j < ch_vec.size(); j++) {
			CharacterMonom* ch = new CharacterMonom(*ch_vec[j]);
			ch_vec_ans.push_back(ch);
		}
	 answ->pushToNominals(new Monom(ch_vec_ans, nom[i]->getFactor()));
	}
	MyList<Monom*> nomnom = *(second.nominals);
	for (size_t i = 0; i < nomnom.get_size(); i++) {
		std::vector<CharacterMonom*> ch_vec = nomnom[i]->getElements();
		std::vector<CharacterMonom*> ch_vec_ans;
		for (size_t j = 0; j < ch_vec.size(); j++) {
			CharacterMonom* ch = new CharacterMonom(*ch_vec[j]);
			ch_vec_ans.push_back(ch);
		}
		answ->pushToNominals(new Monom(ch_vec_ans, nomnom[i]->getFactor()));
	}

	for (size_t i = 0; i < answ->nominals->get_size(); i++) {
		for (size_t j = i + 1; j < answ->nominals->get_size(); j++) {

			bool f = 1;
			for (size_t ii = 0; ii < 26; ++ii) {
				if (answ->nominals->operator[](i)->getPowerElementByIndex(ii) !=
					answ->nominals->operator[](j)->getPowerElementByIndex(ii)) {
					f = 0;
					break;
				}
			}
			if (f) {
				answ->nominals->operator[](i)->setFactor(answ->nominals->operator[](i)->getFactor() + answ->nominals->operator[](j)->getFactor());
				answ->nominals->destroyItemByIndex(j);
				if (answ->nominals->operator[](i)->getFactor() == 0) {
					answ->nominals->destroyItemByIndex(i);
					i--;
					break;
				}
				j--;
			}

		}
	}
	
	answ->sort();
	answ->normalize();
	
	
	std::vector<Monom*> arr;
	for (size_t i = 0; i < answ->nominals->get_size(); i++) {
		arr.push_back(answ->nominals->operator[](i));
	}
	return Polynom(arr);
}
