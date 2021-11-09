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

void Insert()
{
	if(root == NULL)
	{
		root = (node *)malloc(sizeof(node));
		printf("Kök eklenmemiþ veri: ");
		scanf("%d", &root->data);
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		int inp;
		iter = root;
		printf("Veri giriniz: ");
		scanf("%d", &inp);
		while(iter->data != inp)
		{
			if(inp <= iter->data)
			{
				if(iter->left != NULL)
					iter = iter->left;
				else
				{
					iter->left = (node *)malloc(sizeof(node));
					iter = iter->left;
					iter->data = inp;
					iter->left = NULL;
					iter->right = NULL;
				}
			}			
			else
			{
				if(iter->right != NULL)
					iter = iter->right;
				else
				{
					iter->right = (node *)malloc(sizeof(node));
					iter = iter->right;
					iter->data = inp;
					iter->left = NULL;
					iter->right = NULL;
				}
			}
		}
		printf("Ýþlem baþarýlý !\n\n");
	}
}

void Display(node *L)
{
	if(L != NULL)
	{
		Display(L->left);
		printf("%d, ", L->data);
		Display(L->right);
	}
}

node *Find()
{
	int inp;
	printf("Aranacak veri: ");
	scanf("%d", &inp);
	iter = root;
	while(iter->data != inp)
	{
		if(iter->data > inp)
		{
			if(iter->left != NULL)
				iter = iter->left;
			else
			{
				iter = NULL;
				break;
			}
		}
		else
		{
			if(iter->right != NULL)
				iter = iter->right;
			else
			{
				iter = NULL;
				break;
			}
		}
	}
	return iter;
}

void alert()
{
	printf("Alert !\n");
}

void Delete()
{
	node *temp = Find(); node *prev;
	iter = root;
	if(temp != NULL) /*Silenecek veri bulunduysa*/
	{
		/*Silinecek veriden önceki düðümü bulur*/
		while(iter->data == iter->data)
		{
			if(temp->data < iter->data)
			{
				if(iter->left->data != temp->data)
					iter = iter->left;
				else
					break;
			}
			else
			{
				if(iter->right->data != temp->data)
					iter = iter->right;
				else
					break;	
			}	
		}
		
		prev = iter;
		if(root->data > temp->data)		/*Soldaki veriyi silecek isek*/
		{
			/*Özel durum kontrolü*/
			if(temp->left != NULL)
			{
				iter = temp->left;
				while(iter->right != NULL)
					iter = iter->right;
				if(iter->left != NULL)
				{
					prev->left = iter;
					iter = temp->left;
					while(iter->right != prev->left)
						iter = iter->right;
					alert();
					iter->right = prev->left->left;
					prev->left->right = temp->right;
					prev->left->left = temp->left;
					temp->right = temp->left = NULL;
					free(temp); alert();
				}
				else
				{
					iter = temp->left;
					while(iter->right != NULL)
						iter = iter->right;
					prev->left = iter;
					iter = temp->left;
					printf("%d\n", temp->left->data); alert();
					while(iter->right != prev->left)
						iter = iter->right;
					alert();
					iter->right = NULL;
					prev->left->right = temp->right;
					prev->left->left = temp->left;
					temp->right = temp->left = NULL;
					free(temp); alert();
				}	
			}
			else
			{
				if(temp->right != NULL)
					iter = temp->right;
				else
					iter = temp;
				if(prev != root)
					prev->right = iter;
				temp->right = NULL;
				free(temp); alert();
			}
		}
		else
		{
			alert();
			if(temp->right != NULL)
			{
				iter = temp->right;
				while(iter->left != NULL)
					iter = iter->left;
				if(iter->right != NULL)
				{
					prev->right = iter;
					iter = temp->right;
					while(iter->left != prev->right)
						iter = iter->left;
					iter->left = prev->right->right;
					prev->right->left = temp->left;
					prev->right->right = temp->right;
					temp->left = temp->right = NULL;
					free(temp);
				}
				else
				{
					temp->right = iter;
					while(iter->left != NULL)
						iter = iter->left;
					prev->right = iter;
					iter = temp->right;
					while(iter->left != prev->right)
						iter = iter->left;
					iter->left = NULL;
					prev->right->left = temp->left;
					prev->right->left = temp->right;
					temp->left = temp->right = NULL;
					free(temp);
				}	
			}
			else
			{
				iter = temp->left;
				prev->right = iter;
				temp->left = NULL;
				free(temp);
			}	
		}
	}
	else
		printf("Silinecek veri yok !\n\n");
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	root = NULL;
	int selection;
	do
	{
		printf("Ekle[1]\nSil[2]\nGöster[3]\nBul[4]\nÇýkýþ[5]\nSeçim: ");
		selection = getch() - '0';
		printf("%d\n", selection);
		switch(selection)
		{
			case 1:
				Insert();
				break;
			case 2:
				Delete();
				break;
			case 3:
				Display(root);
				printf("\n\n");
				break;
			case 4:
				iter = Find();
				if(iter != NULL)
					printf("Bulundu !\n\n");
				else
					printf("Aðaçta verisi yok !\n\n");
				break;
			case 5:
				
				break;
			default:
				printf("Seçim yanlýþ !\n\n");
				break;
		}
	}while(selection != 5);
	return 0;
}
