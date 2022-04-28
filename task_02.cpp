
//   Завдання 2. Дани два масиви : А[M] і B[N](M і N вво -
//   дяться з клавіатури).Необхідно створити третій масив
//   мінімально можливого розміру, у якому потрібно зібрати
//   елементи масивів A і B, які не є загальними для них, без
//   повторень.



#include <iostream>

void show(int* pArr, size_t size)        // функция выведения массива на экран
{
	for (size_t i = 0; i < size; i++)
		std::cout << pArr[i] << "\t";
	std::cout << "\n\n";
}


void arr_rand_num(int* pArr, size_t size)  //  функция заполнения массива случайными числами
{
	for (size_t i = 0; i < size; i++)
		pArr[i] = rand() % 20;

}


void NewFinishElement(int*& arr, size_t& size)  //  f) функция добавления элемента в конец массива
{
	int* arr1 = new int[size + 1];
	arr1[size] = 0;

	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];

	delete[] arr;
	size++;
	arr = arr1;
}

int* copy_shared_items(int* Arr1, size_t size1, int* Arr2, size_t size2, size_t& size3) // создаем 3й масиив и заполняем его элементами, которых нет во втором массиве, но есть в первом
{
	int* Arr3 = new int[size3];

	for (size_t i = 0; i < size1; i++)  // заполняем массив элементами, которых нет во втором массиве, но есть в первом
	{
		bool availability = false;   // переменная для проверки на повторения

		for (size_t j = 0; j < size2; j++)
			if (Arr1[i] == Arr2[j]) availability = true;

		if (!availability)
			for (size_t k = 0; k < size3; k++)
				if (Arr1[i] == Arr3[k]) availability = true;

		if (!availability)
		{
			NewFinishElement(Arr3, size3);
			Arr3[size3 - 1] = Arr1[i];
		}

	}

	for (size_t i = 0; i < size2; i++) // заполняем массив элементами, которых нет в первом массиве, но есть во втором
	{
		bool availability = false;   // переменная для проверки на повторения

		for (size_t j = 0; j < size1; j++)
			if (Arr2[i] == Arr1[j]) availability = true;

		if (!availability)
			for (size_t k = 0; k < size3; k++)
				if (Arr2[i] == Arr3[k]) availability = true;

		if (!availability)
		{
			NewFinishElement(Arr3, size3);
			Arr3[size3 - 1] = Arr2[i];
		}

	}

	return Arr3;
}

int main()
{
	system("chcp 1251 > 0");

	srand(time(0));

	size_t size1;
	std::cout << "Ведите количество элементов 1го массива : ";
	std::cin >> size1;

	size_t size2;
	std::cout << "Ведите количество элементов 2го массива : ";
	std::cin >> size2;

	int* pArr1 = new int[size1]; // первый массив

	int* pArr2 = new int[size2]; // второй массив

	arr_rand_num(pArr1, size1); // заполняем оба случайными числами
	arr_rand_num(pArr2, size2);

	size_t size3 = 0;  // элементов в третьем массиве

	int* pArr3 = copy_shared_items(pArr1, size1, pArr2, size2, size3); // создаем 3й масиив и заполняем его элементами котрые разные для первого и второго массива

	std::cout << "\nпервый массив : \n";
	show(pArr1, size1);

	std::cout << "второй массив : \n";
	show(pArr2, size2);

	std::cout << "третий массив : \n";
	show(pArr3, size3);

	delete[] pArr1;
	delete[] pArr2;
	delete[] pArr3;
}