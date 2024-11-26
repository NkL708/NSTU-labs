#include "stroka_binary.h";

stroka_binary::stroka_binary() : stroka() {

}

stroka_binary::stroka_binary(int number, int max_size) {
	this->max_size = max_size;
	int n = number, size = 0;
	// Получение размера двоичного числа
	while (n > 0) {
		n /= 2;
		size++;
	}
	this->size = size;
	marka = new char[size + 1];
	char* reverse_arr = new char[size];
	n = number;
	int i = 0;
	// Запись в массив
	while (n > 0) {
		if (n % 2 == 0)
			reverse_arr[i] = '0';
		else
			reverse_arr[i] = '1';
		n /= 2;
		i++;
	}
	// Переворачивание
	marka[size] = '\0';
	for (int i = size - 1, j = 0; i >= 0; i--, j++) {
		marka[i] = reverse_arr[j];
	}
	delete[] reverse_arr;
}