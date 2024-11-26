#pragma once
#include "stroka_binary.h"

class List		// Список
{
public:
	List();
	void remove();
	void remove(int index);
	void add(stroka elem);
	void add(stroka elem, int index);
	void print();

	class Elem {		// Элемент списка

	public:
		Elem* pNext;
		stroka data;

		Elem(stroka data, Elem* pNext = nullptr, Elem* pPrevious = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Elem* head;		// Указатель на первый элемент списка
};