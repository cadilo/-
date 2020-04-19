#include <iostream>
#include "Containers.cpp"

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	
	cout << "Введите количество элементов массива: ";
	int size_arr;
	cin >> size_arr;
	VECTOR vector(size_arr);
	
	
	for(int i = 0; i < size_arr; i++){
		vector[i] = i+1;
	}
	cout << "Массив после добавления числа в заданный участок: ";
	vector.insertBefore(5, 7);
	for (int j=0; j<vector.getLength(); j++) cout << vector[j] << " ";
	cout << endl;
	cout << "Массив после умножения всех элементов на 10: ";
	vector*10;
	for (int j=0; j<vector.getLength(); j++) cout << vector[j] << " ";
	cout << endl;
	
	cout << "Кол-во элементов массива" << endl;
	int size = (vector(size_arr-1));
	cout << size - 1 << endl;
	int n;
	cout << "Переход влево к элементу с номером n: ";
	cin >> n;
	vector - n;
	for(int i = 0; i < n; i++){
		cout << vector[i] << " ";
	}
	cout << endl;
	
	system("pause");
	
	return 0;
}
