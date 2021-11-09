#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#define kareal(x) (x * x)
#define dairealan(r) (3.14 * kareal(r))
#define < (
#define > )
#define makro<x> (x + x)

/*Fonksiyonlar:
	C Programlama dili fonksiyonlardan inþa edilen bir programlama dili olarak tanýmlanabilir. Bütün fonksiyonlar çaðrýlma yolu ile çalýþmaya baþlar ve iþlemi bittikten sonra 
çaðrýldýklarýyere tekrar dönerler. Her fonksiyonun geriye dönderdiði bir tip olabilir veya olmayabilir. Eðer bir fonksiyonun geriye dönüþ tipi olmamasýný yani return kullanmak
istemiyorsak void olarak, eðer geriye dönüþ tipi olmasýný istiyorsak da tip belirttiysek mecburen return kullanmamýz gerekir yoksa program hatalý olacaktýr. Bütün deðiþken tiplerinde
fonksiyon olabilir. Bir fonksiyon void veya tip olmadan yazýlýr ise varsayýlan olarak bu fonksiyon int olur. Fonksiyonlarý da 3 grupta inceleyebiliriz.

1-main() Fonksiyonu: Fonksiyonlarýn çaðrýlmasý gerektiðini söylemiþtik peki main fonksiyonunun çaðrýldýðý yer nerede ? main fonksiyonu da çaðrýlýr fakat program kodlarý içerisinde deðil
de iþletim sistemi tarafýndan çaðrýlýrlar, yani C programýný yazdýktan sonra derleyip çalýþtýrýyoruz, daha sonra iþletim sistemi çalýþtýrma sýrasýnda main fonksiyonunu çaðýrýyor.
	main fonksiyonunu bu zamana kadar parametresiz gördük, bu derste ise main fonksiyonunun 2 adet parametresi vardýr ve biz bunlardan bahsedeceðiz. El ile yazdýðýmýz fonksiyonlarda
nasýl parametreleri tanýmlama varsa burada da vardýr fakat bunlarýn tipleri int ve pointer char olmak üzere sýnýrlýdýr. Örneðin biz bir oyun programý yazdýk ve kullanýcýnýn oyuna
girmeden önce kullanýcý adý ve þifresini girmesini istedik. Bizim 2 adet 5 lvl ve 10 lvl olan kullanýcýlarýmýz olsun ve bunlarýn oyuna girdiklerinde girecekleri mapler farklý olsun,
ne yapmamýz gerekir ? Girilen kullanýcýnýn önce levelini alýp sonra buna göre map.c programýný çalýþtýrmamýz gerekir. Bunu da console üzerinden derleyerek (windows için cmd, linux için
komut defterine) parametre girerek çalýþtýrmamýz gerekir. Derlenirken -> Bu ders için derlenen exe dosyasýnýn konumunu bulmamýz gerekir ve ona göre çalýþtýrýlmalýdýr. (C dizinininin 
içerisindeki program files dosyasý içerisinde olduðunu varsayarak) 
										kullanici leveli (örneðimiz için level 5 veya 10) C/program files/Ders #4 - Fonksiyonlar.exe
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	int genellikle argc (arguman count): Bu parametre fonksiyona gönderilen verilerilerin adetini tutar varsayýlan olarak 1'dir. Bu uygulamanýn ismidir bizim ders dosyasý için
	Ders #4 - Fonksiyonlar.exe'dir.
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	char genellikle *argv (arguman variable): Bu parametre fonksiyona gönderilen verileri tutar. Varsayýlan olarak yukarda da dediðimiz gibi uygulamanýn ismini barýndýrýr.
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NOT: Burda main fonksiyonu için bir örnek program yazdýk ve ne kadar parametre gönderilirse gönderilsin çalýþacaktýr, siz de kendi istediðiniz parametreleri girerek, derlenen exe 
dosyasýnýn konumuna göre derleyin ve örneði inceleyin.


2-Programcý Tarafýndan Yazýlan Fonksiyonlar:
	Programcýnýn bir iþi gerçekleþtirmek için, fonksiyonun tipini ve argümanlarýný(parametreler) belirleyerek yazdýðý fonksiyonlardýr. Fonksiyonlarýn isimleri, okunmada kolaylýk
saðlamasý ve ekip çalýþmasýna uygun olmasý gereði, yaptýðý iþ ile ilgili olmalýdýr. Bu fonksiyonlar void(tipsiz), int, char vb.(tipli) veya iþaretçi(pointer) biçiminde olabilir. void
bir fonksiyon geriye bir deðer döndermez(return anahtar kelimesi kullanýlmaz) çalýþýr ve biter. int vb.(tipli) fonksiyonlar geriye return anahtar kelimesi ile belirtilen tipde
çaðrýldýðý yere deðer dönderir. Ýþaretçi tipinde bir fonksiyon ise geriye address dönderir.(NOT: Ýþaretçi fonksiyonlar haricindeki fonksiyonlar geriye NULL döndermezler.) Fonksiyon
tanýmlarken;
'fonksiyon tipi' fonksiyon_ismi(parametre_tipi parametre_ismi) Ýstenilen sayýda istenilen tipte parametre girilebilir.
{
	Çalýþmasýný istediðimiz kodlar.
	
	return 'deðer'; Fonksiyon return gördüðü yerde çaðrýldýðý yere gider yani return break gibi fonksiyonu sonlandýrýr.
}
þeklinde tanýmlama yapabilirken ilk baþta prototip olarak tipini, parametrelerin tipini ve ismini belirttiðimiz bir fonksiyon yazabiliriz. Prototip fonksiyon yazýlýrken
'fonksiyon tipi' fonksiyon_ismi(parametre_tipi, parametre_tipi) parametrelerin sadece tipleri belirtilir.
þeklinde yazýlýr ve daha sonra bu fonksiyonun içeriðini yazmamak için
'fonksiyon tipi' fonksiyon_ismi(parametre_ismi, parametre_ismi) Bu sefer de yanlýzca parametre ismi girilir çünkü prototipde parametrelerin tipini belirlemiþtik
{
	yapýlacak iþlemler.
}
	Fonksiyonlar sadece tipleri gereði deðil parametreleri gereði de birbirlerinden ayrýlabilirler. Ýlk olarak int topla(int, int); þeklinde fonksiyon oluþturmuþ olalým bu fonksiyonun
yaptýðý iþ de iki tamsayýyý toplayýp geriye döndermek olsun. Daha sonra da float topla(float, float) þeklinde iki adet ondalýklý sayýyý toplayýp geriye bu toplamý dönderen bir fonksiyon
olsun. Peki iki adet deðiþkeni farklý tiplerde olsalar bile tanýmlayamazken, iki adet ayný isimli fonksiyon nasýl oluþtu ve madem yapýlýyor program hangisine gideceðini nerden biliyor ?
Bunu þu þekilde açýklarsak tipleri ve argümanlarý farklý istediðimiz sayýda ayný isimde fonksiyon oluþturabiliriz ve program çaðrýlma kýsmýnda eðer float ise ondalýklý için yazýlan
fonksiyonu, tam sayý ise tamsayý için yazýlan fonksiyonu çaðýrýr. Yine fonksiyonlar sadece tipleri ve parametreleri gereði deðil yaptýklarý iþlem ile de birbirleri ile ayrýlýrlar.
Bunlara "CALL BY VALUE" ve "CALL BY REFERANCE" denir.
	ÝKÝ YAPI DA int a = 5; int b = 3; ÞEKLÝNDE TANIMLANMIÞ ÝKÝ DEÐÝÞKEN ÝÇÝN  a'NIN DEÐERÝ ÝLE b'NÝN DEÐERÝNÝ DEÐÝÞTÝRMEYE YÖNELÝK OLACAKTIR ÖRNEKLERÝ cbvOrnek VE cbrOrnek FONKSÝYONLARI
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	"CALL BY VALUE" -> Bir fonksiyon yanlýzca tek bir deðeri return eder, yani return etmemiz bizim bir iþimize yaramaz dolayýsý ile fonksiyonun tipi void olacaktýr. E peki biz burda ne
	yapacaðýz ? Mecburen yer deðiþtirme iþleminin ardýndan fonksiyon içerisinde deðiþken deðerlerini yazdýrmamýz gerekecektir çünkü, deðerler fonksiyondan sonra ram üzerinden silinecek.
	
Ýþaretçi Ýle Fonksiyon Çaðýrma:
	Bazý durumlarda iþaretçi ile fonksiyon çaðýrmak gerekebilir. Örneðin kullanýcýdan iki adet sayý alalým ve bunlarýn toplamlarý, farklarý, bölümleri ve çarpýmlarýný bulan
fonksiyonlara göndermek isteyelim bunun için direkt fonksiyon ismi ile çaðýrmak amelelik olacaktýr bu yüzden iþaretçi ile fonksiyon çaðýrma yöntemine ihtiyaç duyulur. Bu iþlem
'fonksiyonun_tipi' (*foknsiyonun_çaðrýlacaðý_deðiþken_ismi) (argüman_tipleri);
þeklinde olacaktýr. Bu þekilde iþlem yapýlýr yukarda da birden fazla fonksiyonu ayný argümanlar için çalýþtýrmak için örnek verdik iki adet örnek verilecektir bunlar main fonksiyonunda
incelenerek anlaþýlacaktýr.

Bir Foknsiyona Belirsiz Sayýda Parametre Gönderimi
	Bu konuda bize gerekli olan <stdarg.h> kütüphanesidir. Örnek üzerinden bizim bir firmamýz olduðunu ve bu firmanýn herhangi x departmanýnda 50 tane personel çalýþtýðýný düþünelim,
bu personellere ortalama ne kadar maaþ verildiði öðrenilip bu ortalamaya göre bütün çalýþanlara yýlda 1 kez prim verileceðini varsayýlým. Biz C dili üzerinden bu fonksiyonu yazdýk
fakat hem zahmetli oldu hemde departmana yeni bir personel gireceði zaman tekrardan kodlarý açarak düzeltmemiz gerektiði gözlendi. O halde bizim bir fonksiyon oluþturmamýz ve otomatik
olarak tüm parametreleri toplayýp parametre sayýsýna bölen bir program yazmamýz gerekiyor. Bir örnek ile ortalamaOrnek fonksiyonu içerisinde anlatýlacaktýr.

Recursive (Özyinemeli) Fonksiyon:
	Kendi kendini yineleyen, çaðýran fonksiyonlardýr. Döngüler gibi çalýþýr ve kendi içerisinde fonksiyon tekrar çaðrýlýr. Fonksiyon içerisinde bir kontrol yapýsý olmazsa, ilk
çaðrýldýðý yere dönemez ve sonsuz döngüye girer. Recursive fonksiyonlar döngülere göre daha yavaþtýr ve daha fazla bellek alaný kullanýrlar. Fakat recursive fonksiyononun avantajý
daha kolay ve daha okunabilir yazýlmasýdýr. Ayný zamanda recursive olmadan yapýlamayacak veya yapýlsa bile daha performansýz veya daha zor uygulamalar olacaktýr. recursive isimli 
fonksiyon ile faktoriyel hesaplanan örnek bir program yazýlmýþtýr.

#define Öniþlemci Kodu:
	#include gibi #define da öniþlemci kodudur. Peki nedir bu öniþlemci kodu ? Öniþlemci kodu program derlenmeye baþladýktan sonra ilk baþta çalýþtýrýlan sonra ana kodumuza döndükten
sonra bu öniþlemci kodlarýna göre iþlem yapmamýza yarayan þeydir. #include enjekte etmek gibi düþünülebilir. #define ise tanýmlama veya yerine tanýmlama olarak düþünülebilir. Nasýl
yani ?
#define 'printf' 'yaz'
#define sonuna ';' koyulmaz. Yukardaki tanýmlama örneðinde programda yaz görülen yerde (büyük küçük harf duyarlýdýr) printf yazmasý anlamýna gelir yani bu ne iþimize yarar ?
yaz("metin"); þeklinde yazýlan þey aslýnda -> printf("metin"); anlamýna gelir.

Makro Fonksiyonlar:
	Makro fonksiyonlar #define öniþlemci kodu ile tanýmlanan ve belirli bir iþi yapmak amacý ile yazýlan fonksiyonlardýr. Yazýmlarý da performanslarý da diðer fonksiyonlara göre
oldukça iyidir. Bunun yaný sýra makro fonksiyonlar geriye bir deðer döndermez, aritmetik iþlemlerin yaptýðý gibi doðasý gereði yaptýðý iþlemi dönderir. Ayný zamanda da bu fonksiyonlar
argümanlarý için bir tip istemezler istedikleri tipde argüman ile iþlem yapabilirler. Sadece argüman sayýlarý belirlidir. Kütüphane tanýmlamasý yapýlan yerde makro fonksiyonlar tanýmlý
ve iþlemleri yine main üzerinden takip ediniz.

ÖDEVLER
	-Bir fonksiyon 3 adet parametre alýyor ve biz de bu fonksiyona yanlýzca 2 adet parametre göndermek istiyoruz bunun için ne yapabiliriz ?
	-Ayný isimli farklý parametreli iki adet fonksiyon oluþturmak ile ilgili bir örnek yapýn.
	-Recursive fonksiyon ile yazýlmasý daha uygun olan bir program yazýnýz.
	-Kendi kütüphaneni (header, baþlýk dosyasý, .h) nasýl oluþturursun öðren ve yaz.
	-Bir sayýnýn karesini, karekökünü, çiftmi tek mi olduðunu ve asal olup olmadýðýný öðrenen programý iþaretçi ile fonksiyon çaðrýma yöntemi kullanarak yazýnýz.
*/
 
