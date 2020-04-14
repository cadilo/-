#include <iostream>
#include "point.h"
#include "point2.h"
using namespace std;


int main(){
	setlocale(LC_ALL, "rus");
	int a, k, d;                                                             //k - количество элементов для однонаправленного списка
																			 //d - количество элементов для двунаправленного списка
	pole* bg;
	pole* bg1;
	point2* bg2;
	point2* bg3;
	do{
		cout << " --------------------------" << endl;
		cout << "|1.Однонаправленный список.|" << endl;
		cout << "|2.Двунаправленный список. |" << endl;
		cout << "|3.Выход.                  |" << endl;
		cout << " --------------------------" << endl;
		cout << "|Выберите действие         |" << endl;
		cout << " --------------------------" << endl;
		cin >> a;
		switch(a){
			case 1: cout << "Введите количество элементов" << endl;
					cin >> k;
					bg = unknow(k);
					print_list(bg);
					cout << endl << "Список после удаления элементов с четным номером: " << endl;
					bg1 = new_unknow(bg, k);
					print_list(bg1);
					cout << endl;
					break;
			case 2: cout << "Введите количество элементов в списке: ";
					cin >> d;
					bg2 = male_list(d);
					print_list2(bg2);
					cout << endl;
					bg3 = add_point(bg2, d);
					print_list2(bg3);
					cout << endl;
					break;
			case 3: break;
			default: cout << "Действия под таким номером нет! Введите правильное число!" << endl;
					break;
		}
	}while(a != 3);
}
