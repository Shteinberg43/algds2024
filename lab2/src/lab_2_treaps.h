#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	int key;
	int priority;
	struct node* right;
	struct node* left;
	struct node* parent;
}node;

typedef struct Treap {
	node* root;
}Treap;

void Delete_by_key(Treap* T, int key);
void Treap_Print(node* x, char* str);
void Insert_note(Treap* T, int key, int prioritet);