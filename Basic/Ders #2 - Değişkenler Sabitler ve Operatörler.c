#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*DEÐÝÞKENLER:
	Deðiþkenler register anahtar kelimesi olanlar hariç ramde ikilik yani binary sayý sistemi ile tutulur. Deðiþken türleri C dili için üçe ayrýlýr.
	
1-Tam Sayý: Adýndan da anlaþýlacaðý gibi tam sayýlarý tutar. 'short', 'long' ve 'unsigned' olmak üzere üç adet anahtar kelime ile tanýmlanýr. Anahtar kelime olmadan int olarak tanýmlanan
bir tam sayý ramde 32 bit kadar yer tutar.
	*short: Türkçe anlamý ile kýsa tam sayýlarý tutar. Ramde depolanýrken 16 bit kadar yer tutar.
	*long: Türkçe anlamý ile uzun tam sayýlarý tutar. Ramde depolanýrken 64 bit kadar yer tutar.
	*unsigned: signed Türkçe anlamý ile iþaretli, unsigned ise iþaretsiz anlamýna gelir. '-'(negatif) sayýlarý signed anahtar kelimesi ile tanýmlarýz fakat zaten anahtar kelime olmadan
	tanýmlamada default(varsayýlan) olarak signed anahtar kelimesi vardýr. unsigned anahtar kelimesi ise iþaretsiz anlamý taþýr. Bu anahtar kelime tanýmlandýðý zaman '-'(negatif)
	sayýlar tutulmaz ve negatif alabileceði deðerlikler de pozitif tarafa aktarýlýr. Yani unsigned anahtar kelimesi ile deðiþkenin alabileceði sayý miktarýný ikiye katlamýþ oluruz.
	NOT: Dediðimiz gibi deðiþkenler ikilik tabanda yani binary sayý sistemi ile ramde tutulur, iþaretli(signed) ve iþaretsiz(unsigned) tutulma biçimi farklýdýr. Ýþaretsiz ise normal olarak
	binary sayý sisteminde nasýl ise ramde de öyle tutulur. Ýþaretli ise eksi sayýlar (çoðu iþlemcide) ikiye tamamlama aritmetiði ile elde edilir. Bazý iþlemcilerde ise ikiye tümleme
	aritmetiði yerine mutlak deðer ile de gösterilebilir.
	ÝKÝYE TAMAMLAMA ARÝTMETÝÐÝ:
		Ýlk olarak elimizdeki bir tamsayýyý ele alalým. 3 sayýsý ramde 16 bitlik þekilde "0000 0000 0000 0011" þeklinde tutulur. Bunun negatifini yani '-' iþaretlisini almak istediðimiz
	zaman 1'e tümlemesi yapýlýr. -> "1111 1111 1111 1100" ve bire tümlenmiþ hali budur. 1'e tümlemeden sonra 2'ye tümleme iþlemi için, 1'e tümlenmiþ haline binary sistemde 1 sayýsýný
	ekleriz yani. "1111 1111 1111 1100" + "0000 0000 0000 0001" = "1111 1111 1111 1101" þeklinde ikiye tümleyen bulunmuþ olur ve sonuç bu çýkar.
		Ayrýca deðiþkenlere deðerleri sekizlik, onluk ve onaltýlýk biçimde de atabiliriz.
	*sekizlik deðer atamasý için: Baþýna '0' konarak [0, 7] kapalý aralýðýnda istenilen deðeri yazabiliriz.
	*onluk deðer atamasý için: Standart olarak herhangi bir ek olmadan [0, 9] kapalý aralýðýnda istenilen deðeri yazabiliriz.
	*onaltýlýk deðer atamasý için: Baþýna '0X' koyarak [0, 9] -> [A, F] kapalý aralýðýnda istenilen deðeri yazabiliriz.
