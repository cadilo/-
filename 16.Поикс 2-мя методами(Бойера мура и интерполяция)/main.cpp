#include <iostream>
#include "Boera-Mura.h"
#include "Interpolation.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int k;
	do{
		cout << " -----------------------" << endl; 
		cout << "|1.������-����          |" << endl;
		cout << "|2.������������         |" << endl;
		cout << "|3.�����                |" << endl;
		cout << "|-----------------------|" << endl;
		cout << "|�������� ����� ������: |" << endl;
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
