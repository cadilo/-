#include <iostream>
#include "sort_stack.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	stack <int> intoviy_stack;
	cout << "Сколько хочешь элементов в стэке? " << endl;
	int number;
	cin >> number;
	intoviy_stack = make_stack(number);
	sort_stack(intoviy_stack, number);
	return 0;
}
