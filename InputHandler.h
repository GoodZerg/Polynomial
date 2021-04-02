#pragma once

#include "Polynom.h"

class InputHandler {
public:

	InputHandler(std::string* str);

	~InputHandler();

	Polynom* pol;

	std::string *str;
private:
	bool isInt(int64_t i);
	bool isSign(int64_t i);
	bool isChar(int64_t i);
	bool isPower(int64_t i);


	void startState(int64_t i);
	void firstState(int64_t i);
	void secondState(int64_t i);
	void thirdState(int64_t i);
	void fourthState(int64_t i);
	void fithState(int64_t i, char& a, std::string& pow);
	[[noreturn]] void cring();


	int64_t num = 0;
	bool sign = 0;
	std::vector<int64_t> arr = std::vector<int64_t>(26, 0);
	int64_t iter = 0;
};

