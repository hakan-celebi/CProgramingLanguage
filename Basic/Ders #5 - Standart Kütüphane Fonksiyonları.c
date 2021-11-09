#include <stdio.h> /*STANDART I/O KÜTÜPHANESÝ*/
#include <stdlib.h> /*MALLOC GÝBÝ BAZI STANDART FONKSÝYON KÜTÜPHANESÝ*/
#include <stdarg.h> /*ESNEK ARGÜMAN AKTARIMI KÜTÜPHANESÝ*/
#include <errno.h> /*errno DEÐÝÞKENÝNÝN BÝLDÝRÝMÝ YAPILAN KÜTÜPHANE*/
/*#define NDEBUG*/
#include <assert.h> /*HATA AYIKLAMA ASSERT FONKSÝYONUNUN BÝLDÝRÝMÝ YAPILAN KÜTÜPHANE*/
#include <setjmp.h> /*YEREL OLMAYAN DALLANMA FONKSÝYONU BÝLDÝRÝMÝ YAPILAN KÜTÜPHANE*/
#include <time.h> /*TARÝH VE ZAMAN FONSKÝYONLARININ KÜTÜPHANESÝ*/
#include <ctype.h> /*KARAKTERLER ÜZERÝNDE ÝÞLEM YAPAN KÜTÜPHANE 1.1*/
#include <signal.h> /*AYRICALIKLI DURUM KONTROLÜ FONKSYÝONLARININ BÝLDÝRÝMLERÝ YAPILAN KÜTÜPHANE*/
#include <string.h> /*KATARLAR ÜZERÝNDE ÝÞLEM YAPAN KÜTÜPHANE 2.1*/
#include <locale.h> /*LOKALÝZASYON FONKSÝYONLARININ BÝLDÝRÝMÝ YAPILAN KÜTÜPHANE*/

