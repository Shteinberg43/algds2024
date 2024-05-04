#include "lab_2_treaps.h"

node* create_node(int key, int priority) {
	node* x = malloc(sizeof(node));
	if (x != NULL) {
		x->key = key;
		x->priority = priority;
		x->left = NULL;
		x->right = NULL;
		x->parent = NULL;
	}
	return x;
}

void Left_Rotate(Treap* T, node* x) {
	node* y = x->right;
	x->right = y->left;
	if (y->left != NULL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		T->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void Right_Rotate(Treap* T, node* x) {
	node* y = x->left;
	x->left = y->right;
	if (y->right != NULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		T->root = y;
	}
	else if (x == x->parent->right) {
		x->parent->right = y;
	}
	else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}
void Treap_Insert(Treap* T, node* z) {
	node* y = NULL;
	node* x = T->root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x=x->right;
		}
	}
	z->parent = y;
	if (y == NULL) {
		T->root = z;
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else {
		y->right = z;
	}
	while ((z != T->root) && (z->priority < z->parent->priority)) {
		if (z == z->parent->left) {
			Right_Rotate(T, z->parent);
		}
		else {
			Left_Rotate(T, z->parent);
		}
	}
}
void Insert_note(Treap* T, int key, int prioritet) {
	node* x = create_node(key, prioritet);
	Treap_Insert(T, x);
}
node* Treap_Search(Treap* T, int key) {
	node* y = T->root;
	while ((y != NULL) && (key != y->key)) {
		if (key < y->key) {
			y = y->left;
		}
		else {
			y = y->right;
		}
	}
	return y;
}
//обратная порядок добавления, с помощью поворотов возвращаем узел в положение листа и удаляем
void Treap_Delete(Treap* T, node* z) {
	while ((z->left != NULL) || (z->right != NULL)) {
		if ((z->left == NULL) || ((z->right != NULL) && (z->left->priority > z->right->priority))) {
			Left_Rotate(T, z);
		}
		else {
			Right_Rotate(T, z);
		}
	}
	if (z->parent == NULL) {
		T->root = NULL;
	}
	else if (z == z->parent->left) {
		z->parent->left = NULL;
	}
	else {
		z->parent->right = NULL;
	}
}
void Delete_by_key(Treap* T, int key) {
	node* z = Treap_Search(T, key);
	Treap_Delete(T, z);
	free(z);
}
void Treap_Print(node* x, char* str) {
	if (x != NULL) {
		char c[100];
		sprintf(c, "(%d,%d)", x->key, x->priority);
		strcat(str, c);

		Treap_Print(x->left, str);
		Treap_Print(x->right, str);
	}
}