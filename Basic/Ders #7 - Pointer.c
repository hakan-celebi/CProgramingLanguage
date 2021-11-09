#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <locale.h>

/*Pointer:
	pointer Türkçe anlamý ile iþaretçiler ram de deðer yerine adres tutan deðiþkenlerdir. C dilini en etkin ve hala popüler kýlan nedenlerden biri de bu pointerlardýr. O halde pointerlar
bir C programcýsýnýn etkin kullanmasý gereken þeylerden biridir. Adreslerin tutulmasý çeþitli þekilde çok fazla iþimize yararlar. Dizi tanýmlamasýnda bilindiði gibi baþlangýç ta tanýmlama
anýnda boyutu bildirilmesi gerekmektedir ve bu dizi iþlevini yitirse veya kullanýlmayan alanlar olduðu zaman da ram de boþuna yer tutmaktadýr. Bunun için pointerlar kullanarak C standart
kütüphanelerinde bulunan bazý fonksiyonlar iþimizi görecektir. Buna dinamik bellek yönetimi ismi verilmektedir. Ayný þekilde katarlarýn tutulmasýnda da birçok avantajý vardýr. Bir katarýn
boyutu çoðunlukla eðer dizi ile kullanýlacaksa tahmin usulü yapýlacaktýr. Bunun yerine dinamik bellek yönetimi ile istenilen karakter boyutu kadar yer ayrýlýrsa katarlar da daha
performanslý ve etkin bir biçimde kullanýlacabilecektir. Diðer bir avantajý ise, bilindiði gibi fonksiyonlar geriye return deyimi ile deðer dönderebilir ve sadece tek bir deðer
dönderebilirler. Eðer pointer kullanýlarak return edilirse birden fazla bir deðeri de geriye dönderme þansýný bulabiliriz. Dikkat edilmesi gereken pointerlar ram de ayrýlan alanýn
baþlangýç adresini tutarlar. Genel olarak özellikleri de þu þekilde özetlenebilir.
	-Daha performanslý.
	-Daha hýzlý.
	-Verilere eriþim daha kolay.
	Bildirilirken normal bir deðiþken bildiriminde deðiþken isminin önüne '*' koyularak bildirilirler. Tip belirtilmesi gerekse de tüm tiplerde bildirilen pointerlar ram de ayný miktarda
derleyiciye baðlý yer iþgal eder.
NOT: Normal bir deðiþken için isminin baþýna eðer '&' gelir ise adresini gösterir. Ayný þekilde bir pointer için de '&' gelir ise kendi adresini göstermektedir. Pointerlarda sadece ismi
ile yazýlýrsa gösterdiði adresi, isminin baþýna '*' gelir ise gösterdiði adresin deðerini döndermektedir.

Pointer Aritmetiði:
	int *ptr; örneði üstünden bir örnekleme ile &ptr, ptr ve *ptr için aritmetik iþlemleri inceleyeceðiz.
	-&ptr: Hiç bir aritmetik iþlem yapýlamaz.
	-ptr: Tüm hepsi yapýlabilir fakat bu sefer gösterdiði adresin tipi kadar sekizli ilerletilir.
	*ptr: Normal bir deðiþken gibi tüm aritmetik iþlemler yapýlabilir fakat dikkat edilmesi gereken '*' operatörünün kapsadýðý alandýr. Örneðin *ptr++; adres arttýrdýktan sonra
	arttýrlýlan adresin deðerini gösterecektir. Gösterdiði deðeri arttýrmak için (*ptr)++; þeklinde kullanýlmasý gerekmektedir. ++*ptr; çiminde kullanmakta da hiçbir sakýnca yoktur.
 
Pointer Karþýlaþtýrýlmasý:
	Yine &ptr, ptr ve *ptr için ayrý ayrý konuþmak gerekmektedir.
	-&ptr ve ptr: Ýkisi de adres gösterdiðinden ötürü karþýlaþtýrma operatörlerinin hepsi kullanýlmasýna karþý ek olarak bilinmesi gereken NULL deðeri. &ptr asla NULL deðerini alamaz
	dolayýsýyla bu sadece ptr için geçerli olmaktadýr. ptr = 5; gibi bilindiði gibi atama yapýlamaz 0 hariç. 0 stdio.h kütüphanesi içerisinde NULL deðerine eþittir. Bir adres asla 0
	olamaz dolayýsý ile 0 veya NULL olarak kullanýlabilir.
	*ptr: Normal deðiþkenler ile ayný karþýlaþtýrma iþlemi yapýlýr.

Dinamik Bellek Yönetimi:
	stdlib.h kütüphanesi içerisindeki, malloc, calloc, realloc ve free fonksiyonlarý ile (bazý derleyicilerde farklý fonksiyonlarda vardýr) yapýlýr. Bu fonksiyonlarýn iþlevleri önceki
derste iþlenmiþti. program1 fonksiyonu içerisinde yapýlan örnek te gerekli yerler açýklanmýþtýr.

Ýþaretçi Fonksiyonlar:
	Bu fonksiyonlar da geriye belirtilen tipdeki adresleri dönderir. Dolayýsý ile bir dizinin adresini döndererek aslýnda diziyi geriye dönderebiliriz.


ÖDEVLER:
	-program1() in kayýtlarý istenilen yerden silen programý yazýnýz.
	-Kullanýcýdan aldýðýnýz dizinin elemanlarýný rastgele çarpan ve geriye yeni bir dizi halinde dönderen bir program yazýnýz.
	-int bir dizi için parametre olarak girilen bir deðer bu dizi içerisinde ise 1, deðilse 0 dönderen bir fonksiyon yazýnýz.
	-Ýki boyutlu pointer dizi kullanarak isim, soyisim, passport_no tutan bir program yazýnýz.
	
*/

