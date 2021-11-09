#include <stdio.h>
#include <ctype.h> /*Örneklerde göreceðimiz toupper fonksiyonunun barýndýrdýðý standar c kütüphanesi.*/
#include <locale.h>

/*PROGRAM DENETÝM DEYÝMLERÝ
	Program denetim deyimleri karþýlaþtýma ve döngü deyimleri olarak ikiye ayrýlýr.

1-Karþýlaþtýrm Deyimleri: if ve switch olmak üzere iki tip karþýlaþtýrma deyimi vardýr.
	if - else if - else -> else if ve else yapýlarý if yapýsýndan farklý olarak düþünülmemesi gerekir. if yapýsý ingilizce eðer anlamýna gelir. Parantezleri arasýna bir koþul yazýlýr ve
	koþul true dönderiyor ise scopelarý arasýndaki iþlem yapýlýr. Sadece if yazarak else if veya else deyimlerini kullanmadan if yapýsýný tek olarak yazabiliriz. if yapýsýný yazdýktan 
	sonra içerisindeki koþul saðlanmýyor ise else deyimi, saðlanmýyor fakat baþka bir koþulun saðlanmasý bekleniyor ise else if yapýsý kullanýlýr. else ingilizce deðil anlamýna gelir 
	yani eðer if içerisindeki koþul false gelir ise altýnda da else var ise bu yapý çalýþýr. else if ingilizce deðilse eðer anlamýna gelir. Ýlk olarak if yapýsý içerisindeki koþul
	false gelmelidir. Daha sonra alt tarafta else if var ise oraya girilir ve else if yapýsýnýn koþulu incelenir. Alt tarafta yine bir yapý varsa oraya geçiþ yapýlýr.
	if(koþul)
	{
		koþul true dönderirse buraya girer.
	}
	else if(koþul)
	{
		if yapýsýndaki koþul false bu yapýdaki koþul true dönderirse buraya girer.
	}
	else
	{
		yukakarýdaki tüm koþullarýn saðlanmadýðý yani false dönderdiði durumda buraya girer. en sona yazýlýr devamý olarak else veya else if deyimi kullanýlmaz.
	}
	NOT: if yapýsý altýna if yazarsak, yani iki adet if yaparsak ikisi de ayrý olarak deðerlendirilir ve iki if yapsýnýn koþulu da saðlanýyor ise ikisine de giriþ yapar. Yukardaki
	yazdýðýmýz if, else if ve else yapýsýný baþta kesinlikle if olmak, else kullanýlmak isteniyorsa en alta koymak þartý ile birleþik bir yapýdýr. Ýstendildiði kadar else if eklenebilir
	fakat sadece bir tane if ve else yapýsý olmak zorundadýr. Burada kurduðumuz birleþik yapýda birbirine baðlý koþullar vardýr. Yada operatörünü görmüþtük aslýna yada operatörüne 
	benzerdir, sadece bir yapýda true olmasý beklenir, eðer bir koþulda true gözlenir ve scopelarý arasýna girerse diðer yapýlara bakýlmaz. Bu birleþik yapýyý kurmak zorunda deðiliz
	bunda özgürüz ama dikkat edilmesi gerekenler þunlardýr.
		-if yapýsý olmadan else if deyimi kullanýlamaz.
		-else if yapýsý istenildiði miktarda yazýlabilir, içerisine bir koþul almalýdýr.
		-else yapýsý if yapýsý olmadan kullanýlmaz ve else yapýsý, her if yapýsýna aittir. Yani else yapýsýnýn sayýsý if yapýsýnýn sayýsýný geçemez.
		-Her if yapýsýnýn else veya else if yapýsý olmak zorunda deðildir.
		-else yapýsý koþul içermez.
	Örnek program1_1 fonksiyonunda yazýlmýþtýr. Ýnceleyin ve kullanýcý adý, þifre isteyen eðer doðru ise programý sonlandýran ve hoþgeldiniz mesajý yazan, eðer yanlýþ ise tekrar
	deneyiniz diyip tekrardan kullanýcý adý þifre isteyen programý yazýn.
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	switch -> switch yapýsý da bir kontrol deyimidir. if yapýsýndan farklý olarak sayýsal ve karakter deðiþkenlerin içeriðine göre iþlem yapar. if yapýsýndan daha hýzlýdýr fakat if
	yapýsý kadar kapsamlý deðildir. Örnek vermek gerekirse dört mevsim vardýr, yaz->1, sonbahar->2, kýþ->3 ve ilkbahar->4 deðerleri alan short int mevsim; isimli bir deðiþkenimiz olsun,
	mevsimlerin her biri için ayrý ayrý iþlem yaptýracak olalým, bunun için if yapýsý kullanýlabilir fakat switch yapýsý direkt olarak deðiþken içeriðine göre iþlem yaptýðý için,
	switch yapýsý kullanýlýr.
	switch(deðerine göre kontrol edilecek deðiþkenin ismi)
	{
		case 'deðer':
			case yanýna yazýlan deðer deðiþkende aranan deðer ise true döner ve buraya giriþ yapýlýr.
			break; /*iþlemler bittikten sonra alt case lere geçmemesi için break diyerek switch deyimi bitirilir.
		case 'deðer':
		
			break;
		default:
			Yukarýdaki hiç bir switch deyimindeki deðerler doðru deðil ise yani saðlanmýyor ise son olarak buradaki iþlem yapýlýr yani kullanýcý 4 adet mevsim var giriþ yapabileceði
			deðerler arasýnda seçim yapmaz ise buradaki iþlem yapýlýr.
			break;
	}
	Örnek program1_2 fonksiyonunda yazýlmýþtýr. Ýnceleyin ve switch yapýsýnýn avantajlarý ve dezavantajlarýný araþtýrýn, switch deyimi kullanýlmasý daha performanslý olduðunu
	düþündüðünüz baþka bir örnek program yazýnýz.
	
2-Döngü Deyimleri: while, do while ve for olmak üzere üç adet döngü deyimi vardýr. Döngü deyimleri bir programý belirli bir koþul için true dönderdiði zaman yani if de koþul saðlandýðý
zaman scope arasýn girip iþlem yapýyorken döngü deyimlerinde scope arasý tekrarlanýyor.
	while -> Belirli bir koþul veya mantýksal operatörler ile birleþtirilmiþ koþullar (Karþýlaþtýrma deyimlerinde de bu þekildedir) true dönderirse döngü scopelarý arasýna girer.
	while(koþul)
	{
		koþul true dönderirse buraya girer bu iþlemler bittikten sonra tekrar koþul kontrol edilir eðer hala koþul true ise tekrar scope arasýna girilir. koþul saðlanmayana kadar
		program buraya girer.
	}
	Örnek program2_1 fonksiyonunda gösterilmiþtir.
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	do while -> while ile ayný iþi yapar fakat tek farký baþlangýcýnda do olduðu için döngüyü program ilk okuduðu anda koþul saðlanmasa dahi içeriye girer ve daha sonra koþul kontrol
	edilir eðer koþul saðlanýyor ise tekrardan scope arasýna girilir.
	do
	{
		ilk seferde bu scope arasýna girilir ikinci seferde koþul alanýna gider eðer true dönüyorsa tekrardan buraya girer saðlanmýyor ise program devam eder.
	}while(koþul);
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	for -> while ve do while döngülerinden iki adet farký vardýr. Bunlar for döngü deyiminde sayaç olmasý ve bu sayaç ile ilgili iþlem yapabilmemizdir.
	for(sayaç için kullanýlacak deðiþkene verilecek ilk deðer; koþul; sayaç için yapýlacak iþlem)
	{
		Ýlk deðer ve iþlem bölümü boþ býrakýlabilir sanki varmýþda yazmýþýz gibi ; konur. koþul saðlanýr ise true dönderir ve scope içerisine girer.
			-Ýlk çalýþmada ilk deðer kýsmý okunur daha sonra koþul okunur true ise scope arasýna girer.
			-Scope arasýna girip çýktýktan sonra ilk olarak sayaç iþlem kýsmýna girer iþlem varsa yapýlýr daha sonra koþul kýsmýna girer koþul true ise tekrarlanýr.
	}
	Ödev Yazdýðýmýz banka programýný for döngüsüyle yazýn ve for döngüsü ne için program deyimi olarak kullanýlmaktadýr araþtýrýn.(while ve do while varken neden for a ihtiyaç olmuþ)
	
'break' VE 'continue' DEYÝMLERÝ:
	break -> Sadece döngü deyimleri ve switch deyimi içerisinde kullanýlýr. Program break deyimi üzerinde geldiði zaman yani okuduðu zaman hiç bir koþula bakmaksýzýn içinde bulunduðu
	deyimden dýþarý çýkar.
	Ödev Ýç içe döngü kullandýðýmýz zaman ve en içte break deyimini kullanýrsak ne olur ?
	-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	continue -> Saece döngü deyimleri içerisinde kullanýlan continue, döngü scopelarý arasýndan çýkmamýza, devam etmemize yarar. Yani bir döngü koþulu saðlandýðýnda(true) scope arasýna
	giriyordu, program continue deyimini gördüðü anda scope içerisindeki continue altýndaki herþeyi yoksayarak tekrar while ve do while ise koþul, for ise arttýrma iþlemine daha sonra
	koþula gider.
	Ödev Ýç içe döngü kullandýðýmýz zaman ve en içte continue deyimi kullanýrsak ne olur ?
	
goto DEYÝMÝ
	Programcýlar tarafýndan kodlarýn okunabilirliðini azaltýyor gibi çeþitli nedenlerden önerilmese de bazen kullanmamýz gerekecek alanlar olabilir. goto Ýngilizce git anlamýna gelir.
Programýn herhangi bir yerine (birden fazla olabilir) etiket koyarýz ve goto diyerek o etiketi iþaret ederiz. Program kodlarý satýr satýr okur ve goto 'etiket'; dediðimiz zaman program
etiketin bulunduðu satýra gider ve sanki orda kalmýþ gibi aþaðýya doðru satýr satýr devam eder. Etiket -> 'etiket ismi': tek týrnaklar olmadan etiketin ismi ve daha sonra ':' operatörü
ile koyulur goto deyimi ise -> goto 'etiket ismi'; þeklinde tek týrnaklar olmadan kullanýlýr.
	
ÖDEVLER
	-puts ve gets hazýr kütüphane fonksiyonlarýný araþtýr.
	-while döngüsünde break deyimi kullanýlmazsa ne olur ?
	-do while ile while arasýnda ki farký bildiðinizi göstermek için while kullanýlmasý gereken bir program ardýndan da do while kullanýlmasý gereken program yazýnýz.
	-Asal sayý bulma programýný ayrý bir fonksiyon kullanarak (recursive olmadan) yazýnýz.
	-Klavyeden iki adet sayý isteyin ve bir adet aritmetik iþlem operatörlerinden herhangi birini isteyin. Kullanýcýnýn girdiði operatöre göre sonucu hesaplayan programý yazýnýz.
	-rand() fonksiyonunu araþtýrýn ve sayý tahmin oyunu yapýn.
	
ZOR ÖDEV: Kullanýcýdan ikinci dereceden bir denklem isteyip denkleminin kökleri reel farklý mý, reel eþit mi veya karmaþýk mý bulan programý yazýn. Ödev bitene kadar zaman var.
*/

