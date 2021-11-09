#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stat.h>
#include <fcntl.h>
#include <locale.h>

/*DÝSK DOSYALARI: 
	C dilinde elimizdeki bazý verileri kalýcý olarak bir yere depolamamýz gerekebilir. Bu tür durumlarda dosyalama iþlemleri kullanýlýr. C dilinde dosyalar oluþturulduktan sonra 
dosyalara eriþmek için iki türlü yöntem kullanýlýr. Ýlki, üst düzey I/O (high level I/O) ya da tamponlanmýþ I/O (buffered I/O) olarak, ikincisi alt tüzey I/O yada UNIX vebzeri I/O 
(unix like I/O) olarak adlandýrýlýr. Ýkinci eriþim ANSI C standartlarýnda olmamasýna karþýn bazý derleyiciler sanki standartmýþ gibi bu yöntemi destekler. Bizim derleyicimiz de 
desteklemektedir. (devc++)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-Üst Düzey I/O Yöntemi:
	Bu yöntemde okuma ve yazma iþlemleri, temelde, karakter düzeyinde yapýlýr ve kullanýmý alt düzey I/O yöntemine nazaran daha kolaydýr. Tampon bellek tanýmlama, veri dönüþümü ve 
formatlý okuma yazma için fonksiyon yazmaya gerek yoktur. Destekleniyorsa metin dosyasý ile birlikte ikili dosya þeklinde de kullanýlabilir. Daha önce anlatýlandan farklý bir iþlem 
yoktur.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-Alt Düzey I/O Yöntemi:
	Bir disk dosyasý içerdiði veriye göre, metin dosyasý ve ikili dosya olarak ikiye ayrýlýr. Metin dosyasýnda satýr sonu karakteri CR/LF ikilisine dönüþtürülerek yazýlýr. Tersi durumda
CR/LF karakter çifti satýr sonu karakterine dönüþtürülür Ýkili dosyada ise yanlýzca tek bir karakter ile sonlandýrýlýr. UNIX ve XENIX de dosyalar yanlýzca ikili dosya tipindedir.
	UNIX ve benzeri iþletim sistemlerinde, programcýnýn kütüphane fonksiyonu gibi çaðýrýp kullanabileceði bazý fonksiyonlar bulunur. Dolayýsý ile bu fonksiyonlar ile kullaným daha
hýzlýdýr. Alt düzey yöntemde programcý tampon'u(buffer) kendisi bildirmek zorundadýr. Üst düzey yöntemindeki gibi karakter düzeyinde eriþim ve formatlý eriþim yoktur. Bunlar;
	-open(const char *k1, const char *k2, eriþimlik), creat(const char *k1, const char *k2) -> Ýki adet parametre alýr ve k1 parametresi isminde ve k2 modunda dosyayý açmak için 
	kullanýlýr. k2 modu için üst düzey yöntemden farklý olarak	3 adet mod vardýr fakat kullanýmlarý farklýdýr.
		*r -> Yazma izni.
		*w -> Okuma izni.
		*x -> Yürütme izni.
			Bu izinleri sekizlik sayý sisteminde depolanýr ve bitlerin anlamlarýna göre verilir. xyz 3 bitinden z biti yürütme iznine, y biti yazma iznine ve x biti okuma iznine eþittir.
		Ýzinleri verirken, verilmek istenmeyen izinler yerine '-' karakteri konulur. UNIX benzeri iþletim sistemlerinde kullanýcýlar, owner, group ve others olarak ayrýlýr. Dolayýsý ile
		izinleri verirken;
		owner	group	others
		 rwx	 rwx	 rwx
		biçiminde araya boþluk koyarak verilir. creat fonksiyonu belirtilen izinler ile dosyayý oluþturur. Eðer dosya diskte yok ise yeni dosyayý oluþturur, var ise dosyanýn içeriðini
		siler fakat izinleri deðiþtirmeden býrakýr. open fonksiyonu ise farklý izinler ile dosyaya ulaþmak için kullanýlýr. Bu fonksiyonlar baþarýlý olursa geriye pozitif bir
		sayý, baþarýsýz olurlarsa -1 dönderirler ve errno deðiþkenine hata koduna karþýlýk gelen sayýsal deðeri atarlar. open fonksiyonundaki 3. parametre olan eriþimlik parametresi ise
		eðer dosya yok ise kullanýlýr. Dosya zaten disk de var ise yok sayýlýr. open fonksiyonu için izinler birinci liste ve ikinci liste olarak iki þekilde verilir. Bu izinler araya
		| veya operatörü koyarak birden çok verilebilir fakat birinci liste için sadece bir tane kullanýlýr. fcntl.h adlý baþlýk dosyasýnda ayrýlmýþ bu bayraklar;
		BÝRÝNCÝ LÝSTE
		*O_RDONLY -> Yanlýzca okuma için aç.
		*O_WRONLY -> Yanlýzca yazma için aç.
		*O_RDWR -> Okuma ve yazma için aç.
		ÝKÝNCÝ LÝSTE
		*O_NDELAY -> Bu bayrak UNIX ve benzeri iþletim sistemleri için kullanýlýr. Eðer yazýrsa ise okuma için seçilen dosyanýn eþleniði olan dosya yazma modunda açýlmamýþ
		ise açýlana kadar ilgili iþlem askýya alýnýr. Yazýlmazsa dosya açýldýktan sonra fopen fonksiyonundan dönülür.
		*O_APPEND -> Ekleme için açar ve cursor dosya sonuna konumlandýrýlýr.
		*O_CREAT -> Dosyayý 3.parametre olan eriþim iznine göre tekrar oluþturur.
		*O_EXCL -> O_CREAT bayraðý kullanýldýðýnda diskte zaten ayný isimli dosya var ise -1 döndertir.
		*O_TRUNC -> Zaten ayný isimli dosya varsa dosyanýn içeriðini siler.
		*O_BINARY -> Dosyayý ikili dosya olarak açtýrýr.
		*O_TEXT -> Dosyayý metin dosyasý þeklinde açtýrýr.
		DOS ALTINDA ÇALIÞAN BAZI DERLEYÝCÝLERDE stat.h KÜTÜPHANESÝ ÝÇERÝSÝNDEKÝ BAYRAKLAR
		*S_IWRITE -> Benim için yazma izni.
		*S_IREAD -> Benim için okuma izni.
	-close(int) -> Ýçerisine parametre olarak girilen sayýsal kodun karþýlýk geldiði dosyayý fclose gibi kapatýr.
	-write(int dt, char *tampon, int tamponboyut) -> Belirtilen dosyaya verileri tamponboyut kadar tampon parametresinden yerleþtirir. Geriye yazolan karakter sayýsýný dönderir.
	-read(int dt, char *tampon, int tamponboyut) -> write fonksiyonun tam tersi iþlem görür. Eðer baþarýsýz ise negatif bir deðer, baþarýlý ise pozitif bir deðer dönderir.
	-lseek(dt, oteleme, 0, 1 veya 2) -> fseek fonksiyonu ile ayný kullanýma sahiptir.
*/

void main()
{
	setlocale(LC_ALL, "Turkish");
	
}