typedef struct
{
	char *passport_no;
	char *name;
	char *surname;
	struct tm *birth_date;
	short int age;
}person;

void program1()
{
	person *p = NULL; /*Kiþileri tutan deðiþken.*/
	time_t now = time(NULL); /*Þuan ki zamaný saniye cinsinden tutan deðiþken.*/ time_t bd; /*Doðum tarihini saniye cinsinden tutan deðiþken.*/ time_t tempt;
	struct tm *temptime;
	int n = 0; /*Kayýt sayýsýný tutan deðiþken.*/ int selection; int i;
	do
	{
		printf("Kiþi ekle[1]\nSon kaydý sil[2]\nKayýtlarý göster[3]\nÇýkýþ[0]\nSeçim: ");
		selection  = getch() - '0';
		switch(selection)
		{
			case 1:
				n++;
				if(p != NULL)
					p = (person *)realloc(p, sizeof(person) * n);
				else
					p = (person *)malloc(sizeof(person) * n);
				(p + (n - 1))->passport_no = (char *)malloc(sizeof(char) * 11);
				(p + (n - 1))->name = (char *)malloc(sizeof(char) * 50); /*Geçici olarak kaç adet karakter girileceðini bilmediðimiz için 50 girildi.*/
				(p + (n - 1))->surname = (char *)malloc(sizeof(char) * 50);
				printf("Kiþi ekle\nPasaport no: ");
				scanf("%s", (p + (n - 1))->passport_no);
				printf("Ýsim: ");
				scanf(" ");
				gets((p + (n - 1))->name);
				printf("Soyisim: ");
				scanf(" ");
				gets((p + (n - 1))->surname);
				(p + (n - 1))->name = (char *)realloc((p + (n - 1))->name, sizeof(char) * strlen((p + (n - 1))->name)); /*Boþ alanlarý boþuna yer iþgal etmemesi için
				serbest býrakýlýyor.*/
				(p + (n - 1))->surname = (char *)realloc((p + (n - 1))->surname, sizeof(char) * strlen((p + (n - 1))->surname));
				(p + (n - 1))->birth_date = (struct tm *)malloc(sizeof(struct tm));
				(p + (n - 1))->birth_date->tm_hour = (p + (n - 1))->birth_date->tm_isdst = (p + (n - 1))->birth_date->tm_min = (p + (n - 1))->birth_date->tm_sec = 0;
				printf("gün/ay/yýl formatýnda doðum tarihi: ");
				scanf("%d/%d/%d", &((p + (n - 1))->birth_date->tm_mday), &((p + (n - 1))->birth_date->tm_mon), &((p + (n - 1))->birth_date->tm_year));
				(p + (n - 1))->birth_date->tm_year -= 1900; /*Zaman topluluðu içerisinde zamanlar -1900 ile tutulur.*/
				bd = mktime((p + (n - 1))->birth_date);
				tempt = difftime(now, bd);
				temptime = (struct tm *)localtime(&tempt);
				(p + (n - 1))->age =  temptime->tm_year - 70;
				puts("Ekleme iþlemi baþarý ile tamamlandý !\n");
				break;
			case 2:
				n--;
				printf("Son kaydý sil\n");
				p = (person *)realloc(p, sizeof(person) * n);
				puts("Son kayýt baþarý ile silindi !");
				break;
			case 3:
				printf("Kaydý göster\n\n");
				for(i = 0; i < n; i++)
				{
					printf("%d.Kayýt:\nPasaport no: %s\nÝsim Soyisim: %s %s\nDoðum tarihi: %d/%d/%d\nYaþ: %d\n\n", i + 1, (p + i)->passport_no, (p + i)->name, (p + i)->surname
					, (p + i)->birth_date->tm_mday, (p + i)->birth_date->tm_mon, (p + i)->birth_date->tm_year + 1900, (p + i)->age);
				}
				puts("Kayýtlar baþarý ile sýralandý !\n");
				break;
			case 0:
				puts("Çýkýþ\n");
				break;
			default:
				puts("Seçim geçerli deðil tekrar deneyiniz !\n");
				break;
		}
	}while(selection != 0);
	free(p);
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	program1();
}
