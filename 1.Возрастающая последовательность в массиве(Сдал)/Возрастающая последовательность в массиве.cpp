#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
int n,tmp;
int A[100];
bool ordered = false;
cout << "Введите количество элементов массива" << endl;
cin >> n;
if (n > 0)
{
	cout << "Введите " << n << " элементов массива" << endl;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	tmp = A[0];
	int i = 1;
	while (i < n && ordered == false)
	{
		if (tmp < A[i])
	{
	tmp = A[i];
	i++;
	}
		else if(tmp >= A[i])
	{
		ordered = true;
	}
	}


	if (ordered){
		cout << "Последовательность не упорядочена по возрастанию";
	}
	else if (ordered == false){
		cout << "Последовательность упорядочена по возрастанию";
	}
}
else{
	cout << "Ошибка, количество элементов массива - положительное число!";
}
return 0;
}
