#include <iostream>
#include "point.h"
#include "point2.h"
using namespace std;


int main(){
	setlocale(LC_ALL, "rus");
	int a, k, d;                                                             //k - ���������� ��������� ��� ����������������� ������
																			 //d - ���������� ��������� ��� ���������������� ������
	pole* bg;
	pole* bg1;
	point2* bg2;
	point2* bg3;
	do{
		cout << " --------------------------" << endl;
		cout << "|1.���������������� ������.|" << endl;
		cout << "|2.��������������� ������. |" << endl;
		cout << "|3.�����.                  |" << endl;
		cout << " --------------------------" << endl;
		cout << "|�������� ��������         |" << endl;
		cout << " --------------------------" << endl;
		cin >> a;
		switch(a){
			case 1: cout << "������� ���������� ���������" << endl;
					cin >> k;
					bg = unknow(k);
					print_list(bg);
					cout << endl << "������ ����� �������� ��������� � ������ �������: " << endl;
					bg1 = new_unknow(bg, k);
					print_list(bg1);
					cout << endl;
					break;
			case 2: cout << "������� ���������� ��������� � ������: ";
					cin >> d;
					bg2 = male_list(d);
					print_list2(bg2);
					cout << endl;
					bg3 = add_point(bg2, d);
					print_list2(bg3);
					cout << endl;
					break;
			case 3: break;
			default: cout << "�������� ��� ����� ������� ���! ������� ���������� �����!" << endl;
					break;
		}
	}while(a != 3);
}
