#include "List.h"
#define TYPE std::string

int main()
{
	setlocale(LC_ALL, "Rus");
	int sw = 0;
	bool exit = false;
	int index;
	TYPE value;
	TYPE result;
	List<TYPE> list;
	List<TYPE>::Iterator it;
	std::exception exception("Исключение");

	while (!exit) {
		std::cout << "\n\tСПИСОК ОПЕРАЦИЙ\n";
		std::cout << "\t1. Получить размер списка\n";
		std::cout << "\t2. Очистка списка\n";
		std::cout << "\t3. Проверка списка на пустоту\n";
		std::cout << "\t4. Содержит ли список заданное значение\n";
		std::cout << "\t5. Чтение значения под заданным индексом\n";
		std::cout << "\t6. Изменение значения под заданным индексом\n";
		std::cout << "\t7. Получение позиции в списке для заданного значения\n";
		std::cout << "\t8. Добавить новое значение\n";
		std::cout << "\t9. Включение нового значения с заданным индексом\n";
		std::cout << "\t10. Удаление значения из списка\n";
		std::cout << "\t11. Удаление значения из заданного индекса\n";
		std::cout << "\t12. Вывод списка в консоль\n";
		std::cout << "\t13. Вывод количество просмотренных элементов списка\n";
		std::cout << "\t14. Вывести значение итератора\n";
		std::cout << "\t15. Присвоить begin() итератору\n";
		std::cout << "\t16. Присвоить end() итератору\n";
		std::cout << "\t17. Выполнить к итератору операцию ++\n";
		std::cout << "\t18. Выполнить к итератору операцию --\n";
		std::cout << "\t19. Проверить, равен ли итератор итератору begin()\n";
		std::cout << "\t20. Проверить, равен ли итератор итератору end()\n";
		std::cout << "\t21. Проверить, не равен ли итератор итератору begin()\n";
		std::cout << "\t22. Проверить, не равен ли итератор итератору end()\n";
		std::cout << "\t23. Выход из программы\n";
		std::cout << "\nВведите номер операции: ";
		std::cin >> sw;
		try {
			switch (sw) {
			case 1:
				std::cout << "Размер списка " << list.getSize() << std::endl;
				break;
			case 2:
				list.clear();
				break;
			case 3:
				std::cout << list.isEmpty();
				break;
			case 4:
				std::cout << "Введите значение, наличие которого хотите проверить\n";
				std::cin >> value;
				std::cout << list.isContain(value);
				break;
			case 5:
				std::cout << "Введите индекс: ";
				std::cin >> index;
				if (index <= list.getSize() - 1) {
					std::cout << list.getValue(index) << std::endl;
				}
				else {
					throw exception;
				}
				break;
			case 6:
				std::cout << "Введите индекс: ";
				std::cin >> index;
				if (index <= list.getSize() - 1) {
					std::cout << "Введите значение: ";
					std::cin >> value;
					list.changeValue(index, value);
				}
				else {
					throw exception;
				}
				break;
			case 7:
				std::cout << "Введите значение: ";
				std::cin >> value;
				std::cout << list.getIndex(value) << std::endl;
				break;
			case 8:
				std::cout << "Введите значение: ";
				std::cin >> value;
				list.add(value);
				break;
			case 9:
				std::cout << "Введите индекс: ";
				std::cin >> index;
				if (index <= list.getSize() - 1 || list.isEmpty()) {
					std::cout << "Введите значение: ";
					std::cin >> value;
					list.addAtIndex(index, value);
				}
				else {
					throw exception;
				}
				break;
			case 10:
				std::cout << "Введите значение: ";
				std::cin >> value;
				list.deleteValue(value);
				break;
			case 11:
				std::cout << "Введите индекс: ";
				std::cin >> index;
				if (index <= list.getSize() - 1) {
					list.deleteAtIndex(index);
				}
				else {
					throw exception;
				}
				break;
			case 12:
				list.print();
				break;
			case 13:
				list.getElemViewed();
				break;
			case 14:
				if (it.obj != nullptr) {
					std::cout << *it;
				}
				else {
					throw exception;
				}
				break;
			case 15:
				it = list.begin();
				break;
			case 16:
				it = list.end();
				break;
			case 17:
				it++;
				break;
			case 18:
				it--;
				break;
			case 19:
				std::cout << (it == list.begin());
				break;
			case 20:
				std::cout << (it == list.end());
				break;
			case 21:
				std::cout << (it != list.begin());
				break;
			case 22:
				std::cout << (it != list.end());
				break;
			case 23:
				exit = true;
				break;
			default:
				throw std::exception("Данной операции не существует");
				break;
			}
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
	}
	return 1;
}