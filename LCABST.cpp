// A recursive C program to find LCA of two nodes n1 and n2
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left, *right;
};

struct node *commonAncestor2(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data > n1 && root->data > n2)
           root = root->left;

        else if (root->data < n1 && root->data < n2)
           root = root->right;

        else break;
    }
    return root;
}

struct node *commonAncestor(struct node* root, int n1, int n2)
{
	if (root == NULL) return NULL;
	if (root->data > n1 && root->data > n2)
		return commonAncestor(root->left, n1, n2);

	else if (root->data < n1 && root->data < n2)
		return commonAncestor(root->right, n1, n2);

	return root;
}

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

int main()
{
	struct node *root	 = newNode(20);
	root->left			 = newNode(8);
	root->right			 = newNode(22);
	root->left->left		 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	int n1 = 10, n2 = 14;
	struct node *t;
	t = commonAncestor(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	n1 = 14, n2 = 8;
	t = commonAncestor(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	n1 = 10, n2 = 22;
	t = commonAncestor(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	printf("------Out put with Iterative Mehtod --------\n");

	n1 = 10, n2 = 14;
	t = commonAncestor2(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	n1 = 14, n2 = 8;
	t = commonAncestor2(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);

	n1 = 10, n2 = 22;
	t = commonAncestor2(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	getchar();
	return 0;
}
