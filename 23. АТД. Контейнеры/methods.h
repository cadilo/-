#include <iostream>
#include <cassert> // ��� assert()
using namespace std;
class VECTOR 
{
	protected: 
		int *arr;		//���������� �������
		int size;		//���������� ����������� ��������� �������	
		
	public: 
		VECTOR(): size(0), arr(NULL){}
		
	
		VECTOR(int _size):size(_size){
			assert(_size >= 0);
			
			if(_size > 0) arr = new int[_size];
			else arr = NULL;
		}
		
		int getLength() { return size; }
		//���������� ��������� []
		int& operator[](int index);
    	//���������� ��������� ()
    	int operator()(int arr);
		//���������� ��������� *h
		int* operator * (int h);
		//���������� ��������� -n
		int* operator - (int n);
		
		//���������� �������� ����� ��������� ������
		void insertBefore(int value, int index);
	
	
		
		~VECTOR(){
			delete[] arr;						//���������� ��������� ������ �������
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
