#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef enum bl
{
	false = 0,
	true = 1
}boolean;

typedef struct n
{
	int data;
	struct n *next;
}node;

node *iter;
node *root;

int Insert()
{
	static boolean is_first = true;
	int inp;
	static int a = 0;
	if(is_first == true)
	{
		printf("Kuyruða girmesini istediðiniz eleman: ");
		scanf("%d", &inp);
		iter->data = inp;
		iter->next = NULL;
		is_first = false;
	}
	else
	{
		printf("Kuyruða girmesini istediðiniz eleman: ");
		scanf("%d", &inp);
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next;
		iter->data = inp;
		iter->next = NULL;
		if(a == 3)
			printf("%d\n", root->next->next->data);
	}
	a++;
	return 1;
}

int IsEmpty()
{
	node *fake_root = root;
	if(fake_root->data == 0 && fake_root->next == NULL)
		return 1;
	else
		return 0;
}

void Delete()
{
	if(IsEmpty(root) == 1)
		printf("Kuyruk boþ!\n\n");
	else
	{
		int del = root->data;
		node *fake_root = root->next;
		free(fake_root);
		root = fake_root;
		printf("%d elemaný kuyruktan çýktý\n\n", del);
	}
}

void Display()
{
	node *fake_root = root;
	int a = 1;
	while(fake_root != NULL)
	{
		printf("%d.Eleman = %d ve adresi ->%p\n", a, fake_root->data, &(fake_root->data));
		fake_root = fake_root->next;
		a++;
	}
	printf("\n");
}

node *Search()
{
	node *fake_root = root;
	int inp; int a = 1;
	printf("Aramak istediðiniz eleman: ");
	scanf("%d", &inp);
	while(fake_root != NULL)
	{
		if(fake_root->data == inp)
		{
			printf("Aradðýnýz eleman kuyrukta %d.sýradadýr\n", a);
			return fake_root;
		}
		else
			fake_root = fake_root->next;
		a++;
	}
	return NULL;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	root = (node *)malloc(sizeof(node));
	iter = root;
	node *wanted;
	int selection;
	printf("\t\t\t\t\tKuyruk Ýþlemi\n");
	do
	{
		printf("Kuyruða Eleman Ekle[1]\nKuyruktan Eleman Çýkar[2]\n");
		printf("Kuyruðu Göster[3]\nKuyrukta Eleman Ara[4]\nÇýkýþ[5]\nSeçiminiz: ");
		selection = getch() - '0';
		printf("%d\n", selection);
		switch(selection)
		{
			case 1:
				if(Insert() == 1)
					printf("Kuyruða eleman eklendi...\n\n");
				else
					printf("Ýþlem bir nedenden dolayý baþarýsýz oldu!\n\n");
				break;
			case 2:
				Delete();
				break;
			case 3:
				Display();
				break;
			case 4:
				wanted = Search();
				if(wanted != NULL)
					printf("Aradýðýnýz eleman %d ve adresi->%p\n\n", wanted->data, &(wanted->data));
				else
					printf("Aranan eleman bulunamadý!\n\n");
				break;
			case 5:
				free(root);
				break;
			default:
				printf("Lütfen geçerli bir deðer giriniz!\n\n");
				break;
		}
	}while(selection != 5);
	return 0;
}







