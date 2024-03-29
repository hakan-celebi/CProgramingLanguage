#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <allegro.h>
#include <locale.h>

typedef enum b
{
	false = 0,
	true = 1
}boolean;

/*Her bir d���m*/
typedef struct n
{
	struct n *previous;
	int data;
	boolean Have_Data; /*��erisinde veri varm� yokmu kontroler etmemizi sa�layan bool de�i�keni*/
	struct n *next;
}node;

node *root; /*K�k listenin ilk d���m�n� g�sterir.*/
node *iter; /*Listenin son eleman�n� g�sterir.*/

/*Efektif olarak loading ekran� sa�layan foknsiyon*/
void Loading_Screen(char a[])
{
	int i;
	for(i = 0; i < 3; i++)
	{
		system("CLS");
		if(i == 0)
			printf("%s.", a);
		else if(i == 1)
			printf("%s..", a);
		else
			printf("%s...", a);
		sleep(1);
	}
}

/*D���m ekleme fonksiyonu*/
void Insert()
{
	int inpdata;
	/*rootun verisi yok ise �u ana kadar hi� eleman eklenmemi� olur dolay�s� ile ilk eklemeye uygun olan kodlar �al���r.*/
	if(root->Have_Data == false)
	{
		printf("\nEklemek istedi�iniz de�er: ");
		scanf("%d", &inpdata);
		iter->data = inpdata;
		iter->Have_Data = true;
		printf("%d de�eri d���me eklendi !\n\n", iter->data);
	}
	else
	{
		printf("\nEklemek istedi�iniz de�er: ");
		scanf("%d", &inpdata);
		node *prev = iter;
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next;
		iter->data = inpdata;
		iter->Have_Data = true;
		iter->next = NULL;
		iter->previous = prev;
		printf("%d de�eri d���me eklendi !\n\n", iter->data);
	}
}

int Is_Empty()
{
	/*E�er rootun have_Data de�i�keni bo� ise hi� veri eklenmemi� anlam�na gelir.*/
	if(root->Have_Data == false)
		return 1;
	else
		return 0;
}

void Display()
{
	if(Is_Empty() == 0)
	{
		node *controler = root;
		int counter = 1;
		printf("\nLink List\n");
		while(controler != NULL)
		{
			printf("%d. d���m�n de�eri = %d\n", counter++, controler->data);
			controler = controler->next;
		}
	}
	else
		printf("G�sterilecek d���m yok !\n");
	printf("\n");
}

int Delete(node *Removed_Node)
{
	node *controler = root;
	if(Removed_Node != NULL)
	{
		if(Removed_Node == root)
		{
			if(root->next == NULL)
			{
				root->Have_Data = false;
			}
			else
			{
				root = root->next;
				root->previous = NULL;
				free(controler);
			}
			return 1;
		}
		else
		{
			int deletednode = 1;
			while(controler != Removed_Node)
			{
				controler = controler->next;
				deletednode++;
			}
			node *prev = controler->previous;
			node *next = controler->next;	
			free(controler);
			prev->next = next;
			if(next != NULL)
				next->previous = prev;
			iter = root;
			while(iter->next != NULL)
				iter = iter->next;
			return deletednode;
		}
	}
	else
	{
		printf("B�yle bir d���m yok !\n");
		return 0;
	}
}

void Search(int wanted, int selection, boolean Will_Delete)
{
	node *controler = root;
	boolean Is_Found = false;
	int i; int deletednode; int foundnode = 1;
	switch(selection)
	{
		case 1:
			for(i = 0; i < wanted - 1 && controler != NULL; i++)
				controler = controler->next;
			i = Delete(controler);
			if(controler != NULL)
				printf("%d.D���m silindi\n", i);
			Is_Found = true;
			break;
		case 2:
			while(controler != NULL)
			{
				if(controler->data == wanted)
				{
					if(Will_Delete)
					{
						deletednode = Delete(controler);
						printf("%d.D���m silindi\n", deletednode);	
					}
					else
					{
						printf("Aranan veri %d.d���mde\n", foundnode);
					}
					foundnode++;
					Is_Found = true;
					controler = controler->next;
				}
				else
				{
					foundnode++;
					controler = controler->next;
				}
			}
			break;
	}
	if(!Is_Found)
		printf("B�yle bir veri listede yok !\n");
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	root = (node *)malloc(sizeof(node)); /*Root pointer�na bir adet d���m tutacak yer ay�rma.*/
	iter = root; /*��lemleri iter �zerinden yapaca��m�z i�in iteri root a e�itledik.*/	
	int selection; int wanted;
	root->next = NULL;
	root->previous = NULL;
	root->Have_Data = false;
	do
	{
		printf("Listeden yapmak istedi�iniz i�lemi se�in\nEkle[1]\nSil[2]\nD���mleri g�ster[3]\nAra[4]\n��k��[5]\n");
		printf("Se�iminiz: ");
		selection = getch() - '0';
		printf("%d\n", selection);
		switch(selection)
		{
			case 1:
				Insert();
				break;
			case 2:
				do
				{
					printf("S�raya g�re sil[1]\nVeriye g�re sil[2]\nSe�iminiz: ");
					selection = getch() - '0';
					printf("%d\n", selection);
					switch(selection)
					{
						case 1:
							printf("Hangi d���m� silmek istiyorsunuz: ");
							scanf("%d", &wanted);
							Search(wanted, selection, true);
							break;
						case 2:
							printf("Hangi veriyi silmek istiyorsunuz: ");
							scanf("%d", &wanted);
							Search(wanted, selection, true);
							break;
						default:
							printf("Ge�erli bir se�im yap�n�z !\n\n");
							break;
					}
				}while(selection != 1 && selection != 2);
				break;
			case 3:
				Display();
				break;
			case 4:
				printf("Hangi veriyi aramak istiyorsunuz: ");
				scanf("%d", &wanted);
				Search(wanted, 2, false);
				break;
			case 5:
				Loading_Screen("��k�� yap�l�yor");
				break;
			default:
				printf("Ge�erli bir se�im yap�n�z !\n\n");
				break;
		}
	}while(selection != 5);
	free(root);
	return 0;
}
