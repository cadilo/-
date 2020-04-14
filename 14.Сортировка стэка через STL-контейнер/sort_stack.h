#include <iostream>
#include <stack>
using namespace std;

template <class TYPE>                                      //������� ������ TYPE

	stack <TYPE> make_stack(TYPE number_element){
		stack <TYPE> stl;                                 // ������� ���� stl
		//cout << "������� ������ ��������� � �����? " << endl;
		//int number_element;
		//cin >> number_element;
		cout << "������ ����� ���� ��������: " << endl;
		
		for(int i = 0; i < number_element; i++){
			int add_in_stack;								  // ������� ���������� ������� ����� ��������
			cin >> add_in_stack;							  // ������ ��
			stl.push(add_in_stack);							  // ��������� � ��� ����
		}
		
		/*while(number_element != 0){
			cout << stl.top() << "\t";
			stl.pop();
			number_element--;	
		}
		*/
		return stl;										  // ����������
	}
	
template <class TYPE>
	
	void sort_stack(stack<TYPE>& stl, int number_element){                     //����������� ���� �� �����������
		//stack <TYPE> one_Stack;							   //������� ���� ���� TYPE
		stack <TYPE> two_Stack;
		stack <TYPE> tree_Stack;
		
		/*while(number_element != 0){						   //����� ������� �����
			cout << stl.top() << "\t";
			stl.pop();
			number_element--;	
		}*/
		
		/*while(number_element != 0){						   //����� ������� �����
			int vb = stl.top();
			two_Stack.push(vb);
			cout << two_Stack.top() << "\t";
			stl.pop();
			number_element--;
		}*/
		
		cout << "� ��� ��������������� ����: ";
		
		TYPE* array = new TYPE[number_element];
		
		for(int i = 0; i < number_element; i++){
			array[i] = stl.top();
			stl.pop();
		}
		
		for(int i = 0; i < number_element; i++){
			for(int j = i; j > 0 && array[j-1] > array[j]; j--){
				swap(array[j-1], array[j]);
			}
		}
	
		/*for(int i = 0; i < number_element; i++){
			cout << array[i] << " ";
		} 
		cout << endl;*/
		
		
		for(int i = 0; i < number_element; i++){
			stl.push(array[i]);
		}
		
		while(number_element != 0){						   //����� ������� �����
			cout << stl.top() << "\t";
			stl.pop();
			number_element--;	
		}
		
		
		/*while(number_element != 0){
			cout << two_Stack.top() << "\t";
			two_Stack.pop();
			number_element--;	
		}*/
	}	
	
		
	
