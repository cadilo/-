#include <iostream>
#include "methods.cpp"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");																				//���������� ������� ����
	int n;																									//�������� ���������� n ��� �������
	int proizvedenie, area, Perimetr;
	users_class method;																						//�������� ����� ������ ������
	RECTANGLE gh;
	do{
		cout << "���������� ���������������� ���: " << method.first << " � " << method.second << endl;		//���������� ���� �������
		cout << "1.�������� �������� ����������" << endl;
		cout << "2.��������� ������������ ���� �����" << endl;
		cout << "3.��������� ������� � �������� �������������� � ����� �� ���������" << endl;
		cout << "4.�����" << endl;
		cout << " --------------------------------------------------------------------" << endl;
		cin >> n;																							//������ ���� ��������
		switch(n){	
			case 1:
				method.change();																			//�������� ����� change ������ method
				break;
			case 2:
				proizvedenie = method.composition(method.first, method.second);								//�������������� ���������� ��� ��������� ����������� ������ composition
				cout << proizvedenie << endl;																//������� ����������
				break;
			case 3: 
					area = gh.Area(method.first, method.second);
					Perimetr = gh.perimetr(method.first, method.second);
					cout << "�������: " << area << endl;
					cout << "��������: " << Perimetr << endl;
					break;
		}
	}while(n != 4);
}

