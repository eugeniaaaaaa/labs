//Гюржи Евгения, ИП-82

//У заданому рядку символів підрахувати кількість певного із символів. 

#include "pch.h"
#include <iostream>
#include <ctime>
#include <map>     
#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");

	char string[500];
	cout << "Введите строку: " << endl;
	cin >> string;
	int symbol = 0;
	int j = 0;
	povtor(j,symbol,string);
	return 0;
}
	int povtor(int j, char symbol, char *string)
	{
		j = 0;
		cout << "Количество повторов какого символа вы хотите узнать?" << endl;
		cin >> symbol;
		for (int i = 0; string[i] != '\0'; i++)
		{
			if (string[i] == symbol)
			{
				j++;
			}
		}
		cout << "Символ " << "повторяется " << j << " " << "раз" << endl;
		return j;
	}
