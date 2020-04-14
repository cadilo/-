#include <iostream>
#include <string>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# define NO_OF_CHARS 256
using namespace std;

struct DATA{
	string F;
	string I;
	string O;
	char* account_number = new char[10];
	unsigned long int amount;
};

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void fill(DATA *p){
	cin >> p->F;
	cin >> p->I;
	cin >> p->O;
	cin >> p->account_number;
	cin >> p->amount;
}

void print_struct(DATA *p, int i){
	cout << p[i].F << endl;
	cout << p[i].I << endl;
	cout << p[i].O << endl;
	cout << p[i].account_number << endl;
	cout << p[i].amount << endl;
}

void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}

int BMSearch (char* search_account, DATA* p){
	DATA *ARRAY_STRUCT = p;
	for(int i = 0; i < 4; i++){
		if(p[i].account_number == search_account){
			print_struct(&ARRAY_STRUCT[i], i);
			cout << endl;
		}
	}
	
	int badchar[NO_OF_CHARS];																//(Пока непонятно)
	int m = strlen(search_account);															//m присвоили длину образа
	badCharHeuristic(search_account, m, badchar);											//Вызываем badCharHeuristic() и передаем в нее образ, длинну образа и ...
	
	for(int i = 0; i < 5; i++){
		int n = strlen(p[i].account_number);														//n присвоили длину строки
		//cout << n << endl;
		
	
		int s = 0; 
		//cout << "Таблица инициализирована." << endl;
		while (s <= (n - m))
		{
			int j = m - 1;
			while (j >= 0 && search_account[j] == p[i].account_number[s + j])
				//cout << j << " ";
				j--;
			if (j < 0)
			{
				cout << "Элемент найден!" << endl;
				//print_struct(&ARRAY_STRUCT[j], j);
				cout << p[i].F << endl;
				cout << p[i].I << endl;
				cout << p[i].O << endl;
				cout << p[i].account_number << endl;
				cout << p[i].amount << endl;
				cout << "\n картина происходит при смене = " <<  s  << endl;
				s += (s + m < n) ? m - badchar[ p[i].account_number[s + m]] : 1;
			}
			else{
				//cout << "Элемент не найден." << endl;
				s += max(1, j - badchar[ p[i].account_number[s + j]]);
			}
		}
	}
}

void array_struct(){
	DATA *ARRAY_STRUCT = new DATA[5];																	//Создали массив структур
	cout << "Введите ФИО, номер счета и сумму на этом счете: " << endl;									
	
	for(int i = 0; i < 5; i++){
		fill(&ARRAY_STRUCT[i]);																			//Заполнили массив структур, вызвав функцию fill 
		cout << endl;
	}
	char* search_account = new char[10];																				//Создали образ					
	cout << "Вы молодец! А теперь введите номер счета того, кого необходимо найти(ну, или хотя бы часть): ";
	cin >> search_account;																				//Ввели образ
	//cout << "Не его ищете?" << endl;
	BMSearch(search_account, *&ARRAY_STRUCT);
	
}




