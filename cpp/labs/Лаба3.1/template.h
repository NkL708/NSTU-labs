#include <iostream>
#include <stdarg.h>

using namespace std;

template <typename T>
class stack
{
public:
	stack(int num, T t, ...);
	void print();
	void add(T t);
	void remove();
private:
	T* arr;
	int size = 0;
};

template<typename T>
inline stack<T>::stack(int num, T t, ...)
{
	size = num;
	arr = new T[num];
	va_list args;
	va_start(args, num);

	int i = 0;
	while (num--) {
		arr[i] = va_arg(args, T);
		i++;
	}
	va_end(args);
}

template<typename T>
inline void stack<T>::print()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

template<typename T>
inline void stack<T>::add(T t)
{
	T* temp = new T[size + 1];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = arr[i];
	}
	arr[size] = t;
	size++;
}

template<typename T>
inline void stack<T>::remove()
{
	T* temp = new T[int(size) - 1];
	for (int i = 0; i < size - 2; i++) {
		temp[i] = arr[i];
	}
	size--;
}