void program1_1()
{
	/*Bu örnek recursive fonksiyon ile yapýlmýþtýr. Recursive fonksiyonu daha sonra öðreneceðiz.*/
	/*Static tanýmladýk çünkü program1.1 fonksiyonuna her girildiðinde tekrardan ramde deðiþken oluþturulup, her çýkýldýðýnda deðiþken silerek programýn yavaþlamasýný engelledik.*/
	static char ch;
	printf("Devam için 'E'\nÝptal için 'H'\nSeçiminiz: ");
	ch = getch(); /*Getch klavyeden bir tuþa basýlmasýný bekler ve geriye basýlan tuþu dönderir.*/
	printf("%c\n", ch); /*getch() fonksiyonu kullanýldýktan sonra yani bir tuþa basýldýktan sonra bastýðýmýz tuþ ekranda gösterilmez. Biz manuel olarak ekranda gösteriyoruz.*/ 
	if(toupper(ch) == 'E') /*Kullanýcý harfi küçük olarak da girmiþ olabileceði için ne girilirse girilsin büyük harfe dönüþtürmek için toupper() fonksiyonu kullanýldý.*/
		program1_1(); /*Burada eðer basýlan tuþ 'E' harfi ise tekrardan fonksiyonu çaðýr dedik.*/
	else if(toupper(ch) == 'H')
		printf("Baþarý ile çýkýþ yapýldý !\n"); /*Burada çýkýþ yapýldýðý için mesaj yazdýk ve fonksiyonu tekrar çaðýrmadýk.*/
	else
	{
		/*'E' veya 'H' harfleri girilmedi ise yanlýþ seçim yapýlmýþtýr else bu iki koþulda saðlanmadýðý için çalýþýr ve tekrar fonksiyon çaðrýlýr.*/
		printf("Yanlýþ seçim yapýldý tekrar deneyiniz !\n");
		program1_1();
	}
}