2-Gerçek Sayý: Adýndan da anlaþýlacaðý gibi rasyonel, ondalýklý veya gerçek sayýlarý tutar. Tam sayýlarda olduðu gibi bunun için de anahtar kelimeler vardýr. Ýki adet gerçel sayý
vardýr. Gerçel sayýlar kayan noktalý(floating point) biçiminde ramde saklanýr. Dolayýsýyla kayan noktalý sayýlar olarak da anýlabilir.
	1-Tek Duyarlý: 'float' þeklinde tanýmlanýr. Herhangi bir standart getirilmediði için derleyiciden derleyiciye farklýdýr fakat 6 hane alabilir olarak düþünebiliriz. Virgül yada nokta
	sayýlmadan en fazla 6 hane duyarlýlýðý vardýr.
	2-Çift Duyarlý: 'double' þeklinde tanýmlanýr. Yine derleyiciden derleyiciye deðiþir fakat 15 hane olarak düþünebiliriz. Virgül yada nokta sayýlmadan en fazla 15 hane duyarlýdýr.
	3-Uzun Çift Duyarlý: 'long' anahtar kelimesi ile 'long double' þeklinde tanýmlanýr. Yine elimizdeki herhangi bir sayýyý anahtar kelime olmadan deðer önüne L veya F eklersen 
	l-> long, f-> float tek duyarlý þeklini alabilir. Bu normalde double dan daha büyük olmasý gerekir fakat bazý derleyiciler duyarlýlýðýný ayný varsayýyor.

3-Karakter: Karakterler tek týrnak içerisinde char tanýmlamasý yapýlarak oluþturulur. Eðer dizi biçiminde yapýlýr ise çift týnak arasýna da metin kelime vb. þeyler yazýlabilir. Bütün
herþey bir karakterdir sayýlar da buna dahildir ve bütün bu karakterlerin en çok kullanýlan ascii ve ebcdic tablolarýnda karþýlýðý vardýr ve ramde yine binary sayý sistemi ile tutulur.
char tanýmlamasýnýn karþýsýna ikilik, sekizlik, onluk ve onaltýlýk sayý sisteminde deðer de girilebilir. Karþýlýðý ise tablodaki karþýlýðý olacaktýr.
*/

