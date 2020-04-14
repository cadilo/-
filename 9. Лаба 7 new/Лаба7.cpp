#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

void functions_silence(const string name = "Vladimir", const string family = "Glavatskih", int age = 18){
	cout << name << " " << family << " " << age << " " << endl;
}

void variable_number_of_parametres(int one, ...){
	int *z = &one; //Настроили указатель на параметр p
	int d = *z;  //Значение первого элемента присвоили d
	int next = *(z+2);
	int max;
	while(*z != 0){
		z++;
		if(next > max){
			max = next;
		}
		cout << d << " ";
		d = *(++z);
		next = *(z+2);
	}
	
	cout << "Максимальный элемент " << max << endl;
}


int array(int quantity_elements, int number_of_negative_elements){
	int *array1 = new int[quantity_elements];
	for(int i = 0; i < quantity_elements; i++){
		array1[i] = rand()%20-10;
	}
	
	for(int i = 0; i < quantity_elements; i++){
		cout << array1[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < quantity_elements; i++){
		if(array1[i] < 0){
			number_of_negative_elements++;
		}
	}
	cout << number_of_negative_elements << endl;
	return number_of_negative_elements;
}

double array(int quantity_elements, double number_of_negative_elements){
	float *array1 = new float[quantity_elements];
	
	for(int i = 0; i < quantity_elements; i++){
		array1[i] = rand()%20-10;
	}
	
	for(int i = 0; i < quantity_elements; i++){
		cout << array1[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < quantity_elements; i++){
		if(array1[i] < 0){
			number_of_negative_elements++;
		}
	}
	cout << number_of_negative_elements << endl;
	return number_of_negative_elements;
}

template <class t>
t array_template(t quantity_elements, t number_of_negative_elements){
	t *array1 = new t[quantity_elements];
	
	for(int i = 0; i < quantity_elements; i++){
		array1[i] = rand()%20-10;
	}
	
	for(int i = 0; i < quantity_elements; i++){
		cout << array1[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < quantity_elements; i++){
		if(array1[i] < 0){
			number_of_negative_elements++;
		}
	}
	cout << number_of_negative_elements << endl;
	return number_of_negative_elements;
}	


int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int n;
	int quantity_elements = rand()% 20 + 5;
	int quantity_elements1 = rand()% 20 + 5;
	int number_of_negative_elements = 0;
	int number_of_negative_elements1 = 0;
	do{
		cout << " -------------------------------------------" << endl;
		cout << "|1. Функция с умалчиваемыми параметрами.    |" << endl;
		cout << "|2. Функция с переменным числом параметров. |" << endl;
		cout << "|3. Перегрузка функции.                     |" << endl;
		cout << "|4. Шаблон функции.                         |" << endl;
		cout << "|5. Выход.                                  |" << endl;
		cout << " -------------------------------------------" << endl;
		cin >> n;
		switch(n){
			case 1:  functions_silence();
					 functions_silence("Vova");
					 functions_silence("Vova", "NEGlavatskih", 20);
					 break;
			case 2:  variable_number_of_parametres(1, 2, 4, 3, 0);
					 variable_number_of_parametres(3, 9, 0, 1, 56, 4, 0);
					 
					 break;
			case 3: array(quantity_elements, number_of_negative_elements);
					array(quantity_elements1, number_of_negative_elements1);
					break;
			case 4: array_template(quantity_elements, number_of_negative_elements);
					break;
			case 5: break;
		}
	}while(n != 5);
}
