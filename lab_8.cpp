//Гюржи Евгения, ИП-82

/*Задані дійсні матриці  С(n x m) та В(n x m).
Oдержати нові матриці  Y(n x m) та Z(n x m) шляхом обміну місцями стовпців,
що містять найбільше і найменше значення їх елементів.*/


#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

int** matrix_initialization(int ROW) //инициализация матрицы 
{
	int **arr = new int*[ROW];
	for (int i = 0; i < ROW; i++)
	{
		arr[i] = new int[ROW];
	}
	return arr;
}
	 
  void filling_and_output_the_matrix(int ROW, int COL, int **arr)//заполнение и вывод матрицы 
	{
		setlocale(LC_ALL, "rus");
		
		
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				arr[i][j] = rand() % 10;
				std:: cout << arr[i][j] << "\t";

			}
			std:: cout << endl; 
		}
	}
     

	int find_min_elements(int ROW, int COL, int **arr, int min, int min_ind)//поиск индекса столбца с минимальным элементом
	{
		min = arr[0][0];
		min_ind = 0;
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (arr[i][j] <= min)
				{
					min = arr[i][j];
					min_ind = j;
				}
			}
		}
		
		return min_ind;
	}


	

	int find_max_elements(int max, int **arr, int COL, int ROW, int max_ind)//поиск индекса столбца с максимальным элементом
	{
		max_ind = 0;
		max = arr[0][0];
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (arr[i][j] >= max)
				{
					max = arr[i][j];
					max_ind = j;
				}
			}

		}
		
		return max_ind;
	}

	
	

	int** change_matrix(int ROW,int COL, int temp, int **arr, int max_ind, int min_ind)//получаем новую матрицу
	{
		if (min_ind != max_ind)
		{
			for (int i = 0; i < ROW; i++)
			{
				temp = arr[i][max_ind];
				arr[i][max_ind] = arr[i][min_ind];
				arr[i][min_ind] = temp;
			}
			for (int i = 0; i < ROW; i++)
			{
				for (int j = 0; j < COL; j++)
				{

					cout << arr[i][j] << '\t';
				}
				cout << endl;
			}
		}
		if (max_ind == min_ind)
		{
			cout << "Элементы находятся в одном столбце." << endl;
		}
		return arr;
	}

	

	int main()
	{
		srand(time(NULL));
		setlocale(LC_ALL, "rus");
		int ROW;
		int COL;
		std::cout << "Пожалуйста, введите размерность матрицы C: " << endl;
		cin >> ROW;
		cin >> COL;
		int **arr = matrix_initialization(ROW);
		std::cout << "Матрица С:" << endl;
	    filling_and_output_the_matrix(ROW,COL,arr);
		int ROW1;
		int COL1;
		std::cout << "Пожалуйста, введите размерность матрицы B: " << endl;
		cin >> ROW1;
		cin >> COL1;
		int **arr1 = matrix_initialization(ROW1);
		std::cout << "Матрица В:" << endl;
		filling_and_output_the_matrix(ROW1, COL1, arr1);

		int min = 0;
		int min_ind = 0;
		int min_ind1 = 0;
		int min1 = 0;
		std::cout << "Индекс столбца с наименьшим числом в матрице С: ";
		std:: cout << find_min_elements(ROW, COL, arr, min, min_ind) << endl;
		std::cout << "Индекс столбца с наименьшим числом в матрице В: ";
		std::cout << find_min_elements(ROW1, COL1, arr1, min1, min_ind1) << endl;
		
		
		int max = 0;
		int max_ind = 0;
		int max1 = 0;
		int max_ind1 = 0;
		std::cout << "Индекс столбца с наибольшим числом в матрице C: ";
		std::cout << find_max_elements(max, arr, COL, ROW, max_ind) << endl;
		std::cout << "Индекс столбца с наибольшим числом в матрице В: ";
		std::cout << find_max_elements(max1, arr1, COL1, ROW1, max_ind1) << endl;

		min_ind = find_min_elements(ROW, COL, arr, min, min_ind);
		max_ind = find_max_elements(max, arr, COL, ROW, max_ind);
		int temp = 0;
		cout << "Новая матрица Y: " << endl;
		change_matrix(ROW, COL, temp, arr, max_ind, min_ind);

		min_ind1 = find_min_elements(ROW1, COL1, arr1, min1, min_ind1);
		max_ind1 = find_max_elements(max1, arr1, COL1, ROW1, max_ind1);
		int temp1 = 0;
		cout << "Новая матрица Z: " << endl;
		change_matrix(ROW1, COL1, temp1, arr1, max_ind1, min_ind1);
		
		

		system("pause");
	}


