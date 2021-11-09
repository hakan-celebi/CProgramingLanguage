#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");
	float sayi_1; float sayi_2; int toplam;
	printf("Aralarýnda + býrakarak iki adet gerçel sayý giriniz: ");
	scanf("%f+%f", &sayi_1, &sayi_2);
	toplam = sayi_1 + sayi_2;
	printf("Toplamlarýnýn int hali: %d", toplam);
	return 0;
}
