#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class stroka {
protected:
	char* marka;		// ��������� �� ������ char
	int max_size;		// ������������ ������ �������
	int size;			// ������� ������ �������
	static int count;	// ���������� ����������� ������
public:
	// ���� 1
	stroka();										// ����������� �� ���������
	stroka(const char* marka, int max_size);		// ����������� � �����������
	~stroka();										// ����������
	stroka(const stroka& other);					// ����������� �����������
	void change(const char* marka);					// ��������� ������ �������
	void print();									// ����� ������
	void find_podstroka(const char* podstroka);		// ���������� ���������
	void print_sym(const int index);				// ����� ������ ������� �� ������(�� �������)

	// ���� 2
	void operator=(const stroka& other);			// ���������� ��������� ������������ 
	stroka operator+(const stroka& other);			// ���������� ��������� ��������
	stroka operator-(const stroka& other);			// ���������� ��������� ��������
	stroka operator+(const char* other);			// ���������� ��������� �������� �� �������
	char& operator[](int index);					// ���������� ��������� ��������������
	void sum_of_2(stroka& a, stroka& b);			// �����, ������� ���������� ��� �������
	friend stroka sum_of_2(stroka& a, stroka& b);	// ������������� �������, ������� ���������� ��� �������

	// ���� 3
	friend ostream& operator<<(ostream& os, stroka& p);	// ����� ������� � �������
	friend istream& operator>>(istream& is, stroka& p);			// ���� ������� � �������
	friend ofstream& operator<<(ofstream& os, stroka& p);	// ������ ����� � ������ ������ � ������ ������
	friend ifstream& operator>>(ifstream& is, stroka& p);		// ������ ������� � ����
	ostream& writeToBin(ostream& stream);
	istream& readFromBin(istream& stream);

	// ���� 5 (������������ ����������� �������)
	virtual void virtual_foo() {
		cout << "���������� ������� ������������ ������" << endl;
	}

	// ������� � �������
	char* getMarka() { return marka; }
	void setMarka(char* marka) { this->marka = marka; }
	int getMax_size() { return max_size; }
	void setMax_size(int max_size) { this->max_size = max_size; }
	int getSize() { return size; }
	void setSize(int size) { this->size = size; }
};