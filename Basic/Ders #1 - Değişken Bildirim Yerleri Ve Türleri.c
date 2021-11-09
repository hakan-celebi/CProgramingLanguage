#include <stdio.h>
#include <locale.h>

/*Bu fonksiyon için int val olarak bir parametre belirttik fakat bunu farklý bir biçimde de belirtme imkanýmýz vardý yani
int pow(val)
int val; -> Bu parametrelerin bildirimine ise "FORMAL BÝLDÝRÝM" denir.
{
	
}
	þeklinde de belirtebilirdik bunun örneðini iki ye modunu alan bir fonksiyon yaparak belirleyelim;
*/

char text[67] = "Bu da genel bir deðiþkendir. Fonksiyonlarýn dýþarýsýnda tanýmlanýr."; /*GENEL BÝLDÝRÝM*/

int poww(int val) /*Kare alma fonksiyonu.*/
{
	int newval = val * val; /*Kendi oluþturduðum fonksiyonun içerisindeki yerel deðiþken. YEREL BÝLDÝRÝM*/
	return newval;
	/*Bu fonksiyon içerisindeki deðiþkenler yani kiþisel olarak oluþturduðumuz fonksiyon içerisindeki deðiþken ve parametreler fonksiyon kullanýlýp bitirildikten sonra ram den temelli
	olarak silinirler.*/
}

int mod(val) /*Ýki ye mod alma fonksiyonu.*/
int val;
{
	return val % 2;
}

/*EXTERN (DIÞSAL) BÝLDÝRÝM:
	Büyük bir program yazdýðýmýz zaman ve ekip halinde çalýþtýðýmýz zaman programý kýsým kýsým ayýrmak isteyebiliriz. Hesap.c program kýsmýnda int val; þeklinde bir deðiþken
tanýmladýktan sonra bunu Cikti.c kýsmýnda ki bir fonksiyon içerisinde parametre olarak görmek isteyebiliriz. Ýþte bu yüzden deðiþkenin ilk oluþturulduðu yerde normal, diðer yerlerde ise
'extern' anahtar kelimesini ekleyer kullanacaðýmýz her kýsýmda tanýmlamamýz gerekir, aksi halde program derlenirken hata verir.
*/

int staticdefination()
{
	/*STATIC (SABÝT) BÝLDÝRÝM:
		Fonksiyon içerisine normal bir deðiþken tanýmladýðýmýz zaman deðiþken kullanýlýr ve fonksiyon sonlandýrýldýðý anda deðiþken ramden kaldýrýlýr. Fakat 'static' anahtar kelimesi
	ile fonksiyon içerisine static bir deðiþken koyarsak program sonlandýrýlana kadar bu static deðiþken fonksiyon içerisinde kalýr.
	*/
	static int x = 5;
	return x++;
}

/*REGISTER (SAKLAYICI) BÝLDÝRÝM:
	Register olmayan bir deðiþken tanýmladýðýmýz zaman bu deðiþken ramde tutulur. Register olan bir deðiþken tanýmladýðýmýz zaman iþlemci içerisinde bulunan register alanýnda tutulan
yani daha hýzlý eriþim saðlamamýzý saðlan deðiþken tanýmlamýþ oluruz. 'register' anahtar kelimesi ile tanýmlanýr. Çoðunlukla sýk kullanýlan örneðin döngü sayaçlarý gibi deðiþkenler
için kullanýlýr.
*/

/*VOLATILE BÝLDÝRÝM:
	C derleyicileri istenildiði taktirde bellek kullanýmý ve hýz açýsýndan optimizasyona sokulabilir. Bu optimizasyon sýrasýnda bazý deðiþkenlerin bozulma yada beklenmedik hatalar
alýnmasýna neden olabilir. Bu optimizasyona sokmak istemediðimiz deðiþkenlerin önüne 'volatile' anahtar kelimesini ekleriz.
*/

void main()
{
	setlocale(LC_ALL, "Turkish");
	int val1 = 4; /*Main fonksiyonu içerisinde bulunan bir yerel deðiþkendir. YEREL BÝLDÝRÝM*/
	int val2;
	register int i = 0;
	int nri = 0;
	printf("Program içerisinde tanýmlanmýþ deðiþkenin karesi: %d\n", poww(val1));
	printf("Bir deðer gir: ");
	scanf("%d", &val2);
	printf("Girilen sayýnýn iki ye modu: %d\n", mod(val2));
	printf("%s\n", text);
	/*Bu kýsýmda da görüþdüðü üzere deðiþken ramden program kapatýlana kadar silinmiyor.*/
	printf("Bu static deðiþkene sahip fonksiyonu ilk çaðýrým: %d\n", staticdefination());
	printf("Bu da ikinci çaðýrým: %d\n", staticdefination());
	printf("Bu register olmadan çalýþan for döngüsü\n");
	getch();
	for(nri; nri < 10000; nri++)
		printf("%d\n", nri);
	printf("Bu register deðiþken ile çalýþan for döngüsü\n");
	getch();
	for(i; i < 10000; i++)
		printf("%d\n", i);
	const char ch = 'p'; /*Buna sabit bildirimi denir tanýmlandýðý anda deðer atanmalýdýr. Bu deðiþkenin deðeri deðiþtirilemez veya eklenemez.*/
}
