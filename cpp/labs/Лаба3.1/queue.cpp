#include "queue.h"

List::List() {
	size = 0;
	head = nullptr;
}

void List::remove(int index) {		// ������ ������� �� �������
	try
	{
		Elem* current = head;
		if (index == 0) {
			delete[] head;
		}
		if (index == this->size) {
			for (int i = 0; i < index - 1; i++) {
				current = current->pNext;
			}
			Elem* toDelete = current->pNext;
			current->pNext = head;
			delete toDelete;
		}
		if (index > this->size || index < 0) {
			exception ex;
			throw ex;
		}
		else {
			for (int i = 0; i < index - 1; i++) {
				current = current->pNext;
			}
			Elem* toDelete = current->pNext;
			current->pNext = toDelete->pNext;
			delete toDelete;
		}
		size--;
	}
	catch (const exception& ex)
	{
		cout << "����� �� �������!" << endl;
	}
}

void List::remove() { 		// �������� ���������� �������� �������
	head = head->pNext;
	size--;
}

void List::add(stroka elem) {		// �������� ������� � ����� �������
	if (head == nullptr) {
		head = new Elem(elem);
		size++;
	}
	else {
		Elem* current = head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Elem(elem);
		size++;
	}
}

void List::add(stroka elem, int index) {		// �������� ������� � ����� �������
	try
	{
		if (index == 0) {
			Elem* temp = new Elem(elem);
			temp->pNext = head;
		}
		if (index > this->size || index < 0) {
			exception ex;
			throw ex;
		}	
		else {
			Elem* current = head;
			while (index - 1 != 0) {
				current = current->pNext;
				index--;
			}
			Elem* temp = new Elem(elem);
			temp->pNext = current->pNext;
			current->pNext = temp;
			size++;
		}
	}
	catch (const exception& ex)
	{
		cout << "����� �� �������!" << endl;
	}
}

void List::print() {
	Elem* current = head;
	for (int i = 0; i < size; i++) {
		current->data.print();
		current = current->pNext;
	}
}
