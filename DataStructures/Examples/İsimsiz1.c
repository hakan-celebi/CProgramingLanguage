#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

typedef struct a
{
	int data;
	struct a *next;
}node;

/*
malloc(int); ->void root = (node *)malloc(sizeof(node));
*/

node *root;
node *iter;

void sonaGit() 
{
		while(iter->next != root)
		{
			iter = iter->next;
		}
}

void ekle()
{
	if(root == NULL)
	{
		root = (node *)malloc(sizeof(node));
		printf("Girilecek veri: ");
		scanf("%d",&root->data);
		root->next = root;
		iter = root;
		printf("Ekleme Ýþlemi Baþarýlý.\n\n");
	}
	else
	{
		sonaGit();
	 	iter->next = (node*)malloc(sizeof(node));
	 	iter = iter->next;
	 	printf("Girilecek veri: ");
	 	scanf("%d", &iter->data);
	 	iter->next = root;
	 	printf("Ekleme Ýþlemi Baþarýlý.\n\n");
	}
}

void sil()
{
	if(root == NULL)
		printf("Yýðýn Boþ !!\n\n");
	else
	{
		sonaGit();
		node *silinecek = iter;
		silinecek->next = NULL;
		while(iter->next != silinecek)
		{
			iter = iter->next;
		}
		iter->next = root;
		free(silinecek);
		printf("Silme Ýþlemi Baþarýlý.\n\n");
	}	
}

void bosalt()
{
	while(root != NULL)
	{
		sonaGit();	
		free(iter);
		iter = root;
	}
	root = iter = NULL;	
}

void sirala()
{
	int i = 1;
	iter = root;
	while(iter->next != root)
	{
		printf("%d.Veri: %d\n",i++ ,iter->data);
		iter = iter->next;
	}
	printf("%d.Veri: %d\n\n",i ,iter->data);
}

node *bul(int istenen)
{
	iter = root;
	
	while(iter->data != istenen)
	{
		iter = iter->next;
		if(iter == root)
		{
			iter = NULL;
			break;
		}
	}
	return iter;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	root = NULL;
	int secim;
	int istenen;
	do
	{
		printf("Ekle[1]\nSil[2]\nBoþalt[3]\nSýrala[4]\nBul[5]\nÇýkýþ[6]\nSeçim: ");
		secim = getch() - '0';
		printf("%d \n", secim);
		switch(secim)
		{
			case 1:
				ekle();
				break;		
			case 2:
				sil();
				break;
			case 3:
				bosalt();
				break;
			case 4:
				sirala();
				break;
			case 5:
				printf("Aranacak deðer: ");
				scanf("%d",&istenen);
				if(bul(istenen) != NULL)
					printf("Bulundu !!!\n");
				else
					printf("Bulunamadý !!!\n");	
				break;
			default:
				printf("Hatalý Seçim");
				break;	
		}
	}while(secim != 6);
	return 0;
}
