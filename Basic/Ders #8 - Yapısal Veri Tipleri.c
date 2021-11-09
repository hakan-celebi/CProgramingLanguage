#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Yapýsal Veri Tipleri:
	C dili yapýsal bir programlama dilidir ve kolayca geniþletilebilir. Örneðin, makro fonksiyonlar tanýmlayýp var olan kütüphanelere veya yeni kütüphanelere eklenebilir. Yine ayný
þekilde yeni yazýlan fonksiyonlar da bu þekilde kütüphanelere eklenebilir. Var olan veri tipleri veya daha önce programcý tarafýndan bildirilmiþ veri tipleri kullanýlarak, yeni veri
tipleri oluþturulabilir. Bu yeni veri tiplerinin bildirilmesi "typedef", "struct", "union" ve "enum" anahtar sözcükleri kullanýlarak yapýlýr. "typedef" deyimi ile var olan veri tiplerinin
adlarý deðiþtirilerek daha okunaklý program yazýlabilir. "struct" ile birçok deðiþken bir araya getirilip bir isim verilebilir. "union" da "struct" gibi birçok veri tipini kümelemek için
kullanýlsa da amaç farklýdýr. Amaç bu veri tiplerinin ayný ram gözünü paylaþmalarýdýr. "enum" ise sýnýrlý olarak yeni veri tip kümesi oluþturabilir. Tüm bu anahtar kelimeleri inceleyelim.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-typedef Deyimi:
	#define ön iþlemci komutu gibi bu da var olan veri tipini tekrar isimlendirmek için kullanýlýr. Örneðin typdef int tamsayi; þeklinde bir tanýmlama yapýlmýþ ise artýk tamsayi degisken;
þeklinde int bir deðiþken oluþturabiliriz.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-struct Deyimi: 
	Farklý tiplerden verileri veya ayný veri tiplerinden verileri kümelemek için kullanýlýr. Ýçerisine yazýlan deðiþkenlere bu topluluðun üyesi olarak isimlendirilir. Bu toplulukta bir
deðiþken bildirirken struct topluluk_ismi degisken_ismi; veya struct topluluk_ismi *degisken_ismi; olarak iki þekilde tanýmlama yapabilir. Eðer normal bir deðiþken tanýmlamasý yapýlýrsa
üyelere eriþirken degisken_ismi.uye, pointer tanýmlamasý yapýlmýþ ise, degisken_ismi->uye, þeklinde kullanabiliriz. struct deyimini tanýmlama ve sistemlerini typedef deyimi ile, typedef
deyimi olmadan ve typedef deyimini dýþarda kullanarak yapabiliriz. Ram de kapladýðý alan üyelerinin kapladýðý alanýn toplamýna eþittir.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	2.1-typedef Deyimi olmadan struct:
	struct struct_ismi
	{
		üyeler.
	}degisken_bildirimi, degisken_bildirimi2;
		Yukardaki þekilde tanýmlama yapýlabilir fakat struct_ismi ve degisken_bildirimi kýsýmlarý olmayabilir. Eðer struct_ismi olmaz ise yeni bir topluluk deðiþkeni oluþturmak mümkün
	olamaz ve eðer degisken_bildirimi kýsmý doldurulmuþ ise bu kýsýmlardan baþka da deðiþken bulunamaz. degisken_bildirim kýsmý yazýlmaz ise oluþturma anýnda bir deðiþken bildirimi
	yapýlmýþ olmaz. Eðer struct_ismi kýsmý var ise yeni bir deðiþken oluþturulabilir. Eðer struct_ismi kýsmý yok ise bu topluluk hiç bir iþimize yaramaz.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	2.2-typedef Deyimi ile struct:
	typedef struct struct_ismi
	{
		üyeler.
	}kisaadlandirma, kisaadlandirma2;
		Yukarýdaki þekilde tanýmlama yapýlýlabilir ve yine struct_ismi ve kisaadlandirma kýsýmlarý olmayabilir. Bu þekilde bildirilmiþ bir topluluk deðiþkeni oluþtururken;
			*struct struct_ismi degisken;
			*kisaadlandirma degisken;
			*kisaadlandirma2 degisken;
		Þeklinde yeni deðiþkenler oluþturulabilir. 2.1 bildiriminin aksine alttaki kisaadlandirma kýsmý deðiþken bildirmek için deðil struct struct_ismi yerine kisaadlandirma
	kýsa isimleri kullanabilmemize olanak saðlar.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	2.3-typedef Deyimi dýþarda ile struct:
	struct struct_ismi
	{
	
	}degisken1, degisken2;
	typedef struct_ismi kisaadlandirma;
		Yukarda görüldüðü gibi typedef deyimini dýþarda tanýmlayarak 2.1 bildirimi ile 2.2 bildirimlerinin özelliklerini birleþtirmiþ olduk. Yani iki bildiriminde özelliklerini
	kullanabiliriz.
	---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Yukarýdaki tanýmlamalarý yaptýk fakat 2.1 ve 2.3 sýrasýnda tanýmlanmýþ topluluk deðiþkenlerine veya 2.1, 2.2 ve 2.3 topluluk deðiþkenleri oluþturulduðu sýrada baþlangýç deðeri
atýlmak istenebilir. Baþlangýç deðeri atamalarý dizi baþlangýç deðerleri atamasý ile aynýdýr.	
	
