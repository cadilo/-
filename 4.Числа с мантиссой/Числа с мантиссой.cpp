#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int N;
	cout << "¬ведите количество элементов в массиве: ";
	cin >> N;
	void **mass = new void*[2];
	mass[0] = new int[N];
	mass[1] = new float[N]; 
	for(int i = 0; i < N; i++){
		cin >> ((int*)mass[0])[i] >> ((float*)mass[1])[i];
	}
	for(int i = 0; i < N; i++){
		cout  << '\t' << ((int*)mass[0])[i] << '\t' << ((float*)mass[1])[i] << endl;
	}
}
