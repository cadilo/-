#include <iostream>
#include "methods.h"
using namespace std;

//Перегрузка оператора []
		int& VECTOR::operator[](int index)
    	{
        	assert(index >= 0 && index < size);
        	return arr[index];
    	}

//Перегрузка оператора ()
    	int VECTOR::operator()(int arr){
    		//assert(size <= 0);
    		int size_of = 0;
    		for(int i = 0; i < size; i++){
    			size_of++;
			}
    		return size_of;
		}

//Перегрузка оператора *h
		int* VECTOR::operator * (int h){
			for(int i = 0; i < size; i++){
				arr[i] = arr[i]*h;
			}
			return arr;
		}
		
//Перегрузка оператора -n
		int* VECTOR::operator - (int n){
			int* arr1 = new int[n];
			for(int i = 0; i < n; i++){
				arr1[i] = arr[i];
			}
			return arr1;
		}
		
		
//добавление элемента после заданного номера
		void VECTOR::insertBefore(int value, int index){
			assert(index >= 0 && index <= size);
			
			int *data = new int[size + 1];
			
			for(int before = 0; before < index; before++){
				data[before] = arr[before];
			}
			
			data[index] = value;
			
			for (int after=index; after < size; ++after)
            data[after+1] = arr[after];
            
            delete[] arr;
       	 	arr = data;
        	++size;
		}
