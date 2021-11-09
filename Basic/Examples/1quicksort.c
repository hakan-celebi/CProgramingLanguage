#include <stdio.h> /*STANDART I/O KÜTÜPHANESÝ*/
#include <stdlib.h> /*MALLOC GÝBÝ BAZI STANDART FONKSÝYON KÜTÜPHANESÝ*/
#include <stdarg.h> /*ESNEK ARGÜMAN AKTARIMI KÜTÜPHANESÝ*/
#include <errno.h> /*errno DEÐÝÞKENÝNÝN BÝLDÝRÝMÝ YAPILAN KÜTÜPHANE*/
#include <time.h> /*TARÝH VE ZAMAN FONSKÝYONLARININ KÜTÜPHANESÝ*/
#include <ctype.h> /*KARAKTERLER ÜZERÝNDE ÝÞLEM YAPAN KÜTÜPHANE 1.1*/
#include <string.h> /*KATARLAR ÜZERÝNDE ÝÞLEM YAPAN KÜTÜPHANE 2.1*/
#include <locale.h> /*LOKALÝZASYON FONKSÝYONLARININ BÝLDÝRÝMÝ YAPILAN KÜTÜPHANE*/

void quicksort(int ary[], int left0, int right0)
{
	int left = left0;= r int right = right0; int pivot; int temp = left0; int i;
	for(i = 0; i < (right0 - left0) / 2; i++)
		temp++;
	pivot = ary[temp];
	do
	{	
		while(ary[left] < pivot)
			left++;
		while(ary[right] > pivot)
			right--;
		if(left < right)
		{
			temp = ary[left];
			ary[left] = ary[right];
			ary[right] = temp;
			if(ary[left] == ary[right])
				left++;	
		}
	}while(left < right);
	if(left0 < right)
		quicksort(ary, left0, right - 1);
	if(left < right0)
		quicksort(ary, left + 1, right0);	
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	int arylenght; int i;
	printf("Dizi boyutu: ");
	scanf("%d", &arylenght);
	int ary[arylenght];
	for(i = 0; i < arylenght; i++)
		ary[i] = -100 + rand() % 200; /*-100 ile 100 arasýnda deðer alýr.*/
	puts("Dizinin içeriði: ");
	for(i = 0; i < arylenght; i++)
		printf("ary[%d]: %d\n", i, ary[i]);
	puts("Sýralama fonksiyonu çaðrýlýyor !");
	quicksort(ary, 0, arylenght - 1);
	puts("Dizinin içeriði: ");
	for(i = 0; i < arylenght; i++)
		printf("ary[%d]: %d\n", i, ary[i]);
}
