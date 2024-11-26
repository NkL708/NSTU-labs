#pragma once
#include "product.h"

class Warehouse
{
	class Element
	{
	public:
		Element(Product data, Element* next = nullptr, Element* previous = nullptr);
		Product data;
		Element* next;
		Element* previous;
	};
	Element* head;
	int size;

public:
	Warehouse();
	~Warehouse();
	void Add(Product value);
	void Add(Product value, int index);
	void Delete();
	void Delete(int index);
	void Print();
	void Sort(int column);
	int GetIndex(Element* el);
	void CountSum();
	void Clear();
	ostream& writeToBin(ostream& stream);
	istream& readFromBin(istream& stream);
};