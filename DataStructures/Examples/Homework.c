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
	int no;
	char name[50];
	char surname[100];
	int birthdate;
	struct n *next;
}node;

typedef struct file
{
	int no;
	char name[50];
	char surname[100];
	int birthdate;
}f;

f *filesdata;
FILE *datafile;
node *root;
node *iter;

int readfile()
{
	int i;
	f *fake_filesdata = filesdata;
	for(i = 0; i < 13; i++)
	{
		fscanf(datafile, "%d    %s %s    %d", &(filesdata->no), filesdata->name,
		filesdata->surname, &(filesdata->birthdate));	
		filesdata++;
	}
	filesdata = fake_filesdata;
	printf("\n\nOkunan veriler;\n\n");
	for(i = 0; i < 13; i++)
	{
		printf("No    Ýsim Soyisim    Doðum Tarihi\n");
		printf("%d    %s %s    %d\n\n", filesdata->no, filesdata->name, filesdata->surname,
		filesdata->birthdate);
		filesdata++;	
	}
	filesdata = fake_filesdata;
	return 1;	
}

void PrimeLinkList()
{
	boolean first = true;
	boolean prime = false;
	int i; int j;
	f *fake = filesdata;
	for(i = 0; i < 13; i++)
	{
		for(j = 2; j <= fake->no; j++)
		{
			if(fake->no % j == 0 && fake->no != 2 && fake->no != j)
			{
				prime = false;
				break;
			}
			else
				prime = true;
		}
		if(prime)
		{
			if(first)
			{
				iter->no = fake->no;
				int a;
				for(a = 0; a < 50; a++)
				{
					iter->name[a] = fake->name[a];
				}
				for(a = 0; a < 50; a++)
				{
					iter->surname[a] = fake->surname[a];
				}
				iter->birthdate = fake->birthdate;
				iter->next = NULL;
				first = false;
			}
			else
			{
				iter->next = (node *)malloc(sizeof(node));
				iter = iter->next;
				iter->no = fake->no;
				int a;
				for(a = 0; a < 50; a++)
				{
					iter->name[a] = fake->name[a];
				}
				for(a = 0; a < 50; a++)
				{
					iter->surname[a] = fake->surname[a];
				}
				iter->birthdate = fake->birthdate;
				iter->next = NULL;
			}
			fake++;
			prime = false;
		}
		else
			fake++;
	}
	node *controler = root;
	printf("\n\n Asal numaralýlar\n\n");
	while(controler != NULL)
	{
		printf("No    Ýsim Soyisim    Doðum Tarihi\n");
		printf("%d    %s %s    %d\n\n", controler->no, controler->name, controler->surname,
		controler->birthdate);
		controler = controler->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	if(fopen("veri.txt", "r") == NULL)
		printf("Dosya açýlamadý!\n\n");
	else
	{
		datafile = fopen("veri.txt", "r");
		filesdata = (f *)malloc(sizeof(f) * 13);
		root = (node *)malloc(sizeof(node));
		iter = root;
		readfile();
		PrimeLinkList();
		free(root);
		free(filesdata);
		fclose(datafile);
	}
	return 0;
}
