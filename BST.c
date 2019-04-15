#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

typedef struct BST_node {
	struct BST_node *left;
	struct BST_node *right;
	struct BST_node *parent;
	int value;
}BST_node;

typedef struct BST {
	int count;
	BST_node *root;
}BST;

static inline void BST_destroy_node(BST_node *node)
{
	if (node) {
		BST_destroy_node(node->left);
		BST_destroy_node(node->right);
		printf("%d\n", node->value);
		free(node);
	}
}

void BST_destroy(BST *bst)
{
	if (bst) {
		if (bst->root) {
			BST_destroy_node(bst->root);
		}
		free(bst);
	}
}

BST *BST_create()
{	
	BST *bst = calloc(1, sizeof(BST));
	check_mem(bst);

	bst->count = 0;
	return bst;
error:
	BST_destroy(bst);
	return NULL;
}

static inline BST_node *BST_create_node(int value, BST_node *parent)
{
	BST_node *node = calloc(1, sizeof(BST_node));
	node->value = value;
	node->parent = parent;
	return node;
}

static inline void BST_set_node(BST *bst, BST_node *node, int value)
{
	int cmp = (value - node->value);

	if (cmp < 0) {
		if (node->left == NULL) {
			BST_node *left_node = BST_create_node(value, node);
			node->left = left_node;
		} else {
			BST_set_node(bst, node->left, value);
		}
	} else {
		if (node->right == NULL) {
			BST_node *right_node = BST_create_node(value, node);
			node->right = right_node;			
		} else {
			BST_set_node(bst, node->right, value);
		}
	}
}

int BST_set(int value, BST *bst)
{
	check(bst != NULL, "Can't set a NULL BST.");
	if (bst->root == NULL) {
		BST_node *root = BST_create_node(value, NULL);
		bst->count = 1;
		bst->root = root;
	} else {
		// printf("%d\n", value);
		BST_set_node(bst, bst->root, value);
		bst->count++;
	}
error:
	return 0;
}

static inline void BST_traverse_node(BST_node *node)
{
	if (node) {
		printf("%d\t",node->value);
		BST_traverse_node(node->left);
		BST_traverse_node(node->right);
	}
}

void BST_traverse(BST *bst)
{
	if (bst) {
		if (bst->root) {
			BST_traverse_node(bst->root);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	BST *bst = BST_create();
	int a[6] = { 5, 2, 23, 613, 3, 9};
	for (int i = 0; i < 6; i++) {
		BST_set(a[i], bst);
	}
	BST_traverse(bst);
	printf("Count of BST is %d\n", bst->count);
	BST_destroy(bst);
	return 0;
}