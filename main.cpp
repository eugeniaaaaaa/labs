/*Задана послідовність з n цілих чисел, серед яких є і від’ємні, а також натуральні числа р та q.
Знайти максимальний елемент послідовності і замінити його квадратом всі її елементи, модуль яких при діленні
на р дає у залишку q.*/

//Гюржи Евгения, ИП-82

#include "pch.h"
#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;

const int SIZE = 10;

void random_v(int* p); //генерация массива
void print_arr(int* p);//вывод массива
int max_arr(int* p);//максимальный элемент массива
void change_arr(int* arr, int p, int q, int max);//изменяем массив

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int p = 4, q = 1, arr[10]{};
	random_v(arr);
	print_arr(arr);
	int max = max_arr(arr);
	cout << "Максимальный элемент массива: " << max << endl;
	change_arr(arr, p, q, max);
	return 0;
}

void random_v(int* p)//генерация массива
{
	for (int i = 0; i < SIZE; i++)
	{
		*p = rand() % 19 - 9;
		p++;
	}
}

void print_arr(int* arr)//вывод массива
{
	cout << "Массив: " << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << arr[i] << " ";
		}
}

int max_arr(int* arr)//максимальный элемент массива
{
	int max = arr[0];
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	 
	return max;
}

void change_arr(int* arr, int p, int q, int max)//изменяем массив 
{
	for (int i = 0; i < 10; ++i) //замена всех элементов, модуль которых при делении на p дает в остатке q на квадрат max
	{
		if (abs(arr[i]) % p == q)
			arr[i] = max * max;
	}
}
