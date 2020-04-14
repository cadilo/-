#include <iostream>
#include "Boera-Mura.h"
#include "Interpolation.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int k;
	do{
		cout << " -----------------------" << endl; 
		cout << "|1.Бойера-Мура          |" << endl;
		cout << "|2.Интерполяция         |" << endl;
		cout << "|3.Выход                |" << endl;
		cout << "|-----------------------|" << endl;
		cout << "|Выберите метод поиска: |" << endl;
		cout << " -----------------------" << endl;
		cin >> k;
		switch(k){
			case 1: array_struct();
					break;
			case 2: interpolation();
					break;
		}
	}while(k != 3);
}
