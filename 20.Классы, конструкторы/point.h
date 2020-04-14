using namespace std;

struct point{
	int first;					//Номинал купюры
	int second;					//количество купюр
	void init(int, int);		//Метод для инициализации полей
	void read();				//Метод для чтения записей полей
	void print();				//Метод для вывода значений полей
	int summa();				//вычисление суммы
};