NOT: Bazý donanýmlarda deðiþkenlerin çift alanlara yerleþtirilme kuralý olabilir. Bu da bizim struct tanýmlamamýzda boþa giden bellek alaný olabileceðini gösterir çünkü, struct tipinde
tanýmlanan bir deðiþken tanýmlama yapýldýðý anda ram de üyeleri sýrasý ile bir tanýmlama yapar.
struct t
{
	int val1; 0XAD0 - AXAD4
	char ch; 0XAD5 - 0XAD6
	float val2; 0XAD8 - 0XADA
};
	Yukardaki struct bildirimini int deðiþkenlerini 4'e bölünebilen, float deðiþkenlerini 2'ye bölünebilen adreslere yerleþtiren bir donanýma ait bilgisayar üzerinde çalýþtýrdýðýmýzý
düþünelim. Bu durumda val1 deðiþkeni için ram de 4'e bölünebilen bir adres tutulacak ve ardýndan char deðiþkeni için 1 byte yer ayrýlacak. Dolayýsýyla alttaki kýsým 2'ye bölünemez bir
adres olacaktýr ve bu bellek gözü atlanarak 2'ye bölünebilen alt göze float yerleþtirilecektir. Dolayýsý ile ram de 1 bellek gözü boþa harcanmýþ olacaktýr.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3-union Deyimi: 
	Ortaklýk deyimi olarak adlandýrýlýr. struct deyimi ile bildirilme ve oluþturulma yapýsýndan bire bir aynýdýr. Aralarýndaki tek fark, struct gibi tüm üyelerin ram de kapladýklarý alan
kadar yer kaplamayýp, en çok yer kaplayan üye kadar alan oluþturulmasýdýr.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4-enum Deyimi:
	enum deyimi yeni veri tipi oluþturmak için kullanýlýr. Bu veri tiplerini aktif olarak kullanmaktan ziyade program okunurluðunu arttýrmak için tercih edilir. Yaptýðý iþi int bir
deðiþken ile de yapýlabilir.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*Artýk pointer yazýlan yere tip * gelecektir.*/
typedef char *char_pointer; 
typedef int *int_pointer;
typedef float *float_pointer;

void program1()
{
	char_pointer katar = (char_pointer)malloc(sizeof(char) * 50);
	int_pointer age = (int_pointer)malloc(sizeof(int));
	float_pointer money = (float_pointer)malloc(sizeof(float));
	printf("Ýsim soyisim: ");
	gets(katar);
	katar = (char_pointer)realloc(katar, strlen(katar));
	printf("Yaþ: ");
	scanf("%d", age);
	printf("Para: ");
	scanf("%f", money);
	printf("\n\nÝsim soyisim: %s\nYaþ: %d\nPara: %f TL\n\n", katar, *age, *money);
	free(katar); free(age); free(money);
}

struct program2_1
{
	int intnum;
	char ch;
	float floatnum;
}staticval1 =  {87, 'H', 49.8745}, staticval2;

void program2_1()
{
	puts("Program 1");
	struct program2_1 newstruct = {45};
	staticval2.intnum = 87; staticval2.ch = 'A'; staticval2.floatnum = 147.55;
	printf("%d - %c - %f\n", staticval1.intnum, staticval1.ch, staticval1.floatnum);
	printf("%d - %c - %f\n", newstruct.intnum, newstruct.ch, newstruct.floatnum);
	printf("%d - %c - %f\n", staticval2.intnum, staticval2.ch, staticval2.floatnum);
	puts("\n");
}

typedef struct program2_2
{
	int intnum;
	char ch;
	float floatnum;
}st;

void program2_2()
{
	puts("Program 2");
	st val1; struct program2_2 val2 = {758, 'E', 123.69};
	val1.intnum = 89; val2.ch = 'Y'; val2.floatnum = 78.012;
	printf("%d - %c - %f\n", val1.intnum, val1.ch, val1.floatnum);
	printf("%d - %c - %f\n", val2.intnum, val2.ch, val2.floatnum);
	puts("\n");
}

struct program2_3
{
	int intnum;
	char ch;
	float floatnum;
}staticval3 = {23, 'H', 29.371};

typedef struct program2_3 st2;

void program2_3()
{
	puts("Program 3");
	st2 val1; struct program2_3 val2 = {758, 'E', 123.69};
	val1.intnum = 94; val2.ch = 'A'; val2.floatnum = 231.476;
	printf("%d - %c - %f\n", val1.intnum, val1.ch, val1.floatnum);
	printf("%d - %c - %f\n", val2.intnum, val2.ch, val2.floatnum);
	puts("\n");
}

typedef union program3
{
	unsigned int b; /*4 byte*/
	unsigned char c; /*1 byte*/
}ortak;

void program3()
{
	/*Union deyimi bilindiði gibi en büyük veri tipi kadar alan ayýrtýr. O halde ortak union topluluðu int (4 byte kadar) yer ayýrtacak.*/
	ortak shareval;
	shareval.b = 321; /*0000 0000 0000 0000 0000 0001 0100 0001*/
	/*Görüldüðü gibi shareval deðiþkeninin char üyelesine eleman atýlma iþlemi yapýlmadý. Char için int'ýn en saðdaki 1 byte yazýlýr.*/
	shareval.c = (char)128;
	printf("Ýnt: %u\nChar: %c\n\n", shareval.b, shareval.c);
}

typedef enum md
{
	evli, bekar, dul
}medenidurum;

void program4()
{
	medenidurum kisi;
	kisi = bekar;
	printf("%d\n", kisi);
	kisi = evli;
	printf("%d\n", kisi);
	kisi = dul;
	printf("%d\n", kisi);
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	//program1();
	/*program2_1();
	program2_2();
	program2_3();*/
	program3();
	program4();
}
