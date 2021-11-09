#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct n
{
	struct n *left;
	char data;
	struct n *right;
}node;

node *root;
node *iterleft;
node *iterright;

node circulation(node *L)
{
	if(L != NULL)
	{
		circulation(L->left);
		printf("%c", L->data);
		circulation(L->right);
	}
}

node staticcirculation(node *L)
{
	
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	root = (node *)malloc(sizeof(node));
	root->left = (node *)malloc(sizeof(node));
	root->right = (node *)malloc(sizeof(node));
	iterleft = root->left;
	iterright = root->right;
	root->data = 'A';

	iterleft->data = 'B';

	iterleft->left = (node *)malloc(sizeof(node));
	iterleft->right = (node *)malloc(sizeof(node));
	iterleft->right->data = 'D';
	iterleft->right->left = NULL;
	iterleft->right->right = NULL;
	iterleft = iterleft->left;
	iterleft->data = 'C';

	iterleft->left = (node *)malloc(sizeof(node));
	
	iterleft->right = NULL;
	iterleft = iterleft->left;
	iterleft->data = 'E';
	iterleft->left = NULL;

	iterleft->right = (node *)malloc(sizeof(node));
	iterleft->right->data = 'F';
	
	iterleft->right->left = (node *)malloc(sizeof(node));
	iterleft->right->left->data = 'G';
	iterleft->right->left->left = NULL;
	iterleft->right->left->right = NULL;
	iterleft->right->right = NULL;

	iterright->data = 'H';

	iterright->left = (node *)malloc(sizeof(node));
	iterright->right = NULL;
	iterright = iterright->left;
	iterright->data = 'I';
	iterright->left = iterright->right = NULL;

	circulation(root);
	printf("\n");
	free(root);
	return 0;
}