void cbvOrnek(int a, int b)
{
	int temp; /*Deðiþken isimlerini ingilizce tercih etmek buna alýþmak daha yararlýdýr. temp(geçici) bir deðiþken*/
	temp = a;
	a = b;
	b = temp;
	printf("Call By Value Deðiþtirme Fonksiyonu Ýçerisinde a = %d, b = %d\n", a, b);
	/*Görüldüðü üzere burada parametrelere akdarýlan deðerlerin yerlerini deðiþtirebildik fakat printf fonksiyonu ile burada yazdýk çünkü, fonksiyonlar içerisinde oluþturulmuþ yerel
	deðiþkenler ve parametreler fonksiyon bittikten sonra ram üzerinden silinirler(static deðiþkenler hariç).*/
}

/*CALL BY REFERANCE FONKSÝYONLARI ÝÇÝN ÝKÝ SEÇENEK VARDIR 1.SÝ ÝÇÝN cbrOrnek1, 2.SÝ ÝÇÝN cbrOrnek2 FONKSÝYONLARI YAZILACAKTIR.*/
void cbrOrnek1(int *a, int *b)
{
	int temp;
	temp = *a; /* (*a) þeklnide yazdýk çünkü pointer tanýmlamadan sonra deðiþken (*) ile kullanýrsa, gösterdiði adresteki deðer bölmesini gösterir.*/
	*a = *b;
	*b = temp;
	printf("Call By Referance Deðiþtirme Fonksiyonu Ýçerisinde a = %d, b = %d\n", *a, *b);
}

