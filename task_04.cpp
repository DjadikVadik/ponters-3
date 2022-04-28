
//  Завдання 2. Написати функцію, яка отримує покажчик на
//  динамічний масив і його розмір.Функція має видалити з
//  масиву всі прості числа та повернути покажчик на новий
//  динамічний масив.



#include <iostream>


template <class T>
void showArr(T*& arr, int size)  //   функция показа динамического массива на экран консоли
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ",   ";
	std::cout << "\n";
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

int* del_prime_num(int*& arr, int& size, int& size1) // массив без простых чисел
{
	size1 = 0;
	int* arr1 = new int[size1];

	for (int i = 0; i < size; i++)
	{
		bool prime = true;
		for (int j = 2; j <= arr[i] / 2; j++)
			if (arr[i] % j == 0)
			{
				prime = false;
				break;
			}

		if (!prime)
		{
			NewFinishElement(arr1, size1);
			arr1[size1 - 1] = arr[i];
		}

	}

	return arr1;
}

int main()
{
	system("chcp 1251 > 0");

	int size = 7;
	int* Arr = new int[size]{ 1, 2, 3, 4, 5, 6, 7 };  // исходный массив

	std::cout << "Исходный массив : \n";
	showArr(Arr, size); 

	int size1; // количество элементов в новом массиве
	int* Arr1 = del_prime_num(Arr, size, size1); // выбираем из первого массива все не простые числа и записываем в новый массив

	std::cout << "\nМассив без простых чисел : \n";
	showArr(Arr1, size1);

	delete[] Arr;
	delete[] Arr1;
}


