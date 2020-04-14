#include <iostream>
#include <cstdlib>
#include "random.h"

using namespace std;

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	random();
	
	return 0;
}
