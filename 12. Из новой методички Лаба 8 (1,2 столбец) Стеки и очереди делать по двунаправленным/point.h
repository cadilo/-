#include <iostream>
using namespace std;

struct pole{
	double information_pole; //�������������� ����
	pole* next;				 //�������� ����
};

pole* unknow(int k){
	pole* beg;//��������� �� ������ �������
	pole *n, *m;//��������������� ��������
	beg = new(pole);
	cout << "\n->";
	cin >> beg->information_pole;//������ �������� ��������������� ����
	beg->next = 0;//�������� �������� ����
	n=beg;		  //������ �� ���� ������� ��������� n (��������� �������)
	for(int i = 0; i < k - 1; i++){
		m = new(pole); //������� ����� �������
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
	pole* p,*p1, *r;//��������������� ���������
	beg = new(pole);//�������� ������ ��� ������ �������
	beg->information_pole=bg->information_pole;//������ �������� ��������������� ����
	beg->next = 0;//�������� �������� ����
	//������ �� ���� ������� ��������� p (��������� �������)
	p = beg;
	p1 = bg;
	for(int i = 0; i < k - 1; i++){
		p1 = p1->next;
		if (i % 2 != 0) {
			r = new(pole);//������� ����� �������
			r->information_pole = p1->information_pole;
			r->next = 0;
			p->next = r;//��������� p � r
			//������ �� r ��������� p (��������� �������)
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
