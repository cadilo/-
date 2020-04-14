#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <list>
#include <Windows.h>
using namespace std;

struct EMPLOYEE{
	string family;
	string position;
	int year_born;
	int wage;
};

void fill(EMPLOYEE *p)
{
	cout << "�������: ";
	cin >> p->family;
	cout << "���������: ";
	cin >> p->position;
	cout << "��� ��������: ";
	cin >> p->year_born;
	cout << "���������� �����: ";
	cin >> p->wage;
}

void print_to_console(EMPLOYEE *p)
{
	cout << "�������: " << p->family << endl;
	cout << "���������: " << p->position << endl;
	cout << "��� ��������: " << p->year_born << endl;
	cout << "���������� �����: " << p->wage << endl;
}


int del(EMPLOYEE *p, int n, string r)
{
	for(int j = 0; j < n - 1; j++){
			if(p[j].family == r && j == 0){
				p[j] = p[j + 1];
				j++;
				p[j] = p[j + 1];
			}
			else if(p[j].family == r){
				p[j] = p[j + 1];
			}
	}
	n--;
	return n;
}

int dobav(EMPLOYEE *p, int n, int m, EMPLOYEE t)
{
	int match = -1;
	for (int i = 0; i < n; i++)
	{
		if (i == m - 1)
		{
			match = i + 1;
			break;
		}
	}
	if (match == -1)
		{
			match = n;
			cout << endl << "��� ���������� � ����� �������, ����� ��������� ����� �������� � ����� ������." << endl;
		}
	for (int i = n - 1; i > match; i--)
	{
		p[i] = p[i - 1];
	}
	p[match] = t;
	n++;
	return n;
}

int main()
{
	SetConsoleCP(1251); 	
	SetConsoleOutputCP(1251);
	int default_abit_arr_size = 3;
	int current_abit_arr_size = default_abit_arr_size;
	
	cout << "������� ������:" << endl;
	EMPLOYEE *abitur_arr = new EMPLOYEE[default_abit_arr_size];
	for (int i = 0; i < default_abit_arr_size; i++)
	{
		cout << "��������� �" << i + 1 << endl;
		fill(&abitur_arr[i]);
		cout << endl;
	}
	
	cout << "���������� ������ � �������:" << endl;
	cout << endl;
	for (int i = 0; i < current_abit_arr_size; i++)
	{
		cout << "��������� �" << i + 1 << endl;
		print_to_console(&abitur_arr[i]);
		cout << endl;
	}
	
	string family_to_delete;
	cout << "�� ����� ������� ������� ����������: ";
	cin >> family_to_delete;
	current_abit_arr_size = del(abitur_arr, current_abit_arr_size, family_to_delete);
	cout << endl;
	
	cout << "���������� ������ � ������� ����� ��������:" << endl;
	cout << endl;
	for (int i = 0; i < current_abit_arr_size; i++)
	{
		cout << "��������� �" << i + 1 << endl;
		print_to_console(&abitur_arr[i]);
		cout << endl;
	}
	cout << "���������� �����������: " << endl;
	EMPLOYEE new_abitur;
	fill(&new_abitur);
	int num_to_add_after;
	cout << "������� ����� ������ ������ �������� ������ �����������: ";
	cin >> num_to_add_after;
	current_abit_arr_size = dobav(abitur_arr, current_abit_arr_size, num_to_add_after, new_abitur);
	cout << endl;
	cout << "���������� ������ � ������� ����� ���������� ";
	cout << endl;
	for (int i = 0; i < current_abit_arr_size; i++)
	{
		cout << "��������� �" << i + 1 << endl;
		print_to_console(&abitur_arr[i]);
		cout << endl;
	}
	ofstream fout("����������\\����������.txt", ios::binary);
	if (fout.is_open())
	{
  		for (int i = 0; i < 2; i++){
    	fout.write((char*)&abitur_arr[i], sizeof(EMPLOYEE));
		}
  		fout.close(); 
	}
	
	EMPLOYEE *pEMPLOYEE = new EMPLOYEE[default_abit_arr_size];
	
	ifstream fin("����������\\����������.txt", ios::binary);	
	if (fin.is_open())
	{
		for (int i = 0; i < current_abit_arr_size; i++)
		fin.read((char*)&pEMPLOYEE[i], sizeof(pEMPLOYEE));
		fin.close(); 
	}
	cout << endl;
	
	cout << "���������� ������ � ������� ����� ������ ";
	cout << endl;
	for (int i = 0; i < current_abit_arr_size; i++)
	{
		cout << "��������� �" << i + 1 << endl; 
		print_to_console(&abitur_arr[i]);
		cout << endl;
	}
	return 0;
}
