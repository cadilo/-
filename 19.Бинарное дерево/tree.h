#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

int amount = 0;
#define MAXWORD 100
struct tnode {                // ���� ������
	char* word;                  // ��������� �� ������ (�����)
	int count;                   // ����� ���������        
	struct tnode* left;          // ����� �������
	struct tnode* right;         // ������ �������
};
// ������� ���������� ���� � ������
struct tnode* addtree(struct tnode* p, char* w) {
	int cond;
	if (p == NULL) {
		p = (struct tnode*)malloc(sizeof(struct tnode));      //��������� ������
		p->word = _strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)         //���������� ����� (������) ����� �������� ���� ��������, ���������� �� ���������� ���������
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}
// ������� �������� ���������
void freemem(tnode* tree) {
	if (tree != NULL) {
		freemem(tree->left);
		freemem(tree->right);
		free(tree);
	}
}
// ������� ������ ������
void treeprint(struct tnode* p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
//����� �� �����, ������� ����������
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
		printf("���������� �������, �� ���������� ������� ����� �� �������� ����� � ������������� ������\n(<����������> <������� ������>\n");
	else printf("���������� � ������� ������� � ������ �� ���������!");
}
