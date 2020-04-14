#include <iostream>
using namespace std;

int main(){
	string name;
	cin >> name;
	int *ascii_mass = new int[name.length()];
	for(int i = 0; i < name.length(); i++){
		ascii_mass[i] = name[i];
		cout << ascii_mass[i] << " ";
	}
}