/*void cbrOrnek1(int &a, int &b)
{
	/*Parametre tanýmlamalarýnýn ve parametrelerin deðiþkenlerden pek bir farký yoktu ve biz burda ilk defa &(ampersant) iþareti ile deðiþken tanýmlama görmüþ olduk. Bu deðiþkenin
	ismi referance deðiþkenidir genellikle de bu tip iþlemler için geçici süreliðine oluþturulurlar. Adý üstünde referans olarak bir deðiþkeni alýrlar vekalet verme gibi düþünülebilir
	ve daha sonra bu referans deðiþkenleri normal deðiþken gibi kullanýlýr fakat bu deðiþken üzerinde yapýlan deðiþiklikler referans alýnan deðiþken üzerinde de yapýlmýþ olur. Fakat
	C dilinde bu tip tanýmlama yoktur C++ dilinde vardýr yani C dilinde bu tanýmlama hata verecektir bu fonksiyon çalýþmayacaktýr.
	
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("Call By Referance Deðiþtirme Fonksiyonu Ýçerisinde a = %d, b = %d\n", a, b);
}
*/
 
void prototipFonksiyon(int, int); /*Prototip fonksiyon bazý durumlarda hatalardan kaçýnmak için kullanýlýr. Parametrelerin tiplerinin verilmesi yeterlidir isimlere gerek yoktur.*/ 

