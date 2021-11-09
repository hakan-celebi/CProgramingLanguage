#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/*DÝZÝLER:
	Diziler ayný tipde verilerin bir arada kümelenmesidir. Bir dizinin boyutu [size] arasýna boyut bildirilerek yapýlýr. Daha fazla köþeli parantez eklenerek boyut arttýrýlabilir.
Diziler tek boyutlu (vektör), iki boyutlu (matris) ve çok boyutlu olarak sýnýflandýrýlabilir.
1-Tek Boyutlu Diziler (Vektör): 
	type name[size] biçiminde tanýmlanýrlar ve eðer type name[] = {elements}; þeklinde tanýmlama yapýlmaz ise mecburen köþeli parantezler arasýna size bildirimi yapýlmalýdýr.
2-Ýki Boyutlu Diziler (Matris):
	type name[size(satýr olarak düþünülebilir)][size(sütun olarak düþünülebilir)]; biçiminde tanýmlanýr ve eðer type name[][size] = {elements}; þeklinde tanýmlama yapýlmaz ise ilk
size belirtilmelidir. Ýkinci size her daim belirtilmelidir çünkü dizi [3][2] mi [2][3] mü biçimde bildirileceðini bilemez. Eleman atamasýnda ise örneðin [5][3] lük bir dizi düþünelim
bunun atamasý iki þekilde yapýlabilir.
	-Küme içinde kümeleme: {{77, 88, 54}(Burada 0 için 0, 1 ve 2. indislere atama yapýlýyor), {48, 88, 97}(Burada 1 için 0, 1, 2. indislere atama yapýlýyor), ...} þeklinde kümelenerek
	ait olunan yerlere deðer atamasý yapýlabilir.
	-Direkt olarak: {0, 1, 5, 8} þeklinde atama yapýlýrsa eðer indisleme 00, 01, ... þeklinde ilerleyecektir.
3-Çok Boyutlu Diziler:
	Tek boyutlu diziden sonra iki boyutlu diziler için nasýl bir deðiþiklik yapýldý ise çok boyutlu için de ayný kurallar geçerlidir. Ek olarak sadece boyut kadar [] eklenir.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Dizilerin Fonksiyona Parametre Olarak Gönderilmesi:
	Diziler fonksiyonlara parametre gönderilirken yine tek ve iki boyutlu için incelenirler. Ýki boyutlu dizilerde uygulanacak kural da çok boyutlular için geçerlidir.
1-Tek Boyutlu Diziler Ýçin:
	Öncelikle fonksiyonlara parametre aktarýmý yýðýn üzerinden yapýlmaktadýr. Biz tüm dizi elemanlarýný göndermek yerine dizi ismi yazýlarak sadece dizinin ilk elemanýnýn adresini
gönderiyoruz ve dizinin aslýnda iki elemanlýymýþ gibi davranmasýný saðlýyoruz. Ýlerlettikçe ilk adres sabit kalsa da ikinci altýndaki adres deðiþmekte olur. [] arasýna birþey
NOT: Dizi ismi ary için
	ary = &ary[0]
	*ary = ary[1]
tanýmlamasýna gerek yoktur parametre aktarýmý da atama iþlemi ile benzerdir.
2-Ýki Ve Çok Boyutlu Diziler Ýçin:
	Yine ayný þekilde ilk size için [] deðer yazýlmasý gerekmez ama diðerleri belirtilmek zorundadýr.
NOT: Dizi ismi ary için
	ary = ary[0] = &ary[0][0]
	*ary = ary[0] = &ary[0][0]
	**ary = ary[0][0]
	Yukarda görüldüðü üzere *ary ile ary ayný gibi gözükür farklarý ise þudur; ary tüm kümeyi kapsayacak þekilde baþlangýç adresi tutarken, *ary belirtilen indis için yani 0. indisin
0, 1, ...., n. idisleri için adres tutar.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

int enbuyuk(int dizi[10], int lenght)
{
	int enbuyuk = 0; int i;
	printf("%d\n", sizeof(dizi));
	for(i = 0; i < lenght; i++)
	{
		if(dizi[i] > enbuyuk)
			enbuyuk = dizi[i];
	}
	return enbuyuk;
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	int ary[10]; int i; int j; int mary[5][2]; int counter = 0;
	int tary[2][3] = {{0, 1}, {8, 7, 3}};
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)
			printf("tary[%d][%d]: %d\n", i, j, tary[i][j]);
	}
	for(i = 0; i < 10; i++)
		*(ary + i) = rand() % 100;
	for(i = 0; i < 10; i++)
		printf("%d.eleman: %d\n", i + 1, *(ary + i));
	printf("%p - %p\n", ary, &ary[0]);
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 2; j++, counter++)
				*(mary[i] + j) = rand() % 100;
			
	}
	counter = 0;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 2; j++, counter++)
			printf("[%d]", **(mary + counter));
		printf("\n");
	}
	printf("%p - %p - %p\n", mary, mary[0], &mary[0][0]);
	printf("En büyük eleman: %d\n", enbuyuk(ary, sizeof(ary) / 4));
}
