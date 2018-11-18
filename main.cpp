#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

long int fact(long int k)
{
  if (k == 0) // если пользователь ввел ноль,
    return 1; // возвращаем факториал от нуля 
  else // Во всех остальных случаях
    return k * fact(k - 1); // делаем рекурсию.
}

double func(double a)
{
  double sum1 = 0,  sum2 = 0;
  for (int k = 0; k <= 20; k++)
  {
    sum1 += (pow(a, 2 * k + 1)) / (fact((2 * k + 1)));
    sum2 += (pow(a, 2 * k) / (fact(2 * k)));

  }

  return sum1 / sum2;
}
 
int main()
{
  setlocale(LC_ALL, "ru");

  long int a;
  double Y;
  cout << "Введите число:" << endl;
  cin >> a;

  Y = (2 * func(0.5) - 3 * func(a - 0.1)) / (5 - func(4*a - 1));
  cout << Y;

}
