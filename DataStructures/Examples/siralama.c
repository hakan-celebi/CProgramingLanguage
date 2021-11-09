#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void sirala()
{
	int i; int j; int dizi[5]; int min; int gecici;
	/*selection*/
	for(i = 0; i < 5; i++)
	{
		min = i;
		for(j = i + 1; j < 5; j++)
		{
			if(dizi[j] < dizi[min])
				min = j;
		}
		gecici = dizi[i];
		dizi[i] = dizi[min];
		dizi[min] = gecici;
	}
	/*bubble*/
	for(i = 0; i < 5; i++) 
	{
		for(j = i + 1; j < 5; j++)
		{
			if(dizi[j] < dizi[j + 1])
			{
				gecici = dizi[i];
				dizi[i] = dizi[j + 1];
				dizi[j + 1] = gecici;
			}
		}
	}
	/*insertion*/
	for(i=1; i<5; i++)
	{
		gecici=dizi[i];
		for(j=i-1; j>=0 && gecici<dizi[j]; j--)
	 	{
	 		dizi[j+1]=dizi[j];
	 	}
	 	dizi[j+1]=gecici;
	};
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int dizi[] = {8,22,3,115,41,23,4}; int i; int j; int pivot = 0; int gecici;
	int sol = 0; int sag = 6; int a = 0;
	while(sol != 1 || sag != 0)
	{
		sol = pivot;
		sag = 6;
		while(dizi[sol] <= dizi[pivot])
			sol++;
		while(dizi[sag] > dizi[pivot])
			sag--;
		if(pivot == 0)
		{
			gecici = dizi[sol - 1];
			dizi[sol - 1] = dizi[pivot];
			dizi[pivot] = gecici;
		}
		if(a == 0)
			a = sol - 1;
		if(dizi[sol] > dizi[pivot] && dizi[sag] < dizi[pivot])
		{
			gecici = dizi[sol];
			dizi[sol] = dizi[sag];
			dizi[sag] = gecici;
		}
		for(i = 0; i < 7; i++)
			printf("%d - ", dizi[i]);
		printf("\n%d - %d\n", sol, sag);
		getch();
	}
	pivot = a;
	printf("Aþa %d - %d\n", a, pivot);
	while(pivot >= pivot)
	{
		sol = pivot + 1;
		sag = 6;
		while(pivot == pivot)
		{
			printf("\n%d - %d\n", sol, sag);
			for(i = 0; i < 7; i++)
				printf("%d - ", dizi[i]);
			getch();
			while(dizi[sol] < dizi[pivot])
				sol++;
			while(dizi[sag] > dizi[pivot])
				sag--;
			gecici = dizi[sol - 1];
			dizi[sol - 1] = dizi[pivot];
			dizi[pivot] = gecici;
			
		}
	}
	return 0;
}

