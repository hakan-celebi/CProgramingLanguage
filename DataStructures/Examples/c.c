#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void ekle(int *dizi, int *last, int *baslangic, int *eklenen)
{
	if((*last == *baslangic && *last != 0 && *baslangic != 0) || (*last == 5 && *baslangic == 0))
	{
		printf("Kuyruk dolu !\n");
	}
	else
	{
		if(*last == 5 && *baslangic != 0)
			*last = 0;
		printf("Veri ekle: ");
		scanf("%d", &dizi[(*last)++]);
		printf("Veri eklendi !\n\n");
		(*eklenen)++;
	}
}

void sil(int last, int *baslangic, int *eklenen)
{
	if(last == 0 && *baslangic == 0) 
		printf("Kuyruk boþ !\n\n");
	else
	{
		if(*baslangic == 4)
			*baslangic = 0;
		else
			(*baslangic)++;
			(*eklenen)--;
		printf("Veri silindi !\n\n");
	}
}

void goster(int dizi[], int baslangic, int eklenen, int last)
{
	if(last == 0 && baslangic == 0)
		printf("Gösterilecek veri yok !\n\n");
	else
	{
		printf("\n");
		int i;
		for(i = 0; i < eklenen; i++)
		{
			if(baslangic == 5)
				baslangic = 0;
			printf("%d.Veri: %d\n", i + 1, dizi[baslangic++]);
			
		}
		printf("\n");
	}
}

void bul(int dizi[], int baslangic, int eklenen)
{
	int i; int aranan;
	printf("Aranacak veri: ");
	scanf("%d", &aranan);
	for(i = 0; i < eklenen; i++)
	{
		if(baslangic == 5)
			baslangic = 0;
		if(dizi[baslangic++] == aranan)
			break;
	}
	if(i == eklenen)
		printf("Veri yok !\n\n");
	else
		printf("Veri bulundu !\n\n");
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int dizi[5]; int i; int secim; int last = 0; int baslangic = 0; int eklenen = 0;
	do
	{
		printf("Ekle[1]\nSil[2]\nGöster[3]\nBul[4]\nÇýkýþ[5]\nSeçim: ");
		secim = getch() - '0';
		printf("%d\n", secim);
		switch(secim)
		{
			case 1:
				ekle(dizi, &last, &baslangic, &eklenen);
				break;
			case 2:
				sil(last, &baslangic, &eklenen);
				break;
			case 3:
				goster(dizi, baslangic, eklenen, last);
				break;
			case 4:
				bul(dizi, baslangic, eklenen);
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
