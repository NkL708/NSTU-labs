#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class stroka {
protected:
	char* marka;		// Указатель на массив char
	int max_size;		// Максимальный размер массива
	int size;			// Текущий размер массива
	static int count;	// Количество экземпляров класса
public:
	// Лаба 1
	stroka();										// Конструктор по умолчанию
	stroka(const char* marka, int max_size);		// Конструктор с параметрами
	~stroka();										// Деструктор
	stroka(const stroka& other);					// Конструктор копирования
	void change(const char* marka);					// Изменение строки объекта
	void print();									// Вывод строки
	void find_podstroka(const char* podstroka);		// Нахождение подстроки
	void print_sym(const int index);				// Вывод одного символа из строки(по индексу)

	// Лаба 2
	void operator=(const stroka& other);			// Перегрузка оператора присваивания 
	stroka operator+(const stroka& other);			// Перегрузка оператора сложения
	stroka operator-(const stroka& other);			// Перегрузка оператора разности
	stroka operator+(const char* other);			// Перегрузка оператора сложения со строкой
	char& operator[](int index);					// Перегрузка оператора индексирования
	void sum_of_2(stroka& a, stroka& b);			// Метод, который складывает два объекта
	friend stroka sum_of_2(stroka& a, stroka& b);	// Дружественная функция, которая складывает два объекта

	// Лаба 3
	friend ostream& operator<<(ostream& os, stroka& p);	// Вывод объекта в консоль
	friend istream& operator>>(istream& is, stroka& p);			// Ввод объекта с консоли
	friend ofstream& operator<<(ofstream& os, stroka& p);	// Чтение файла и запись данных в объект класса
	friend ifstream& operator>>(ifstream& is, stroka& p);		// Запись объекта в файл
	ostream& writeToBin(ostream& stream);
	istream& readFromBin(istream& stream);

	// Лаба 5 (демонстрация вирутальной функции)
	virtual void virtual_foo() {
		cout << "Реализация функции материнского класса" << endl;
	}

	// Геттеры и сеттеры
	char* getMarka() { return marka; }
	void setMarka(char* marka) { this->marka = marka; }
	int getMax_size() { return max_size; }
	void setMax_size(int max_size) { this->max_size = max_size; }
	int getSize() { return size; }
	void setSize(int size) { this->size = size; }
};