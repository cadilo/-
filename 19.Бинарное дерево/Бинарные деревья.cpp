// BinaryTree.cpp : Ётот файл содержит функцию "main". «десь начинаетс€ и заканчиваетс€ выполнение программы.
//

#include <iostream>
#include "tree.h"
#include <Windows.h>

#define MAXWORD 100

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	struct tnode* root;
	char word[MAXWORD];
	char key[25];
	int amount = 0;
	root = NULL;
	cout << "¬вод слов (строк) дл€ заполнени€ дерева. ќдинаковые слова не будут записаны, но количество их повторений будет подсчитано!\n";
	do {
		scanf_s("%s", word, (unsigned)_countof(word));
		if (isalpha(word[0]))
			root = addtree(root, word);
	} while (word[0] != '0');    // условие выхода Ц ввод символа С0Т
	treeprint(root);
	//поиск по ключу"
	cout << "¬ведите значение, наличие которого нужно проверить: \n";
	cin >> key;
	find(root, key);
	answer();
	freemem(root);

	return 0;
}