/*Prototipi tanýmlanmýþ fonksiyonu daha sonra oluþtururken deðiþken tipleri vermemize gerek yoktur.*/
void prototipFonksiyon(a, b)
{
	printf("Toplamlarý: %d\n", a + b);
}

void isaretciIle(int x, int y)
{
	printf("Ýþaretçi ile fonksiyon çaðrýldý, Sayýlar: x = %d, y = %d\n", x, y);	
}

void toplam(int x, int y)
{
	printf("Ýki Sayýnýn Toplamý: %d\n", x + y);	
} 

void fark(int x, int y)
{
	printf("Ýki Sayýnýn Farký: %d\n", x - y);	
} 

void carpim(int x, int y)
{
	printf("Ýki Sayýnýn Çarpýmý: %d\n", x * y);	
} 

void bolum(int x, int y)
{
	printf("Ýki Sayýnýn Bölümü: %d\n", x / y);	
}

/*Aþaðýda da görüldüðü gibi istenilen sayýda parametre gönderilecek fonksiyona mecburen 1 adet belirli bir parametre bildirimi yapýlmalý ve daha sonra '...' ile daha sonra gelen
parametrelerin belirsiz olduðu gösterilmelidir. Belirtilen ilk parametre yani bizim örneðimiz için argumanSayisi isimli parametre, bu fonksiyona çaðrýlma sýrasýnda gönderilen parametre
sayýsýný tutar.*/
float ortalamaOrnek(const int argumanSayisi, ...)
{
	/*Aþaðýda <stdarg.h> kütüphanesi içerisinde bulunan va_list isimli tip ile argumanlar isimli bir liste tanýmlamýþ olduk. Bu liste diziler mantýðý gibi deðildir bu listede þu anda
	bu fonksiyona çaðrýlma sýrasýnda gönderilen argümanlar tutulmaktadýr. az sonra açýklayacaðýmýz va_stard ve va_end arasýnda va_arg ile her kullanýmda bir sonraki parametreye geçecek
	tir.*/
	va_list argumanlar;
	int top = 0; int i; int value; /*value isimli deðiþken argumanlar listesindeki yani tüm parametrelerdeki deðerleri tutmasý ve toplam deðiþkenine atmasý içindir.*/
	va_start(argumanlar, argumanSayisi); /*Bu fonksiyonda argumanlar listesindeki argumanSayisina kadar olan elemanlarý göstereceðimizi belirttik, bir türlü döngü gibi düþünülebilir.*/
	for(i = 0; i < argumanSayisi; i++) /*Argüman sayýsý kadar dönecek bir for döngüsü oluþturduk.*/
	{
		value = va_arg(argumanlar, int); /*Argümanlar içerisinden baþtan baþlayarak int tipte olan deðiþkeni dönderdi. For döngüsü tekrar döndüðü zaman bir sonraki dönecektir.*/
		top += value;
	}
	va_end(argumanlar); /*Bu fonksiyonda argumanlar listesinin elemanlarýnýn listelenmesinin biteceðini belirttik.*/
	printf("\n%d/%d\n", top, argumanSayisi);
	return (float)(top / argumanSayisi); /*Aritmetik ortalamayý dönderdik.*/
}

