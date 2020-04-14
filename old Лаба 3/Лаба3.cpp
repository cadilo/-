#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Statick(){  																	//Решение через статический массив
	srand(time(NULL));
	int C = 0;																		//Объявили счетчик четных чисел
	bool nol = false;
	int n = rand()%20;																//Создали рандомное число n для размера массива 
	cout << "Количество элементов массива " << n << endl;
	int array[n];																	//Создали сам статический массив
	int i = 0;
	while (i < n){                                  								// Заполнили массив случайными числами
		array[i] = rand() % 10;
		cout << array[i] << " ";
		i++;
	}
	cout << endl;
	cout << "Массив после удаления первого элемента равного 0: \n";  				// Удалили первый элемент массива равный 0
	for(int i = 0; i < n; i++){
		for(int i = 0; i < n; i++){
			if(array[i] == 0 && nol == false){
				while (i < n - 1){
					array[i] = array[i+1];
					i++;
				}
				n--;
				nol = true;
				break;
			}
		}		
	}
		for (int i=0; i<n; i++){													// Вывели массив
			cout<< array[i] <<' ';
		}	
		
		cout << endl;
	
	
	for(int i = 0; i < n; i++){             										//Посчитали сколько четных
		if(array[i] % 2 == 0 && array[i] != 0){
			C++;
		}
	}
	
	
	int newArray[n+C];																//Создали массив с тем же количеством, но плюсом четные
	
	for(int i = 0, j = 0; i < n, j < n + C; i++, j++){
		if(array[i] % 2 != 0){
			newArray[j] = array[i];
		}
		else{
			newArray[j] = array[i];
			j++;
			newArray[j] = newArray[j - 2] + 2;
			
		}
	}
	cout << "Массив после добавления элементов со значением M[I-1] + 2." << endl;
	for(int j = 0; j < n+C; j++){													//Вывели полученный массив
		cout << newArray[j] << " ";
	}
		
}

void Dynamic(){																		//Решение через динамический массив
	srand(time(NULL));
	int C = 0;	
	bool nol = false;
	int n = rand()%20;
	cout << "Количество элементов массива " << n << endl;
	int *array = new int[n];
	int i = 0;
	while (i < n){                                   
		array[i] = rand() % 10;
		cout << array[i] << " ";
		i++;
	}
	cout << endl;
	cout << "Массив после удаления первого элемента равного 0: \n";  				// Удалили первый элемент массива равный 0
	for(int i = 0; i < n; i++){
		for(int i = 0; i<n; i++){
			if(array[i] == 0 && nol == false){
				while (i < n - 1){
					array[i] = array[i+1];
					i++;
				}
				n--;
				nol = true;
				break;
			}
		}		
	}
	for (int i=0; i<n; i++){
		cout<< array[i] <<' ';
	}
	cout << endl;
	
	
	for(int i = 0; i < n; i++){             										//Посчитали сколько четных
		if(array[i] % 2 == 0 && array[i] != 0){
			C++;
		}
	}
	
	
	int *newArray = new int[n+C];													//Создали динамический массив с тем же количеством, но плюсом четные
	
	for(int i = 0, j = 0; i < n, j < n + C; i++, j++){
		if(array[i] % 2 != 0){
			newArray[j] = array[i];
		}
		else{
			newArray[j] = array[i];
			j++;
			newArray[j] = newArray[j - 2] + 2;
			
		}
	}
	cout << "Массив после добавления элементов со значением M[I-1] + 2." << endl;
	for(int j = 0; j < n+C; j++){
		cout << newArray[j] << " ";
	}
	delete[] array;
	delete[] newArray;
	
}

int main(){																			//Менюшка
	setlocale(LC_ALL, "rus");
	string rts;
	bool p = false;
	cout << "Выберите способ решения (statick/dynamick): ";
	while(p == false){
		cin >> rts;
		if(rts == "statick"){
			cout << "Вы выбрали метод решения через статический массив. Количество элементов массива получается рандомным\n";
			p = true;
			Statick();
		}
		else if(rts == "dynamick"){
			cout << "Вы выбрали метод решения через динамический массив. Количество элементов массива получается рандомным\n";
			p = true;
			Dynamic();
		}
		else{
			cout << "Вы неверно ввели способ решения! Напишите правильно!" << endl;
	}
	}
}
