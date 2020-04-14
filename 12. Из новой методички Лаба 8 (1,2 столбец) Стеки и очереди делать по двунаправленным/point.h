#include <iostream>
using namespace std;

struct pole{
	double information_pole; //Информационное поле
	pole* next;				 //Адресное поле
};

pole* unknow(int k){
	pole* beg;//Указатель на первый элемент
	pole *n, *m;//Вспомогательные элементы
	beg = new(pole);
	cout << "\n->";
	cin >> beg->information_pole;//Вводим значение информационного поля
	beg->next = 0;//Обнуляем адресное поле
	n=beg;		  //Ставим на этот элемент указатель n (Последний элемент)
	for(int i = 0; i < k - 1; i++){
		m = new(pole); //Создали новый элемент
		cout << "\n->";
		cin >> m->information_pole;
		m->next = 0;
		n->next = m;
		n = m;
	}
	return beg;
}

pole* new_unknow(pole* bg, int k){
	pole* beg;
	pole* p,*p1, *r;//вспомогательные указатели
	beg = new(pole);//выделяем память под первый элемент
	beg->information_pole=bg->information_pole;//вводим значение информационного поля
	beg->next = 0;//обнуляем адресное поле
	//ставим на этот элемент указатель p (последний элемент)
	p = beg;
	p1 = bg;
	for(int i = 0; i < k - 1; i++){
		p1 = p1->next;
		if (i % 2 != 0) {
			r = new(pole);//создаем новый элемент
			r->information_pole = p1->information_pole;
			r->next = 0;
			p->next = r;//связываем p и r
			//ставим на r указатель p (последний элемент)
			p = r;
		}
	}
	return beg;
}

void print_list(pole* beg){
	pole* n = beg;
	while(n != 0){
		cout << n->information_pole << "\t";
		n = n->next;
	}	
}

pole* delete_element(pole* beg, int k){
	for(int i = 0; i < k; i++){
		pole* t = beg;
		beg=beg->next;
		delete t;
		return beg;
	}
}