int recursive(int f)
{
	/*Bu deðiþkeni static olarak oluþturduk çünkü recursive fonksiyonun özelliði tekrar tekrar çaðrýlmasýdýr ve bu çaðrýlma sýrasýnda tekrar tekrar deðiþken oluþturulmasý programý
	yavaþlatýr. Recursive foknsiyonlarý iç içe fonksiyon içerisindeki kod satýrlarýnýn açýlmasý olarak düþünebiliriz. Eðer static olarak oluþturmasak bile program çalýþacaktýr ama
	faktoriyel hesaplamak için buna gerek yoktur en iyi yol budur.*/
	static int result = 1;
	if(f > 1) /*f'in 1'den büyük olduðu durumlarda çalýþmasýný istedik çünkü 1 ve 1'in altýndaki deðerlerde sonuç 0 ve negatif olacaktýr.*/
		result = f * recursive(f - 1); /*fonksiyona f - 1 gönderdik. Dikkat eðer --f gönderirsek f! yerine (f-1) faktoriyelin cevabý bulunur sizce neden ?*/
	return result;	
} 
 
void main(int argc, char *argv[]) /*Fonsiyonumuz void yani geriye birþey döndermeyen fonksiyon.*/
{
	setlocale(LC_ALL, "Turkish"); 
	int i; int a = 5; int b = 3;
	printf("Bu uygulamanýn ismi: %s\n", argv[0]); /*argv pointer dizi parametresi ilk elemanýnda uygulama ismini verir.*/
	printf("%d adet parametre girildi.", argc - 1); /* Girilen parametre sayýsý + 1 (bu bir program isminden geliyor) */
	if(argc > 1)
	{
		printf(" Bunlar:\n");
		for(i = 0; i < argc - 1; i++)
			printf("%d.Parametre: %s\n", i + 1, argv[i + 1]);
	}
	else
		printf("\n");
	printf("\n");
	printf("Call By Value Deðiþtirme Fonksiyonundan Önce a = %d, b = %d\n", a, b);
	cbvOrnek(a ,b);
	printf("Call By Value Deðiþtirme Fonksiyonundan Sonra a = %d, b = %d\n", a, b);
	printf("\n");
	printf("Call By Referance Deðiþtirme Fonksiyonundan Önce a = %d, b = %d\n", a, b);
	/*a ve b deðiþkenleri düz deðiþkenlerdir ve bizim fonksiyonumuzun parametreleri pointer yani adres tutan deðiþkenlerdir bu yüzden & ile deðiþkenlerin adresleri gönderilmiþ oldu*/
	cbrOrnek1(&a, &b);
	printf("Call By Referance Deðiþtirme Fonksiyonundan Sonra a = %d, b = %d\n", a, b);
	printf("\n");
	prototipFonksiyon(15, 18);
	/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	/*Ýþaretçi deðiþken ile fonksiyon çaðýrma*/
	/*Bu örnekte yapýlan iþlem þöyle açýklanabilir. Pointerlar dediðimiz gibi bellek adreslerini tutar. Biz bir deðiþkenin bellek adresini tutan bir pointer yaparken deðiþken gibi
	bir pointer tanýmlýyorduk, þimdi ise fonksiyon gibi aþaðýdaki 1 ile iþaretli noktada fonksiyon adresi tutan bir pointer tanýmlamýþ olduk ve 2 nolu yerde ise fonksiyonun adresini
	bu pointer'a atmýþ olduk. Bundan sonra da deðiþken ile 3 nolu yerdeki gibi çaðýrma iþlemi yapýlabilir.*/
	int x; int y;
	void (*isaretci) (int, int); /*1*/
	isaretci = isaretciIle; /*2*/
	printf("Aralarýnda Boþluk Býrakarak Ýki Adet Sayý Girin: ");
	scanf("%d %d", &x, &y);
	isaretci(x, y); /*3*/
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	/*Dizi iþaretçi ile fonksiyon çaðýrma*/
	/*Bu örnekte de görüldüðü gibi hep typedef ile (henüz görmedik) hem de yukarda tanýmlama yaptýðýmýz gibi tanýmlama yapabildik. 1 Numarada kendimize ait bir tip tanýmladýk ve bu
	tipi "void tipli iki adet int parametre alan fonksiyon iþaretçisi" olarak tanýmladýk ve 2 no da bunun için normal diziye deðer atar gibi deðer atamasý yapabildik. Tip tanýmlamadan
	da 3 no da görüldüðü gibi tanýmlama da yapýlabilirdi ve ayný þekilde de 4 no da görüldüðü gibi de her iki þekilde (tip tanýmlama ile veya 3 no da olduðu gibi) deðer atamasý
	yapýlabilecektir. 5 no da görüldüðü gibi de fonksiyonlar çaðrýlabilmektedir.*/
	typedef void (*fonksiyonIsaretcisi) (int, int); /*1*/
	fonksiyonIsaretcisi fonksiyonlar[4] = {toplam, fark, carpim, bolum}; /*2*/
	void (*fonksiyon[4])(int, int) = {toplam, fark, carpim, bolum}; /*3*/
	/*Aþaðýnýn 4 no*/
	/*fonksiyon[0] = toplam;
	fonksiyon[1] = fark;
	fonksiyon[2] = carpim;
	fonksiyon[3] = bolum;*/
	/*Aþaðý 5 no*/
	for(i = 0; i < 4; i++)
		fonksiyonlar[i](x, y);
	for(i = 0; i < 4; i++)
		fonksiyon[i](x, y);
	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	printf("Girilen sayýlarýn aritmetik ortalamasý = %f 	\n", ortalamaOrnek(8, 10, 15, 14, 12, 48, 65, 88, 5));
	printf("\nFaktoriyeli hesaplanacak sayýyý giriniz: ");
	scanf("%d", &x); /*Yukarda x tanýmlanmýþtý tekrar baþka deðiþken tanýmlamaya gerek duymadým.*/
	printf("x! = %d\n\n", recursive(x));
	int r;
	printf("Alaný hesaplanacak dairenin yarýçapý: ");
	scanf("%d", &r);
	printf("%d Yarýçaplý dairenin alaný: %f", r, dairealan(r));
	printf("%d\n", makro<r>); 
}

