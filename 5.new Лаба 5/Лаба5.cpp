#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int array1(){
	setlocale(LC_ALL, "rus");																			//������� array1() ���������� ��������� �������� n,
	srand(time(NULL));																					//������� �������� ���������� ��������� �������
	static int n = rand()%20;
	cout << "���������� ��������� ������� " << n << endl;
	return n;
}
int** rty(){
	int p = rand()%10;
	int q = rand()%10;
	cout << "���������� ����� � �������: " << p << endl;
	cout << "���������� �������� � �������: " << q << endl;
	int** matr = new int*[p];
	for (int i = 0; i < p; i++){
		matr[i] = new int[q];
	}
	
	for (int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			matr[i][j] = rand()%9;
		}
	}
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "������� ����� �������, ����� �������� ����� �������� ��� ���� �������: ";
	int er;
	cin >> er;
	er--;
	q++;
	int **newMass = new int*[p];
	for(int i = 0; i < p; i++){
		newMass[i] = new int[q];
	}
	for(int i = 0; i < p; i++){
		for(int j = 0, k = 0; j < q, k < q; j++, k++){
			if(j == er){
				newMass[i][j] = matr[i][k];
				j++;
				newMass[i][j] = rand()%10;
				}
				else{
					newMass[i][j] = matr[i][k];
				}
			}
		}
	
	
	for(int i = 0; i<p; i++){
		for(int j = 0; j<q; j++){
			cout << newMass[i][j] << " ";
		}
		cout << endl;	
	}
	return newMass;
}
int main(){
	setlocale(LC_ALL, "rus");																//������ ��������� 
	cout << "���������� ������������ ������: ";
	srand(time(NULL));
	bool nol = false;
	int size;
	size = array1();																		//���������� size ���������� �������� ������� array1()
	int *array = new int[size];																//������� ������������ ���������� ������ array � ����������� ��������� size
	cout << "��� ������: " << endl;
	for(int i = 0; i < size; i++){															
		array[i] = rand()%20 - 10;															//��������� ��� ������ ���������� ������� � �������
		cout << array[i] << " ";
	}	
	
	cout << endl;
	cout << "������ ����� �������� ������� �������������� ��������: " << endl;				//��� ������� ������ ������������� �������
	for(int i = 0; i < size; i++){
				if(array[i] < 0){
					while (i < size - 1){
						array[i] = array[i+1];
						i++;
					}
					size--;
					nol = true;
					break;
				}
					
		}
		
	for(int i = 0; i < size; i++){															//������� ������������ ������
		cout << array[i] << " ";
	}
	cout << endl << endl;
	cout << "��������� ������������ ������: " << endl;
	rty();

}
