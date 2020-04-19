#include <iostream>
#include <cassert> // для assert()
using namespace std;
class VECTOR 
{
	protected: 
		int *arr;		//Объявление массива
		int size;		//Объявление колличество элементов массива	
		
	public: 
		VECTOR(): size(0), arr(NULL){}
		
	
		VECTOR(int _size):size(_size){
			assert(_size >= 0);
			
			if(_size > 0) arr = new int[_size];
			else arr = NULL;
		}
		
		int getLength() { return size; }
		//Перегрузка оператора []
		int& operator[](int index);
    	//Перегрузка оператора ()
    	int operator()(int arr);
		//Перегрузка оператора *h
		int* operator * (int h);
		//Перегрузка оператора -n
		int* operator - (int n);
		
		//добавление элемента после заданного номера
		void insertBefore(int value, int index);
	
	
		
		~VECTOR(){
			delete[] arr;						//Деструктор очищающий память массива
		}	
};


class Integer
{
protected:
	int num;

public:
	Integer() {};
	Integer(int _num) : num(_num) {};

	friend istream& operator >> (istream&, Integer&);
	friend ostream& operator << (ostream&, const Integer&);

};

istream& operator >> (istream& in, Integer& a)
{
	in >> (a.num);
	return in;
}

ostream& operator << (ostream& out, const Integer& a)
{
	out << (a.num);
	return out;
}