void program1_2()
{
	static char ch;
	printf("Yaz[y]\nKýþ[k]\nÝlkbahar[i]\nSonbahar[s]\nSeçim yapýnýz: ");
	ch = getch();
	/*Ýngilizce de büyük 'Ý' harfi olmadýðý için hata ile karþýlaþabiliriz. Büyük 'Ý' harfinin ascii kodu -104 dür if yapýsý ile eðer büyük 'Ý' girilmiþ ise küçük 'i' harfi yapýyoruz.*/
	if((int)ch == -104)
		ch = 'i';
	switch(tolower(ch)) /*Büyük harf girilmiþ olabilir, tolower fonksiyonu ile küçük harfe dönüþtürme yapýyoruz.*/
	{
		case 'y':
			printf("y\n"); /*getch fonksiyonunun basýlan tuþu ekrana yazmadýðýný söylemiþtik bu yüzden y harfi yazdýrdýk baþta.*/
			printf("Yaz mevsiminin aylarý: Haziran, Temmuz ve Aðustos aylarýdýr.\n");
			break;
		case 'k':
			printf("k\nKýþ mevsiminin aylarý: Aralýk, Ocak ve Þubat aylarýdýr.\n");
			break;
		case 'i':
			printf("i\nÝlkbahar mevsiminin aylarý: Mart, Nisan ve Mayýs aylarýdýr.\n");
			break;
		case 's':
			printf("s\nSonbahar mevsiminin aylarý: Eylül, Ekim ve Kasým aylarýdýr.\n");
			break;
		default:
			printf("Yanlýþ seçim yaptýnýz tekrar deneyiniz !\n");
			program1_2();
			break;
	}
}

