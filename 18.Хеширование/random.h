#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;
int hash_function(int k);

void** random(){
	setlocale(LC_ALL, "rus");
	//Объявление и инициализация статических массивов ФИО
	string name_static[] = {"Иван", "Петр", "Сидор", "Никола", "Илон", "Альберт", "Исаак", "Роберт", "Иосиф", "Владимир", "Карл", "Алексей"};
	string surname_statick[] = {"Иванов", "Петров", "Сидоров", "Тесла", "Маск", "Эйнштейн", "Ньютон", "Гук", "Сталин", "Ленин", "Смирнов", "Соболев"};
	string patronymics_statick[] = {"Иванович", "Петрович", "Сидорович", "Николаевич", "Илонович", "Альбертович", "Исаакович", "Робертович", "Маркович", "Иосифович", "Владимирович", "Карлович"};
	//Объявление динамических массивов, того же размера что и статические ФИО
	//Самое длинное ФИО 30 символов(Включая пробелы между ними)

	void** array_arrayev = new void*[5];
	array_arrayev[0] = new string[12];
	array_arrayev[1] = new string[12];
	array_arrayev[2] = new string[12];
	array_arrayev[3] = new int[102];
	array_arrayev[4] = new long[102];

/*	string *name_dynamick = new string[12];
	string *surname_dynamick = new string[12];
	string *patronymics_dynamick = new string[12];
*/
	//Объявление и генерирование номера счета и суммы на нем
/*
	int *nomer_scheta = new int[102];
	long *summa = new long[102];
*/
	//Заполнение динамических массивов
	for(int i = 0; i < 12; i++){
		((string*)array_arrayev[0])[i] = name_static[i];
		((string*)array_arrayev[1])[i] = surname_statick[i];
		((string*)array_arrayev[2])[i] = patronymics_statick[i];
		//cout << name_dynamick[i] << " " << surname_dynamick[i] << " " << patronymics_dynamick[i] << endl; //Вывод того что заполнилось
	}
	
	cout << " --------------------------------------------" << endl;
	cout << "|ФИО:                             |№   |сумма|"<< endl;
	cout << " --------------------------------------------" << endl;
		int rand_name;
		int rand_surname;
		int rand_patronymics;
	for(int i = 0; i < 102; i++){
		rand_name = rand()%12;
		rand_surname = rand()%12;
		rand_patronymics = rand()%12;
		((int*)array_arrayev[3])[i] = rand()%9000+1000;
		//Объявление и генерация суммы на счету
		((long*)array_arrayev[4])[i] = rand()%99999+11111;
		cout << "|" << 	((string*)array_arrayev[0])[rand_name] << " " <<  	((string*)array_arrayev[1])[rand_surname] << " " << 	((string*)array_arrayev[2])[rand_patronymics];
		for(int j = 0; j < 31 - (((string*)array_arrayev[0])[rand_name].length() +	((string*)array_arrayev[1])[rand_surname].length() + ((string*)array_arrayev[2])[rand_patronymics].length()); j++){
			cout << " ";
		}
		cout << "|" << ((int*)array_arrayev[3])[i] << "|" << ((int*)array_arrayev[4])[i] << "|" << endl;
		cout << " --------------------------------------------" << endl;
	}
	int *e = new int[102];
	
	for(int i = 0; i < 102; i++){
		e[i] = hash_function((((int*)array_arrayev[3])[i]));
		//cout << e[i] << endl;
	}
	
	int** tabl;
	tabl[0] = e;	
	tabl[1] = new int[102];
	
	for(int i = 0; i < 102; i++){
		int t = ((int*)array_arrayev[3])[i];
		((int*)tabl[1])[i] = t;
	}
	cout << " ----------------" << endl;
	cout << "Хеш-ключ  |  ключ" << endl;
	
	for (int i = 0; i < 102; i++){
		cout << ((int*)tabl[0])[i] << " " << ((int*)tabl[1])[i] << endl;
	}
	cout << "Введите ключ: ";
	int key;
	cin >> key;
	int hash_key = hash_function(key);
	
	for(int i = 0; i < 102; i++){
		if(hash_key == ((int*)tabl[0])[i]){
				cout << "|" << 	((string*)array_arrayev[0])[rand_name] << " " <<  	((string*)array_arrayev[1])[rand_surname] << " " << 	((string*)array_arrayev[2])[rand_patronymics];
		for(int j = 0; j < 31 - (((string*)array_arrayev[0])[rand_name].length() +	((string*)array_arrayev[1])[rand_surname].length() + ((string*)array_arrayev[2])[rand_patronymics].length()); j++){
			cout << " ";
		}
		cout << "|" << ((int*)array_arrayev[3])[i] << "|" << ((int*)array_arrayev[4])[i] << "|" << endl;
		}
		else{
		}
	}
	
	return array_arrayev;
}


int hash_function(int k){
	
	int j = k*k;
	j = j / 100;
	int H = j % 1000;
	return H;
}
