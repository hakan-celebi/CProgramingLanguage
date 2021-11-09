#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <locale.h>

struct node *inp_controler; /*Baþtan sondan ekleme silme iþlemlerini yapar.*/

typedef enum boole
{
	false = 0,
	true = 1
}boolean;

typedef struct node
{
	int data;
	boolean inp_checker;
	struct node *next;
}n;

int a = 0;

void Insert(struct node *root)
{
	if(inp_controler->inp_checker == 1)
		a++;
	if(IsFull(root) == 0)
	{
		int inp;
		printf("Stack verisi: ");
		scanf("%d", &inp);
		if(a != 0)
			inp_controler = inp_controler->next;
		inp_controler->data = inp;
		inp_controler->inp_checker = 1;
		if(inp_controler->data == inp)
			printf("%d verisi eklendi...\n\n", inp_controler->data);
		else
			printf("Ekleme baþarýsýz!\n");
	}
	else
		printf("\nStack dolu!\n\n");
	if(a == 0)
		a++;
}

void Delete(struct node *root)
{
	if(IsEmpty(inp_controler) == 0)
	{
		printf("\n%d verisi stack'ten silindi...\n\n", inp_controler->data);
		inp_controler->inp_checker = false;
		inp_controler->data = 0;
		if(inp_controler != root)
		{
			struct node *fake_root = root;
			while(fake_root->next != inp_controler)
				fake_root = fake_root->next;
			inp_controler = fake_root;	
		}
	}
	else
		printf("\nSilinecek veri yok!\n");
}

void Display(struct node *root)
{
	printf("\n");
	if(IsEmpty(root) == 0)
	{
		int i = 1;
		struct node *controler = root;
		while(controler != NULL)
		{
			printf("%d.Eleman: %d\n", i++, controler->data);
			controler = controler->next;
		}
	}
	else
		printf("Stack içerisinde gösterilecek veri yok!\n");
	printf("\n");
}

void Drain(struct node *root)
{
	if(IsEmpty(root) == 0)
	{
		struct node *controler = root;
		while(controler != NULL)
		{
			controler->data = 0;
			controler->inp_checker = 0;
			controler = controler->next;
		}
		inp_controler = root;
		a = 0;
		printf("\nStack boþaltýldý...\n\n");
	}
	else
		printf("\nZaten stack boþ!\n\n");
}

/*Ekleme yapýlmadan önce dolumu diye kontrol eder.*/
int IsFull(struct node *root)
{
	if(root->inp_checker == 0)
		return 0;
	else
	{
		if(inp_controler->next != NULL)
			return 0;
		else
			return 1;		
	}
}

/*Display yapmadan önce boþmu deðilmi diye kontrol eder.*/
int IsEmpty(struct node *root)
{
	if(root->inp_checker == 0)
		return 1;
	else
		return 0;
}

/*Kullanýcýnýn girdiði deðer kadar link list oluþturur.*/
int Create(struct node *iter, int *stack_size)
{
	int i;
	iter->inp_checker = 0;
	iter->next = NULL;
	for(i = 1; i < *stack_size; i++)
	{
		iter->next = (struct node *)malloc(sizeof(struct node));
		iter = iter->next;
		iter->inp_checker = false;
		iter->next = NULL;
	}
	return 1;
}

void AddNode(struct node *iter)
{
	int addsize; int i;
	printf("Stack'i ne kadar geniþleteceksiniz: ");
	scanf("%d", &addsize);
	while(iter->next != NULL)
		iter = iter->next;
	for(i = 0; i < addsize; i++)
	{
		iter->next = (struct node *)malloc(sizeof(struct node));
		iter = iter->next;
		iter->inp_checker = false;
		iter->next = NULL;
	}
}

void DeleteNode(struct node *root, struct node *iter)
{
	char selection; boolean cont;
	while(iter->next != NULL)
		iter = iter->next;
	if(iter->inp_checker == true)
	{
		do
		{
			printf("Silmek istediðiniz stack bölümü içerisinde veri var silmek istiyormusunuz[E-H]: ");
			selection = getch();
			selection = toupper(selection);
			printf("%c\n", selection);
			if((int)selection == (int)'E' || (int)selection == (int)'H')
				cont = 1;
			else
			{
				printf("Lütfen geçerli bir seçim yapýnýz!\n");
				cont = 0;
			}
		}while(cont == 0);
		if(selection == 'E')
		{
			struct node *controler = root;
			boolean con = 0;
			while(controler != iter)
			{
				if(controler->next == iter)
					break;
				else
					controler = controler->next;
			}
			if(inp_controler == iter)
			{
				inp_controler = root;	
				con = 1;
			}
			iter->inp_checker = 0;
			free(iter);
			iter = controler;
			iter->next = NULL;
			if(con == 1)
			{
				while(inp_controler->next != NULL)
					inp_controler = inp_controler->next;
			}
			printf("\nBaþarýyla bölüm silindi...\n");
		}
		printf("\n");	
	}
	else
	{
		struct node *controler = root;
		while(controler != iter)
		{
			if(controler->next == iter)
				break;
			else
				controler = controler->next;
		}
		iter->inp_checker = false;
		free(iter);
		iter = controler;
		iter->next = NULL;
		printf("\nBaþarýyla bölüm silindi...\n\n");
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	struct node *root = (struct node *)malloc(sizeof(struct node));
	struct node *iter;
	int i;
	iter = root;
	inp_controler = root;
	root->inp_checker = false;
	int stack_size; int selection;
	do
	{
		printf("Stack boyutunu giriniz :");
		scanf("%d", &stack_size);
	}while(stack_size < 1);
	if(Create(iter, &stack_size) == 1)
		printf("Stack oluþturuldu...\n");
	do
	{
		printf("Veri ekle[1]\nVeri sil[2]\nStack'i boþalt[3]\nStack'i göster[4]\n");
		printf("Stack'i geniþlet[5]\nStack'i daralt[6]\nÇýkýþ[7]\nSeçiminiz: ");
		selection = getch() - '0';
		printf("%c\n", selection + '0');
		switch(selection)
		{
			case 1:
				Insert(root);
				break;
			case 2:
				Delete(root);
				break;
			case 3:
				Drain(root);
				break;
			case 4:
				Display(root);
				break;
			case 5:
				AddNode(iter);
				break;
			case 6:
				DeleteNode(root, iter);
				break;
			case 7:
				system("CLS");
				printf("Çýkýþ yapýlýyor...");
				sleep(1);
				break;
			default:
				printf("Lütfen geçerli bir seçim yapýnýz!\n");
				break;
		}
	}while(selection != 7);
	free(root);
	free(iter);	
	return 0;
}
