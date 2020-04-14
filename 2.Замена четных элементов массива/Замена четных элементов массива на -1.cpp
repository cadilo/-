#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	int array[100];
	int n, p, tmp, t, r;
	
	cout << "¬ведите количество элементов массива: ";
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> array[i];
		if(array[i] % 2 == 0){
			array[i+1] = array[i];
			array[i] = -1;
			i++;
			n++;
		}
	}
	
	for(int i = 0; i<n; i++){
		cout << array[i] << " ";
	}
}
