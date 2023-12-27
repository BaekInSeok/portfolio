#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b)(a)

typedef struct element
{
	char eng[100];
	char kor[100];
}element;

typedef struct AVLNode
{
	int key;
	element sentence;
	struct AVLNode *left;
	struct AVLNode *right;
}AVLNode;

int get_height(AVLNode *node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(AVLNode *node) {
	if (node == NULL) return 0;

	return get_height(node->left) - get_height(node->right);
}

AVLNode* create_node(int key, element e)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->sentence = e;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

AVLNode *rotate_right(AVLNode *parent) {
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

AVLNode *rotate_left(AVLNode *parent) {
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}

AVLNode* insert(AVLNode* node, int key, element e)
{
	if (node == NULL)
		return(create_node(key, e));

	if (key < node->key)
		node->left = insert(node->left, key, e);
	else if (key > node->key)
		node->right = insert(node->right, key, e);
	else
		return node;

	int balance = get_balance(node);

	if (balance > 1 && key < node->left->key)
		return rotate_right(node);

	if (balance < -1 && key > node->right->key)
		return rotate_left(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

void preorder(AVLNode *root, char e[]) {
	if (root != NULL)
	{
		if (strcmp(root->sentence.eng, e) == 0) {
			printf("%s - %s\n", root->sentence.eng, root->sentence.kor);
		}
		preorder(root->left, e);
		preorder(root->right, e);
	}
}