/*STANDART KÜTÜPHANE FONKSÝYONLARI:
	C dili dediðimiz gibi kütüphanelerden oluþan bir dildir. Dolayýsý ile C de profesyonel yada amatör bir çok kütüphane vardýr ve yazýlmaya devam edilebilir. Bu da bizim bir programý
farklý iþletim sistemleri üzerinde çalýþtýrmamýzý engeller. Yani biz windows üzerinde çalýþtýrýlýp derlenen bir programý linux içerisinde derleyip çalýþtýramayabiliriz, çünkü
kütüphaneler ve derleyiciler farklýdýr. Bu yüzden standartlaþtýrma adýna ANSI C(American National Standards Institute C) ile belirli standartlaþtýrmalar getirilmiþtir. Bu bölümde
standart kütüphaneler ve içeriklerini, 11 bölümde inceleyeceðiz.
NOT: Bütün fonksiyonlarýn örnekleri main fonksiyonu içerisinde yukardan aþaðý doðru vardýr.
NOT: Geçen bölümlerde standart giriþ çýkýþ fonksiyonlarýný araþtýrýlmasýný ödev olarak istemiþtik bu bölümde not olarak 6 adet standart giriþ/çýkýþ fonksiyonlarý vardýr bunlardan
printf ve scanf fonksiyonu esgeçilerek
	puts(parametre) -> Tek bir metinsel parametre alýr, int, float vb gibi parametreler yazdýrýlamazlar. Yani char dizisi veya çift týrnak içerisinde metinsel ifade yazdýrýlabilir. Bu
	fonksiyon ile yazýlan metinsel ifadeden sonra direkt olarak \n yapar ve alt satýra geçilir.
	gets(parametre) -> Char dizisini parametre olarak kabul eder fakat direkt char kullanarak bir deðiþken yazýlýrsa uyarý verir ama hata vermez önerilmez. Bu char dizisi olarak aldýðý
	parametrenin içerisine ekrandan girilen bir metini atar peki bu fonksiyonun scanf fonksiyonundan farký nedir ? scanf fonksiyonu boþluk tab ve enter karakterlerini girilen metin
	içerisine almaz yani bu karakterlerden enter a basýlýrsa fonksiyon kesin olarak sonlanýr, boþluk ve taba basýlýrsa bu karakterlerden sonra yazýlan hiç bir metin scanf ile okunamaz.
	gets fonksiyonunda ise sadece enter ile sonlandýrma yapýlýr boþluk ve tab karakterleri de bu fonksiyon ile okunur.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-Karakter Üzerine Ýþlem Yapan Fonksiyonlar Ve Kütüphanesi:
	Adý üzerinde bu bölümde karakterler üzerinde iþlem yapan fonksiyonlarý göreceðiz bunlar için kullanýlacak bir adet kütüphane vardýr. Bu kütüphane içerisindeki fonksiyonlarýn tamamý
"MAKRO" fonksiyonlardýr ve karakter kümesinin içerisindeki sýnýfýný belirleyen ve deðiþtirme fonksiyonlarý ikiye ayrýlabilirler.
	1.1-<ctype.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isalnum(); -> Ýçerisine int parametre alýr bu int ifade ondalýk sayý tabanýndaki binary koda denk gelir yani içerisine char koyarsak kendisi otamatik cast ederek int a çevirir
		yani binary koda çevirir. Ýçerisine gönderilen karakterin veya ascii kodun karþýlýk geldiði karakterin alfasayýsal kod(a-z, A-Z,0-9) ise 0'dan farklý bir sayý deðil ise 0
		dönderen bir fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isalpha(); -> Bu fonksiyonunda parametre gönderimi isalnum fonksiyonu ile aynýdýr. Bu fonksiyon girilen karakterin veya binary kodun karþýlýk geldiði karakterin sayýsal deðer
		mi yoksa harf mi kontrol eden fonksiyondur. Harf ise 0'dan farklý deðer sayý ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isascii() -> Diðerleri ile ayný þekilde parametre alýr. Bu fonksiyon girilen karakterin veya binary kodun standart ascii(7 bitlik binary kod 0 - 127) kod mu deðil mi
		anlaþýlmasý	içindir. Geri dönen ifade 0'dan farklý ise ascii kod, 0 ise ascii kod deðil anlamýna gelir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*iscntrl() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter kontrol karakteri ise 0'dan farklý, kontrol karakteri deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isgraph() -> Diðerleri ile ayný þekilde parametre alýr. iscntrl fonksiyonunun tersidir. Yani eðer karakter kontrol karakteri deðil ise 0'dan farklý, kontrol karakteri ise 0
		dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isdigit() -> Diðerleri ile ayný þekilde parametre alýr. Eðer 0-9 ondalýk sayý ise 0'dan farklý, deðil ise 0 dönderir. (0-9 rakamlarýnýn sayýsal kodu 48-57)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isxdigit() -> Diðerleri ile ayný þekilde parametre alýr. Eðer 0-9 ve Aa-Ff arasýnda ise 0'dan farklý deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*islower() ve isupper() -> Diðerleri ile ayný þekilde parametre alýr. Girilen karakter veya sayýsal kodu girilen karakter küçük harf ise islower için 0'dan farklý, isupper için
		0, büyük harf ise isupper için 0'dan farklý ve islower için 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isprint() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter yazýlabilen bir karakter ise 0'dan farklý, deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ispunct() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter noktalama karakteri ise 0'dan farklý, deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*isspace() -> Diðerleri ile ayný þekilde parametre alýr. Eðer karakter tab(9), yeni satýr(10), boþluk(32), sayfa alta(page down 12) ve sayfa üste(page up 13) ise 0'dan farklý
		deðil ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*toupper() ve tolower() -> Diðerleri ile ayný þekilde parametre alýr. Deðiþtirme fonksiyonu olarak bahsedilen fonksiyonlardýr. toupper parametre olarak girilen harfi büyük
		harfe dönüþtürür. tolower ise küçük harfe dönüþtürür. Yani toupper geriye parametre olarak gönderilen harfin büyük harfini dönderir. tolower geriye parametre olarak gönderilen
		harfin küçük harfini dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-Katarlar Üzerinde Ýþlem Yapan Fonksiyonlar Ve Kütüphanesi:
	Katar, NULL('\0') ile sonlandýrýlmýþ karakter dizisidir. Üzerinde iþlem yapan fonksiyonlar (str... ile baþlar), kopyalama iþlemi yapan fonksiyonlar ve sorgulama iþlemi yapan
fonksiyonlar olmak üzere ikiye ayrýlýr. Kopyalama iþlemi yapan fonksiyonlar genelde karakter iþaretçi dönderirler. Sorgulama yapan fonksiyonlar ise genelde mantýksal sonuç(0 veya 1)
dönderirler.
	Buna ek olarak bellek üzerinde iþlem yapan fonksiyonlar (mem... ile baþlar) katar üzerine iþlem yapanlara benzer, fakat bunlar NULL ile sonlandýrýlmazlar.
NOT: Bir katar diðerine kopyalanýrken yeteri kadar bellek alaný olmadýðý durumlarda, hatalar ile karþýlaþýlabilir.
	2.1-<string.h> (char k1[size]; char k2[size]; üzerinden gidilecektir. Pointer biçimi ile tanýmlanmýþ katarlar da bu fonksiyonlara dahildir.)
		*strcat(char k1, const char k2) -> Görüldüðü üzere bu fonksiyon iki adet parametre alýr ve ikinci parametresi const olarak tanýmlanmýþtýr. Bunun sebebi eðer gördüðümüz call by
		referance þeklinde yani pointer þeklinde bir veri gönderilir ise deðiþimden korumak için const olarak belirlenmiþtir. Bu fonksiyon k1 katarýnýn sonuna(yani NULL olan yerine)
		k2 katarýný ekler. Geriye dönüþ deðeri k1 katarýnýn baþlangýç adresidir.(Dizilerde adresleme konusunu sözel olarak anlatacaðým)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncat(char k1, const char k2, int size) -> strcat fonksiyonundan tek farký k1 katarýna k2 katarýnýn 3.parametre olan size parametresi kadar olan elemanlarýný eklemesi
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strchr(const char k1, int aranan) -> Görüldüðü gibi iki adet parametre alýr. aranan parametresi bir sayýsal koda denk gelir. Bu fonksiyon bu girilen sayýsal koda karþýlýk gelen
		karakter, k1 katarý içerisinde var ise(Bulunan ilk yerde durur yani hakan da iki adet a vardýr ilk a yý gördüðünde durur soldan saða okur) katar içerisinde bulunan yerin
		adresini dönderir, yok ise NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		strrchr(const char k1, int aranan) -> strchr fonksiyonundan tek farký arama iþlemine saðdan baþlamasýdýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcmp(const char k1, const char k2) -> Ýki adet parametre alýr. Bu girilen parametrelerin eþitliðini kontrol eder. Eðer bu iki katar eþit ise 0 dönderir. k1 alfabetik sýrada
		k2 den sonra ise pozitif, önceyse negatif dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncmp(const char k1, const char k2, int size) -> strcmp fonksiyonundan tek farký k1 katarý ile k2 katarýný 3.parametre olan size kadar karþýlaþtýrma yapmasý.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcoll(const char k1, const char k2) -> strcmp fonksiyonu gibi katarlar arasýndaki iliþkiyi kontrol eder. Arasýndaki fark strcmp alfabesel üstünlüðe göre kontrol ederken
		bu fonksiyon ascii kod tablosundaki sayýsal üstünlüðe göre kontrol eder. Geri dönüþ deðeri strcmp ile aynýdýr. pozitif ise büyük, negatif ise küçük veya 0 ise eþit.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcpy(char k1, const char k2) -> k1 katarýna(k1 katarýnýn eski hali silinir) k2 katarýnýn deðerini yerleþtirir. Geriye k1 katarýnýn baþlangýç adresini dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strncpy(char k1, const char k2, int size) -> strcpy fonksiyonundan tek farký k1 katarýna k2 katarýnýn 3.parametre olan size kadar elemaný kopyalamasý.(atama)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strcspn(const char k1, const char k2) -> strchr() fonksiyonuna benzer bir iþlem görür. strchr fonksiyonu girilen katar içerisinde girilen karakterin var mý yok mu olduðunu
		kontrol edip ilk bulunduðu yerin adresini dönderir, bulunmaz ise null dönderirdi. Bu fonksiyon ise k1 katarýnýn içerisinde k2 katarýnýn karakterleri arasýnda varmý yok mu
		kontrol eder.(k1 katarýnýn baþýndan baþlayarak) k1 katarýnýn içerisinde olmayan karakter sayýsýný verir.(Örneðin kullanýcýdan bir metin girilmesini istedik ve bazý
		karakterlerin olmasýný istemedik yani strcpsn fonksiyonunun 0 dönmesini istedik buna göre kontrol ettirebiliriz.) DÝKKAT: BULUNMADIÐI ALT KÜMEYÝ DÖNDERÝR.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strspn(const char k1, const char k2) -> strcspn fonksiyonu k2 katarýnýn elemanlarýnýn olmadýðý en uzun alt kümeyi dönderiyordu. Bu fonksiyon ise içerdiði en uzun alt kümeyi
		dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strerror(int errno) -> Genellikle parametre yerine gönderilirken errno sabiti kullanýlýr. Eðer hata adresi biliniyorsa hata adresi girilir ve geriye hata mesajýný dönderir.
		Hata adresi bilinmiyor ise kendi çaðrýldýðý yerden önce karþýlaþýlan hatanýn hata mesakýný dönderir.
		NOT: errno OLARAK KULLANDIÐIMIZ DEÐÝÞKEN, errno.h STANDART KÜTÜPHANESÝ ÝÇERÝSÝNDE TANIMLANMIÞTIR.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strlen(const char k1) -> Girilen katarýn NULL dýþýnda içerdiði karakter sayýsýný dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strpbrk(const char k1, const char k2) -> k1 katarýnýn içerisinde k2 katarýnýn herhangi bir elemaný olup olmadýðýný araþtýrýr. Bulunursa bulunan ilk yerin adresini, bulunmazsa
		NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strstr(const char k1, const char k2) -> k1 katarýnýn içerisinde k2 katarýnýn(fark edildiði üzere strpbrk fonksiyonundan farký, strpbrk fonksiyonu k2 katarýnýn elemanlarýndan
		herhangi birinin içermesi durumunu kontrol ederken bu fonksiyon k2 katarýnýn tamamýnýn içerip içermediðin kontrol ediyor) varlýðýný araþtýrýr. Eðer varsa bulunan yerin ilk
		adresini dönderir, yoksa NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtok(cosnt char k1, const char k2) -> k1 katarýný k2 katarýna göre parçalamak için kullanýlýr. Örnek üzerinden gitmek gerekirse "Merhaba c dünyasý ne haber, ne iþ" þeklinde
		olan bir katarý strtok("Merhaba c dünyasý ne haber, ne iþ", " ,") Görüldüðü üzere k2 katarýna virgül ve boþluk koyduk bu fonksiyon boþluk veya , görene kadar ki kýsmý
		böler geriye "Merhaba" kalýr ve adresini dönderir. Daha sonra null koyarak bunu devam ettirirsek yani strtok(NULL, " ,") þeklinde sona kadar parçalama devam eder.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strxfrm(char k1, const char k2, int size) -> Bu fonksiyon, farklý sayý kümelerinde ki(örneðin ASCII olmayan ve olan) deðerleri kýyaslamak için uygun bir forma dönüþtürür.
		k2 katarýnýn size kadar elemanýný dönüþtürerek k1 katarýna atar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memchr(char *adres, char ch, int size) -> Bu fonksiyon, verilen adresten baþlayarak size kadar 8 bitlik ilerleyerek kr karakterinin varlýðýný araþtýrýr. Eðer bulursa bulduðu
		yerin adresini bulamaz ise NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memcmp(char *adres, char *adres, int size) -> Verilen iki adresteki deðerleri size kadar 8 bitlik deðer okuyarak karþýlaþtýrýr. Ayný ise 0, ilk parametredeki adreste var olan
		metin alfabetik olarak daha önce ise negatif, daha sonra ise pozitif deðer dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memcpy(char *adres, char *adres, int size) -> Verilen ikinci adresteki deðeri size kadar 8 bitlik veriyi, birinci adresteki deðere atar ve ilk adresi dönderir. Ýki bellek
		alaný kesiþirse yani ilk adresten 8 bitlik ilerlemeye baþladýktan sonra ikinci adres ile kesiþirse ne olacaðý belli deðildir.(overlap)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memmove(char *adres, char *adres, int size) -> memcpy ile ayný görevi yapar fakat iki adres kesiþtikleri zaman bile doðru biçimde kopyalama iþlemi yapar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*memset(char *adres, char ch, int size) -> Verilen parametredeki adrese ch karakteri veya sayýsal kodu verilmiþ karakteri, size kadar 8 bitlik alana yerleþtirir.
		(Bazý fonksiyonlarda verilen 8 bitlik yani 1 byte lýk alan denmesinin sebebi c deki her bir karakter 1 byte yer kaplamasýdýr. Biz kadar olarak kullandýðýmýz zaman örneðin
		8 harfli bir katar kullanýrsak bu ramde 8 byte yer kaplar.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		NOT: errno sayýsal bir deðer tutar. Nasýl ascii kod tablosunda 32 space anlamýna gelirse, errno için de sayýsal kodlar bazý hata mesajlarýna denk gelir. Hata ile karþýlaþýldýðý
		anda errno sabitine o hata ile ilgili hata kodu deðeri atýlýr.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3-Standart I/O (Input/Giriþ, Output/Çýkýþ) Fonksiyonlarý Ve Kütüphanesi
	Bütün giriþ/çýkýþ fonksiyonlarý, bir dosyaya veya bir çevre biriminine (monitor, printer) eriþirken, tampon adý verilen bir arabellek üzerinden eriþir. (getch fonksiyonunda bu
yoktu doðrudan klavye den alýr) Bir dosya açýldýðýnda da ona bir tampon atanýr. Dosya kapatýldýðý zaman da bu tampon sisteme geri verilir. FILE tipi dosyaya eriþim için gerekli tüm
bilgilerin içerildiði bir topluluk (struct) yapýsýnda olup, hangi üyelere sahip olduðu sisteme baðlýdýr. Olmasý gereken tüm temel elemanlar aþaðýdaki gibidir.
typdef struct
{
	int cnt; Tampon da kullanýlan yer miktarý.
	unsigned char *b_ptr; Bir sonraki eriþim için kullanýlan deðiþken.
	unsigned char *base; Tampon baþlangýcý.
	int bufsize; Tampon boyutu.
	short flags;
	char fd; Dosya tanýmlayýcýsý
}FILE;
	1-<stdio.h>
									Bu kütüphanede bulunan;
									YENÝ VERÝ TÝPLERÝ
									post_t -> fsetpos fonksiyonunda kullanýlýyor. (long)
									size_t -> Birçok fonksiyonda kullanýlýyor. Byte cinsinden verileri ifade etmek için kullanýlýr.(unsigned)
									va_list -> vprintf() ailesince kullanýlýyor. (char *)
									SÝMGESEL SABÝTLER
									BUFFSIZE -> Aksi söylenmediði sürece tampon boyutu.
									EOF -> Dosya sonu karakteri (-1)
									FILENAME_MAX Dosya adýnýn en fazla karakter sayýsý.
									FOPEN_MAX Ayný anda açýlabilecek dosya sayýsý.
									_IOFBF (errno gibi sistem tarafýndan oluþturulmuþ fonksiyona gönderilecek parametre) -> setvbuf(): Tam tamponlu. (0)
									_IOLBF (errno gibi sistem tarafýndan oluþturulmuþ fonksiyona gönderilecek parametre) -> setvbuf(): Satýr tamponlu. (0x80)
									_IONBF (errno gibi sistem tarafýndan oluþturulmuþ fonksiyona gönderilecek parametre) -> setvbuf(): Tamponsuz. (0x04)
									SEEK_SET (errno gibi sistem tarafýndan oluþturulmuþ fonksiyona gönderilecek parametre) -> fseek(): Dosya baþýna.(0)
									SEEK_CUR (errno gibi sistem tarafýndan oluþturulmuþ fonksiyona gönderilecek parametre) -> fseek(): O anda bulunan yere. (1)
									SEEK_END (errno gibi sistem tarafýndan oluþturulmuþ fonksiyona gönderilecek parametre) -> fseek(): Dosya sonuna. (2)
									STANDART GÝRÝÞ ÝÞARETÇÝLERÝ
									(Standart olmayan ancak dos altýnda çalýþan birçok derleyicide stdprn ve stdaux adlý iþaretçiler de vardýr.)
									stdin -> Standart giriþ için. Varsayýlan olarak klavye.
									stdout -> Standart çýkýþ için. Varsayýlan olarak monitör ve console ekraný.
									stderr -> Standar hata çýkýþý için. Varsayýlan olarak console ekranýdýr.
		FILE *f;
		f = fopen("dosya.txt", "r");
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																		DOSYALAMA ÝLE ÝLGÝLÝ FONKSÝYONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*clearerr(FILE *f) -> Eðer dosya açma iþlemi baþarýsýz olur ve hata alýrsa, dosya topluluðunda ki flags deðiþkeninin deðeri yani hata bayraðý birlenir ve dosya kapatýlmadýðý
		sürece böyle kalýr. Bu fonksiyon ise içerisine parametre olarak aldýðý dosyanýn hata bayraðýný ve diðer hatalarý sýfýrlar. Geriye herhangi birþey döndermez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fopen(const char *dosya_adi(xxx.txt gibi), const char *dosya_modu) -> Diskte dosya oluþturmak veya var olan dosya üzerinde iþlem yapmak için kullanýlýr. fclose ile açýldýktan
		sonra hata ile karþýlaþmamak için(veri kaybý) kapatýlmalýdýr. Eðer dosya açma iþlemi baþarýlý olursa geriye açýlan dosyanýn adresini, baþarýsýz olursa geriye NULLL dönderir.
		6 adet dosya açma modu vardýr.
			-"r" -> read-only biçiminde var olan dosyayý sadece okumak için açar. Eðer diskte dosya yok ise fopen fonksiyonu NULL dönderir. Cursor dosya baþýna konumlanýr.
			-"w" -> write-only biçiminde dosyayý yanlýzca yazmak için açar. Eðer diskte zaten bir dosya var ise dosya sýfýrlanýr. Yok ise yeni dosya açýlýr. Cursor dosya baþýna gelir.
			-"a" -> input-only biçiminde dosyayý yanlýzca eklemek içni açar. Eðer diskte zaten bir dosya var ise dosya açýlýr cursor dosya sonuna konumlandýrýlýr. Eðer diskte dosya yok
			ise yeni dosya açýlýr.
			-"r+" -> Okuma ve yazma için açar, cursor dosya baþýna gelir. Dosya yoksa NULL dönderir.
			-"w+" -> "w" modu ile aynýdýr. Ek olarak okuma iþlemi de yapýlabilir.
			-"a+" -> Eklemek için açýlýr. Eðer dosya yok ise yeniden oluþturur ve cursor baþa gelir. Dosya var ise cursor dosya sonuna konumlandýrýlýr. Okuma ve yazma iþlemleri de
			yapýlýr.
			(BINARY VE TXT BÝÇÝMÝDE ÝKÝ ADET DOSYA TÜRÜ VARDIR BUNLARI BELÝRTMEK ÝSTÝYORSAK BINARY ÝÇÝN MOD SONUNA B, TXT VARSAYILANDIR AMA BELÝRTMEK ÝÇÝN MOD SONUNA t GELÝR)
			(KONUM BELÝRTÝLMEZ ÝSE KAYNAK KODUNUN BULUNDUÐU DOSYA ÝÇERÝSÝNE KAYIT YAPILIR. KAYIT BELÝRTMEK ÝSTENÝRSE DE "\\" KULLANILIR. C::\\dosya_ismi.txt GÝBÝ)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fclose(FILE *f) -> Herhangi bir modda açýlmýþ ve içerisine parametre olarak gönderilen pointer içerisinde tutulan dosyayý kapatýr ve tampon sýfýrlanýr. Eðer dosya yazma veya
		ekleme modunda açýlmýþ ise önce tampondaki verileri diske kaydeder daha sonra tampon sýfýrlanýr ve dosya kapanýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*feof(FILE *f) -> Eðer açýlmýþ dosya içerisindeki cursor ismini verdiðimiz çoðu yerde yatay çizgi halinde bir konum üzerinde duran iþaretçi için, eðer bu cursor dosya sonunda
		ise geriye 0'dan farklý bir deðer, dosya sonunda deðil ise 0 dönderir.
		(Örneðin txt dosyasý içerisinde "Merhaba dosyalama iþlemleri" þeklinde bir verimiz olsun. Cursor eðer i'nin saðýnda ise dosya sonunda olduðu için 0'dan farklý bir deðer, farklý
		herhangi bir yerde ise 0 dönderir.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ferror(FILE *f) -> Parametre olarak gönderilen dosyada en son yapýlan okuma, yazma veya ekleme iþleminde herhangi bir hata var ise 0'dan farklý bir deðer, hata yok ise 0
		dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fflush(FILE *f) -> Parametre olarak gönderilen dosyanýn tampon içerisindeki verileri eðer yazma veya ekleme modunda açýlmýþ ise önce diske kaydeder daha sonra tüm modlar için
		tampon belleði sýfýrlar. Örneðin stdin klavye olarak bildirilmiþ ve tamponda daha önceden kalma bir veri varsa, klavyeden yeni deðerin girilmesi beklenmez tampondaki eski
		veriler okunur. Bunu önlemek için kullanýlýr. Geriye int tipinde bir deðer dönderir ne dönderdiðini siz deneyerek bulun.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fgetpos(FILE *f, pos_t *position) -> Parametre olarak gönderilen dosya için, yine parametre olarak gönderilen pos_t veri tipinde position isimli iþaretçi parametreye bu
		dosyanýn cursor pozisyonunu dönderir. Ýþlem baþarýlý ise 0'dan farklý, baþarýsýz ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fsetpos(FILE *f, pos_t *position) -> Parametre olarak gönderilen dosyanýn cursor pozisyonunu, yine parametre olarak gönderilen pos_t veri tipindeki bir parametre ile ayarlar.
		Ýþlem baþarýlý ise 0'dan farklý, baþarýsýz ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*putc(char ch, FILE *f) -> f parametresinin gösterdiði dosyanýn, cursor'unun saðýna verilen karakter veya sayýsal kodun ifade ettiði karakteri yazar. Baþarýlý olursa yazýlan
		karakteri, baþarýsýz olursa EOF(-1) dönderir. Makro fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*getc(FILE *f) -> f parametresinin gösterdiði dosyanýn cursor'unun baþlangýcýndan bir sekizlik veri okur ve geriye dönderir. Eðer hata oluþursa veya dosya sonunda gelinirse
		geriye EOF(-1) dönderir. Makro fonksiyondur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fputc(char ch, FILE *f) -> f parametresinin gösterdiði dosyananýn cursorun saðýna belirtilen karakteri veya sayýsal kodu gönderilen karakteri yazar. Baþarýlý olursa geriye
		yazýlan karakteri, baþarýsýz olursa EOF(-1) dönderir. putc ile (putch ile karýþtýrma) ayný iþlevi görür. Tek farký putc makro fonksiyondur bu fonksiyon deðildir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fgetc(FILE *f) -> Parametre olarak gönderilen dosya içerisinde cursor'un saðýnda bulununan karakterin sayýsal kodunu (int tipinde) dönderir. getc foknsiyonundan tek farký
		(getch ile karýþtýrma) getc fonksiyonu makro fonksiyondur bu makro fonksiyon deðildir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fputs(char *k1, FILE *f) -> f dosya iþaretçisinin gösterdiði dosyaya k1 katarýnýný cursorun saðýndan baþlayarak yazmak için kullanýlýr. Baþarýlý olursa pozitif bir sayý,
		baþarýsýz olursa EOF(-1) dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fgets(char *k1, int n, FILE *f) -> Parametre olarak gönderilen k1 katarýnýn içerisine, f dosyasýnýn içerisindeki (cursor olduðu yerden) veriyi n-1 karakter olarak atar ve
		katarlarda olduðu gibi k1 katarýnýn sonuna NULL atar. (\n yani newline görürse veya dosya sonuna gelinir ise okuma iþlemi sonlanýr.) Eðer iþlem baþarýlý ise k1 katarýnýn
		adresini baþarýsýz ise geriye NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fprintf(FILE *f, const char *k1, ...arguman) -> Parametre olarak gönderilen f dosya iþaretçisinin gösterdiði dosyaya standart I/O üzerinde iþlem yapan printf'e benzer þekilde
		yazý veya formatlý yazý yazmamýzý saðlar. Geriye int bir deðer dönderir bunu siz bulun.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fscanf(FILE *f, const char *k1, ...arguman) -> Parametre olarak gönderilen f dosya iþaretçisinin gösterdiði dosyaya standart I/O üzerinde iþlem yapan scanf'e benzer þekilde
		formatlý veri almamýzý saðlar. Geriye int bir deðer dönderir bunu siz bulun.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fwrite(void *k1, size_t s, size_t n, FILE *f) -> f dosyasýna tek karakteri s sekizli(char için 1, int için 4 gibi) olan bir deðiþkenin n karakterini dosya içerisine cursor'un
		saðýndan yazmaya yarar. Eðer baþarýlý olursa n, baþarýsýz olursa n'den küçük bir deðer dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fread(void *k1, size_t s, size_t n, FILE *f) -> f dosyasýndan tek karakteri s sekizli(char için 1, int için 4 gibi) n karakteri okuyarak k1 deðiþkeninie yerleþtirir. Bu
		fonksiyon baþarýlý ise geriye okunan eleman sayýsýný, baþarýsýz ise 0 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fseek(FILE *f, Belirttiðimiz(SEEK_SET - 0, SEEK_CUR - 1, SEEK_END - 2), int n) -> f ile belirtilen iþaretçinin gösterdiði dosyanýn cursor'unu, SEEK_SET(Baþtan), SEEK_CUR(
		Cursor'un olduðu yerden) veya SEEK_END(Dosya sonundan) itibaren n kadar ötelemeyi saðlar. Baþarýlý olursa 0, baþarýsýz olursa 0'dan farklý bir deðer dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ftell(FILE *f) -> Belirtilen f dosya iþaretçisinin gösterdiði dosya için, dosya baþýndan itibaren cursor'un uzaklýðýný 8 bitlik(1 byte sayarak) geriye dönderir. Eðer baþarýsýz
		olursa geriye -1 dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*freopen(const char *dosyaAdi, const char *dosyaAcilmaModu, FILE *f) -> fopen fonksiyonu gibi bu fonksiyon da, belirtilen dosya adý ve mod da dosya açar ve adresini f
		pointerýna gönderir. Bu fonksiyon daha çok standart I/O iþlemlerini dosyaya yöneltmek için kullanýlýr. FILE *f ile belirtilen parametreye stdin, stdout veya stderr yazýlýr.
		Örneðin freopen("dosya.txt", "w", stdout); fonksiyonunu kullandýðýmýz zaman, standart çýkýþa çýkýþ saðlayan fonksiyonlar (printf, puts gibi) artýk dosya.txt isimli dosyaya
		çýkýþ saðlarlar. Baþarýlý olursa FILE *f ile belirtilen parametrenin adresini, baþarýsýz olursa NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*remove(const char *dosyaAdi) -> Disk üzerinde dosyaAdi katarýnýn deðeri ile isimlendirilmiþ(katar örneðin dosya.txt) dosyayý diskten kaldýrýr. Eðer baþarýlý olursa 0, baþarýsýz
		olursa 0'dan farklý bir deðer dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*rename(const char *eskiDosyaAdi, const char *yeniDosyaAdi) -> Diskte eskiDosyaAdi ile isimlendirilmiþ dosyanýn ismini yeniDosyaAdi ile deðiþtirir. Verilen yeni dosya adý eðer
		o disk klasörü içerisinde zaten varsa ne yapýlacaðý sisteme baðlýdýr. Genellikle üzerine yazar. Eðer iþlem baþarýlý ise 0, baþarýsýz ise 0'dan farklý bir deðer dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*rewind(FILE *f) -> Geriye bir deðer döndermez. Cursor'u dosya baþýna konumlandýrýr ve clearerr fonksiyonu gibi hatalarý ve bayraklarý temizler.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setbuf(FILE *f, char *tampon) -> Geriye deðer döndermeyen bu fonksiyonun kullanýmý için, dosya açýlmýþ fakat hiç iþlem yapýlmamýþ olmasý gerekmektedir. Bu þartlar saðlandýðý
		noktada, açýlan bir dosyaya otomatik bir tampon atandýðýný söylemiþtik, eðer tamponu biz manule olarak atamak istiyorsak bu fonksiyonu kullanýrýz. Tampon yerine eðer NULL
		girilirse bu dosya ivedi olarak tamponsuz çalýþacaktýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setvbuf(FILE *f, char *tampon, int mod, size_t n) -> Bu fonksiyon da tampon deðiþtirmek için kullanýlýr. Belirtilen dosya üzerinde yine bir iþlem yapýlmamasý gerekir. tampon
		ile belirtilen bellek adresinden baþlayarak n sekizli (n 1 byte) olarak tamponu ayarlar. mod için ise 3 adet sabit vardýr.
			_IONBF -> Arabellek boyu sýfýrlanýr. Eriþimler direkt olarak yapýlýr.
			_IOFBF -> Arabellek boyunu verilen parametreler doðrultusunda deðiþtirir.
			_IOLBF -> _IOFBF ile ayný iþe yarar tek farklý arabellekden dosyaya veri aktarýlmasý ya dolduðunda ya da \n newline ile karþýlaþtýðýnda olur.
		Geriye eðer baþarýlý olursa 0, baþarýsýz olursa 0'dan farklý bir int deðer dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tmpfile(void) -> Geçici olarak disk dosyasý oluþturarak eðer oluþturma baþarýlý ise bu dosyanýn adresini, baþarýsýz ise NULL dönderir. Dosya w+ modunda açýlýr eðer
		destekleniyorsa binary dosya yapýsý olarak açýlýr. Program sonlandýðýnda dosya da diskten silinir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tmpnam(char *fileName) -> Bu fonksiyon TMP_MAX sabiti kadar L_tmpnam karakterlik ve kullanýlmayan, var olmayan rastgele dosya ismi üretir. Üretilen dosya ismini geriye
		dönderir. Eðer baþarýsýz olursa NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ungetc(char kr, FILE *f) -> Belirtilen dosyadan okunan karakteri geri tampona atar. Ardý ardýna iki kez kullanýlmaz. Geriye eðer baþarýlý ise eklenen karakterin sayýsal
		kodunu, baþarýsýz ise NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*vfprintf(FILE *f, "", ...) -> Standart I/O konusunda belirtilen vprintf yapýsý ile aynýdýr tek farký stdout'a deðil belirtilen dosya iþaretçisinin gösterdiði dosyaya verileri
		yazdýrýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																		STANDART I/O ÝLE ÝLGÝLÝ FONKSÝYONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*perror(const char *k1) -> Geriye bir deðer döndermez. Ýçerisine aldýðý k1 katarýný ekrana basar ve ": " koyar daha sonra errno sabitinin içerdiði sayýsal kdoun karþýlýk
		geldiði hata kodunu basar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*putchar(char ch) -> stdout (varsayýlan monitör - console) üzerine tampon kullanmadan direkt olarak veriyi aktarmayý saðlar. Parametre olarak girilen sayýsal kodun karþýlýk
		geldiði karakteri veya girilen karateri basar. Geriye eðer baþarýlý ise basýlan karakterin sayýsal kodunu, baþarýsýz ise EOF(-1) dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*getchar(void) -> stdin (varsayýlan klavye) üzerinden tampon kullanmadan direkt olarak veri alýnmasýný saðlar. Parametre almaz geriye stdin den gelen verinin sayýsal kodunu
		dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*printf("%n", ...) -> Ýlk parametresine yazýlan metin bazý kontrol karakterleri, sabitler ve deðiþkenler hariç direkt olarak yazdýrýlýr. Kontrol karakterlerinden % ve \ iþareti
		nin ayrý ayrý görevleri vardýr ve kendilerinin kaçýþ karakterleridir. Yani bu kontrol karakterlerinin görevleri olduðu için metin içerisinde tek baþlarýna yazýlamazlar. Bundan
		dolayý eðer % karakteri stdout a yazdýrýlmak isteniyorsa çift %% þeklinde, \ karakteri için se çift \\ þeklinde yazýlmasý gerekir. Bu karakterlerin görevleri de yine stdout
		üzerinde iþlem yapar. Kýsacasý printf formatlý bir biçimde stdout üzerine veri yazmak için kullanýlýr. Eðer baþarýlý olursa basýlan karakter sayýsý, baþarýsýz olursa geriye
		negatif bir sayý dönderir.
		% KARAKTERÝ VE GÖREVLERÝ
			c -> Karakter deðiþkeni yazýlmasý içni.
			d ve i -> int (anahtar kelimeler dahil long, short) yazýlmasý için.
			u -> unsigned int yazýlmasý için.
			o -> Sekizlik sayý sisteminde sayý yazýlmasý için. (Eðer onluk veya onaltýlýk sayý sisteminde bir deðer varsa bunu otomatik convert ederek yazdýrýr.)
			f -> Gerçel sayýlarý yazmak için kullanýlýr. Ayný zamanda a ve b tam sayý olmak üzere %a.bf þeklinde yazýlýr ise solda a kadar sayý ve saðda b kadar sayý formatýnda yazar.
			NOT: Duyarlýlýðý ikinci parametreden alma printf("%*.*f", 5, 3, degisken); Yukardaki a, b örneði ile ayný iþi görür.
			lf -> Double yazdýrýrken kullanýlýr.
			x ve X -> Onaltýlýk sayý sisteminde sayý yazýlmasý için. (Otomatik convert eder.)
			e ve E -> Gerçel sayýyý e tabanlý [-/+]a.bbbbbbbbe[-/+]cccc biçiminde yazar. (Örneðin 3.142857e+002)
			g ve G -> Gerçel sayýlarý %f veya %e hangisi kýsa yazýlýr ise onunla yazýlmasýný tercih eder. %f ile yazýlýrsa gereksiz 0 lar yok sayýlýr. Eðer tamamen 0 ise nokta koyulmaz.
			p -> Bellek adresi yazdýrmak için kullanýlýr. (pointerlar veya & ile adres dönderenler.)
			s -> Katarlarý yazdýrmak için kullanýlýr.
			n -> Karþýlýk olarak bir int deðiþken gelmelidir ve &(ampersant) kullanýlarak yazýlmalýdýr. Bu deðiþkene %n den önce yazýlan karakter sayýsý atanýr.
		\ KARAKTERÝ VE GÖREVLERÝ
			a -> Ses üretir.
			b -> Ýmleç bir sola kayar. (backspace)
			f -> Sayfa atla, bir sonraki sayfanýn baþýna geç. (Bir world dosyasýnda 2. sayfanýn baþýna geçirir.)
			n -> Satýr atla, alt satýra geç.(newline)
			r -> Satýr baþý yap.
			t -> Yatay tab yapar yani n kadar boþluk býrakýr. (n derleyici ayarlarýna baðlý olarak deðiþir.)
			v -> Dikey tab yapar yani sütun deðiþmeden kaldýðý sütündan alt satýra geçer.
			NOT: Float deðiþkeni için kaç hane yazýlacaðý gibi bir sistem anlatýldý, bütün deðiþkenler için yazýlabilecek bayrak sistemi % den hemen sonra yazýlan 4 adet bayrak vardýr.
				' '(space) -> pozitif sayýlarýn önüne ' '(space) negatif sayýlarýn önüne (-) yazýlmasýný saðlar.
				(+) -> Tüm sayýlarýn önüne, pozitif ise (+), negatif ise (-) koyulmasýný saðlar.
				(-) -> Örneðin char k1[] = "Merhaba"; þeklindeki katarý printf("[%10s]", k1); þeklinde yazarsak soluna 10 boþluk býrakarak [          Merhaba] þeklinde yazar. Önüne
				bu bayraðý koyarsak printf("[%-10s]", k1); [Merhaba          ] þeklinde yazar.
				# ->
					c, s, d, i, ve u da bir etkisi yoktur.
					o için önüne '0' koyar.
					x için önüne '0x' koyar.
					f, e ve g için tam ve kesirli kýsýmlarýn her zaman ayrýlacaðýný belirtir.
			BAYRAKLAR AYNI ANDA KULLANILABÝLÝR.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*scanf("", a, ...) -> Yine içerisine belirsiz sayýda deðiþken alýr. Ýlk parametrede belirtildiði formatta stdin üzerinden (burada tampon console ekranýdýr.) istenile veri
		tiplerinde deðer okumamýzý saðlar. Aslýnda bütün herþeyi katar olarak okur fakat belirtilen formata göre ilgili deðiþkenlere cast ederek deðer atamasý yapar. Eðer baþarýlý
		olursa okunan atama adetini, baþarýsýz olursa EOF(-1) dönderir. Formatlamada belirleyici olan % karakteridir.
		% KARAKTERÝ VE GÖREVLERÝ
			* -> c, d gibi (s yani katarlar hariç) karakterler ile % karakteri arasýna yazýlýrsa o formatta o noktada hiç bir atama yapýlmayacaðý anlamýna gelir atama yapýlmaz.
			[...] ve [^...] -> Birbirlerinin deðili olan iki görev, sadece katarlar için kullanýlýr. Köþeli parantez içerisine alýnan küme elemanlarýnýn içerdikleri yere kadar okunur,
			eðer içermeyen yer varsa okuma sonlandýrýlýr.(Örneðin scanf("%[Abdula]", k1); ve girdisi Abdullah olduðunu varsayarsak k1 katarýnýn deðeri Abdulla olur çünkü h harfi ile
			karþýlaþýlmýþtýr.) Deðili yani [^...] ise bulunmayana kadar okur eðer bulunan varsa okuma sonlandýrýlýr.(Örneðin scanf("%[^lh]", k1); girdi yine Abdullah olsun bu sefer
			k1 katarýnýn deðeri Abdu olur çünkü verilen küme elemanlarýndan birini içermektedir ve okuma sonlandýrýlmýþtýr.)
			Geniþlik: Float da olduðu gibi tüm deðiþkenlerde geniþlik verilebilmektedir. Ýnt deðiþkeni için ise bu indis anlamýna gelir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*puts(const char *k1) -> k1 katarýný veya "" ile yazýlýrsa yazýlaný ekrana basar ve newline yapar. Baþarýlý olursa pozitif bir deðer, baþarýsýz olursa EFO(-1) dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*gets(char *k1) -> Ekrandaki satýrý k1 katarýna atar. Bu okuma iþlemi karakter karakter olur eðer \n(newline) veya satýr sonu(EOF) ile karþýlaþýlýrsa sonlanýr. Ýþlem baþarýlý
		olursa geriye k1 katarýnýn adresini, baþarýsýz olursa NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		sprintf(char *k1, "", ...) -> printf fonksiyonu ile ayný iþi görür fakat printf fonksiyonunda olduðu gibi stdout'a deðil de k1 katarý içerisine formatlý veri giriþi yapýlýr.
		Geri dönüþü printf fonksiyonu ile aynýdýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		sscanf(const char *k1, "", ...) -> Bu da scanf fonksiyonu ile aynýdýr. Farklarý stdin üzerinden deðil de verilen katar üzerinden formatlý okuma yapýlýr. Geri dönüþü scanf
		fonksiyonu ile aynýdýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		vprintf("", va_list arguman) -> Görüldüðü üzere stdarg kütüphanesi tipi olan va_list argüman kabul ediyor. Biz çoklu parametre göndermede gördüðümüz va_arg fonksiyonu ile
		teker teker çaðýrarak okuyorduk, bunun yerine vprintf ile yazdýrýlan va_list argumanlar tüm argumanlarý ekrana yazar. Geriye argüman sayýsýný dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		vsprintf(char *k1, "", va_list arguman) -> vprintf ile aynýdýr. stdout yerine k1 katarýna yerleþtirir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4-Matematiksel Fonksiyonlar Ve Kütüphanesi:
	Matematiksel fonksiyonlarýn tipleri çift duyarlý gerçel sayýlardýr. (double) math.h kütüphanesi içerisinde tanýmlanmýþlardýr. Bu kütüphane içerisinde de bazý simgesel
sabitler (errno gibi deðiþkenler) tanýmlanmýþtýr. Fonksiyonlara gelen parametreler belirtilen sýnýrlarýn dýþarýsýnda ise errno deðiþkeninie EDOM atanýr. (Örneðin sqrt kare kök
hesaplayan fonksiyon parametre olarak negatif deðer alamaz hesaplayamaz.) Eðer fonksiyonlarýn geriye döndermek için hesaplanan deðerleri çok büyük veya çok küçük ise, errno
deðiþkenine ERANGE atanýr ve çaðrýlana HUGE_VAL (Bu kütüphanenin simgesel sabiti) dönderilir.
NOT: ANLATILAN TÜM FONKSÝYONLAR GERÝYE DOUBLE DÖNDERÝR.
		1-<math.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																			TRÝGONOMETRÝK FONKSÝYONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*cos(double) -> Radyan cinsinden verilen açýnýn kosinüsünü hesaplar ve geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*acos(double) -> Verilen parametrenin ters kosinüsünü hesaplar. Eðer parametre [-1, +1] kapalý aralýðýnda deðilse, errno deðiþkenine EDOM atanýr; arasýnda ise hesaplanan sonuç
		[0, PI] arasýnda dönderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*cosh(double) -> Radyan cinsinden verilen açýnýn hiperbolik kosinüsünü hesaplar ve geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*sin(double) -> Radyan cinsinden verilen açýnýn sinüsünü hesaplar ve geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*asin(double) -> Verilen parametrenin ters sinüsünü hesaplar. Eðer parametre [-1, +1] kapalý aralýðýnda deðilse, errno deðiþkenine EDOM atanýr; arasýnda ise hesaplanan sonuç
		[-PI/2, +PI/2] arasýnda dönderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*sinh(double) -> Radyan cinsinden verilen açýnýn hiperbolik sinüsünü hesaplar ve geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tan(double) -> Radyan cinsinden verilen açýnýn tanjantýný hesaplar ve geriye dönderir. Eðer açý PI/2'nin tek katlarýna yaklaþýrsa hata üretilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atan(double) -> Verilen parametrenin ters tanjantýný hesaplar ve geriye dönderir. Sonuç [-PI/2, +PI/2] arasýnda olur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*tanh(double) -> Radyan cinsinden verilen açýnýn hiperbolik tanjantýný hesaplar ve geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																		    DÝÐER MATEMATÝKSEL FONKSÝYONLAR
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ceil(double) -> Verilen parametreden küçük olmayan, en küçük tamsayý deðerini dönderir. (Örneðin 8.2 ise en küçük tam sayý deðeri 9 olmalýdýr.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*floor(double) -> Verilen parametreden büyük olmayan, en büyük tamsayý deðerini dönderir. (Örneðin 8.2 ise en büyük tam sayý deðeri 8 olmalýdýr.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*exp(double) -> e'nin verilen paramtre üssünü alýr ve geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*frexp(double val, int *us) -> val ismindeki parametre val = k*2^n biçiminde düþünülür, k ve n deðerleri hesaplanýr. (k, [0.5, 1) aralýðýnda olmalýdýr) Hesaplanan n deðerinin
		adresi *us parametresine, k deðerini ise geriye dönderir.
		NOT: Eðer val = 0 ise k ve n = 0 olacaktýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ldexp(double val, int n) -> val*2^n iþlemini hesaplar ve geriye dönderir. Bu fonksiyon frexp fonksiyonunun eþleniðidir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fabs(double) -> Verilen paramtrenin mutlak deðerini alýr ve geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*log(double) -> Verilen parametrenin e tabanýnda log yani ln'ini hesaplar ve geriye dönderir. Eðer verilen parametre negatif bir deðere sahip ise, errno deðiþkenine EDOM atanýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*log10(double) -> Verilen parametrenin 10 tabanýnda log yani ln'ini hesaplar ve geriye dönderir. Eðer verilen parametre negatif bir deðere sahip ise, errno deðiþkenine EDOM
		atanýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*modf(double x, double *tam) -> x gerçel sayýsýnýn tam ve kesirli kýsýmlarýný ayýrýr ve tam kýsmýný *tam deðiþkenine, kesirli kýsmýný geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*fmod(double x, double y) -> x/y iþleminden kalaný dönderir. Eðer y = 0 ise 0, sýfýrdan farklýysa i tam sayý olmak üzere, x = i * y + fmod(x, y) saðlama yöntemini saðlayacak
		þekilde kalaný hesaplar ve geriye dönderir. Geriye dönderilen deðerin iþareti, x deðiþkeninin iþareti ile aynýdýr. (+ / -)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*mod(double x, double y) -> x^y deðerini hesapla ve geriye dönderir. Eðer x negatif ve y tam sayý deðilse veya x = 0 ve y <= 0 ise EDOM hatasý üretilir ve çoðu derleyicide
		geriye 0.0 dönderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*sqrt(double) -> Verilen parametrenin karakökünü hesaplar ve geriye dönderir. Eðer x negatif bir sayýysa EDOM hatasý üretilir ve çoðu derleyicide geriye 0.0 deðeri dönderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
5-Genel Amaçlý Foknsiyonlar Ve Kütüphanesi:
	Bazý simgesel sabitler ve yeni veri tipleri aþaðýda verilmiþtir.
EXIT_SUCCESS -> exit fonksiyonunda kullanýlýr. exit(0)
EXIT_FAILURE -> exit fonksiyonunda kullanýlýr. exit(1)
RAND_MAX -> rand fonksiyonun dönderebileceði maximum deðer.
typedef struct
{
	int quot;
	int rem;
}div_t;

typedef struct
{
	long int quot;
	long int rem;
}ldiv_t;
	1-<stdlib.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*abort(void) -> Programý ivedi olarak sonlandýrýr. Bu normal olmayan bir sonlandýrma anlamýnda kullanýlýr. Bunun için raise(SIGABRT) fonksiyonu çaðrýlýr. Derleyiciye baðlý
		olmasýna karþýn, çoðunda açýk olan dosyalar kapatýlýr. Sisteme hatalý sonlanma anlamýnda sayý gönderilir. (DOS'ta bu sayý 3'dür.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*abs(int) -> Verilen int tipindeki parametrenin mutlak deðerini hesaplayýp geriye dönderir. Ýþaretli sayýlar eðer ikiye tümleyen aritmetiði ile hesaplanýyor ise en kçük eksi
		sayýnýn mutlak deðerine karþýlýk gelen artý sayý yoktur. Çünkü farzedelim ki unsigned bir deðiþken 255 dahil deðer alabiliyor, eðer unsigned olmasaydý [-228, +227] arasýnda
		olacaktý, bu yüzden -228'in mutlak deðer karþýlýðý verilemez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*labs(long int) -> abs fonksiyonundan tek farký long tipinde olmasýdýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atexit(fonksiyon adresi) -> Program sonlandýktan sonra çalýþtýrýlmasý için fonksiyonlarý kuyruðe ekler ve program sonlandýktan sonra bu fonksiyonlar çalýþtýrýlýr. Maximum
		32 adet fonksiyon kuyruða kayýt edilebilir. Yürütmeler kayýt sýrasýnýn tersi sýrada ilerler yani en son atexit fonksiyonu kullanýldýðý yerden baþlanýlýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atof(const char *k1) -> k1 katarý içerisindeki [0, 9] ve '+, -, ., e, E' karakterlerinden herhangi birini bulduðu noktadan baþlayarak içermeyen noktaya veya NULL ile
		karþýlaþana kadar okur ve geriye double tipinde dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atoi(const char *k1) -> k1 katarý içerisindeki rakamsal karakter olan noktadan baþlayarak içermeyen noktaya veya NULL ile karþýlaþana kadar okur ve geriye int tipinde dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*atol(const char *k1) -> atoi fonksiyonu ile aynýdýr. Tek fark geriye int deðil long int dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*qsort(void *dizi, size_t dizielemansayýsý, size_t elemanbyte, int fonk(int *, int *)) -> Buradaki parametre olarak gönderilen fonksiyon sýnama için kullanýlan
		fonksiyondur. Geriye hiç bir deðer döndermez. Dizinin adresi gönderilmelidir çünkü dizinin elemanlarýný deðiþtirmesi gerekmektedir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*bsearch(const void *aranan, const void *dizi, size_t dizielemansayýsý, size_t elemanbyte, int fonk(int *, int *)) -> void olarak bildirilen yerler tipi belirli deðil anlamýnda
		herhangi bir tip için geçerli olabilir olarak kullanýlmýþtýr. Bu fonksiyon küçükten büyüðe sýralanmýþ bir dizi içerisinde aranan deðiþkenini ilerde göreceðimiz ikili arama
		(binary search) algoritmasý ile arayarak, eðer bulunursa bulunan deðerin adresini, bulunamazsa NULL dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*malloc(size_t) -> Ýþletim sisteminden verilen parametre kadar sekizli (1 byte) bellek tahsis etmek için kullanýlýr. Eðer bellek de istenilen bellek miktarý var ise bellek de
		yer ayrýlýr ve baþlangýç adresini geriye dönderir. Eðer bellek de istenilen kadar yer yoksa geriye NULL dönderir. Geriye dönüþ tipi void olarak belirtildiðinden dolayý tüm
		veri tipleri için kullanýlabilir fakat cast edilmesi gerekir.(örneðin int *a; için kullanýrsak a = (int *)malloc(size_t) þeklinde kullanýlmalýdýr.)
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*calloc(size_t n, size_t k) -> Temelinde malloc fonksiyonu ile ayný görevi yapan calloc fonksiyonu, n*k byte bellek tahsilatý için kullanýlýr. Yani k yerine genellikle bellek
		alaný almak istediðimiz deðiþken tipinin kaç byte alan kapladýðýdýr. Geriye eðer alan ayýrma baþarýlý ise baþlangýç adresini, baþarýsýz ise NULL dönderir. Yine malloc fonksiyonu
		gibi bu fonksiyon da geriye void dönderir, dolayýsý ile cast etme gereklidir. (int a = (int *)calloc(lenght, sizeof(int)))
		NOT: malloc ve calloc söylenildiði gibi temellerinde ayný iþlevi görürler ve gözle görülebilir farklarý malloc 1 byte varsayýlan olarak seçerken, calloc fonksiyonu için byte
		sayýsýný manuel olarak seçiliyor fakat aralarýnda tek fark da bu deðildir. malloc fonksiyonu varsayýlan olarak char haricindeki veri tiplerinde bir deðer atmazken, calloc
		varsayýlan olarak 0 deðerini atamaktadýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*realloc(void *val, size_t n) -> Daha önce malloc veya calloc ile bellek alaný tahsis edilmiþ ve bu tahsis edilen bellek baþlangýç adresini tutan val deðiþkeni için, tahsis
		edilen bellek adresinin deðiþtirilmesini saðlar. Verilen bellek miktarýnýn arttýrýlmasý veya azaltýlmasýný saðlar. Eðer arttýrýlmasý isteniyorsa önceden tahsis edilmiþ bellek
		alanýndaki veriler kopyalanýr ve yeni tahsis edilen bellek alanýna yerleþtirilir yani eski verilerin kaybolmasý engellenir. Eðer azaltýlmasý isteniyorsa önceden tahsis edilmiþ
		bellek alanýndaki veriler kopyalanýr ve baþtan itibaren sýðabildiði kadarý ile yerleþtirilir. Eski bellek alaný serbest býrakýlýr. Ýstenilen kadar yer yoksa geriye NULL,
		tahsis edilme iþlemi yapýlýr ise hem val parametresine hem de geriye baþlangýç adresi dönderilir. Eðer val parametresi yerine NULL yerleþtirilirse n > 0 için malloc fonksiyonu
		iþlevi, n = 0 ise free fonksiyon iþlevini yapar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*free(void *p) -> Verilen parametre ram de ayrýlmýþ bir bellek alanýnýn baþlangýç adresini gösterdiði varsayýlarak bu bellek adresini serbest býrakmak için kulanýlýr. Geriye
		herhangi bir deðer döndermez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*div(int pay, int payda) -> Yukarda verilen div_t tipinde geriye dönüþ saðlar. Saðladýðý bu div_t tipindeki ilk üyeye (quat) (int)23/4 = 5, ikinci üyeye (rem) kalan yani 3
		atanýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ldiv(long int pay, long int payda) -> div fonksiyonundan tek farký long olmasýdýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*exit(int durum) -> Aþaðýdaki iþlemler yapýldýktan sonra program sonlandýrýlýr ve verilen parametreyi sisteme gönderir. Geriye dönüþ saðlamaz.
			-atexit fonksiyonuna bildirilmiþ tüm fonksiyonlar çalýþtýrýlýr.
			-Bütün dosyalar kapatýlýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*getenv(const char *k1) -> Ýþletim sistemi üzerinde çalýþan simgesel sabitlerin deðerinin baþlangýç adreslerini dönderir. Örneðin "PATH" parametre olarak gönderilirse iþletim
		sistemi üzerinde çalýþan iþlemlerin dosya konumlarýnýn char tipindeki baþlangýç adresleri dönderilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*rand(void) -> Rastgele sayý üretmek için kullanýlýr. Sayý 0 ile RAND_MAX arasýndadýr. % operatörü ile bunu küçültebiliriz. Geriye üretilen sayýyý dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*srand(int cekirdek) -> Rastgele sayý üreticisinin çekirdek sayýsýný deðiþtirmek için kullanýlýr. Böylece rand fonksiyonu peþ peþe çaðrýldýðý zaman farklý sayý vermesi saðlanýr.
		Program çalýþtýktan sonra çekirdek sayýsý deðiþtirilmemiþ ise 1 dir. Çekirdek sayýsýnýn deðiþtirilmesi için genellikle zaman fonksiyonlarý kullanýlýr. Geriye herhangi bir deðer
		döndermez.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtod(const char *k1, char **sonch) -> Verilen katar içerisindeki [0, 9] ve "+, -, ., e ve E" karakterlerininden herhangi birinden baþlayarak bunlar dýþýndaki karakterleri
		görene kadar veya NULL ile karþýlaþana kadar okur ve geriye dönderir. sonch pointer pointerýna okumanýn bitmesine sebep olan bellek adresini atar. Geriye double tipine
		dönüþtürülmüþ deðeri dönderir. Eðer sonch yerine NULL gönderilirse atof fonksiyonu ile ayný þekilde çalýþýr. Eðer dönüþtürülme iþlemi baþarýlý olmazsa sonch deðiþkenine k1
		katarýnýn baþlangýç adresi atýlýr ve geriye dönecek deðer derleyiciye kalmýþtýr ve çoðu derleyicide 0.0 dýr.
		(Örneðin double val; char k1[] = {Abdullah 2003.57 ile c dersleri}; char *ptr; deðiþkenleri için val = strtod(k1, ptr) iþleminde val = 2003.57000 ve ptr = baþlangýç adresi
		ve bu baþlangýç adresininin deðerini yazdýrýrsak = "ile c dersleri.")
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtol(const char *k1, char **sonch, int taban) -> k1 katarý içerisindeki sayýsal deðeri tabana göre (0 girilir ise sekizlik anlama gelir ve [0, 7] ve "+, -, ., e ve E"
		karakterleri, 0x girilir ise onaltýlýk anlama gelir ve [0, 9] - [A, F] ve "+, -, ., e ve E" geri kalanlar için ondalýk [0, 9] ve "+, -, ., e ve E" karakterleri) dönüþüm
		iþlemine baþlar. NULL veya dönüþüme uymayan karakter ile karþýlaþýldýðý zaman okuma iþlemi sonlandýrýlýr ve sonch ye bu karakterin adresi atanýr. Geriye dönüþtürülen bu deðer
		long int tipinde dönderilir. Eðer sonch yerine NULL girilirse atol fonksiyonu ile ayný çalýþýr. Eðer okuma iþlemi baþarýsýz olursa sonch parametresine k1 katarýnýn baþlangýç
		adresi atanýr. Taban parametresi 2 ile 36 arasýnda olabilir (0 da yazýlabilir).
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strtoul(const char *k1, char **sonch, int taban) -> strtol ile aynýdýr tek farký "+, -, ., e ve E" içerisindeki - iþaretini okuma yapmaz. Çünkü unsigned dir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	 	*system(const char *cmd) -> Kendisine verilen sistem komutunu yürütmek için kullanýr. Bu komutu yürütmek için komut yorumlayýcýsýna ihtiyaç vardýr. Eðer komut yorumlayýcýsý
	 	için cmd yerine NULL yazýlýr ise, sonuç 0 dan farklý ise vardýr, 0 ise yoktur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
6-Esnek Argüman Aktarým Fonksiyonlarý Ve Kütüphanesi:
	Bir fonksiyonun farklý sayýlarda argüman alabilmesi için 1 tip bildirimi ve 3 makro fonksiyonu olan stdarg.h kütüphanesi yazýlmýþtýr.
	1-<stdarg.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*va_start(va_list, ilkarguman) -> Bilindiði gibi farklý sayýda parametre ile çalýþan bir fonksiyon yazabilmek için sabit bir adet formal bildirim yapýlmasý gerekir. Bu
		fonksiyon verilen bu ilkarguman'dan sonra gelen ilk paremetreden baþlayarak sona kadar verilen va_list tipindeki parametre içerisine atar. Ýlk bu fonksiyon çaðrýlýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*va_arg(va_list, type) -> va_start fonksiyonu çaðrýldýðý anda ilk olarak birtane static counter tanýmlandýðýný düþünelim ve bu counter va_arg fonksiyonu ile artar. Arguman
		listesinden belirtilen tipdeki ve counter indisindeki deðeri geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*va_end(va_list) -> Belirtilen alma iþleminin kapatýlmasý için kullanýlýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
7-Tarih Ve Zaman Fonksiyonlarý Ve Kütüphanesi:
	Zaman ve tarih ile ilgili fonksiyonlarýn bildirilmesi ve bazý yeni veri tiplerinin bildirilmeri yapýlan time.h kütüphanesi
typedef long clock_t;
typedef long time_t;

struct tm 
{
	int tm_sec; -> Saniye için [0, 59]
	int tm_min; -> Dakika için [0, 59]
	int tm_hour; -> Saat için [0, 23]
	int tm_mday; -> Gün için [0, 31]
	int tm_mon; -> Ay için [0, 11]
	int tm_year; -> Yýl için [1900, ...]
	int tm_wday; -> Haftanýn günleri için (Pazartesi, Salý, ...., Cumartesi, Pazar)[0, 6]
	int tm_yday; -> Yýlýn günleri için [0, 365]
	int tm_isdst; -> tm_isdst > 0 ise yaz saati uygulanýyor.
}
	1-<time.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*clock(void) -> Program baþladýktan sonra kaç saat darbesi geçtiðini geriye dönderir. Saniye cinsinden öðrenmek için CLK_TCK adlý simgesel sabite bölünerek öðrenilebilir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*time(time_t *) -> 1970 tarihinden itibaren geçen zamaný saniye cinsinden fonksiyona gelen parametreye gönderir ve geriye dönderir. Eðer parametre olarak NULL girilirse geriye
		yine 1970 tarihinden bu yana geçen zamaný saniye cinsinden dönderir.
		Not: time_t deðiþkeni bildirildiði zaman varsayýlan olarak 70 ler saniyesine göre deðer alýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*gmtime(time_t *) -> Parametre olarak gelen saniye cinsinden zamana göre, GMT (Greenwich Mean Time) uygun olarak struct tm topluluðuna yerleþtirir ve geriye baþlangýç adresini
		dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*localtime(time_t *) -> gmtime fonksiyonu ile ayný iþlevi görür. Aralarýndaki fark bu fonksiyon GMT'ye göre deðil yerel zamana göre topluluða yerleþtirir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*asctime(const struct tm *) -> Kendisine gelen saniye cinsinden zamaný (Burada zaman topluluðunun tamamý bildirilmiþ) kullanaraki zaman ve tarihle ilgili bilgileri ekrana
		yazýlacak biçimde (Sonuna NULL ekleyerek) karakter katarýna dönüþtürür. Katar, GGG(Gün thu gibi) AAA(Ay aug gibi) gg(Ay 15 gibi) ss(Saat):dd(Dakika):xx(Saniye) YYYY(Yýl)\n\0
		formatýnda olur.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*ctime(const time_t *) -> asctime ile ayný iþlevi görür fakat bu sefer topluluða göre deðil de saniyeye göre iþlem yapar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*mktime(const struct tm *) -> gmtime ve localtime fonksiyonlarýnýn tam tersini yapar. Yani topluluða göre geriye saniye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*strftime(char *k1, size_t katarboyutu, const char *format, const struct tm *) -> Bu fonksiyon k1 katarý içerisine katarboyutu kadar *formatda struct tm içerisindeki zaman
		ve tarih bilgilerini atar. Geriye atýlan karakter sayýsýný size_t tipinde dönderir.
			%a -> Fri biçiminde haftanýn günleri.
			%A -> Friday biçiminde haftanýn günleri.
			%s -> Apr biçiminde aylar.
			%S -> April biçiminde aylar.
			%c -> Apr 15 21:10:15 2020 biçiminde tarih ve zaman.
			%d -> Ayýn sayýsal günü 15.
			%h -> a.m - p.m biçiminde saat.
			%H -> 24'lük biçimde saat.
			%j -> Yýlýn günü.
			%m -> Yýlýn ayý.
			%M -> Dakika.
			%p -> a.m - p.m.
			%s -> Saniye.
			%U -> Yýlýn haftasý.
			%w -> Haftanýn günü sayýsal olarak.
			%x -> Apr 15 2020 biçiminde tarih.
			%X -> 21:10:15 biçiminde zaman.
			%y -> Yüzyýlýn tarihi. (örneðin 1970 için 70 2020 için 120)
			%Y -> Yýl.
			%Z -> Zaman bölgesi.
			%% -> % karakteri.
 		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*difftime(time_t, time_t) -> Saniye cinsinden verilen iki zamaný çýkartýr ve yine saniye cinsinden geriye dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
8-Yerel Olmayan Dallanma Foknsiyonlarý Ve Kütüphanesi:
	Yapýsal bir dil olan C programlama dili içinde dallanma deyimi 'goto' kullanýlmasýna gerek olmayacak biçimde esnek kontrol ve döngü deyimleri vardýr. Ama yine de bazý zamanlarda
bu dallanma yapýlmasý gerekebilir. Dallanma fonksiyonlarý 'goto' ile yapýlan yerel dallanma ve setjmp.h fonksiyonu ile yapýlan yerel olmayan dallanma olarak ikiye ayrýlýr. Bu kütüphane
içerisinde bir adet özel deðiþken bildirimi ve iki adet makro fonksiyon tanýmlanmýþtýr. Deðiþken tipi jmp_buf olup bu tipte bir deðiþken, iþlemci içerisindeki saklayýcýlarýn
herhangi bir andaki deðerlerini tutacak yapýdadýr.
	1-<setjmp.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setjmp(jmp_buf) -> Ýçerisine aldýðý parametreye göre geliþ kapýsý açar ve ilk çaðrýldýðýnda 0 dönderir. Daha sonra longjmp fonksiyonuna gönderilen 2. parametrenin deðerini
		dönderir. Dönüþ tipi int. 
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*longjmp(jmp_buf, int) -> Belirtilen ilk parametredeki jmp_buf tipindeki deðiþken set edilmiþ ise set edilen noktaya gider ve o noktadaki set fonksiyonunun geri dönüþ deðerini
		ikinci parametre olarak ayarlar.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
9-Ayrýcalýklý Durum Kontrolü Fonksiyonlarý Ve Kütüphanesi:
	Bazý durumlarda program (sýfýra bölme gibi) içerisinde ayrýcalýklý durumlar meydana gelebilir ve sistem bunun için bazý fonksiyonlarý çaðýrýr.
	1-<signal.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*signal(int, fonk) -> Sistemin kendine ait belirtilen ayrýcalýklý durum kontrol fonksiyonu (1. parametre) yerine ikinci parametredeki fonksiyon bu belirtilen durumda çalýþýr.
		Sadece bir kerelik olarak bu deðiþimi yapar. Tekrar yapmak isteniyorsa fonksiyon tekrar çaðrýlmalýdýr.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*raise(int) -> Belirtilen ayrýcalýklý durumunu çaðýrýr ve çaðýrmasýna neden olan durum için fonksiyon deðiþir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
10-Hata Ayýklama (Diagnostics) Fonksiyonlar Ve Kütüphanesi:
	Hatalar yazým ve mantýk hatasý olarak ikiye ayrýlýr. Yazým hatalarý derleyici tarafýndan bildirilirken, mantýk halatarý için özel editörler veya assert.h kütüphanesi kullanýlabilir.
	1-<assert.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*assert(koþul) -> Belirtilen koþul saðlanýrsa stderr'in iþaret ettiði dosyaya (varsayýlan olarak console) Assertion Failed: dosya adý satýrno biçiminde bir mesaj gönderir.
		Geriye hiçbirþey döndermez. Bu hata ayýklamanýn en iyi yaný istenilen yere istenildiði sayýda assert iþlemi yazýlabilmesidir. Eðer kaldýrýlmak isteniyorsa kütüphane
		bildiriminden önce #define NDEBUG yazýlmasý yeterlidir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
11-Lokalizasyon Fonksiyonlar Ve Kütüphanesi:
	Bazý durumlarda örneðin Ýngilizce de Türkçe karakterler desteklenmemektedir ve bu yüzden kullanýcýya sunulan bir programda eðer kullanýcý Türk ise bazý sorunlar ortaya çýkacaktýr.
Bu sorunlardan bir tanesi Ý harfi gibi bazý harflerin yazýlamamasýdýr.

		1-<locale.h>
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		*setlocale(simgesel sabit, const char *k1) -> Ýlk parametre locale.h kütüphanesi içerisinde bildirilen bazý simgesel sabitleri alýr. Bu simgesel sabitler
			-LC_ALL -> Tüm durumlar için.
			-LC_COLLATE -> Katar karþýlaþtýrma iþlemlerinin yapýlmasý durumlarýna göre kullanýlýr.
			-LC_CTYPE -> Karakter karþýlaþtýma fonksiyonlarý için kullanýlýr.
			-LC_NUMERIC -> Gerçel sayýlarda bilindiði gibi tam kýsým ile ondalýklý kýsým . ile ayrýlýyor. Bazý dillerde bu nokta karateri desteklenmez ise bu fonksiyon da o bölge için
			set edilirse . yerine , kullanýlabilir.
			-LC_TIME -> Zaman fonksiyonlarýnda desteklenmeyen bir karakter var ise belirtilen dile göre desteklenen baþka bir karakter yerleþtirilir.
			Ýkinci olarak belirtilen simgesel sabit yerine belirtilen konumu "Turkish" "Euro" "English" gibi belirtilir. Eðer set iþlemi baþarýsýz olursa geriye NULL, baþarýlý olursa
		geriye katar bir adres dönderir.
		---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ÖDEVLER
	-Mantýksal bir iliþki kurarak karakter üzerinde iþlem yapan fonksiyonlar ile her durumu kontrol edecek þekilde bir program yazýnýz.
	-Mantýksal bir iliþki kurarak katarlar üzerinde iþlem yapan fonksiynolar ile ayrý ayrý örnekler yazýnýz.
	-Dosyalama iþlemlerinde kullanýlan freopen fonksiyonunda stdin, stdout veya stderr fonksiyonlarýnýn deðerlerini deðiþtirdikten sonra tekrardan console ekraný nasýl yapýlýr ?
	-tmpfile() fonksiyonunu araþtýr kullanmayý dene hatalarý çöz.
	-E-Ticaret sitesi kurduðunuzu ve üye ol, üye giriþi ve parolamý unuttum kýsmý olsun. Üye ol kýsmýnda da özel soru baþlýðý altýnda özel bir veri isteyin. Daha sonra parolamý
	unuttum yapýldýðý zaman o özel karakter ile sýfýrlama yapýlabilsin. Üye giriþi yapýldýktan sonra stok ta olan ürünler listelensin stokta biten ürünler görüntülenmesin fakat
	silinmesinde. Bir cüzdan olsun ve cüzdana giriþ yapýldýðýnda bakiye gösterilsin ve bakiye yükleme seçeneði olsun. Bakiye yüklemede 16 haneli bir kart numarasý istensin ve bu
	kart numarasý eðer birinci ve ikinci hanelerinin toplamýnýn birler basamaðý onaltýncý hanesinin basamaðýna eþit ve 2 ye bölünebilir olmasý þartý olsun. Bütün bunlar dosyalama
	iþlemi ile yapýlacaktýr.
	-vscanf, vsscanf, vfscanf fonksiyonlarý varmý varsa araþtýr.
	-Ýþletim sistemi simgesel sabitlerini araþtýrýn.
	-scanf fonksiyonunu yaz.
	-Standart kütüphaneler yardýmý ile atoi fonksiyonunun yaptýðý iþi yapan bir fonksiyon yaz.
*/

