#pragma once
#include <iostream>
#include <string>

template <typename T>
class List
{
	class Element
	{
	public:
		Element(Element* next, T data = T());
		T data;
		Element* next;
	};

	int elemViewed = 1;
	Element* head;
	int size; 

public:
	List();									// К-ор
	~List();								// Д-ор
	List(const List& obj);					// К-ор копирования
	int getSize();							// Размер списка
	void clear();							// Очистка списка
	bool isEmpty();							// Проверка на пустоту
	bool isContain(T value);				// Содержит ли заданное значение 
	T getValue(int index);					// Чтение значения под индексом
	void changeValue(int index, T value);	// Изменение значения под индексом
	int getIndex(T value);					// Получение позиции в списке для заданного значения
	void add(T value);						// Включение нового значения
	void addAtIndex(int index, T value);	// Включение нового значения с индексом
	void deleteValue(T value);				// Удаление значения из списка
	void deleteAtIndex(int index);			// Удаление значения из заданного индекса
	void print();							// Вывод списка
	int getElemViewed();					// Вывод кол-во просмотренных э-ов списка

	class Iterator
	{
	public:
		Element* obj;

		T& operator*();
		Iterator operator++(int) {
			Iterator it = *this;
			obj = obj->next;
			return it;
		}

		Iterator operator--(int) {
			Iterator it = *this;
			Element* target = obj;
			while (obj->next != target) {
				obj = obj->next;
			}
			return it;
		}
		bool operator ==(const Iterator& it);
		bool operator !=(const Iterator& it);
	};
	Iterator begin() {
		Iterator it;
		it.obj = head;
		return it;
	}
	Iterator end() {
		Iterator it;
		if (!isEmpty()) {
			it.obj = head;
			while (it.obj->next != head) {
				it.obj = it.obj->next;
			}
			return it;
		}
		else {
			it.obj = head;
			return it;
		}
	}
};

template<typename T>
inline List<T>::Element::Element(Element* next, T data)
{
	this->data = data;
	this->next = next;
}

template<typename T>
inline List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
inline List<T>::~List()
{
	clear();
}

template<typename T>
inline List<T>::List(const List& obj)
{
	Element* current = obj.head;
	do {
		this->add(current->data);
		current = current->next;
	} while (current != obj.head);
}

template<typename T>
inline int List<T>::getSize()
{
	return this->size;
}

template<typename T>
inline void List<T>::clear()
{
	while (head) {
		if (head->next = head) {
			head->next = nullptr;
		}
		Element* next = head->next;
		delete head;
		head = next;
		size--;
	}
}

template<typename T>
inline bool List<T>::isEmpty()
{
	if (size == 0 || head == nullptr) {
		return true;
	}	
	else {
		return false;
	}
}

template<typename T>
inline bool List<T>::isContain(T value)
{
	elemViewed = 1;
	Element* current = head;
	do {
		if (current->data == value) {
			return true;
		}
		current = current->next;
		elemViewed++;
	} while (current != head);
	return false;
}

template<typename T>
inline T List<T>::getValue(int index)
{
	elemViewed = 1;
	int i = 0;
	Element* current = head;
	while (i != index) {
		current = current->next;
		elemViewed++;
		i++;
	}
	return current->data;
}

template<typename T>
inline void List<T>::changeValue(int index, T value)
{
	elemViewed = 1;
	int i = 0;
	Element* current = head;
	while (i != index) {
		current = current->next;
		elemViewed++;
		i++;
	}
	current->data = value;
}

template<typename T>
inline int List<T>::getIndex(T value)
{
	elemViewed = 1;
	int index = 0;
	Element* current = head;
	do {
		if (current->data == value) {
			return index;
		}
		current = current->next;
		elemViewed++;
		index++;
	} while (current != head);
	return -1;
}

template<typename T>
inline void List<T>::add(T value)
{
	elemViewed = 1;
	if (head != nullptr) {
		Element* current = head;
		while (current->next != head) {
			current = current->next;
			elemViewed++;
		}
		current->next = new Element(head, value);
	}
	else {
		head = new Element(nullptr, value);
		head->next = head;
	}
	size++;
}

template<typename T>
inline void List<T>::addAtIndex(int index, T value)
{
	elemViewed = 1;
	if (index == 0) {
		elemViewed = 0;
		Element* temp = head;
		head = new Element(temp, value);
		Element* current = temp;
		while (current->next != temp) {
			current = current->next;
			elemViewed++;
		}
		current->next = head;
		size++;
		return;
	}
	int i = 0;
	Element* current = head;
	while (i < index - 1) {
		current = current->next;
		elemViewed++;
		i++;
	}
	Element* temp = current->next;
	current->next = new Element(temp, value);
	size++;
}

template<typename T>
inline void List<T>::deleteValue(T value)
{
	elemViewed = 1;
	int index = 0;
	Element* current = head;
	do {
		if (current->data == value) {
			deleteAtIndex(index);
			return;
		}
		current = current->next;
		elemViewed++;
		index++;
	} while (current != head);
}

template<typename T>
inline void List<T>::deleteAtIndex(int index)
{
	elemViewed = 1;
	if (index == 0) {
		Element* temp = head;
		Element* current = head;
		while (current->next != head) {
			current = current->next;
			elemViewed++;
		}
		head = temp->next;
		current->next = head;
		delete temp;
		size--;
		return;
	}
	int i = 0;
	Element* current = head;
	while (i < index - 1) {
		current = current->next;
		elemViewed++;
		i++;
	}
	Element* temp = current->next;
	current->next = temp->next;
	delete temp;
	size--;
}

template<typename T>
inline void List<T>::print()
{
	std::cout << "Список:\n";
	if (getSize() == 0) {
		std::cout << "Пуст" << std::endl;
	}
	for (int i = 0; i < getSize(); i++) {
		std::cout << getValue(i) << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
inline int List<T>::getElemViewed()
{
	return elemViewed;
}

template<typename T>
inline T& List<T>::Iterator::operator*()
{
	return obj->data;
}

template<typename T>
inline bool List<T>::Iterator::operator==(const Iterator& it)
{
	if (obj == it.obj) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline bool List<T>::Iterator::operator!=(const Iterator& it)
{
	if (obj != it.obj) {
		return true;
	}	
	else {
		return false;
	}
}