#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

/*BÝT DÜZEYÝNDE ÇALIÞMA:
	C dilinde her bir bit için ayrý özel durumlar olduðu durumlar olabilmektedir. Örneðin xxxx 4 bitlik deðerde son hane pozitif ve negatif, 3.bit hata var ve yok, 2.bit yine 0 ve 1 lik
bir durum 1. bit de ayný þekilde olduðu durumlar gözlenebilmektedir. Genellikle micro iþlemci ve mantýksal durumlara göre iþlem gören entegre ve entegre olmayan sistemler, USB, seri ve
paralel I/O portlarý üzerinde iþlemler gerçekleþtirmek için bit düzeyinde çalýþma gereklidir. Yine bir örnek üzerinden konuya deyinelim. C programlama dilinde mantýksal kontrolleri yani,
true/false iþlemlerini gerçel sayý tutan deðiþkenler haricindeki tüm veri tiplerinde saðlayabiliriz. Fakat en az ram de yer kaplayan veri tipi olan char veri tipinde 8 bit vardýr. Bize
tek bit yeterli olduðu için diðer 7 bit boþuna ram de yer kaplamaktadýr. Bit düzeyinde çalýþma bunun için daha performansýldýr diyemeyiz çünkü, struct topluluðunda bildirilen bit
düzeyinde çalýþmak için deðiþken ram de en az bir tamsayýlýk yer kaplamaktadýr.

ÖDEVLER
	-Klavyeden girilen 8 bitlik bir verinin bitlerindeki 1'lerin adeti çift mi tek mi olup olmadýðýný ekrana yazan programý yazýnýz.
	-Klavyeden girilen 16 bitlik bir verinin bitlerinin baþýndaki 1 ise hata var, sonundaki biti 1 ise aksilik yok her ikisi de 1 ise hatalý veri yazan programý yazýnýz.
*/

typedef struct
{
	unsigned short int val : 1; /*':' karakterinden sonra gelen tam sayý deðeri ram de kaç bit yer tutacaðýnýn bildirilmesidir.*/ 
}bool;

void stringtolower(char *string)
{
	register int i;
	for(i = 0; i < strlen(string); i++)
		*(string + i) = tolower(*(string + i));
}

int bytetobit(int size)
{
	return size * 8;
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	bool kont; char *string = (char *)malloc(sizeof(char) * 6); int controller = 0;
	printf("bool size: %d byte = %d bit\nYukarda görüldüðü gibi biz 1 bit yer ayýrmamýza raðmen 2 byte yer gösteriliyor.\n\n", sizeof(bool), bytetobit(sizeof(bool)));
	getch();
	do
	{
		printf("Mantýksal ifadeyi giriniz(true/false): ");
		gets(string);
		string = (char *)realloc(string, sizeof(char) * (strlen(string) + 1)); /*+1 sondaki NULL ifadesi için*/
		stringtolower(string);
		printf("%s\n", string);
		if(!strcmp(string, "true")) /*strcmp geriye int bir deðer dönderir. Dolayýsý ile mantýksal kontrol de false ise 0 anlamýna gelir.*/
		{
			kont.val = 1;
			controller = 1;
		}
		else if(!strcmp(string, "false"))
		{
			kont.val = 0;
			controller = 1;
		}
		else
		{
			free(string);
			string = (char *)malloc(sizeof(char) * 6);
			puts("Yanlýþ deðer girildi !\n");
		}
	}while(controller != 1);
	switch(kont.val)
	{
		case 0:
			puts("Mantýksal ifade FALSE");
			break;
		case 1:
			puts("Mantýksal ifade TRUE");
			break;
	}
	free(string);
}
