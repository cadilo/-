#include <iostream>

using namespace std;
int fun(int, int); //�������� fun
int complex_recursion2(int, int); //�������� complex_recursion2
int complex_recursion1(int, int); //�������� complex_recursion1


int fun_input(int n){
	cout << "����� ����� ������� ������ �����������: ";
	cin >> n;
	return n;
}

int fun(int n, int rev){
	if(n > 0){
		rev=n%10;
    	if(rev==0) rev=n%10;
    	n=n/10;
    	cout<<rev;
    	fun(n, rev);
	}
}

int complex_recursion1(int n, int rev){
	if(n > 0){
		rev=n%10;
    	if(rev==0) rev=n%10;
    	n=n/10;
    	cout << rev;
    	complex_recursion2(n, rev);
	}
}

int complex_recursion2(int n, int rev){
	if(n > 0){
		rev=n%10;
    	if(rev==0) rev=n%10;
    	n=n/10;
    	cout<<rev;
    	complex_recursion1(n, rev);
	}
}

tail_recursion(int n, int rev){
	if(n > 0){
	    rev=n%10;
    	if(rev==0) rev=n%10;
    	n=n/10;
    	cout << rev;
	}
	return tail_recursion(n, rev);
}

int main(){
	setlocale(LC_ALL, "rus");
	int k, n = 0;
	int rev = 0;
	do{
		cout << "1.������� ��������." << endl;
		cout << "2.������� ��������." << endl;
		cout << "3.��������� ��������." << endl;
		cout << "4.�����" << endl;
		cin >> k;
		switch(k){	
			case 1: 
					n = fun_input(n);
					fun(n, rev);
					cout << endl;
					break;
			case 2: 
					n = fun_input(n);
					complex_recursion1(n, rev);
					cout << endl;
					break;
			case 3: 
					n = fun_input(n);
					tail_recursion(n, rev);
					cout << endl;
					break;
			case 4: break;
		}
	}
	while(k != 4);
	
	return 0;
}