/*OPERATÖRLER:
	Deðiþkenler veya sabitler üzerinde belirli iþlem yapan iþaretler anlamýna gelir. Aritmetik, mantýksal, karþýlaþtýrma ve bitsel operatörler olarak dörde ayrýlýr. ?:, * ve &
operatörleri bitsel operatörler veya mantýksal operatörler içerisine girse de ayrý yerleri vardýr.

1-Aritmetik Operatörler: 7 adet operatör vardýr bunlar +(toplama), -(çýkarma), *(çarpma), /(bölme), %(mod alma), --(azaltma) ve ++(arttýrma) operatörleridir.
	Toplama (+) -> Ýki sayýsal deðeri toplamaya veya iki karakterleri yan yana birleþtirmeye yarar. Sola sað ekleme yapar.
	Çýkarma (-) -> Ýki sayýsal deðeri çýkarmaya yarar. Sola sað çýkartma yapar.
	Çarpma (*) -> Ýki sayýsal deðeri çarpmaya yarar. Sola sað çarpma yapar.
	Bölme (/) -> Ýki sayýsal deðeri bölmeye yarar. Sola sað bölme yapar.
	Mod (%) -> Ýki sayýsal deðerin bölümünden çýkan kalaný verir. Sola sað mod bulur.
	Arttýrma (++) -> Tek sayýsal deðer üzerinden veya karatker üzerinden 1 arttýrma yapar. Eðer sayýsal ise 1 arttýrýr eðer karakter ise bir sonraki harfi gösterir. Eðer bu arttýrma
	operatörü baþka bir deðere atanýrken kullanýlýyorsa (int number = ++5; veya int number = 5++;) solda olmasý ilk önce arttýrýp sonra deðer atamasý yaptýrýr. Saðda olmasý ise önce
	deðeri atýp sonra belirtilen deðeri bir arttýrmasý anlamýna gelir.
	NOT: % Operatörü belirtildiði gibi mod almaya yarar lakin rand() fonksiyoni ile 'int randomnumber = rand() % 100;' biçimide yazým görmüþsünüzdür. Burada mod operatörünün görevi
	deðiþmiyor rand() fonksiyonu 0 ile 32767 arasýnda rastgele deðer dönderir. Mod alma iþlemine sokmamýz demek rand() fonksiyonundan üretilen sayýnýn 100 e kalanýný vermesi demek, 
	yani elimizde 0 ile 99 kapalý aralýðýnda rastgele sayý olmasý demektir.
	 
2-Karþýlaþtýrma Operatörler: 6 Adet operatör vardýr bunlar >(büyük mü), >=(büyük veya eþit mi), <(küçük mü), <=(küçük veya eþit mi), ==(eþit mi) ve !=(eþit deðil mi) operatörlerdir.
Stringler için yani char dizileri için kullanýlamazlar bunlar string.h kütüphanesi içerisinde bulunan fonksiyonlar ile saðlanýr. Görevleri de isimlerinden anlaþýldýðý gibidir. Eðer
koþul saðlanýyor ise true saðlanmýyor ise geriye false döner.

3-Mantýksal Operatörler: 3 Adet operatör vardýr bunlar &&(ve), ||(veya) ve !(deðil) operatörleridir. Karþýlaþtýrma operatörlerini birbirine baðlamak, birleþtirmek için kullanýlýr.
	Ve (&&) -> Adýndan da anlaþýlacaðý gibi birden fazla koþul arasýna ve gelir ve hepsi true ise ancak true döner geri kalan iþlemlerde false döner.
	Veya (||) -> Yine adýndan da anlaþýlacaðý gibi birden fazla koþul arasýna veya gelir eðer hepsi false ise ancak false döner, geri kalan iþlemlerde true döner.
	Deðil (!) -> Eðer koþul true dönderiyor ise false, false dönderiyor ise true ya çevirir yani tersini almamýzý saðlar.
	
4-Bitwise Operatörler: Bitler üzerinde iþlem yapmak için kullanýlýr. Ramde tutulan bir deðiþkenin deðerleri ile deðil de bitleri üzerinde direkt olarak iþlem yapmak için kullanýlýr.
6 Adet bitwise operatör vardýr bunlar &(bit düzeyinde ve), |(bit düzeyinde veya), ^(bit düzeyinde yada), ~(bire tümleme yani 1'ler 0, 0'lar 1), <<(sola öteleme) ve >>(saða öteleme) dir.
	Bit Düzeyinde Ve (&) -> Direkt olarak örnek üzerinden ilerleyelim. Ve nin anlamý ikisi de ayný anda olmasý anlamýna gelir. Yani ikiside true(1) ise true, eþlenen deðerlerden
	herhangi biri false(0) ise false olacaktýr. Örneðin: int bitnumber = 'value'; þeklinde herhangi bir deðere eþit binary biçimde "xxxx xxxx" þeklinde olan bir deðiþken alalým ve bitwise
	operatörler ile iþlem yapalým bu da -> bitnumber = bitnumber & 4; þeklinde olsun. 4'ün binary kodu -> "0001 0000" þeklindedir. Ve'nin anlamý herhangi eþleþen eleman 0 olduðu anda
	false olmasýydý 4 için sadece 3 cü yani onluk tabanda 2^2 deðerine sahip bit. Bu yüzden 0 olanlarý & operatörü gereði 0 olmasý gerekir yeni bitnumber deðiþkenin binary kodu ise
	-> "0000 0x00" þeklinde olur. x eðer 1 ise -> "0000 0100", 0 ise -> "0000 0000" þeklindedir.
	Bit Düzeyinde Veya (|) -> Veya'nýn da ve gibi çalýþtýðý söylenilebilir. Veya da herhangi eþleþen bitlerden biri true(1) ise true gelir. Yine örnek üzerinde: int bitnumber = 'value';
	þeklindeki deðiþkenin binary kodu -> "xxxx xxxx" olacaktýr. bitnumber = bitnumber | 7; iþlemini yaparsak 7 nin binary kodu -> "0000 0111"; þeklindedir. Veya da herhangi bir eþleþen
	bit true olmasý yeterli demiþtik yani bitnumber deðiþkeninin binary kodu -> "xxxx x1111" olacaktýr. Burada belirleyici olan bitnumber deðiþkeninin ilk halindeki binary kodu, eðer
	bu x'ler 1 ise sonuçtaki o bit yerine 1, 0 ise o yere 0 gelecektir.
	Bit Düzeyinde Yada (^) -> Yada operatöründe ise birbiriyle eþleþen ve farklý olan bitlerin deðeri true, ikisi de ayný, yani 1 - 1 veya 0 - 0 olan bitlerin deðerinin 0 olmasý
	anlamýna gelir. Yine bir örnek üzerinden: int bitnumber = 27; deðiþkenini tanýmlayalým. Bu deðiþkenin binary kodu -> "0001 1011" þeklindedir. Bu deðiþkeni yada iþlemine sokarsak
	bitnumber = bitnumber ^ 41; 41 sayýsýnýn binary kodu -> "0010 1001" þeklindedir. Dolayýsýyla yada iþlemi ile ayný olanlar 0, farklý olanlar 1 olacaktýr. bitnumber deðiþkeninin
	yeni binary kodu -> "0011 0010" olacaktýr.
	NOT: Genel olarak yukardaki operatörler bitleri 0 lamak veya 1 lemek için farklý iþlemler için sadece mantýk kullanarak çözmemize olanak saðlayan araçlardýr.
	Bir'e Tümleme (~) -> Örnek olarak 42 sayýsýný alalým, binary kodu -> "0010 1010" þeklindedir. Bu sayýnýn tümleyenini aldýðýmýz zaman binary kodu -> "1101 0101" yani onluk tabanda
	213 sayýsýna eþittir. Biz 42 sayýsýný 8 bit ile yazabiliyoruz ve 8 bitin maximum alabileceði deðer 255 dir. Dikkat ettiysek alabileceði maximum deðerden kendisini çýkardýðýmýz
	zaman 213 yani tümleyenini bulmuþ oluyoruz.
	Öteleme (<< veya >>) -> Saða veya sola öteleme operatörleri ayný iþi görür, 1 olan tüm bitler istenildiði deðer kadar belirtilen (<< veya >>) yönde ötelenir. Saðdan ve soldan
	devamlý 0 gelir yani eðer fazla saða veya sola ötelersek 1 olan bitler kayýp yok olacaktýr ve biz elimizdeki binary kodu -> "0000 0000 0000 0000" þeklinde bulabiliriz.
	
Diðer Operatörler: +=, -=, *=, /=, %=, &=, |=, ^=, <<= ve >>= gibi bazý operatörler vardýr bunlar da bildiðimiz gibi iþlemi yapýp atamayý saðlarar. Bir diðer operatör ise ?: operatörü
bu operatör:
if(koþul)
{
	koþul saðlanýrsa(true gelirse) yapýlacak iþlemler.
}
if yapýsýnýn fazla yer kaplamamasýný, direkt olarak sorgu yapabilmemizi saðlar.
Kullanýmý -> (Koþul) ? (Saðlanýrsa - True ise yapýlacak iþlem) : (Saðlanmazsa - False ise yapýlacak iþlem);

Ýþaretçi Operatörler: '*' ve '&' olmak üzere iki adet iþaretçi operatörü vardýr.
	pointer (*) -> Bu iþaretçi anahtar kelimeler gibi deðiþken tanýmlamada kullanýlýr. Normal bir int deðiþken tanýmlamasý bildiðimiz gibi þu þekildedir -> int number = 'value';
	pointer tanýmlamasýnda ise '*' operatörü deðiþken isminin sol tarafýna koyulur ve tercihen bitiþik yazýlýr. (int *number = 'address') Bu þekilde tanýmlamaya pointer tanýmlamasý
	denir. Pointer deðiþken normal deðiþkenlerden farklý olarak bir deðer tutmaz adres tutar. Yani pointer ramdeki bir adresi tutar. O halde bir pointer deðiþkenine baþka bir
	pointer deðiþkenini atmak istersek atabiliriz çünkü diðer pointer da adres tutar. (int *ptr1 = 'address'; int *ptr2 = ptr1;) Burada karýþtýrýlmamasý gereken '*' operatörünü
	sadece tanýmlama yaparken kullandýk, yani eðer adrese ulaþmak istiyorsak, '*' operatörünü koymamamýz gerekir. Peki koyarsak ne olur ? Dediðimiz gibi bu deðiþken ramdeki bir gözün
	adresini tutar, eðer '*' operatörü ile tanýmlamadan sonra deðiþkeni kullanýrsak tutulan o adresteki deðeri bize dönderir. Ram'in örneksel çizimi aþaðýdaki gibidir.
															
																    		   ADDRESS			    VALUE
																		-----------------------------------------
	Pointer buradaki adres gözünü tutar. (atama haricinde * olmadan)  <-|				   |					| -> Normal deðiþken burayý tutar. Eðer atama haricinde * koyulur ise
	Normal deðiþkenin baþýna & gelirse o da buradaki adresi dönderi		-----------------------------------------	 pointer deðiþkeni de buradaki deðeri dönderir.	
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
																		|				   |					|
																		-----------------------------------------
	NOT: Eðer pointer baþýna & gelir ise pointer da ramde biryer tutar ve & ile pointerýn kendi sabit adresi dönderilir. Pointerlar da mantýk gerektiren ve iþimizi kolaylaþtýran
	deðiþkenlerdir.

sizeof(deðiþken tipi veya deðiþken ismi); -> Geriye byte olan bir deðer dönderir. (1 byte = 8 bit) ramde kapladýðý alaný bulmamýzý saðlar.
*/

