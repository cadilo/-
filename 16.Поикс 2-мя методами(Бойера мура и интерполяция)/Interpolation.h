#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void interpolation(){
	srand(time(NULL));
	int *MY_ARRAY = new int[1000];
	int x = 0;                         //Текущая позиция массива, с которым сравниваем искомое
	int a = 0;                         //Левая граница области, где ведется поиск
	int b = 999;                      //Правая граница области, где ведется поиск
	bool found = false;
	for(int i = 1; i < 1000; i++){
		MY_ARRAY[i] = rand()%1000+1;
		cout << MY_ARRAY[i] << " ";
	}
	cout << endl;
	
	cout << "Введите значение которое хотите найти(От 0 до 100): ";
	int search_number;
	cin >> search_number;
	
	for(int i = 0; i < 1000; i++){
		for(int j = i; j > 0 && MY_ARRAY[j-1] > MY_ARRAY[j]; j--){
			swap(MY_ARRAY[j-1], MY_ARRAY[j]);
		}
	}
	
	for(int i = 0; i < 999; i++){
		cout << MY_ARRAY[i] << " ";
	} 
	cout << endl;
	
	
	for (found = false; (MY_ARRAY[a] < search_number) && (MY_ARRAY[b] > search_number) && !found; )
 	{
 		x = a + ((search_number - MY_ARRAY[a]) * (b - a)) / (MY_ARRAY[b] - MY_ARRAY[a]);
 		if (MY_ARRAY[x] < search_number)   
 		a = x + 1;
 		else if (MY_ARRAY[x] > search_number)   
 		b = x - 1;
 		else
 		found = true;
 	}
	
	cout << x << endl;
	
	if (MY_ARRAY[a] == search_number){	
		cout << search_number << " найден в элементе " << a << endl;
	}
 	else if (MY_ARRAY[b] == search_number){
 		cout << search_number << " найден в элементе " << b << endl;
 	}
 	else{
 		cout << "Не найден" << endl;
 	}
 	delete MY_ARRAY;
}
