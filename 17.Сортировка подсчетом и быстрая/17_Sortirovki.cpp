#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int* init(int n)
{
	int* mas = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 50;		
	}
	return mas;
}
void print(int n, int *mas)
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}

void counting(int n,int *mas)
{
	const int k = 50;
	int c[k] = { 0 };
	for (int i = 0; i < n; i++) {
		c[mas[i]] = c[mas[i]] + 1;
	}

	int b = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < c[i]; j++) {
			mas[b] = i;
			b = b + 1;
		}
	}
}

void qsort(int* mas, int n) 
{
	int i = 0;
	int j = n - 1;
	int mid = mas[n / 2];
	do 
	{
		while (mas[i] < mid) 
		{
			i++;
		}	
		while (mas[j] > mid) 
		{
			j--;
		}
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) 
	{
		qsort(mas, j + 1);
	}

	if (i <n) 
	{
		qsort(&mas[i], n - i);
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n, k=0;	
	cout << "Введите количество элементов в массиве:";
	cin >> n;
	int* mas = init(n);
	do
	{
		cout << "-------------------------\n";
		cout << "1. Вывести массив на экран\n" << "2. Сортировка подсчетом\n" << "3. Быстрая сортировка\n" << "4. Выход\n";
		cout << "-------------------------\n";
		cin >> k;
		switch (k)
		{		
		case 1:
			print(n, mas);	
			break;
		case 2:
			counting(n, mas);
			break;
		case 3:
			qsort(mas, n);
			break;
		}
	} while (k != 4);
	system("pause");
}
	
