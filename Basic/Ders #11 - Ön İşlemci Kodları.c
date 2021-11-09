#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*C Dili Ön Ýþlemci Kodlarý:
	Bir C programýnda simgesel sabitler, makro fonksiyonlar veya programýn koþullu derlenmesi istenirse bu öniþlemci kodlarý kullanýlýr. Öniþlemci komutlarý C program kodunun 
derlenmeden önce bu komutlar iþlevlerini yerine getirir. Bu ön iþlemci kodlarý ile yazýlan bir programý farklý bir sisteme geçirerek çalýþmasýný veya yazýlan ortak bir program parçasýný
tekrar tekrar yazmak yerine ön iþlemci kodlarý ile hazýr halde kullanýlabilir.
	Ön iþlemci kodlarý '#' karakteri ile baþlarlar ve sonuna ';' karakteri konulmaz, tüm satýr o ön iþlemci koduna aitdir. Eðer satýr yetmez ve alt satýrdan devam edilmesi istenirse
satýr sonuna '\' karakteri konulur ve alt satýrdan öniþlemci kodu devam eder. Bu derste 12 adet ANCI C deki öniþlemci kodlarýný inceleyeceðiz.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1-#define Öniþlemci Kodu:
	Bu kod ile simgesel sabit bildirimi, bir program parçasýna simgesel bir isim ve makro fonksiyon tanýmlamasý yapýlabilir. Tanýmlanýrken #define simgeselsabitadi sabitdeger biçiminde
tanýmlanýrlar. Dikkat edilmesi gereken tip tanýmlama için geçerli olmamasýdýr. Tip tanýmlamak için typedef deyimi kullanýlýr.
	STANDART KÜTÜPHANEDE BÝLDÝRÝLMÝÞ BAZI SÝMGESEL SABÝTLER
		*__FILE__ -> Kaynak kodunun bulunduðu dosya adýný tutar.(katar)
		*__LINE__ -> Kaynak kodunun bulunduðu dosyadaki satýr sayýsýný tutar. (tamsayý)
		*__DATE__ -> Derleme tarihini tutar. (ay, gün, yýl)
		*__TIME__ -> Derleme saatini tutar. (saat dakika saniye)
		*__STDC__ -> Derleyicinin standardý destekleyip desteklemediðini gösterir. (1 - 0)
2-#undef Öniþlemci Kodu:
	Daha önce #define öniþlemci kodu ile tanýmlanmýþ simgesel sabit, program deyimi veya makro fonksiyonu geçersiz kýlmak için kullanýlýr. Tanýmlanmasý #undef simgeselsabit þeklindedir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3-#include Öniþlemci Kodu:
	Program içerisinde baþlýk dosyasý veya bir kaynak kod eklemek için kullanýlýr. Eðer derleyicinin belirlediði alandaki dosya için ise tanýmlanmasý #include <dosyaismi> biçiminde, 
deðilse #include "dosyaismi" biçimindedir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
4, 5, 6, 7, 8, 9 -> #if, #else, #endif, #elif, #ifdef ve #ifndef Öniþlemci Kodlarý:
	#if, #elif, #else ve #endif öniþlemci kodlarý bilinen if - else if - else yapýsý ile aynýdýr. Tek farklarý #endif görülene kadar olan tüm satýrlarý iþler bu yüzden sonuna #endif
koyulmalýdýr. #ifdef ve #ifndef ise tanýmlanmýþ ise veya tanýmlanmamýþ ise iþlem yapmak için kullanýlýr. Yine #endif beklenir. Bunlar yerine defined deyimi de kullanýlabilir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
10-#line Öniþlemci Kodu:
	Standart kütüphanede bildirilen __FILE__ ve __LINE__ simgesel sabitlerinin deðerlerinin deðiþtirilmesi için kullanýlýr. #line satirno "dosyaismi" þeklinde kullanýlýr ve eðer
__FILE__ deðiþtirilmek istenmez ise "dosyaismi" kýsmý olan ikinci parametre yazýlmaz.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
11-#error Öniþlemci Kodu:
	Yanýna yazýlan metini standart çýkýþa yazar ve derleme iþlemini durdurur.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
12-#pragma Öniþlemci Kodu:
	Ýlk parametre olarak verilen sistem deðiþkeni için ikinci ve diðer parametrelerde deðerlerini deðiþtirir.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/	

void main()
{
	setlocale(LC_ALL, "Turkish");
}