void program1()
{
	/*1 Karakter üzerinde iþlem yapan fonksiyonlar örnekleri*/
	char ch;
	printf("Test edilecek karakteri girin: ");
	ch = getch(); /*getch fonksiyonu getchar fonksiyonu ile aynýdýr bir kýsaltmasýdýr. Ayný þekilde putch fonksiyonu da putchar fonksiyonunun kýsaltmasýdýr.*/
	printf("%c\n",ch); /*Getch fonksiyonu ile klavyeden basýlan tuþ direkt olarak alýnýr ve ekrana girilen tuþ gözükmez bu yüzden biz manuel olarak basýyoruz.*/
	if(isalnum(ch))   /*Eðer kontrol operatörü koymadan direkt olarak fonksiyon bu þekilde yazýlýrsa 0'dan farklý deðerler true 0 olan deðerler false sayýlýr.*/
	{
		/*Girilen karakter alfasayýsal ise ya harftir yada sayýdýr. Sayý mý harf mi ayrýmýný da bu if içerisinde yapmamýz gerekir.*/
		puts("Alfasayýsal bir karakterdir !");
		if(isalpha(ch))
		{
			/*islower ve isupper alfa karakterler için iþlem yapýlýr dolayýsý ile alfa karakter anlamýna gelmesi yani bu if içerisinde kullanýlmasý gerekir.*/
			puts("	Alfa Bir Karakterdir !"); /*Alfa Harf Anlamýna Gelir.*/
			if(islower(ch))
			{
				puts("		islower Fonksiyonu Ýle Küçük Harf !");
				ch = toupper(ch);
				printf("		toupper Fonksiyonu Ýle Büyük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
			else
			{
				puts("		islower Fonksiyonu Ýle Küçük Harf Deðil !");
				ch = tolower(ch);
				printf("		tolower Fonksiyonu Ýle Küçük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
			if(isupper(ch))
			{
				puts("		isupper Fonksiyonu Ýle Büyük Harf !");
				ch = tolower(ch);
				printf("		tolower Fonksiyonu Ýle Küçük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
			else
			{
				puts("		isupper Fonksiyonu Ýle Büyük Harf Deðil !");
				ch = toupper(ch);
				printf("		toupper Fonksiyonu Ýle Büyük Harf'e Dönüþtürüldü !(KARAKTER: %c)\n", ch);
			}
		}
		else
		{
			/*Sayýsal olmayan bir rakam olamadýðý için isdigit ve isxdigit fonksiyonlarýnýn da bu else içerisinde kullanýlmasý gerekir. isxdigit fonksiyonunun ayrý olarak alfa
			kodlara	ait rakamlarý o*/
			puts("	Sayýsal Bir Karakterdir !");
			if(isdigit(ch)) /*0-9 arasýnda rakammý kontrol edilir.*/
				puts("		Ondalýk Bir Rakam !");
			else
				puts("		Ondalýk Bir Rakam Deðil !");
			if(isxdigit(ch))
				puts("		Onaltýlýk Bir Rakam !");
			else
				puts("		Onaltýlýk Bir Rakam Deðil !");
		}
	}
	else
	{
		/*Eðer girilen alfasayýsal bir karakter deðil ise noktalama iþareti olma þansý var bu yüzden bu else içerisinde ispunct fonksiyonu kullanýlacak.*/
		puts("Alfasayýsal Bir Karakter Deðildir !");
		if(ispunct(ch))
			puts("	Noktalama Ýþaretidir !");
		else
			puts("	Noktalama Ýþareti Deðildir !");
	}
	if(isascii(ch))
	{
		/*Burada bir de kontrol karakteri mi deðil mi onu kontrol edeceðiz. Kontrol karakterleri ascii kod olarak 0 - 32 ve 127 ye denk gelir dolayýsý ile ascii kod olmayan kontrol
		karakteri yoktur o yüzden bu if içerisinde kontrol edeceðiz.*/
		puts("Ascii Koddur!");
		if(iscntrl(ch))
			puts("	iscntrl Fonksiyonu Ýle Kontrol Karakteridir !"); /*non-printing yani enter home vb tuþlar gibi de denilebilir.*/
		else
		{
			/*Görüldüðü üzere isspace fonksiyonu için kontrol edilen deðerler iscntrl ile kontrol edilen deðerler kümesi ile ayný bu yüzden bu else içerisinde kullanýrýz.*/
			puts("	iscntrl Fonksiyonu Ýle Kontrol Karakteri Deðildir !");
			if(isspace(ch))
				puts("		Girilen Karakter Boþluk Karakterleridir !");
			else
				puts("		Girilen Karakter Boþluk Karakterleri Deðildir !");
		}
		if(isgraph(ch)) /*Görüldüðü gibi yazýlabilir deðerleri kontrol eder yani iscntrl fonksiyonunun tersidir.*/
			puts("	isgraph Fonksiyonu Ýle Kontrol Karakteri Deðildir !");
		else
		{
			/*Görüldüðü üzere isspace fonksiyonu için kontrol edilen deðerler iscntrl ile kontrol edilen deðerler kümesinin tersi ile ayný bu yüzden bu else içerisinde kullanýrýz.*/
			puts("	isgraph Fonksiyonu Ýle Kontrol Karakteridir !");
			if(isspace(ch))
				puts("		Girilen Karakter Boþluk Karakterleridir !");
			else
				puts("		Girilen Karakter Boþluk Karakterleri Deðildir !");
		}
	}
	else
		puts("Ascii Kod Deðildir !");
	if(isprint(ch))
		puts("Yazýlabilen Bir Karakterdir !");
	else
		puts("Yazýlamayan Bir Karakterdir !");
}

void program2_1()
{
	/*2 Katarlar üzerinde iþlem yapan fonksiyonlar örnekleri*/
	/*Aþaðýda yapýlan iþlem kýsaca anlatýlmak istenirse, biz klavyeden girilecek karater sayýsýný bilemiyoruz dolayýsý ile buna göre static olarak yani dizi biçiminde bir deðiþken
	oluþturmak performansý etkiler. Bu yüzden bir tane klavyeden girilen metni tutan geçici bir buf isiminde sabit bir dizi ile tutulup daha sonradan bunun sayýsýna göre pointera
	bellek ayýrma yapýyoruz. k1 pointerýnýn boyutunu arttýrýyoruz ki k2 pointerýnýn deðerini de tutabilsin.*/
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1;
	char *k2;
	char src;
	int buflenght;
	int i;
	printf("Ýsim: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcat(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("Soyisim: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	strcat(k2, buf);
	strcpy(buf, "\0");
	k1 = (char *)realloc(k1, sizeof(char) * (buflenght + 1 + strlen(k1))); /*+1 aþaðýda yapýlan boþluk eklemesinden dolayýdýr.*/
	strcat(k1, " ");
	strcat(k1, k2);
	printf("Hoþgeldin %s\n", k1); /*Katar pointerlar yazýlýrken * ihmal edilir.*/
	puts("");
	free(k1);
	free(k2);
}

void program2_2()
{
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1;
	char *k2;
	char src;
	int buflenght;
	int i;
	printf("k1 katarý: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcat(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("k2 katarý: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	strcat(k2, buf);
	strcpy(buf, "\0");
	printf("k1 katarýnýn uzunluðu %d, k2 katarýnýn uzunluðu %d\n", strlen(k1), strlen(k2));
	printf("\nGirilen k1 katarýnda aratmak istediðiniz karakter: ");
	src = getch();
	if(isspace(src)) /*Girilen karakter boþluk ise boþluk karakteri nonprinting olduðu için yazýlamaz bu yüzden bu if yapýsýný kurduk.*/
		printf("BOÞLUK\n");
	else
		printf("%c\n", src);
	if(strchr(k1, src) != NULL)
	{
		/*While iþlemi kaçýncý indiste bulunduðunu bulmak için*/
		i = 0;
		while((k1 + i) != strchr(k1, src))
			i++;
		printf("Aranan karakter %p bellek adresinde %d. indiste bulundu !\n", strchr(k1, src), i);
	}
	else
		puts("Aranan karakter bulunamadý !");
	/*k1 katarýna harf, k2 katarýna sayýsal bir deðer girilmesini istemediðimizi farzederek bir kontrol yapýsý.*/
	if(strcspn(k1, "abcdefghýijklmnoöprsþtuüvyzABCDEFGHIÝJKLMNOÖPRSÞTUÜVYZ") != 0)
		puts("Baþarýlý k1 katarýna harf girilmedi !");
	else
		puts("Baþarýsýz k1 katarýna harf girildi !");
	if(strcspn(k2, "0123456789") != 0)
		puts("Baþarýlý k2 katarýna rakam girilmedi !");
	else
		puts("Baþarýsýz k2 katarýna rakam girildi !");
	FILE *fp; /*Dosyalama iþleminde görülecek kodlar.*/
	fp = fopen("file.txt", "r");
	printf("Error: %s\n", strerror(errno));
	puts("");
	free(k1);
	free(k2);
}

void program2_3()
{
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1;
	char *k2;
	char *src;
	int buflenght;
	int i;
	printf("Yazýlacak metin: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("Ayrým operatörleri: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	printf("k1 katarý: %s\n", k1);
	strcpy(k2, buf);
	strcpy(buf, "\0");
	i = 1;
	/*Burada aklýnýzda bir soru olmasý gerekir yoksa da sorulan soruyu cevaplamanýz gerekir.*/
	src = strtok(k1, k2);
	while(src != NULL)
	{
		printf("%d.Parça: %s\n", i++, src);
		src = strtok((char *)NULL, k2);
	}
	free(k1);
	free(k2);
}

void program2_4()
{
	char buf[100]; /*Klavyeden girilen yazýnýn boyutunu öðrenmek için kullanýlan geçici bellek olarak düþünülebilir.*/
	char *k1;
	char *k2;
	char *src;
	int buflenght;
	int i;
	printf("Yazýlacak metin: ");
	gets(buf);
	buflenght = strlen(buf); /*Klavyeden girilen ismin karakter sayýsýný buluyor. (NULL KARAKTER OLARAK SAYILMAZ)*/
	k1 = (char *)malloc(sizeof(char) * buflenght);
	strcpy(k1, buf); /*k1 zaten boþ bu yüzden ekleme iþlemi yaptýk ayný zamanda taþýma iþlemi de yaptýk.*/
	printf("Ayrým operatörleri: ");
	gets(buf);
	buflenght = strlen(buf);
	k2 = (char *)malloc(buflenght);
	printf("k1 katarý: %s\n", k1);
	strcpy(k2, buf);
	strcpy(buf, "\0");
	src = memchr(k1, 'A', 10);
	if(src == NULL)
		puts("Bulunamadý !");
	else
		printf("%p adresinde %c deðeri bulundu !\n", src, *src);
}

program3()
{
	FILE *f;
	char mod;
	char selection;
	char *dataToFile;
	do
	{
		/*mod tek karater alabildiði için r+, w+ ve a+ yerine R, W ve A yazýlmasý istenmiþtir.*/
		printf("Yanlýzca Okuma(Yeni dosya oluþturulamaz.)[r]\nYanlýzca Yazma(Yeni dosya oluþturulur.)[w]\nYanlýzca Ekleme(Dosya yoksa yeni dosya oluþturulabilir.)[a]\n");
		printf("Okuma Ve Yazma(Yeni dosya oluþturulamaz.)[R(r+)]\nYazma Ve Okuma(Yeni dosya oluþturulur.)[W(w+)]\nEkleme, Yazma ve Okuma(Dosya yoksa yeni dosya oluþturulabilir.)");
		printf("[A(a+)]\nDosya hangi mod da açýlacak: ");
		mod = getch();
		printf("%c\n", mod);
		switch(mod)
		{
			case 'r':
				if(fopen("dosya.txt", "r") == NULL) /*Dosya dizinde yoksa, yazma modu ile açýlamaz NULL dönderir.*/
				{
					printf("\n");
					puts("Dosya dizinde yoktur ! Tekrar yönlendiriliyorsunuz.");
					mod = '\0';
				}
				else
				{
					int i;
					f = fopen("dosya.txt", "r");
					printf("\n");
					puts("Dosya r modunda açýldý !");
				}
				break;
			case 'w':
				if(fopen("dosya.txt", "r") != NULL)
				{
					do
					{
						printf("Dosya dizinde mevcuttur. Yeniden yazma modunda açmak dosya içerisindeki verilerin sýfýrlanmasýna neden olacaktýr. Yinede açmak istiyormusunuz");
						printf("[E]/[H]: ");
						selection = getch();
						switch(tolower(selection)) /*Kullanýcý büyük harf de girebilir eðer büyük harf girerse kontrol etmek zorlaþacaðý için küçük harfe dönüþtürülüyor.*/
						{
							case 'e':
								f = fopen("dosya.txt", "w");
								printf("E\n");
								puts("Dosya oluþturuldu ! w modun da açýldý.");
								break;
							case 'h':
								printf("H\n");
								puts("Mod seçimine tekrar yönlendiriliyorsunuz !");
								break;
							default:
								printf("\n");
								printf("Seçim anlaþýlmadý !\n");
								selection = '\0';
								break;
						}
					}
					while(selection == '\0');
				}
				else
				{
					f = fopen("dosya.txt", "w");
					printf("\n");
					puts("Dosya oluþturuldu ! w modun da açýldý.");
				}
				break;
			case 'a':
				f = fopen("dosya.txt", "a");
				printf("\n");
				puts("Dosya a modunda açýldý !");
				break;
			case 'R':
				if(fopen("dosya.txt", "r") == NULL) /*Dosya dizinde yoksa, yazma modu ile açýlamaz NULL dönderir.*/
				{
					printf("\n");
					puts("Dosya dizinde yoktur ! Tekrar yönlendiriliyorsunuz.");
					mod = '\0';
				}
				else
				{
					int i;
					f = fopen("dosya.txt", "r+");
					printf("\n");
					puts("Dosya r+ modunda açýldý !");
				}
				break;
			case 'W':
				if(fopen("dosya.txt", "r") != NULL)
				{
					do
					{
						printf("\n");
						printf("Dosya dizinde mevcuttur. Yeniden yazma modunda açmak dosya içerisindeki verilerin sýfýrlanmasýna neden olacaktýr. Yinede açmak istiyormusunuz");
						printf("[E]/[H]:");
						selection = getch();
						switch(tolower(selection))
						{
							case 'e':
								f = fopen("dosya.txt", "w+");
								printf("E\n");
								puts("Dosya oluþturuldu ! w+ modun da açýldý.");
								break;
							case 'h':
								printf("H\n");
								puts("Mod seçimine tekrar yönlendiriliyorsunuz !");
								break;
							default:
								printf("\n");
								printf("Seçim anlaþýlmadý !\n");
								selection = '\0';
								break;
						}
					}
					while(selection == '\0');
				}
				else
				{
					f = fopen("dosya.txt", "w+");
					printf("\n");
					puts("Dosya oluþturuldu ! w+ modun da açýldý.");
				}
				break;
			case 'A':
				f = fopen("dosya.txt", "a+");
				printf("\n");
				puts("Dosya a+ modunda açýldý !");
				break;
			default:
				puts("\nGeçersiz bir deðer girildi tekrar yönlendiriliyorsunuz !");
				mod = '\0';
				break;
		}
	}
	while(mod == '\0');
	/*Yukarda sadece dosya açýlmasý yapýlmýþtýr.*/
	fclose(f);
	f = tmpfile(); /*w+ modunda geçici bir dosya açar. Program kapatýldýðýnda silinir.*/
	perror("Hata mesajý");
	getch();
	/*Aþaðýda bir hata alacaksýnýz hata þu ilk yazý ve ikinci yazý yazdýktan sonra üçüncü yazýdan önce bir Abdullah yazýsý görünüyor dosyada peki bu neden*/
	dataToFile = (char *)malloc(sizeof(char) * 8);
	strcpy(dataToFile, "Abdullah");
	fopen("dosya1.txt", "w");
	fprintf(f, "%s ile c dersleri ilk yazý !\n", dataToFile);
	fwrite("Abdullah ile c dersleri ikinci yazý !", 1/*Her verinin kaç binary olduðu bizimde char olduðu için 1*/, 50/*Kaç binary belirtildi ise tek eleman 1 olmak üzere *binary*/, f);
	fputs("\nAbdullah ile c dersleri üçüncü yazý !\n", f);
	fputc(103, f); /*g harfi*/
	fclose(f);
}

void program5_1()
{
	puts("Program sonlandýrýlmadan önce !");
	atexit(program2_1);
	atexit(program1);
	/*abort(); Console ekranýnda return value deðeri 3 olduðu gözlenecektir. atexit fonksiyonlarý abort yani anormal biçimde sonlanma halinde çalýþmazlar.*/
	exit(1);
}

int program5_2fonk(int *a, int *b) /*Sýnama fonksiyonu*/
{
	/*Buranýn içerisinde eðer a - b = 0 ise eþit, a - b > 0 ise a b'den büyük veya a - b < 0 ise b a'dan büyük olur ve biz bu fonksiyondan geriye bunu döndeririz ve bu fonksiyondaki
	geri dönüþ deðerine göre bsearch fonksiyonu iþlem yapar.*/
	return *a - *b;
}

void program5_2()
{
	int arylenght;
	int i;
	int *ary;
	int *found;
	int sval;
	srand(time(NULL));
	printf("Kullanýlacak dizinin eleman sayýsý: ");
	scanf("%d", &arylenght);
	ary = (int *)malloc(sizeof(int) * arylenght);
	puts("");
	/*Dizinin elemanlarýný rastgele atýyoruz.*/
	for(i = 0; i < arylenght; i++)
		*(ary + i) = rand() % 1000;
	/*Dizinin elemanlarýný bsearch fonksiyonunda kullanmak için qsort fonksiyonu ile küçükten büyüðe sýralýyoruz.*/
	qsort(ary, arylenght, sizeof(int), (void *)program5_2fonk);
	for(i = 0; i < arylenght; i++)
		printf("%d.eleman: %d\n", i + 1, *(ary + i));
	/*Arama iþlemi yapýyoruz.*/
	printf("Aranan deðer: ");
	scanf("%d", &sval);
	found = bsearch(&sval, ary, arylenght, sizeof(int), (void *)program5_2fonk); /*Aranan deðerin adresi girilmelidir.*/
	/*Bulunup bulunmadýðýný kontrol ediyoruz.*/
	if(found != NULL)
	{
		/*Bulunan deðerin indis numarasýný buluyoruz.*/
		i = 0;
		while(found != (ary + i))
			i++;
		printf("Aranan deðer %p adresinde %d.indiste bulundu !\n", found, i);
	}
	else
		puts("Aranan deðer dizi içersiinde bulunmuyor !");
	free(ary);
}

void program5_3()
{
	int pay;
	int payda;
	div_t bolme;
	printf("Bölme iþlemini a/b formatýnda giriniz: ");
	scanf("%d/%d", &pay, &payda);
	bolme = div(pay, payda);
	printf("Bölme iþleminde bölüm: %d, kalan: %d\n\n", bolme.quot, bolme.rem);
	printf("Sorgulama sonucu: \n%s", getenv("DATE"));
}

void program5_4()
{
	system("HELP");
}

typedef struct
{
	int d;
	char c;
	float f;	
}v;

void yaz(char *str, ...)
{
	/*Bu uygulamada printf fonksiyonu gibi çalýþan bir fonksiyon yazýlacak.*/
	int i; int counter;
	i = counter = 0; 
	char temp; char buf[100];
	va_list argumans;
	v var;
	va_start(argumans, str);
	while(*(str + i) != '\0')
	{
		if(*(str + i) == '%')
		{
			i++;
			temp = *(str + i);
			switch(temp)
			{
				case 'd':
					counter = 0;
					var.d = va_arg(argumans, int);
					itoa(var.d, buf, 10);
					while(buf[counter] != '\0')
					{
						putch(buf[counter++]);
					}
					i++;
					break;
				case 'i':
					counter = 0;
					var.d = va_arg(argumans, int);
					itoa(var.d, buf, 10);
					while(buf[counter] != '\0')
					{
						putch(buf[counter++]);
					}
					i++;
					break;
				case 'f':
					counter = 0;
					var.f = va_arg(argumans, double);
					gcvt(var.f, 8, buf);
					while(buf[counter] != '\0')
					{
						putch(buf[counter++]);
					}
					i++;
					break;
				case 'c':
					var.c = va_arg(argumans, int);
					putch(var.c);
					i++;
					break;
				case 's':
					strcpy(buf, va_arg(argumans, char *));
					for(counter = 0; counter < strlen(buf); counter++)
						putch(buf[counter]);
					i++;
					break;
				case '%':
					putch('%');
					i++;
					break;
			}
		}
		else
		{
			putch(*(str + i));
			i++;
		}
	}
	va_end(argumans);
}

void program7()
{
	time_t s = time(NULL);
	time(&s);
	/*Yukarýdaki iki iþlem de ayný þeyi ifade eder.*/
	clock_t cl;
	clock_t cl1;
	struct tm *z;
	char ktr[250];
	z = gmtime(&s);
	puts("GMT'ye göre");
	printf("Saat: %d, Dakika: %d, Saniye: %d, Gün: %d, Ay: %d, Yýl: %d\n", z->tm_hour, z->tm_min, z->tm_sec, z->tm_mday, z->tm_mon + 1, z->tm_year + 1900);
	z = localtime(&s);
	puts("Yerel zamana göre");
	printf("Saat: %d, Dakika: %d, Saniye: %d, Gün: %d, Ay: %d, Yýl: %d\n", z->tm_hour, z->tm_min, z->tm_sec, z->tm_mday, z->tm_mon + 1, z->tm_year + 1900);
	puts("");
	printf("asctime: %s\nctime: %s\n", asctime(z), ctime(&s));
	s = mktime(z);
	printf("Topluluða göre zaman %d\n", s);
	strftime(ktr, 250, "%B(%m) - %A(%d) - %Y", z);
	puts(ktr);
	int i = 0;
	puts("Registersýz deðiþken ile while döngüsü.");
	getch();
	cl1 = clock();
	while(i < 10000)
		printf("%d\n", i++);
	cl = clock();
	printf("%d saniye oldu.\n", ((cl - cl1) / CLK_TCK));
	puts("Register deðiþken ile while döngüsü.");
	getch();
	register int a;
	cl1 = clock();
	while(a < 10000)
		printf("%d\n", a++);
	cl = clock();
	printf("%d saniye oldu.\n", ((cl - cl1) / CLK_TCK));
}

void jmpfonk(jmp_buf *p)
{
	puts("Fonksiyon çaðrýldý. Geri dallanma yapýlýyor...");
	longjmp(*p, 1); /*Bu fonksiyon çaðrýldýktan sonra setjmp fonksiyonuna return deðeri olarak 2. parametreyi gönderir.*/
}

void program8()
{
	int x;
	jmp_buf p;
	x = setjmp(p); /*goto deyiminde nokta: gibi gidiþ kapýsý açýlýyor.*/
	if(x)
	{
		printf("Yerel olmayan dallanma yapýldý, x: %d\n", x);
		exit(x);
	}
	puts("Ýf içerisine girilmedi fonksiyon çaðrýlýyor...");
	jmpfonk(&p);
}

void ayricalik()
{
	int selection;
	printf("Ayrýcalýklý durum algýlandý.\n");
	do
	{
		printf("Çýkýþ[0]\nDevam[1]\nSeçim: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 0:
				exit(1);
				break;
			case 1:
				puts("Devam ediliyor.");
				signal(SIGINT, ayricalik); /*SIGINT deðiþkeni eðer 0 a bölme ayrýcalýk durum yaþanýrsa sistem tarafýndan çalýþtýrýlacak fonksiyondur.*/
				break;
		}
	}while(selection == 0);

}

void program9()
{
	float a; float b; float result;
	int selection;
	signal(SIGINT, ayricalik); /*SIGINT deðiþkeni eðer 0 a bölme ayrýcalýk durum yaþanýrsa sistem tarafýndan çalýþtýrýlacak fonksiyondur.*/
	do
	{
		printf("a/b formatýnda iki adet sayý giriniz: ");
		scanf("%f/%f", &a, &b);
		if(!a) /*a == false yani a == 0 durumu kontrol ediliyor.*/
			raise(SIGINT);
		if(!b)
			raise(SIGINT);
		result = a / b;
		printf("Tekrar Bölme Yapýlacak mý\nÇýkýþ[0]\nDevam[1]\nSeçim: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 0:
	
				break;
			case 1:
				puts("Devam ediliyor.");
				break;
		}
	}while(selection != 0);
	printf("Sonuç: %f", result);
}

void program10()
{
	int inpval;
	printf("0'dan büyük bir deðer giriniz: ");
	scanf("%d", &inpval);
	if(inpval > 0)
		printf("Girilen deðer: %d\n", inpval);
	else
		assert(inpval > 0);
	puts("Element");
}

void main()
{
	puts(setlocale(LC_ALL, "Turkish"));
	/*1 Karakter üzerinde iþlem yapan fonksiyonlar örnekleri*/
	//program1();
	/*2 Katarlar üzerinde iþlem yapan fonksiyonlar örnekleri*/
	//program2_1();
	//program2_2();
	//program2_3();
	//program2_4();
	/*3 Standart I/O fonksiyonlarý örnekleri*/
	//program3();
	/*5 Genel amaçlý fonksiyonlar örnekleri*/
	//program5_1();
	//program5_2();
	//program5_3();
	//program5_4();
	/*6 Esnek argüman aktarýmý fonksiyonu*/
	/*int a = 5; float b = 128.4782; char temp[] = "(Bu bir string)";
	yaz("Abdullah %d ile %d%d deneme. Float: %f String: %s Char: %c  %%", 2000, a, 500, b, temp, 'a');*/
	/*7 Zaman ve tarih fonksiyonu*/
	program7();
	/*8 Yerel olmayan dallanma fonksiyonu*/
	//program8();
	/*9 Ayrýcalýklý durum kontrolü fonksiyonlarý*/
	//program9();
	/*10 Hata ayýklama fonksiyonu*/
	//program10();
}
