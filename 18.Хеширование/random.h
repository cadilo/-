#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;
int hash_function(int k);

void** random(){
	setlocale(LC_ALL, "rus");
	//���������� � ������������� ����������� �������� ���
	string name_static[] = {"����", "����", "�����", "������", "����", "�������", "�����", "������", "�����", "��������", "����", "�������"};
	string surname_statick[] = {"������", "������", "�������", "�����", "����", "��������", "������", "���", "������", "�����", "�������", "�������"};
	string patronymics_statick[] = {"��������", "��������", "���������", "����������", "��������", "�����������", "���������", "����������", "��������", "���������", "������������", "��������"};
	//���������� ������������ ��������, ���� �� ������� ��� � ����������� ���
	//����� ������� ��� 30 ��������(������� ������� ����� ����)

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
	//���������� � ������������� ������ ����� � ����� �� ���
/*
	int *nomer_scheta = new int[102];
	long *summa = new long[102];
*/
	//���������� ������������ ��������
	for(int i = 0; i < 12; i++){
		((string*)array_arrayev[0])[i] = name_static[i];
		((string*)array_arrayev[1])[i] = surname_statick[i];
		((string*)array_arrayev[2])[i] = patronymics_statick[i];
		//cout << name_dynamick[i] << " " << surname_dynamick[i] << " " << patronymics_dynamick[i] << endl; //����� ���� ��� �����������
	}
	
	cout << " --------------------------------------------" << endl;
	cout << "|���:                             |�   |�����|"<< endl;
	cout << " --------------------------------------------" << endl;
		int rand_name;
		int rand_surname;
		int rand_patronymics;
	for(int i = 0; i < 102; i++){
		rand_name = rand()%12;
		rand_surname = rand()%12;
		rand_patronymics = rand()%12;
		((int*)array_arrayev[3])[i] = rand()%9000+1000;
		//���������� � ��������� ����� �� �����
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
	cout << "���-����  |  ����" << endl;
	
	for (int i = 0; i < 102; i++){
		cout << ((int*)tabl[0])[i] << " " << ((int*)tabl[1])[i] << endl;
	}
	cout << "������� ����: ";
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
