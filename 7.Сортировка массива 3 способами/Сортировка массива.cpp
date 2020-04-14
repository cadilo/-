#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int method_1(int *array1, const int k){
		
	for(int i = 0; i < k; i++){
		for(int j = i; j > 0 && array1[j-1] > array1[j]; j--){
			swap(array1[j-1], array1[j]);
		}
	}
	
	for(int i = 0; i < k; i++){
		cout << array1[i] << " ";
	} 
	cout << endl;
}

int method_2(int *array1, const int k){
	int min, str;
	for(int i = 0; i < k - 1; i++){
		min = i;
		
		for(int j = i + 1; j < k; j++){
			if(array1[j] < array1[min]){
				min = j;
			}
		}
		str = array1[i];
		array1[i] = array1[min];
		array1[min] = str;
	}
	
	for(int i = 0; i < k; i++){
		cout << array1[i] << " ";
	}
	cout << endl;
}

int method_3(int *array1, const int k){
	int tmp;
	for(int i = 0; i < k - 1; i++)
	{
		for(int j = 0; j < k - i - 1; j++)
		{
			if(array1[j] > array1[j + 1])
			{
				tmp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = tmp;
			}
		}
	} 
	
	
	for(int i = 0; i < k; i++){
	  	cout << array1[i] << " ";
	}
	cout << endl;
}

int main(){
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int k = rand() % 10 + 1;
	cout << "��� ������: ";
	int *array1 = new int[k];
		for(int i = 0; i < k; i++){
			array1[i] = rand()%10 + 1;
			cout << array1[i] << " ";
		}
	cout << endl;
	int n;
	do{
		cout << "1. ����� �������." << endl;
		cout << "2. ����� ������." << endl;
		cout << "3. ����� ��������." << endl;
		cout << "4. �����." << endl;
		cin >> n;
		switch(n){
			case 1: method_1(array1, k); break;
			case 2: method_2(array1, k); break;
			case 3: method_3(array1, k); break;
			case 4: break;
			default: cout << "Error" << endl;
		}
		
	}
	while(n != 4);
}
