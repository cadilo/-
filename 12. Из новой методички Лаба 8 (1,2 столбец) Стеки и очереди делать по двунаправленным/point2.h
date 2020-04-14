#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct point2{
	char* key;
	point2* next;
	point2* pred;
};

point2* make_point(){
	point2* p = new(point2);
	p->next = 0;
	p->pred = 0;
	char s[50];
	cout << "\nВведите строку: ";
	cin >> s;
	p->key = new char[strlen(s)+1]; //Выделение памяти под строку
	strcpy(p->key, s);
	return p;
}

point2* male_list(int n){
	point2 *p, *beg2;
	beg2 = make_point(); 
	for(int i = 0; i < n - 1; i++){
		p = make_point();
		p->next = beg2;
		beg2->pred = p;
		beg2= p;
	}
	return beg2;
}

void print_list2(point2* beg2){
	point2* r = beg2;
	while(r != 0){
		cout << r->key << "\t";
		r = r->next;
	}	
}

point2* add_point(point2* beg2, int n){
point2* p = beg2;
	point2* New = new(point2);
	char s[50];
	cout << "Введите новый элемент: ";
	cin >> s;
	int k;
	cout << "После элемента с каким номером добавить этот элемент? ";
	cin >> k;
	New->key = new char(strlen(s) + 1);
	strcpy(New->key, s);
	if (k == 0){
		New->next = beg2;
		beg2 = New;
		return beg2;
	}
	for (int i = 0; i < k - 1 && p != 0; i++)
	p = p->next;
	if (p != 0)
	{
		New->next = p->next;
		p->next = New;
	}
	return beg2;
}


