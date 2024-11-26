#pragma once
#include "stroka_binary.h"

class List		// ������
{
public:
	List();
	void remove();
	void remove(int index);
	void add(stroka elem);
	void add(stroka elem, int index);
	void print();

	class Elem {		// ������� ������

	public:
		Elem* pNext;
		stroka data;

		Elem(stroka data, Elem* pNext = nullptr, Elem* pPrevious = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Elem* head;		// ��������� �� ������ ������� ������
};