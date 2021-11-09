#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");
	int sayi_1; int sayi_2; int sayi_3;
	printf("Aralarýna - koyarak üç adet sayý giriniz: ");
	scanf("%d-%d-%d", &sayi_1, &sayi_2, &sayi_3);
	printf("(%d + %d) / %d = %d", sayi_1, sayi_2, sayi_3, (sayi_1 + sayi_2) / sayi_3);	
	return 0;
}
