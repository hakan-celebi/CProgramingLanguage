#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

/*Dosyalama iþlemleri;
	int gibi FILE tipi vardýr tanýmlanmasý;
	FILE *dosyaismi = fopen(); þeklindedir.
fopen() -> Ýçerisine iki adet argüman alýr dosyayý açmak için kullanýlýr.
1.Dosya adý a.txt gibi.
2.Dosya modu 6 adet dosya modu vardýr bunlar.
w->Sadece yazmak için açar eðer dosya yoksa tekrardan dosya oluþturur varsa üzerine oluþturur. Cursor
dosyanýn baþýndadýr.
r->Sadece okumak için açar eðer dosya yoksa açmaz hata verir.
a->Eklemek için açar yoksa oluþturur cursor dosyanýn sonundadýr.
w+->Yazmak için açar eðer dosya yoksa tekrardan dosya oluþturur varsa üzerinde oluþturur. Ayný zamanda
okuma iþlemi de yapar cursor dosyanýn baþýndadýr.
r+->Hem okuyum hep yazmak için açar dosya yoksa oluþturmaz cursor dosyanýn baþýndadýr.
a+->Eklemek için yazar okumada yapýlabilir cursor dosyanýn sonundadýr dosya yoksa onu açar.
kullanýmý -> fopen(dosyaismi.txt, dosyamodu(w, r, a, w+, r+, a+));

fclose() -> içerisine tek argüman alýr dosyayý kapatmak için kullanýlýr.
1.Dosya ismi.
kullanýmý->fclose(dosyaismi);

getc() -> içerisinde tek argüman alýr dosyadan karakter okur.
1.Dosya ismi.
kullanýmý -> char kr = getc(dosyaismi);

putc() -> içerisinde iki adet argüman alýr dosyaya karakter yazar.
1.Yazýlacak karakter.
2.Dosya ismi.
kullanýmý -> putc(kr, dosyaismi);

feof() ve EOF -> feof içerisinde tek argüman alýr EOF ise fonksiyon deðildir. Cursor sonda olup
olmadýðýný kontrol eder.
feof() true yada false deðerler alýr.
1.Dosya ismi
feof() kullanýmý -> feof(dosyaismi);
EOF kullanýmý char kr = getc(dosyaismi) != EOF;

fprintf() -> formatlý dosyaya veri yazdýrmak için kullanýlýr.
kullanýmý -> fprintf(dosyaismi, "%d gibi deðiþken þeyleri veya metin", degiskenismi);

fscanf() -> Belirtilen formatta konsol ile ayný þekilde dosyadan veri alýr.
kullanýmý -> fscanf(dosyaismi, "%d gibi deðiþken þeyleri", &degiskenismi);

fputs() -> Direkt olarak istediðimiz veriyi dosyaya yazmamýzý saðlar içerisine iki adet argüman alýr.
1.Veri.
2.Dosya ismi.
kullanýmý -> fputs(dosyaismi, "Yazýlacak veri");

fgets() -> Direkt olarak isteddiðimiz veriyi dosyadan okumamýzý saðlar içerisinde üç adet argüman alýr.
1.Okunacak verinin tutulduðu deðiþken.
2.Kaç karakterlik veri atýlacaðý n ise n-1 karakter.
3.Dosya ismi.
kullanýmý -> fgets(degiskenismi, okumaboyutu, dosyaismi);

fwrite() -> Direkt olarak dizi yazmamýzý saðlar üç adet argüman alýr.
1.Yazýlacak dizi.
2.Dizi boyutu.
3.Dosya ismi.
kullanýmý -> fwrite(dizi, diziboyut, dosyaismi);

fread() -> Dizi üzerinden direkt olarak veri okumamýzý saðlar üç adet argüman alýr.
1.Okunan dizinin tutulacaðý dizi.
2.Dizi boyutu.
3.Dosya ismi
kullanimi(dizi, diziboyut, dosyaismi)

fseek() -> Dosya içerisinde ki cursor'un pozisyonunu ayarlamamýzý saðlar üç adet argüman alýr.
1.Dosyaismi
2.Cursorun ilerletme miktarý.
3.Baþtan ortadan veya sondan yani 0, 1, 2;
kullanýmý -> fseek(dosyaismi, ilerletmemiktari, cursorbastamisondamiortadami).
*/

int main()
{
	setlocale(LC_ALL, "Turkish");
	FILE f = fopen("a.txt", a);
	fwrite()
	fclose(f);
	return 0;
}
