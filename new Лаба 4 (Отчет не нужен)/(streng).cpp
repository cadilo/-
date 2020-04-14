#include <iostream>
#include <string.h>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	string str;
	getline(cin, str);
	int n = 0;
	char* ert = new char[str.length()];
	for(int i = 0; i < str.length(); i++){
		ert[i] = str.at(i);
		if(ert[i] == ' '){
			n++;
		}
	}
	cout << "В тексте " << n + 1 << " слов" << endl;
}