/*ÖDEVLER
	-Bitwise operatörlerinin nerelerde kullanýlabileceðini araþtýr.1
	-Tüm operatörlerin ve aritmetik iþlemlerin önceliklerini araþtýr.1
	-Ýkilik tabanda toplama ve çýkarma iþlemlerini öðren.1
	-Cast etme yani dönüþüm yapma nedir nasýl yapýlýr ?1
	-Bitwise operatörler hangi tip deðiþkenler ile yapýlabilir ?0
	-Bir metin yazmak istediðimiz zaman char dizileri kullanýyoruz, peki bir char dizisi oluþturduðumuz zaman diziye ayýrdýðýmýz boyuttan küçük boyutlu eleman eklersek boþ kalan yerlere
	ne olur ?\0
	-strlen() hazýr kütüphane fonksiyonu ne iþe yarar ?1
*/
void main()
{
	setlocale(LC_ALL, "Turkish");
	int octal = 047; /*Sekizlik sayý sisteminde deðiþkene deðer atama.*/
	int decimal = 93; /*Onluk sayý sisteminde deðiþkene deðer atama.*/
	int hexadecimal = 0XFA; /*Onaltýlýk sayý sisteminde deðiþkene deðer atama*/
	/*%d decimal anlamýna gelir deðiþkenlere hangi sayý sisteminde deðer atýlmýþ olursa olsun sayýnýn decimal karþýlýðýný bize verir.*/
	printf("Onluk tabandaki deðerleri\n");
	printf("Sekizlik: %d, Onluk: %d, Onaltýlýk: %d\n", octal, decimal, hexadecimal);
	/*%o herhangi bir sayý sistemindeki sayýyý sekizlik tabanda, %x ise herhangi bir sayý sistemindeki sayýyý onaltýlýk tabanda yazdýrýr.*/
	printf("Onluk tabandaki deðerleri\n");
	printf("Sekizlik: %o, Onluk: %d, Onaltýkýk :%x\n", octal, decimal, hexadecimal);
	/*Aþaðýdaki gibi anahtar kelime kullanmadan deðerlerin sonuna l->long U->unsigned þeklinde de belirlemeler yapabiliriz. Tüm sayý sistemleri için geçerlidir.*/
	int ld = 19;
	int uld = 29UL;
}
