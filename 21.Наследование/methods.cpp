#include <iostream>
using namespace std;

class users_class{
	public: 
		int first;									//������ ����������
		int second;									//������ ���������
	
	users_class(){									//����������� ��� ����������
		first = 1;
		second = 2;
	}
	
	constructor2(int first, int second){			//����������� � �����������
		int new_first = first;
		int new_second = second;
	}
	
	constuctor3(users_class& b){					//����������� �����������
		int new_first = b.first;
		int new_second = b.second;
	}
	
/*	void init(int F, int S){						//������������� ������ ��� ������������� ����������
		int first = F;
		int second = S;
	}
*/	
	void change(){									//������������� ������ ��� ��������� �����
		cout << "������� ����� �������� first � second: ";
		cin >> first >> second;
	}
	
	void print(){
		cout << "first: " << first << endl;
		cout << "second: " << second << endl;
	}
	
	int composition(int F, int S){					//������������� ������ ��� ���������� ������������ ���� �����
		return F*S;
	}
	
	double composition(double F, double S){			//���������� �������� ���������
		return F*S;
	}
	
	
	~users_class(){};								//���������� ������
};

class RECTANGLE: public users_class{
	public:
		int Area(int first, int second){
			return first*second;
		}
		
		int perimetr(int first, int second){
			return (first + second)*2;
		}	
	};


