#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

int amount = 0;
#define MAXWORD 100
struct tnode {                // узел дерева
	char* word;                  // указатель на строку (слово)
	int count;                   // число вхождений        
	struct tnode* left;          // левый потомок
	struct tnode* right;         // правый потомок
};
// Функция добавления узла к дереву
struct tnode* addtree(struct tnode* p, char* w) {
	int cond;
	if (p == NULL) {
		p = (struct tnode*)malloc(sizeof(struct tnode));      //выделение памяти
		p->word = _strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)         //одинаковые слова (строки) будут записаны лишь единожды, количество их повторений посчитано
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}
// Функция удаления поддерева
void freemem(tnode* tree) {
	if (tree != NULL) {
		freemem(tree->left);
		freemem(tree->right);
		free(tree);
	}
}
// Функция вывода дерева
void treeprint(struct tnode* p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
//поиск по ключу, подсчёт совпадений
void find(struct tnode* p, char* w) {
	int temp;
	if (p != NULL) {
		find(p->left, w);
		if ((temp = strcmp(w, p->word)) == 0)
			amount++;
		find(p->right, w);
	}
}

void answer()
{
	if (amount == 1)
		printf("Совпадение нашлось, их количество указано слева от искомого слова в распечатанном дереве\n(<количество> <искомое словао>\n");
	else printf("Совпадений с искомой строкой в дереве не оказалось!");
}
