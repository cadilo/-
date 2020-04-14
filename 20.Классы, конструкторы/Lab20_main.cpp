#include <iostream>
#include "point.cpp"
using namespace std;

point make_point(long F, long S){
	point t;
	t.init(F, S);
	return t;
}

int main(){
	point A;
	point B;
	B.read();
	B.print();
	//cout <<  "A.summa(" << A.first << "," << A.second << ") = " << A.summa() << endl;
	cout <<  "B.summa(" << B.first << "," << B.second << ") = " << B.summa() << endl;
	point *X = new point;
	X->read();
	X->print();
	X->summa();
	cout << "X.summa(" << X->first << "," << X->second << ") = " << X->summa() << endl;
	point mass[3];
	for(int i = 0; i < 3; i++){
		mass[i].read();
	}
	for(int i = 0; i < 3; i++){
		mass[i].print();
	}
	for(int i = 0; i < 3; i++){
		mass[i].summa();
		cout << "mass[" << i << "].summa(" << mass[i].first << "," << mass[i].second << ") = " << mass[i].summa() << endl;
	}
	
	int y, x;
	cout << "first? " << endl;
	cin >> y;
	cout << "second? " << endl;
	cin >> x;
	
	point F = make_point(y, x);
	F.print();
	return 0;
}
