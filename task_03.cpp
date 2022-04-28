
//   Завдання 1. Написати такі функції для роботи з дина -
//   мічним масивом :
//   1 Функція розподілу динамічної пам’яті;
//   2 Функція ініціалізації динамічного масиву;
//   3 Функція друку динамічного масиву;
//   4 Функція видалення динамічного масиву;
//   5 Функція додавання елемента в кінець масиву;
//   6 Функція вставки елемента за вказаним індексом;
//   7 Функція видалення елемента за вказаним індексом.



#include <iostream>

template <class T>
void NewArr(T*& arr, int size)  //   функция выделения динамической памяти под массив
{
	arr = new T[size];
}

template <class T>
void SetRandArr(T*& arr, int size)  //   функция инициализации динамического массива случайными числами
{
	srand(time(0));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
}

template <class T>
void showArr(T*& arr, int size)  //   функция показа динамического массива на экран консоли
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ",   ";
	std::cout << "\n";
}

template <class T>
void DelArr(T*& arr) //   функция очистки памяти от динамического массива
{
	delete[] arr;
	arr = nullptr;
}

template <class T>
void NewFinishElement(T*& arr, int& size)  //   функция добавления элемента в конец массива
{
	T* arr1 = new int[size + 1];

	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];

	delete[] arr;
	size++;
	arr = arr1;
}

template <class T>
void NewNumElement(T*& arr, int& size, int num) //  функция вставки элемента по указанному индексу
{
	T* arr1 = new int[size + 1];

	for (int i = 0; i < size + 1; i++)
	{
		if (i < num) arr1[i] = arr[i];
		else if (i == num) arr1[i] = 0;
		else if (i > num) arr1[i] = arr[i - 1];
	}

	delete[] arr;
	size++;
	arr = arr1;
}

template <class T>
void DelNumElement(T*& arr, int& size, int num)  //  функция удаления элемента по указанному индексу
{
	T* arr1 = new int[size - 1];

	for (int i = 0; i < size; i++)
	{
		if (i < num) arr1[i] = arr[i];
		else if (i == num) continue;
		else if (i > num) arr1[i - 1] = arr[i];
	}

	delete[] arr;
	size--;
	arr = arr1;
}

int main()
{
	
}


