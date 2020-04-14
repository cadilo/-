#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Statick(){  																	//������� ����� ����������� ������
	srand(time(NULL));
	int C = 0;																		//�������� ������� ������ �����
	bool nol = false;
	int n = rand()%20;																//������� ��������� ����� n ��� ������� ������� 
	cout << "���������� ��������� ������� " << n << endl;
	int array[n];																	//������� ��� ����������� ������
	int i = 0;
	while (i < n){                                  								// ��������� ������ ���������� �������
		array[i] = rand() % 10;
		cout << array[i] << " ";
		i++;
	}
	cout << endl;
	cout << "������ ����� �������� ������� �������� ������� 0: \n";  				// ������� ������ ������� ������� ������ 0
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
		for (int i=0; i<n; i++){													// ������ ������
			cout<< array[i] <<' ';
		}	
		
		cout << endl;
	
	
	for(int i = 0; i < n; i++){             										//��������� ������� ������
		if(array[i] % 2 == 0 && array[i] != 0){
			C++;
		}
	}
	
	
	int newArray[n+C];																//������� ������ � ��� �� �����������, �� ������ ������
	
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
	cout << "������ ����� ���������� ��������� �� ��������� M[I-1] + 2." << endl;
	for(int j = 0; j < n+C; j++){													//������ ���������� ������
		cout << newArray[j] << " ";
	}
		
}

void Dynamic(){																		//������� ����� ������������ ������
	srand(time(NULL));
	int C = 0;	
	bool nol = false;
	int n = rand()%20;
	cout << "���������� ��������� ������� " << n << endl;
	int *array = new int[n];
	int i = 0;
	while (i < n){                                   
		array[i] = rand() % 10;
		cout << array[i] << " ";
		i++;
	}
	cout << endl;
	cout << "������ ����� �������� ������� �������� ������� 0: \n";  				// ������� ������ ������� ������� ������ 0
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
	
	
	for(int i = 0; i < n; i++){             										//��������� ������� ������
		if(array[i] % 2 == 0 && array[i] != 0){
			C++;
		}
	}
	
	
	int *newArray = new int[n+C];													//������� ������������ ������ � ��� �� �����������, �� ������ ������
	
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
	cout << "������ ����� ���������� ��������� �� ��������� M[I-1] + 2." << endl;
	for(int j = 0; j < n+C; j++){
		cout << newArray[j] << " ";
	}
	delete[] array;
	delete[] newArray;
	
}

int main(){																			//�������
	setlocale(LC_ALL, "rus");
	string rts;
	bool p = false;
	cout << "�������� ������ ������� (statick/dynamick): ";
	while(p == false){
		cin >> rts;
		if(rts == "statick"){
			cout << "�� ������� ����� ������� ����� ����������� ������. ���������� ��������� ������� ���������� ���������\n";
			p = true;
			Statick();
		}
		else if(rts == "dynamick"){
			cout << "�� ������� ����� ������� ����� ������������ ������. ���������� ��������� ������� ���������� ���������\n";
			p = true;
			Dynamic();
		}
		else{
			cout << "�� ������� ����� ������ �������! �������� ���������!" << endl;
	}
	}
}
