#include "warehouse.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Warehouse collection;
	ofstream bFileOut;
	ifstream bFileIn;
	//collection.Add(Product("Мыло", "Хозтовары", 200, Product::Date(2018, 5, 30), 40, 11));
	//collection.Add(Product("Вёдра", "Хозтовары", 10, Product::Date(2019, 9, 20), 400, 10));
	//collection.Add(Product("Швабры", "Хозтовары", 5, Product::Date(2020, 7, 30), 500, 20));
	//collection.Add(Product("Коробки", "Прочее", 1000, Product::Date(2021, 7, 28), 10, 5));
	//collection.Add(Product("Гвозди", "Стройматериалы", 50000, Product::Date(2020, 5, 20), 50, 14));
	//collection.Add(Product("Скотч", "Стройматериалы", 300, Product::Date(2021, 6, 28), 100, 16));
	int value, index, column;
	bool sw = true;
	while (sw) {
		cout << "\n_________Меню программы_________" << endl;
		cout << "0. Завершить программу" << endl;
		cout << "1. Добавить товар на склад (в конец)" << endl;
		cout << "2. Добавить товар на склад с указанием позиции" << endl;
		cout << "3. Удалить последний товар на складе" << endl;
		cout << "4. Удалить товар на складе с укаанием позиции" << endl;
		cout << "5. Просмотреть все товары на складе" << endl;
		cout << "6. Отсортировать товары на складе" << endl;
		cout << "7. Подсчитать стоимость склада" << endl;
		cout << "8. Сохранить данные в файл" << endl;
		cout << "9. Загрузить данные из файла" << endl;
		cout << endl;
		cout << "Введите номер операции ";
		cin >> value;
		switch (value) {
		case 0:
			sw = false;
			break;
		case 1:
			collection.Add(Product::CreateProduct());
			break;
		case 2:
			cout << "Позиция: ";
			cin >> index;
			collection.Add(Product::CreateProduct(), index);
			break;
		case 3:
			collection.Delete();
			break;
		case 4:
			cout << "Позиция: ";
			cin >> index;
			collection.Delete(index);
			break;
		case 5:
			collection.Print();
			break;
		case 6:
			cout << "Столбец: ";
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
			cout << "Склад сохранён в файл" << endl;
			break;
		case 9:
			bFileIn.open("bFile.txt");
			collection.readFromBin(bFileIn);
			bFileIn.close();
			break;
		default:
			cout << "Неверный номер операции! Попробуйте снова" << endl;
			break;
		}
	}
	
	
	return 0;
}