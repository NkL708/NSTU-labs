#include "stroka.h"

int stroka::count = 0;

stroka::stroka() {		// ����������� �� ���������
	this->marka = nullptr;
	this->max_size = 0;
	this->size = 0;
	this->count++;
}

stroka::stroka(const char* marka, int max_size) {		// ����������� � �����������
	this->marka = strdup(marka);
	this->max_size = max_size;
	this->size = strlen(marka) + 1;
	this->count++;
}

stroka::~stroka() {		// ����������
	delete[] marka;
}

stroka::stroka(const stroka &other) {		// ����������� �����������
	int lenght = other.size + 1;
	this->marka = new char[lenght];
	this->marka = strcpy(this->marka,other.marka);
	this->max_size = other.max_size;
	this->size = other.size;
}

void stroka::change(const char* marka) {	// ��������� ������ �������
	setlocale(LC_ALL, "Rus");

	int lenght = strlen(marka);
	while (lenght >= this->max_size) {
		this->max_size *= 2;
		delete[] this->marka;
		this->marka = new char[max_size];
	}
	strcpy(this->marka, marka);		// ����������� � ���� this->marka ��������� marka
	this->size = lenght;
}

void stroka::print() {		// ����� ������
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < size; i++) {
		cout << marka[i];
	}
	cout << endl;
}

void stroka::print_sym(const int index) {		// ����� ������ ������� �� ������(�� �������)
	cout << this->marka[index] << endl;
}

void stroka::find_podstroka(const char* podstroka) {		// ���������� ���������
	setlocale(LC_ALL, "Rus");

	int lenght = strlen(podstroka);
	int index_p = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->marka[i] == podstroka[index_p]) {		// ���� �� ������ ������� marka = podstroka[0] ���, �� ����� ����������
			int index_start, index_end;
			index_start = index_end = i;

			while (index_p < lenght) {
				if (this->marka[index_end] == podstroka[index_p]) {
					index_p++, index_end++;
				}

				else break;		// ���� �� ��� ��������� ����� ���������, ���� ������������
			}

			if (index_p == lenght) {	// ���� �� ������ ��� ���������
				for (int i = 0; i < index_start; i++) {
					cout << marka[i];
				}
				cout << " ";
				cout << podstroka << " ";
				for (int i = index_end; i < this->size; i++) {
					cout << marka[i];
				}
				cout << endl;
			}
			else {
				cout << "��������� �� �������!\n";
			}
		}
	}
}

void stroka::operator=(const stroka& other) {		// �������� ������������
	delete[] this->marka;
	this->marka = new char[other.max_size];
	this->marka = strcpy(this->marka, other.marka);
	this->size = other.size;
	this->max_size = other.max_size;
}

char& stroka::operator[](int index) {	//�������� ��������������
	return this->marka[index];
}

stroka stroka::operator+(const stroka & other) {	// �������� ��������
	stroka temp;
	temp.size = this->size + other.size + 1;
	temp.marka = new char[temp.size];
	//temp.marka[0] = '\0';

	for (int i = 0; i < this->size - 1; i++) {
		temp.marka[i] = this->marka[i];
	}

	for (int i = this->size - 1, j = 0; i < temp.size; i++, j++) {
		temp.marka[i] = other.marka[j];
	}

	temp.max_size = other.max_size + this->max_size;
	count--;
	return temp;
}

stroka stroka::operator+(const char* other) {	// �������� ��������, �� � ������� �������
	stroka temp;
	temp.size = this->size + strlen(other) + 1;
	temp.marka = new char[temp.size];
	//temp.marka[0] = '\0';

	for (int i = 0, j = 0; i < this->size; i++, j++) {
		temp.marka[i] = this->marka[j];
	}

	for (int i = this->size, j = 0; i < temp.size; i++, j++) {
		temp.marka[i] = other[j];
	}

	temp.max_size = temp.size + 1;
	count--;
	return temp;
}

stroka stroka::operator-(const stroka& other)	// �������� ���������
{
	stroka temp;
	int lenght = strlen(other.marka);
	int index_p = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->marka[i] == other.marka[index_p]) {		// ���� �� ������ ������� marka = podstroka[0] ���, �� ����� ����������
			int index_start, index_end;
			index_start = index_end = i;

			while (index_p < lenght) {
				if (this->marka[index_end] == other.marka[index_p]) {
					index_p++, index_end++;
				}

				else break;		// ���� �� ��� ��������� ����� ���������, ���� ������������
			}

			if (index_p == lenght) {	// ���� �� ������ ��� ���������
				int size = this->size - (index_end - index_start) + 1;
				temp.marka = new char[size];

				for (int i = 0; i < index_start; i++) {
					temp.marka[i] = this->marka[i];
				}

				for (int i = index_end, j = index_start; i < this->size + 1; i++, j++) {
					temp.marka[j] = this->marka[i];
				}

				temp.size = this->size - other.size;
				temp.max_size = this->max_size;
				temp.count--;
				return temp;
			}
			else {
				cout << "��������� �� �������!\n";
			}
		}
	}
}

void stroka::sum_of_2(stroka &a, stroka &b) {	// �����, ������� ���������� ��� �������
	stroka temp = a + b;

	delete[] this->marka;
	int size = temp.size + 1;
	this->marka = new char[size];
	this->marka = strcpy(this->marka, temp.marka);

	this->size = temp.size;
	this->max_size = temp.max_size;
}

stroka sum_of_2(stroka& a, stroka& b) {		// ������������� �������, ������� ���������� ��� �������
	stroka temp = a + b;
	return temp;
}


ostream& operator<<(ostream& os, stroka& p) {		// ����� ������� � �������
	os << "string: " << p.marka << " size: " << p.size << " max size: " << p.max_size << endl;
	return os;
}

istream& operator>>(istream& is, stroka& p) {	// ���� ������� � �������
	cout << "string: ";
	char* temp = new char[256];
	is.get(temp, 256);
	p.marka = new char[strlen(temp) + 1];
	strcpy(p.marka, temp);
	p.size = strlen(temp) + 1;
	p.max_size = p.size + 1;
	delete[] temp;
	return is;
}

ifstream& operator>>(ifstream& is, stroka& p) {		// ������ ����� � ������ ������ � ������ ������
	char* temp = new char[256];
	is.get(temp, 256);
	p.marka = new char[strlen(temp) + 1];
 	strcpy(p.marka, temp);
	delete[] temp;
	is >> p.size >> p.max_size;
	is.get();
	return is;
}

ofstream& operator<<(ofstream& os, stroka& p) {	// ������ ������� � ����
	os << p.marka << endl << p.size << " " << p.max_size << endl;
	return os;
}

ostream& stroka::writeToBin(ostream& stream) {		// ������ ������� � �������� ����
	stream.write((char*)&size, sizeof(size));
	stream.write((char*)&max_size, sizeof(max_size));
	stream.write(marka, this->size * sizeof(char));
	return stream;
}

istream& stroka::readFromBin(istream& stream) {		// ������ � ������ � ��������� �����
	stream.read((char*)&size, sizeof(size));
	//marka = (char*)(malloc(this->size * sizeof(char)));
	marka = new char[this->size];
	stream.read((char*)&max_size, sizeof(max_size));
	stream.read(marka, this->size * sizeof(char));
	return stream;
}