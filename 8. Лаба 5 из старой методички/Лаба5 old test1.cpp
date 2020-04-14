#include<iostream>
#include<time.h>
	
using namespace std;
void my_swap(double* &a, double* &b){
    double* tmp = a;
    a = b;
    b = tmp;
} 
double** start_array(int num_of_row, int num_of_col){
	double** matrix;
    matrix = new double* [num_of_row];
        for (int i=0; i<num_of_row; i++)
                matrix[i]= new double [num_of_col];
                
    
    for (int i=0; i<num_of_row;i++)
        for (int j=0;j<num_of_col;j++)
            matrix[i][j] = rand()%100 + 1;

    for(int i=0;i<num_of_row;i++){
        for(int j=0;j<num_of_col;j++) 
            cout<<matrix[i][j]<<"\t";
        cout<<endl;
    }
cout<<endl;
	return matrix;
}

double** end_array(double** new_mass, int num_of_row, int num_of_col){
	for (int i = 1;i < num_of_row;){
        if (new_mass[i-1][2]>new_mass[i][2]){
            my_swap(new_mass[i-1],new_mass[i]);
            i--;
        }
        else i++;
        
        if(i == 0) i++;
            
    }
    
    for(int i=0;i<num_of_row;i++){
        for(int j=0;j<num_of_col;j++) 
            cout<<new_mass[i][j]<<"\t";
        cout<<endl;
    }       
 
    for (int i=0; i<num_of_row; i++)
        delete[] new_mass[i];
    delete[] new_mass;
}

int main(void){
	srand(time(NULL));
 	int num_of_row;
    int num_of_col;
	double** new_mass = start_array(8, 6);
    end_array(new_mass, 8, 6);
 
    
 
return 0;   
}
 

