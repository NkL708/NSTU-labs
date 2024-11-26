#pragma once
#include "stroka.h"

class stroka_binary : public stroka {
protected:
	public:
	stroka_binary();
	stroka_binary(int number, int max_size);
	void virtual_foo() override {
		cout << "Реализация функции дочернего класса" << endl;
	}
};