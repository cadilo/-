#include <iostream>
#include "point.h"
using namespace std;


void point::init(int F, int S){
	int first = F;
	int second = S;
}

void point::read(){
	cout << "first?" << endl;
	cin >> first;
	cout << "second?" << endl;
	cin >> second;
}

void point::print(){
	cout << "first: " << first << endl;
	cout << "second: " << second << endl;
}

int point::summa(){
	return first*second;
}
