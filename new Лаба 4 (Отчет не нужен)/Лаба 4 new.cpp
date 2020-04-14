#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int dimensional_massive(){
	int e = rand()%30+10;
	int even_number_counter = 0;
	cout << "Количество элементов массива " << e << endl;
	int *array1 = new int[e];
	cout << "Сам массив ";
	for(int i = 0; i < e; i++){
		array1[i] = rand()%50-10;
		if(array1[i]%2 == 0){
			even_number_counter++;
		}
		cout << array1[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "Количество четных элементов в массиве: " << even_number_counter << endl;
	cout << "Массив после удаления четных элементов: " << endl;
	int *array2 = new int[e - even_number_counter];
	for(int i = 0; i < e; i++){
		if(array1[i]%2 == 0){
		}
		else{
			array2[i] = array1[i];
			cout << array2[i] << " ";
		}
	}
	
	cout << endl;
	cout << endl;
}
int two_dimensional_massive(){
	int p = rand()%10+1;
	int q = rand()%10+1;
	int m = 0;
	int g, z, k = 0;
	int t = 0;
	int l = 1;
	cout << "Количество строк в массиве: " << p << endl;
	cout << "Количество столбцов в массиве: " << q << endl;
	int **array1 = new int*[p];
	
	for(int i = 0; i < p; i++){
		array1[i] = new int[q];
	}
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			array1[i][j] = rand()%9;
			if(i == p-1){
				if((j + 1) % 2 == 0){
					m++;
				}
			}
		}
	}
	 
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < q; j++){
			cout << array1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Количество четных столбцов в массиве: " << m << endl;	
	
	while(t < m){
		int *chet_mass = new int[p];	
		for(int i = 0; i < p; i++){
			for(int j = 0; j < q; j++){
				if(j == l){
					chet_mass[k] = array1[i][j];
					k++;
				}
			}
		}
		
		for(int i = 0; i < k/2; i++){
			g = k - 1 - i;
			z = chet_mass[g];
			chet_mass[g] = chet_mass[i];
			chet_mass[i] = z;
		}
		
		k = 0;
		for(int i = 0; i < p; i++){
			for(int j = 0; j < q; j++){
				if(j == l){
					array1[i][j] = chet_mass[k];
					k++;
				}
			}
		}
		delete[] chet_mass;
		l = l+2;
		t++;
	}
	cout << endl;
	for(int i = 0; i < p; i++){
			for(int j = 0; j < q; j++){
				cout << array1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
}

int strong(string str){
					int z = 0;
					char* ert = new char[str.length()];
					int r = str.length();
					for(int i = 0; i < r; i++){
						ert[i] = str.at(i);
						if(ert[i] == ' ' && ert[r - 1] != ' '){
							z++;
						}
					}
					return z;
					
}
	
int main(){
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	string str;
	int n;
	do{
		cout << "1. Одномерный массив\n";
		cout << "2. Двумерный массив\n";
		cout << "3. Строки\n";
		cout << "4. Выход\n";
		cin >> n;
		switch(n){
			case 1: dimensional_massive(); break;
			case 2: two_dimensional_massive(); break;
			case 3: 
					cin.ignore();
					getline(cin, str);
					cout << "В тексте " << strong(str) + 1<<  " слова" << endl;
					break;
			case 4: break;
		}
	}
	while(n!=4);
}
