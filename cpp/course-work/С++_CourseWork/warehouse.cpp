#include "warehouse.h"

Warehouse::Warehouse()
{
	head = nullptr;
	size = 0;
}

Warehouse::~Warehouse()
{
}

void Warehouse::Add(Product value)
{
	if (head == nullptr) {
		head = new Element(value, nullptr, nullptr);
	}
	else {
		Element* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		Element* newItem = new Element(value, nullptr, current);
		current->next = newItem;
	}
	size++;
}

void Warehouse::Add(Product value, int index)
{
	Element* current = head;
	if (index == 0) {
		head = new Element(value, head, nullptr);
	}
	else if (index == size) {
		while (current->next != nullptr) {
			current = current->next;
		}
		Element* newItem = new Element(value, nullptr, current);
		current->next = newItem;
	}
	else {
		while (index - 1 > 0) {
			current = current->next;
			index--;
		}
		Element* newItem = new Element(value, current->next, current);
		current->next = newItem;
		current->next->previous = newItem;
	}
	size++;
}

void Warehouse::Delete()
{
	if (head == nullptr) return;
	else {
		Element* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		delete current;
		current = nullptr;
	}
	size--;
	if (size == 0) head = nullptr;
}

void Warehouse::Delete(int index)
{
	Element* current = head;
	if (index == 0) {
		if (head->next == nullptr) {
			head = nullptr;
			size--;
			return;
		}
		head = head->next;
		delete head->previous;
		head->previous = nullptr;
	}
	else if (index == size - 1) {
		Element* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}
	else {
		while (index > 0) {
			current = current->next;
			index--;
		}
		current->next->previous = current->previous;
		current->previous->next = current->next;
		delete current;
	}
	size--;
}

void Warehouse::Print()
{
	if (head == nullptr) {
		cout << "Склад пуст!" << endl;
		return;
	}
	Element* current = head;
	int i = 0;
	cout << "Товары на складе: " << endl;
	do {
		cout << "Товар номер " << i << endl;
		cout << "Имя товара: " << current->data.name << endl;
		cout << "Категория товара: " << current->data.category << endl;
		cout << "Количество товара: " << current->data.count << " шт." << endl;
		cout << "Дата прибытия товара: " << current->data.arrivalDate.year << "." << current->data.arrivalDate.month <<
			"." << current->data.arrivalDate.day << endl;
		cout << "Стоимость товара: " << current->data.cost << " рублей" << endl;
		cout << "Торговая надбавка товара: " << current->data.percent << "%" << endl << endl;
		current = current->next;
		i++;
	} while (current != nullptr);
}

void Warehouse::Sort(int column)
{
	Warehouse temp;
	switch (column) {
	case 1:
		while (size > 0) {
			Element* current = head->next, * upper = head;
			int i = 0;
			while (current != nullptr) {
				if (current->data.name[i] == upper->data.name[i]) {
					i++;
					continue;
				}
				else if (current->data.name[i] > upper->data.name[i]) {
					upper = current;
				}
				i = 0;
				current = current->next;
			}
			temp.Add(upper->data, 0);
			Delete(GetIndex(upper));
		}
		*this = temp;
		break;
	case 2:
		while (size > 0) {
			Element* current = head->next, * upper = head;
			int i = 0;
			while (current != nullptr) {
				if (current->data.category[i] == upper->data.category[i]) {
					i++;
					continue;
				}
				else if (current->data.category[i] > upper->data.category[i]) {
					upper = current;
				}
				i = 0;
				current = current->next;
			}
			temp.Add(upper->data, 0);
			Delete(GetIndex(upper));
		}
		*this = temp;
		break;
	case 3:
		while (size > 0) {
			Element* current = head->next, * upper = head;
			while (current != nullptr) {
				if (current->data.count > upper->data.count) {
					upper = current;
				}
				current = current->next;
			}
			temp.Add(upper->data, 0);
			Delete(GetIndex(upper));
		}
		*this = temp;
		break;
	case 4:
		while (size > 0) {
			Element* current = head->next, * upper = head;
			while (current != nullptr) {
				if (current->data.arrivalDate.year > upper->data.arrivalDate.year) {
					upper = current;
				}
				else if (current->data.arrivalDate.month > upper->data.arrivalDate.month) {
					upper = current;
				}
				else if (current->data.arrivalDate.day > upper->data.arrivalDate.day) {
					upper = current;
				}
				current = current->next;
			}
			temp.Add(upper->data, 0);
			Delete(GetIndex(upper));
		}
		*this = temp;
		break;
	case 5:
		while (size > 0) {
			Element* current = head->next, * upper = head;
			while (current != nullptr) {
				if (current->data.cost > upper->data.cost) {
					upper = current;
				}
				current = current->next;
			}
			temp.Add(upper->data, 0);
			Delete(GetIndex(upper));
		}
		*this = temp;
		break;
	case 6:
		while (size > 0) {
			Element* current = head->next, * upper = head;
			while (current != nullptr) {
				if (current->data.percent > upper->data.percent) {
					upper = current;
				}
				current = current->next;
			}
			temp.Add(upper->data, 0);
			Delete(GetIndex(upper));
		}
		*this = temp;
		break;
	default:
		break;
	}
}

int Warehouse::GetIndex(Element* el)
{
	Element* current = head;
	int index = 0;
	while (current != el) {
		current = current->next;
		index++;
	}
	return index;
}

void Warehouse::CountSum()
{
	Element* current = head;
	int sum = 0;
	while (current != nullptr) {
		sum += current->data.count * current->data.cost;
		current = current->next;
	}
	cout << "Стоимость всех товаров равна " << sum << "Р" << endl;
}

void Warehouse::Clear()
{
	Element* current = head;
	while (head) {
		current = current->next;
		delete head;
		head = current;
	}
	head = nullptr;
}

ostream& Warehouse::writeToBin(ostream& stream) {
	Element* current = head;
	while (current) {
		//const auto& data = current->data;
		int nameLen = current->data.name.size(), categoryLen = current->data.category.size();
		stream.write((char*)&nameLen, sizeof(int));
		stream.write((char*)current->data.name.c_str(), nameLen);
		stream.write((char*)&categoryLen, sizeof(int));
		stream.write((char*)current->data.category.c_str(), categoryLen);
		stream.write((char*)&current->data.count, sizeof(int));
		stream.write((char*)&current->data.arrivalDate, sizeof(Product::Date));
		stream.write((char*)&current->data.cost, sizeof(int));
		stream.write((char*)&current->data.percent, sizeof(int));
		current = current->next;
	}
	return stream;
}

istream& Warehouse::readFromBin(istream& stream) {
	Clear();
	while (stream) {
		int count, cost, percent, nameLen, categoryLen;
		Product::Date arrivalDate;
		string name, category;
		stream.read((char*)&nameLen, sizeof(int));
		if (!stream)break;
		name.resize(nameLen, '\0');
		stream.read((char*)name.data(), name.size());
		stream.read((char*)&categoryLen, sizeof(int));
		category.resize(categoryLen, '\0');
		stream.read((char*)category.data(), category.size());
		stream.read((char*)&count, sizeof(int));
		stream.read((char*)&arrivalDate, sizeof(Product::Date));
		stream.read((char*)&cost, sizeof(int));
		stream.read((char*)&percent, sizeof(int));
		Product product(name, category, count, arrivalDate, cost, percent);
		Add(product);
	}
	return stream;
}

Warehouse::Element::Element(Product data, Element* next, Element* previous)
{
	this->next = next;
	this->previous = previous;
	this->data = data;
}