void program2_1()
{
	/*Bir banka gibi düþünelim ve kullanýcý bankaya bir miktar para yatýrsýn ve 0.02 oranýnda vadeli olsun bu hesap. Yatýrýlan para da vade ile 0.02 oranýnda artacaktýr. Bir noktadan
	sonra durmasý gerekir eðer hesaptaki para yatýrýlan para miktarýnýn 12 katýný geçerse vade bozulsun ve vade bitmiþtir uyarasýsý verilsin.*/
	float vadeOran = 0.02;
	double hesap; double vadeSonu; double yatanPara; double oncekiPara;
	short int i = 1;
	short int ctrl;
	printf("Yatýrmak istediðiniz para: ");
	scanf("%lf", &hesap);
	yatanPara = hesap;
	vadeSonu = hesap * 12;
	printf("Hesabýnýza %lf TL yatýrýlmýþtýr vade oranýnýz %f, hesabýnýzda %lf TL olduktan sonra vadeniz sonlandýrýlacaktýr.\n", hesap, vadeOran, vadeSonu);
	while(hesap < vadeSonu)
	{
		oncekiPara = hesap;
		hesap += (hesap * vadeOran);
		printf("%d.Gün\nHesabýnýza %lf TL vadeden dolayý eklenmiþtir.\n", i++, (hesap - oncekiPara));
		do
		{
			printf("Hesap Görüntüle[1]\nToplam Kazanç[2]\nDevam[3]\nSeçiminiz: ");
			ctrl = getch() - '0'; /*getch karakterin ascii kodunu alýr, '0' karakterinin ascii kodunu aldýðýmýz zaman sayýsal deðere ulaþýrýz.*/
			switch(ctrl)
			{
				case 1:
					printf("1\nHesabýnýzda %lf TL bulunuyor.\n", hesap);
					break;
				case 2:
					printf("2\nToplam kazanç: %lf TL\n", (hesap - yatanPara));
					break;
				case 3:
					printf("3\n");
					break;
				default:
					printf("Seçim yanlýþtýr tekrar deneyiniz !\n");
					break;
			}
		}while(ctrl != 3);
	}
	printf("Vadeniz bitmiþtir.\nToplam kazanç: %lf TL\nHesap: %lf TL\n", (hesap - yatanPara), hesap);
}

void main()
{
	a:
	int a; int b;
	setlocale(LC_ALL, "Turkish");
	//program1_1(); /*Ýlk karþýlaþtrýma deyimi örnek*/
	printf("\n");
	//program1_2(); /*Ýkinci karþýlaþtýrma deyimi örnek*/
	printf("\n");
	program2_1(); /*Ýlk döngü deyimi örnek*/
	goto a;
	goto b;
}
