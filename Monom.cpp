#include "Monom.h"

inline Monom::Monom(int64_t factor) {
	this->factor = factor;

	this->normaizeElements();
	this->sortMonom();
}

Monom::Monom(std::vector<CharacterMonom*>& arr, int64_t factor) {
	this->elements = arr;
	this->factor = factor;

	this->normaizeElements();
	this->sortMonom();
}



Monom::~Monom() {
}

inline int64_t Monom::getPowerElementByIndex(int64_t i) const noexcept {
	return this->elementsAfterNormalize[i];
}

int64_t Monom::getFactor() noexcept
{
	return factor;
}

void Monom::setFactor(int64_t num) noexcept {
	factor = num;
}

inline void Monom::setPowerElementByCh(CharacterMonom&& ch) noexcept {
	this->elementsAfterNormalize[static_cast<int64_t>(ch.variable) - 'a'] = ch.variable;
}

int64_t Monom::getSeniorCoefficient() noexcept {
	return this->elementsAfterNormalize[this->sortedElementIndex[0] == -1 ? 0 : this->sortedElementIndex[0]];
}

inline void Monom::sortMonom() noexcept {
	std::vector<vec2<int64_t>> tmp = std::vector<vec2<int64_t>>(26, { 0,0 });

	for (int64_t i = 0; i < tmp.size(); i++) {
		tmp[i] = { i, this->elementsAfterNormalize[i] };
	}

	std::sort(tmp.begin(), tmp.end(),
		[](const vec2<int64_t>& first, const vec2<int64_t>& second) {
			return first.y > second.y;
		});

	for (int64_t i = 0; i < tmp.size() && tmp[i].y != 0; i++) {
		this->sortedElementIndex[i] = tmp[i].x;
	}
	return;
}

inline void Monom::normaizeElements() noexcept {
	for (auto i : this->elements) {
		this->elementsAfterNormalize[static_cast<int64_t>(i->variable) - 'a'] = i->power;
	}
	this->isNormalized = 1;
}

Monom operator*(const Monom& first, const Monom& second) {
	Monom* tmp = new Monom();
	for (size_t i = 0; i < first.elementsAfterNormalize.size(); ++i) {
		tmp->setPowerElementByCh(CharacterMonom(
			static_cast<char>(i + 'a'),
			first.getPowerElementByIndex(i) + second.getPowerElementByIndex(i)
		));
	}
	return *tmp;
}