#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void ekle(int *dizi, int *last)
{
	if(*last == 5)
		printf("Kuyruk dolu !\n\n");
	else
	{
		printf("Veri ekle: ");
		scanf("%d", &dizi[(*last)++]);
		printf("Veri eklendi !\n\n");
	}
}

void sil(int *dizi, int *last)
{
	if(*last == 0)
		printf("Kuyruk boþ !\n\n");
	else
	{
		int i;
		(*last)--;
		for(i = 0; i < *last; i++)
			dizi[i] = dizi[i + 1];
		printf("Veri silindi !\n\n");
	}
}

void goster(int dizi[], int last)
{
	if(last == 0)
		printf("Gösterilecek veri yok !\n\n");
	else
	{
		printf("\n");
		int i;
		for(i = 0; i < last; i++)
			printf("%d.Veri: %d\n", i + 1, dizi[i]);
		printf("\n");
	}
}

void bul(int dizi[], int last)
{
	int i; int aranan;
	printf("Aranacak veri: ");
	scanf("%d", &aranan);
	for(i = 0; i < last; i++)
	{
		if(dizi[i] == aranan)
			break;
	}
	if(i == last)
		printf("Veri yok !\n\n");
	else
		printf("Veri bulundu !\n\n");
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int dizi[5]; int i; int secim; int last = 0;
	do
	{
		printf("Ekle[1]\nSil[2]\nGöster[3]\nBul[4]\nÇýkýþ[5]\nSeçim: ");
		secim = getch() - '0';
		printf("%d\n", secim);
		switch(secim)
		{
			case 1:
				ekle(dizi, &last);
				break;
			case 2:
				sil(dizi, &last);
				break;
			case 3:
				goster(dizi, last);
				break;
			case 4:
				bul(dizi, last);
				break;
			case 5:
				
				break;
			default:
				printf("Seçim yanlýþ !\n\n");
				break;
		}
	}while(secim != 5);
	return 0;
}
