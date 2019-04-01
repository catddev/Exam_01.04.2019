#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<math.h>
#include<Windows.h>
#include<ctime>
#include<cstring>
#include<fstream>
using namespace std;

#pragma region
//array
void createArray(int *&a, int n) {
	a = new int[n];
}
void fillArray(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = rand() % 5-1;
}
void fillArray2(int *a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
void printArray(const int *a, int n) {
	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << " ";
	cout << endl;
}
void deleteArray(int *&a) {
	delete[] a;
}
//matrix
void fill_matrix(int **pp, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			pp[i][j] = rand() % 21;
}
void print_matrix(int**pp, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << left << pp[i][j] << " ";
		}
	cout << endl;
	}
	cout << endl;
}
void delete_matrix(int**pp, int n, int m) {
	for (int i = 0; i < n; i++)
		delete[] pp[i];
	delete[] pp;
}
#pragma endregion
//2.	Написать функцию, которая принимает указатель на массив и количество элементов.
// Функция сжимает массив, удаляя из него элементы равные 0.
// Возвращает указатель на новый массив, не содержащий 0.
// case 1
void erase_zeros(int *&a, int &n) {
	int *tmp;
	int k = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
			k++;
	}
	tmp = new int[k];

	for (int i = 0; i < n; i++)
		if (a[i] != 0)
			tmp[j++] = a[i];

	delete[] a;
	a = tmp;
	n = k;
}
//4.	Описать функцию IsPowerN(K, N) логического типа,
// возвращающую TRUE, если целый параметр K(> 0) является степенью числа N(> 1),
// FALSE в противном случае.
// Дано число N(> 1) и набор из 10 целых положительных чисел.
// С помощью функции IsPowerN найти количество степеней числа N в данном наборе.
// case 2
//
bool IsPowerN(int k, int n) {
	if (k > 0 && n > 1)
	{
		while (k % n==0)
			k /= n;
		return (k == 1);
	}
	else
		return false;
}
// 5.	Дана матрица размера M × N и целое число K(1 ≤ K ≤ N).
// Вывести элементы K - го столбца данной матрицы.
// case 3
void printColumn(int **pp, int n, int k) {
	for(int i=0; i<n; i++)
			cout << pp[i][k-1] << endl;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
			
		{
			int *p;
			int n;
			cout << "Enter a number of elements" << endl;
			cin >> n;
			createArray(p, n);
			fillArray(p, n);
			printArray(p, n);
			cout << endl << endl;
			erase_zeros(p, n);
			printArray(p, n);
			deleteArray(p);
		}
		break;
		case 2:
		{
			int n;
			int *p;
			createArray(p, 10);
			fillArray2(p, 10);
			printArray(p, 10);
			cout << "Enter N>1:" << endl;
			cin >> n;
			int j = 0;
			cout << "элементы, являющиеся степенями числа " << n << ": " << endl;
			for (int i = 0; i < 10; i++)
			{
				if (IsPowerN(p[i], n))
				{
					cout << p[i] << " ";
					j++;
				}
			}
			cout << endl << "количество степеней числа N в данном наборе: " << j << endl << endl;
		}
		break;
		case 3:
		{
			int n, m;
			cout << "Enter number of rows and columns:" << endl;
			cin >> n >> m;
			int **pp = new int*[n];
			for (int i = 0; i < n; i++)
				pp[i] = new int[m];
			fill_matrix(pp, n, m);
			print_matrix(pp, n, m);
			int k;
			cout << "Enter number of the column to print K(1 <= K <= N)" << endl;
			cin >> k;
			cout << endl;
			printColumn(pp, n, k);
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}