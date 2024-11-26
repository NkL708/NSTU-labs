#include "warehouse.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Warehouse collection;
	ofstream bFileOut;
	ifstream bFileIn;
	//collection.Add(Product("����", "���������", 200, Product::Date(2018, 5, 30), 40, 11));
	//collection.Add(Product("¸���", "���������", 10, Product::Date(2019, 9, 20), 400, 10));
	//collection.Add(Product("������", "���������", 5, Product::Date(2020, 7, 30), 500, 20));
	//collection.Add(Product("�������", "������", 1000, Product::Date(2021, 7, 28), 10, 5));
	//collection.Add(Product("������", "��������������", 50000, Product::Date(2020, 5, 20), 50, 14));
	//collection.Add(Product("�����", "��������������", 300, Product::Date(2021, 6, 28), 100, 16));
	int value, index, column;
	bool sw = true;
	while (sw) {
		cout << "\n_________���� ���������_________" << endl;
		cout << "0. ��������� ���������" << endl;
		cout << "1. �������� ����� �� ����� (� �����)" << endl;
		cout << "2. �������� ����� �� ����� � ��������� �������" << endl;
		cout << "3. ������� ��������� ����� �� ������" << endl;
		cout << "4. ������� ����� �� ������ � �������� �������" << endl;
		cout << "5. ����������� ��� ������ �� ������" << endl;
		cout << "6. ������������� ������ �� ������" << endl;
		cout << "7. ���������� ��������� ������" << endl;
		cout << "8. ��������� ������ � ����" << endl;
		cout << "9. ��������� ������ �� �����" << endl;
		cout << endl;
		cout << "������� ����� �������� ";
		cin >> value;
		switch (value) {
		case 0:
			sw = false;
			break;
		case 1:
			collection.Add(Product::CreateProduct());
			break;
		case 2:
			cout << "�������: ";
			cin >> index;
			collection.Add(Product::CreateProduct(), index);
			break;
		case 3:
			collection.Delete();
			break;
		case 4:
			cout << "�������: ";
			cin >> index;
			collection.Delete(index);
			break;
		case 5:
			collection.Print();
			break;
		case 6:
			cout << "�������: ";
			cin >> column;
			collection.Sort(column);
			break;
		case 7:
			collection.CountSum();
			break;
		case 8:
			bFileOut.open("bFile.txt");
			collection.writeToBin(bFileOut);
			bFileOut.close();
			cout << "����� ������� � ����" << endl;
			break;
		case 9:
			bFileIn.open("bFile.txt");
			collection.readFromBin(bFileIn);
			bFileIn.close();
			break;
		default:
			cout << "�������� ����� ��������! ���������� �����" << endl;
			break;
		}
	}
	
	
	return 0;
}