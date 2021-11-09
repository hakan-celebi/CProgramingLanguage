#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct n
{
	struct n *left;
	int data;
	struct n *right;
}node;

node *root;
node *iter;

void Insert(node *L, int inpdata)
{
	if(L == NULL)
	{
		printf("Kök girilmemiþ kök e %d verisi yerleþtiriliyor...\n\n", inpdata);
		root = (node *)malloc(sizeof(node));
		root->data = inpdata;
		iter = root;
		root->left = root->right = NULL;
	}
	else
	{
		if(L->data < inpdata)
		{
			if(L->right != NULL)
				Insert(L->right, inpdata);
			else
			{
				L->right = (node *)malloc(sizeof(node));
				L = L->right;
				L->data = inpdata;
				L->left = L->right = NULL;
				printf("Data added with succes to root node's right !\n\n");
			}
		}
		else
		{
			if(L->left != NULL)
				Insert(L->left, inpdata);
			else
			{
				L->left = (node *)malloc(sizeof(node));
				L = L->left;
				L->data = inpdata,
				L->left = L->right = NULL;
				printf("Data added with succes to root node's left !\n\n");
			}
		}
	}
}

node *max(node *L)
{
	if(L->right != NULL)
		max(L->right);
	else
		return L;
}

node *min(node *L)
{
	if(L->left != NULL)
		min(L->left);
	else
		return L;
}

void Delete(node *L, int inpdata)
{
	if(L != NULL)
	{
		if(L->data < inpdata)
		{
			if(L->right != NULL)
				Delete(L->right, inpdata);
			else
				printf("No data available !\n\n");
		}
		else if(L->data > inpdata)
		{
			if(L->left != NULL)
				Delete(L->left, inpdata);
			else
				printf("No data available !\n\n");
		}
		else
		{
			printf("Data available !\nData is deleted !\n\n");
			if(L->left == NULL && L->right == NULL)
			{
				iter = root;
				while(iter != NULL)
				{
					if(iter->data < L->data)
					{
						if(iter->right != L)
							iter = iter->right;
						else
						{
							iter->right = NULL;
							iter = NULL;
							free(L);	
						}	
					}
					else if(iter->data > L->data)
					{
						if(iter->right != L)
							iter = iter->right;
						else
						{
							iter->right = NULL;
							iter = NULL;
							free(L);	
						}	
					}
				}
			}
			else if(L->right != NULL)
			{
				iter = min(L->right);
				L->data = iter->data;
				node *temp = iter;
				iter = L->left;
				while(iter->left != temp)
					iter = iter->left;
				iter->left = NULL;
				free(temp);
			}
			else
			{
				iter = max(L->left);
				L->data = iter->data;
				node *temp = iter;
				iter = L->left;
				while(iter->right != temp)
					iter = iter->right;
				iter->right = NULL;
				free(temp);
			}
		}
	}
	else
		printf("The tree is empty !\n\n");
}

void Inorder(node *L)
{
	if(L != NULL)
	{
		Inorder(L->left);
		printf("%d-", L->data);
		Inorder(L->right);
	}
}

void Clear_Memory(node *L)
{
	if(L != NULL)
	{
		Inorder(L->left);
		if(L->right == NULL)
			free(L);
		else
		{
			Inorder(L->right);
			free(L);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	root = iter = NULL;
	int selection; int inpdata;
	do
	{
		printf("Insert[1]\nDelete[2]\nTravel[3]\nTrash[4]\nExit[5]\nChoice: "); selection = getch() - '0'; printf("%d\n", selection);
		switch(selection)
		{
			case 1:
				printf("Enter the data: "); scanf("%d", &inpdata);
				Insert(root, inpdata);
				break;
			case 2:
				printf("Enter data to be deleted: "); scanf("%d", &inpdata);
				Delete(root, inpdata);
				break;
			case 3:
				Inorder(root);
				printf("\n\n");
				break;
			case 4:
				if(root != NULL)
				{
					Clear_Memory(root);
					printf("The tree is cleared !\n\n");
				}
				else
					printf("The tree is already empty !\n\n");
				break;
			case 5:
				Clear_Memory(root);
				printf("The memory was successfully cleared.\n Logging out...\n\n");
				break;
			default:
				printf("Wrong choice try again !\n\n");
				break;
		}
	}while(selection != 5);
	return 0;
}
