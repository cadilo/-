#include <iostream>
#include "methods.cpp"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");																				//Подключили русский язык
	int n;																									//Объявили переменную n для менюшки
	int proizvedenie, area, Perimetr;
	users_class method;																						//Объявили метод нашего класса
	RECTANGLE gh;
	do{
		cout << "Переменные инициализированы как: " << method.first << " и " << method.second << endl;		//Собственно сама менюшка
		cout << "1.Поменять значение переменных" << endl;
		cout << "2.Вычислить произведение двух чисел" << endl;
		cout << "3.Вычислить площадь и перимерт прямоугольника с этими же сторонами" << endl;
		cout << "4.выход" << endl;
		cout << " --------------------------------------------------------------------" << endl;
		cin >> n;																							//Вводим наше значение
		switch(n){	
			case 1:
				method.change();																			//вызываем метод change класса method
				break;
			case 2:
				proizvedenie = method.composition(method.first, method.second);								//инициализируем переменную как результат возвращения метода composition
				cout << proizvedenie << endl;																//Выводим переменную
				break;
			case 3: 
					area = gh.Area(method.first, method.second);
					Perimetr = gh.perimetr(method.first, method.second);
					cout << "Площадь: " << area << endl;
					cout << "Периметр: " << Perimetr << endl;
					break;
		}
	}while(n != 4);
}

