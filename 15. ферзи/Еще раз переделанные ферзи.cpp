#include <iostream>
using namespace std;
const int SIZE = 8; // ������.
 
int board[SIZE][SIZE];
int results_count = 0; // ���������� �������.
 
// ������� showBoard() - ���������� �����.
void showBoard()
{
    for(int a = 0; a < SIZE; ++a)
    {
        for(int b = 0; b < SIZE; ++b)
        {
            cout << ((board[a][b]) ? "1 " : "0 ");
        }
        cout << '\n';
    }
}
 
// ������� tryQueen() - ��������� ��� �� ��� ������������� ������,
// �� ���������, ����������.
bool tryQueen(int a, int b)
{
    for(int i = 0; i < a; ++i)
    {
        if(board[i][b])
        {
            return false;
        }
    }
 
    for(int i = 1; i <= a && b-i >= 0; ++i)
    {
        if(board[a-i][b-i])
        {
            return false;
        }
    }
 
    for(int i = 1; i <= a && b+i < SIZE; i++)
    {
        if(board[a-i][b+i])
        {
            return false;
        }
    }
 
    return true;
}
 
// ������� setQueen() - ������� ����� ���������� �������.
void setQueen(int a) // a - ����� ��������� ������ � ������� ����� ��������� ���������� �����.
{
    if(a == SIZE)
    {
        showBoard();
        cout << "������� �" << ++results_count << "\n\n";
        return; // �����������.
    }
 
    for(int i = 0; i < SIZE; ++i)
    {
        // ����� ���������, ��� ���� �������� � board[a][i] ����� (�������),
        // �� �� ����� ������������ � ���� ������, ������� � ����������.
        if(tryQueen(a, i))
        {
            board[a][i] = 1;
            setQueen(a+1);
            board[a][i] = 0;
        }
    }
 
    return; // �����������.
}
 
int main()
{
	setlocale(LC_ALL, "rus");
    setQueen(0);
 
    return 0;
}
