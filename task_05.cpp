
//  Завдання 3. Написати функцію, яка отримує покажчик
//  на статичний масив і його розмір.Функція розподіляє
//  додатні, від’ємні та нульові елементи в окремі динамічні
//  масиви.



#include <iostream>

template <class T>
void showArr(T* arr, int size);

template <class T>
void NewFinishElement(T*& arr, int& size);

int* negative_numbers(int* arr, int size);

int* null_numbers(int* arr, int size);

int* positive_numbers(int* arr, int size);





template <class T>
void showArr(T* arr, int size)  //   функция показа динамического массива на экран консоли
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

int* negative_numbers(int* arr, int size, int& element_newArr)      // создаем массив с отрицательными элементами
{
	element_newArr = 0;
	int* arr1 = new int[element_newArr];

	for (int i = 0; i < size; i++)
		if (arr[i] < 0)
		{
			NewFinishElement(arr1, element_newArr);
			arr1[element_newArr - 1] = arr[i];
		}

	return arr1;
}


int* null_numbers(int* arr, int size, int& element_newArr)      // создаем массив с нуливыми элементами
{
	element_newArr = 0;
	int* arr1 = new int[element_newArr];

	for (int i = 0; i < size; i++)
		if (arr[i] == 0)
		{
			NewFinishElement(arr1, element_newArr);
			arr1[element_newArr - 1] = arr[i];
		}

	return arr1;
}

int* positive_numbers(int* arr, int size, int& element_newArr)      // создаем массив с положительными элементами
{
	element_newArr = 0;
	int* arr1 = new int[element_newArr];

	for (int i = 0; i < size; i++)
		if (arr[i] > 0)
		{
			NewFinishElement(arr1, element_newArr);
			arr1[element_newArr - 1] = arr[i];
		}

	return arr1;
}

int main()
{
	system("chcp 1251 > 0");

	const int size = 10;
	int Arr[size]{ -1, 2, 0, 4, -5, 0, 7, -8, 9, 0 };  // исходный массив

	std::cout << "Исходный массив : \n";
	showArr(Arr, size); 

	int size1 = 0;
	int* Arr1 = negative_numbers(Arr, size, size1); // создаем массив с отрицательными элементами

	std::cout << "\nМассив с отрицательными элементами : \n";
	showArr(Arr1, size1);

	int size2 = 0;
	int* Arr2 = null_numbers(Arr, size, size2);  // создаем массив с нуливыми элементами

	std::cout << "\nМассив с нулевыми элементами : \n";
	showArr(Arr2, size2);

	int size3 = 0;
	int* Arr3 = positive_numbers(Arr, size, size3);  // создаем массив с положительными элементами

	std::cout << "\nМассив с положительными элементами : \n";
	showArr(Arr3, size3);
}


