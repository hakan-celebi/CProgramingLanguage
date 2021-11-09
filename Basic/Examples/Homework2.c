#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

unsigned short int n;
unsigned short int urun_id;

typedef enum
{
	normal, admin
}authority;

typedef enum
{
	false, true
}bool;

typedef struct
{
	unsigned short int primary_key;
	authority yetki;
	char *name;
	char *password;
	char *special_code;
	double fund;
}member;

typedef struct
{
	unsigned short int primary_key;
	char *product_name;
	unsigned short int unit;
	double price;
}stock;

/*Using file names
	*struct uye -> uyeler.txt
	*struct stok -> stok.txt
	*log -> log.txt (giriþ çýkýþ iþemlerinin kayýtlarýný tutar.)
*/

/*Üye Ýçin Primary Key Arttýrma*/
void setkey()
{
	FILE *temp = fopen("key.txt", "w");
	n++;
	fprintf(temp, "%d", n);
	fclose(temp);
}

/*Stok Ýçin Primary Key Arttýrma*/
void seturun_id()
{
	FILE *temp = fopen("urun_id.txt", "w");
	urun_id++;
	fprintf(temp, "%d", urun_id);
	fclose(temp);
}

/*Üye'nin Veri Tabanýnda Varlýðýný Kontrol Etme*/
bool checkLogin(char *inpname, char *inppassword, member *uye)
{
	FILE *f = fopen("uyeler.txt", "r"); struct tm *z; time_t nows;
	if(f != NULL)
	{
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(uye->primary_key), &(uye->yetki), uye->name, uye->password);
			fscanf(f, "%s %lf", uye->special_code, &(uye->fund));
			if(!strcmp(uye->name, inpname) && !strcmp(uye->password, inppassword))
			{
				
				fclose(f);
				return 1;
			}
		}
		fclose(f);
		return 0;	
	}
	else
	{
		puts("Dosya açýlamadý !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - uyeler.txt dosyasý açýlamadý.\n",z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*Üye Giriþi*/
bool login(member *uye)
{
	system("CLS");
	char *inpname = (char *)malloc(sizeof(char) * 50); char *inppassword = (char *)malloc(sizeof(char) * 50);
	struct tm *z; time_t nows; FILE *f;
	unsigned short int selection;
	do
	{
		printf("Kullanýcý Adý: ");
		fflush(stdin);
		gets(inpname);
		inpname = (char *)realloc(inpname, sizeof(char) * (strlen(inpname) + 1));
		fflush(stdin);
		printf("Þifre: ");
		gets(inppassword);
		inppassword = (char *)realloc(inppassword, sizeof(char) * (strlen(inppassword) + 1));
		if(checkLogin(inpname, inppassword, uye))
			selection = 2;
		else
		{
			do
			{
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - name: %s, password: %s ile yanlýþ kullanýcý giriþ denemesi yapýldý.\n", 
				z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, inpname, inppassword);
				fclose(f);
				printf("Kullanýcý adý veya þifre yanlýþ !\nTekrar Dene[1]\nGeri[2]\nSeçim: ");
				selection = getch() - '0';
				switch(selection)
				{
					case 1:
						puts("Tekrar Dene\n");
						free(inpname);
						free(inppassword);
						inpname = (char *)malloc(sizeof(char) * 50); 
						inppassword = (char *)malloc(sizeof(char) * 50);
						break;
					case 2:
						puts("Geri\n");
						free(inpname);
						free(inppassword);
						return 0;
						break;
					default:
						puts("Yanlýþ seçim !\n");
						break;
				}
			}while(selection != 1 && selection != 2);
		}
	}while(selection != 2);
	free(inpname);
	free(inppassword);
	return 1;
}

/*Giriþ Yapýlan Üye Ýçin Kullanýlan Struct Verilerini Optimize Etme*/
void optimization(member *uye)
{
	uye->name = (char *)realloc(uye->name, sizeof(char) * (strlen(uye->name) + 1));
	uye->password = (char *)realloc(uye->password, sizeof(char) * (strlen(uye->password) + 1));
	uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * (strlen(uye->special_code) + 1));
}

/*Yeni Admin Ekleme*/
bool insertAdmin()
{
	FILE *f = fopen("uyeler.txt", "a+");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		member yeni;
		char *temp = (char *)malloc(sizeof(char) * 50);
		yeni.name = (char *)malloc(sizeof(char) * 50);
		yeni.password = (char *)malloc(sizeof(char) * 50);
		yeni.special_code = (char *)malloc(sizeof(char) * 50);
		printf("Kullanýcý Adý: ");
		fflush(stdin);
		gets(yeni.name);
		yeni.name = (char *)realloc(yeni.name, sizeof(char) * (strlen(yeni.name) + 1));
		fclose(f);
		f = fopen("uyeler.txt", "r");
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s %s %d", &(yeni.primary_key), &(yeni.yetki), temp, yeni.password, yeni.special_code, &(yeni.fund));
			if(!strcmp(temp, yeni.name))
			{
				fclose(f);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s admin zaten var olduðundan dolayý ekleme baþarýsýz oldu.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900,
				z->tm_hour, z->tm_min, z->tm_sec, yeni.name);
				fclose(f);
				free(yeni.name);
				free(yeni.password);
				free(yeni.special_code);
				free(temp);
				puts("Eklenmek istenen admin zaten var !");
				return 0;
			}
		}
		fclose(f);
		f = fopen("uyeler.txt", "a+");
		printf("Þifre: ");
		fflush(stdin);
		gets(yeni.password);
		yeni.password = (char *)realloc(yeni.password, sizeof(char) * (strlen(yeni.password) + 1));
		printf("Özel Kod: ");
		fflush(stdin);
		gets(yeni.special_code);
		yeni.special_code = (char *)realloc(yeni.special_code, sizeof(char) * (strlen(yeni.special_code) + 1));
		yeni.fund = 0;
		yeni.primary_key = n;
		yeni.yetki = admin;
		setkey();
		fprintf(f, "%u %d %s %s %s %d\n", yeni.primary_key, yeni.yetki, yeni.name, yeni.password, yeni.special_code, (int)yeni.fund);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s yeni admin eklendi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, yeni.name);
		fclose(f);
		free(yeni.name);
		free(yeni.password);
		free(yeni.special_code);
		free(temp);
		return 1;
	}
	else
	{
		puts("Dosya açýlamadý !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - uyeler.txt dosyasý açýlamadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*Yeni Ürün Ekleme*/
bool insertProduct()
{
	FILE *f = fopen("stok.txt", "a+");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		stock yeni;
		char * temp = (char *)malloc(sizeof(char) * 50);
		yeni.product_name = (char *)malloc(sizeof(char) * 50);
		printf("Ürün Ýsmi: ");
		fflush(stdin);
		gets(yeni.product_name);
		fclose(f);
		f = fopen("stok.txt", "r");
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(yeni.primary_key), temp, &(yeni.unit), &(yeni.price));
			if(!strcmp(temp, yeni.product_name))
			{
				fclose(f);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s ürünü zaten var olduðundan dolayý ekleme baþarýsýz oldu.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900,
				z->tm_hour, z->tm_min, z->tm_sec, yeni.product_name);
				fclose(f);
				free(yeni.product_name);
				free(temp);
				puts("Eklenmek istenen ürün zaten var !");
				return 0;
			}
		}
		fclose(f);
		f = fopen("stok.txt", "a+");
		yeni.primary_key = urun_id;
		seturun_id();
		printf("Adet - Kilo: ");
		scanf("%u", &(yeni.unit));
		printf("Fiyat: ");
		scanf("%lf", &(yeni.price));
		fprintf(f, "%u %s %u %lf\n", yeni.primary_key, yeni.product_name, yeni.unit, yeni.price);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s ürünü stoða eklendi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, yeni.product_name);
		fclose(f);
		free(yeni.product_name);
		return 1;
	}
	else
	{
		puts("Dosya açýlamadý \n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - stok.txt dosyasý açýlamadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*Var Olan Ürünün Stokuna Veri Ekleme*/
bool insertUnit()
{
	FILE *f = fopen("stok.txt", "r+");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		stock tmp;
		char *src = (char *)malloc(sizeof(char) * 50);
		char *filedata = (char *)malloc(sizeof(char) * 50);
		tmp.product_name = (char *)malloc(sizeof(char) * 50);
		char *tmpdata = (char *)malloc(sizeof(char) * 50);
		printf("Aranan Ürün Ýsmi: ");
		fflush(stdin);
		gets(src);
		src = (char *)realloc(src, sizeof(char) * (strlen(src) + 1));
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(tmp.primary_key), filedata, &(tmp.unit), &(tmp.price));
			if(!strcmp(filedata, src))
			{
				short int newunit;
				printf("Eklenecek Adet - Kilo: ");
				scanf("%d", &newunit);
				fclose(f);
				FILE *temp = fopen("temp.txt", "w");
				f = fopen("stok.txt", "r");
				strcpy(tmpdata, " ");
				while(!feof(f))
				{
					fscanf(f, "%u %s %u %lf", &(tmp.primary_key), tmp.product_name, &(tmp.unit), &(tmp.price));
					if(strcmp(tmpdata, tmp.product_name) != 0) /*Aþaðýda tmpdata ya son veri eklendikten sonra yine scanf den gelen veri aynýysa hiç bir iþlem yapýlmýyor.*/
					{
						if(!strcmp(tmp.product_name, src))
						{
							if(tmp.unit + newunit < 0) /*Stok -1 e düþmesi engelleniyor.*/
								tmp.unit = 0;
							else
								tmp.unit += newunit;
						}
						fprintf(temp, "%u %s %u %lf\n", (tmp.primary_key), tmp.product_name, (tmp.unit), (tmp.price));
					}
					strcpy(tmpdata, tmp.product_name); /*Son veri iki kez okunur bunu engellemek amacýyla kullanmak için tmpdata ya son okunanýn verisini atyýyoruz.*/
				}
				fclose(temp);
				fclose(f);
				strcpy(tmpdata, " ");
				temp = fopen("temp.txt", "r");
				f = fopen("stok.txt", "w");
				while(!feof(temp))
				{
					fscanf(temp, "%u %s %u %lf", &(tmp.primary_key), tmp.product_name, &(tmp.unit), &(tmp.price));
					if(strcmp(tmp.product_name, tmpdata) != 0)
						fprintf(f, "%u %s %u %lf\n", (tmp.primary_key), tmp.product_name, (tmp.unit), (tmp.price));
					strcpy(tmpdata, tmp.product_name);
				}
				fclose(temp);
				fclose(f);
				remove("temp.txt");
				free(tmp.product_name);
				free(filedata);
				free(tmpdata);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s ürününe %d kilo - adet eklendi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src, newunit);
				fclose(f);
				free(src);
				return 1;
			}
		}
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s ürünü bulunamadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
		fclose(f);
		free(src);
		return 0;	
	}
	else
	{
		puts("Dosya açýlmadý !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - stok.txt dosyasý açýlamadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

bool listandbuy(member *uye)
{
	FILE *f = fopen("stok.txt", "r");
	struct tm *z; time_t nows;
	if(f != NULL)
	{
		stock stok;
		unsigned short int wantunit;
		double total;
		char *tempdata = (char *)malloc(sizeof(char) * 50);
		char *want = (char *)malloc(sizeof(char) * 50);
		stok.product_name = (char *)malloc(sizeof(char) * 50);
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
			if(strcmp(stok.product_name, tempdata))
				printf("%u %s %u %lf\n", stok.primary_key, stok.product_name, stok.unit, stok.price);
			strcpy(tempdata, stok.product_name);
		}
		printf("Alýnacak ürün: ");
		fflush(stdin);
		gets(want);
		want = (char *)realloc(want, sizeof(char) * (strlen(want) + 1));
		fseek(f, 0, SEEK_SET); /*Cursor dosya baþýna konumlandýrýlýyor.*/
		while(!feof(f))
		{
			fscanf(f, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
			if(!strcmp(want, stok.product_name))
			{
				printf("Miktar: ");
				scanf("%d", &wantunit);
				total =	(double)(wantunit * stok.price);
				if(total <= uye->fund && stok.unit >= wantunit)
				{
					FILE *temp = fopen("temp.txt", "w");
					FILE *temp2 = fopen("uyeler.txt", "r");
					member tempuser;
					tempuser.name = (char *)malloc(sizeof(char) * 50);
					tempuser.password = (char *)malloc(sizeof(char) * 50);
					tempuser.special_code = (char *)malloc(sizeof(char) * 50);
					uye->fund -= total;
					while(!feof(temp2))
					{
						fscanf(temp2, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
						fscanf(temp2, "%s %lf", tempuser.special_code, &(tempuser.fund));
						if(strcmp(tempdata, tempuser.name))
						{
							if(!strcmp(uye->name, tempuser.name))
								tempuser.fund = uye->fund;
							fprintf(temp, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
						}
						strcpy(tempdata, tempuser.name);
						
					}
					fclose(temp);
					fclose(temp2);
					temp = fopen("temp.txt", "r");
					temp2 = fopen("uyeler.txt", "w");
					while(!feof(temp))
					{
						fscanf(temp, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
						fscanf(temp, "%s %lf", tempuser.special_code, &(tempuser.fund));
						if(strcmp(tempdata, tempuser.name))
							fprintf(temp2, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
						strcpy(tempdata, tempuser.name);
					}
					fclose(temp);
					fclose(temp2);
					free(tempuser.name);
					free(tempuser.password);
					free(tempuser.special_code);
					fseek(f, 0, SEEK_SET);
					temp = fopen("temp.txt", "w");
					while(!feof(f))
					{
						fscanf(f, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
						if(strcmp(stok.product_name, tempdata))
							fprintf(temp, "%u %s %u %lf\n", stok.primary_key, stok.product_name, stok.unit, stok.price);
						strcpy(tempdata, stok.product_name);
					}
					fclose(f);
					fclose(temp);
					f = fopen("stok.txt", "w");
					temp = fopen("temp.txt", "r");
					while(!feof(temp))
					{
						fscanf(temp, "%u %s %u %lf", &(stok.primary_key), (stok.product_name), &(stok.unit), &(stok.price));
						if(strcmp(stok.product_name, tempdata))
						{
							if(!strcmp(stok.product_name, want))
								stok.unit -= wantunit;
							fprintf(f, "%u %s %u %lf\n", stok.primary_key, stok.product_name, stok.unit, stok.price);
						}
						strcpy(tempdata, stok.product_name);
					}
					fclose(f);
					fclose(temp);
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s ürünü %u adet %lf TL'ye satýn alýndý.\n", z->tm_mday, z->tm_mon + 1,
					z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, want, wantunit, total);
					fclose(f);
					free(want);
					free(tempdata);
					free(stok.product_name);
					remove("temp.txt");
					return 1;
				}
				else if(wantunit > stok.unit)
				{
					puts("Stok yetersiz !\n");
					fclose(f);
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s ürünü %u stok yetersiz olduðundan %lf * %u satýn alýmý baþarýsýz.\n", z->tm_mday, z->tm_mon + 1,
					z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, want, stok.unit,  stok.price, wantunit);
					fclose(f);
					free(want);
					free(tempdata);
					free(stok.product_name);
					return 0;
				}
				else
				{
					puts("Bakiye yetersiz !\n");
					fclose(f);
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s üye bakiyesi %lf yetersiz olduðundan %s ürünü %lf * %u satýn alýmý baþarýsýz.\n", z->tm_mday, z->tm_mon + 1,
					z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name, uye->fund, want, stok.price, wantunit);
					fclose(f);
					free(tempdata);
					free(want);
					free(stok.product_name);
					return 0;
				}
			}
		}
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s ürünü bulunamadý.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, want);
		fclose(f);
		free(want);
		free(tempdata);
		free(stok.product_name);
		return 0;
	}
	else
	{
		puts("Dosya açýlmadý !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - stok.txt dosyasý açýlamadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
	}
}

bool insertfund(member *uye)
{
	int cardno[4]; int a; int b; double addmoney;
	struct tm *z; time_t nows; FILE *f;
	printf("Kredi kart numarasý: ");
	scanf("%d %d %d %d", &cardno[0], &cardno[1], &cardno[2], &cardno[3]);
	a = ((cardno[0]) - (cardno[0] % 1000)) / 1000;
	b = ((cardno[0] % 1000) - (cardno[0] % 100)) / 100;
	if((cardno[3] % 10) == ((a + b) % 10) && (cardno[3] % 10) % 2 == 0)
	{
		printf("Eklenecek bakiye: ");
		scanf("%lf", &addmoney);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %d %d %d %d - Kart numarasý doðru girildi.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, cardno[0], cardno[1], cardno[2], cardno[3]);
		fclose(f);
		FILE *temp = fopen("temp.txt", "w");
		f = fopen("uyeler.txt", "r");
		char *tempdata = (char *)malloc(sizeof(char) * 50);
		member tempuser;
		tempuser.name = (char *)malloc(sizeof(char) * 50);
		tempuser.password = (char *)malloc(sizeof(char) * 50);
		tempuser.special_code = (char *)malloc(sizeof(char) * 50);
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
			fscanf(f, "%s %lf", tempuser.special_code, &(tempuser.fund));
			if(strcmp(tempdata, tempuser.name))
			{
				if(!strcmp(uye->name, tempuser.name))
				{
					uye->fund += addmoney;
					tempuser.fund = uye->fund;
				}
				fprintf(temp, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
			}
			strcpy(tempdata, tempuser.name);					
		}
		fclose(temp);
		fclose(f);
		temp = fopen("temp.txt", "r");
		f = fopen("uyeler.txt", "w");
		while(!feof(temp))
		{
			fscanf(temp, "%u %d %s %s", &(tempuser.primary_key), &(tempuser.yetki), tempuser.name, tempuser.password);
			fscanf(temp, "%s %lf", tempuser.special_code, &(tempuser.fund));
			if(strcmp(tempdata, tempuser.name))
				fprintf(f, "%u %d %s %s %s %lf\n", tempuser.primary_key, tempuser.yetki, tempuser.name, tempuser.password, tempuser.special_code, tempuser.fund);
			strcpy(tempdata, tempuser.name);
		}
		fclose(temp);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullanýcýsýna %lf bakiye yüklendi.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name, addmoney);
		fclose(f);
		remove("temp.txt");
		free(tempuser.name);
		free(tempuser.password);
		free(tempuser.special_code);
		free(tempdata);
	}
	else
	{
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - Kart numarasý doðru olmadýðý için bakiye yüklenmedi.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

/*Login Ýþlemleri*/
void adminLogin()
{
	unsigned short int selection;
	do
	{
		printf("Yönetici Ekle[1]\nÜrün Ekle[2]\nStok Ekle[3]\nGeri[4]\nSeçim: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 1:
				puts("Yönetici Ekle");
				if(insertAdmin())
					puts("Admin Baþarý Ýle Eklendi !\n");
				else
					puts("Admin Ekleme Ýþlemi Baþarýsýz !\n");
				break;
			case 2:
				puts("Ürün Ekle");
				if(insertProduct())
					puts("Ürün Baþarý Ýle Eklendi !\n");
				else
					puts("Ürün Ekleme Ýþlemi Baþarýsýz !\n");
				break;
			case 3:
				puts("Stok Ekle");
				if(insertUnit())
					puts("Stok Baþarý Ýle Eklendi !\n");
				else
					puts("Stok Ekleme Ýþlemi Baþarýsýz !\n");
				break;
			case 4:
				puts("Geri\n");
				break;
			default:
				puts("Yanlýþ seçim !\n");
				break;
		}
	}while(selection != 4);
}

/*Login Ýþlemleri*/
void normalLogin(member *uye)
{
	unsigned short int selection;
	do
	{
		printf("Alýþveriþ Yap[1]\nBakiye Göster[2]\nGeri[3]\nSeçim: ");
		selection = getch() - '0';
		switch(selection)
		{
			case 1:
				puts("Alýþveriþ Yap");
				if(listandbuy(uye))
					puts("Satýn alým baþarýlý !\n");
				else
					puts("Satýn alým baþarýsýz !\n");
				break;
			case 2:
				puts("Bakiye Göster");
				printf("Mevcut bakiye: %lf\n", uye->fund);
				do
				{
					printf("Bakiye Yükle[1]\nGeri[2]\nSeçim: ");
					selection = getch() - '0';
					switch(selection)
					{
						case 1:
							puts("Bakiye Yükle");
							if(insertfund(uye))
								puts("Bakiye yükleme iþlemi baþarýlý !\n");
							else
								puts("Bakiye yükleme iþlemi baþarýsýz !\n");
							break;
						case 2:
							puts("Geri");
							break;
						default:
							puts("Yanlýþ seçim !\n");
							break;
					}
				}while(selection != 2);
				break;
			case 3:
				puts("Geri");
				break;
			default:
				puts("Seçim yanlýþ !\n");
				break;
		}
	}while(selection != 3);
}

/*Üye Olma*/
bool signup(member *uye)
{
	FILE *f = fopen("uyeler.txt", "a+"); struct tm *z; time_t nows;
	if(f != NULL)
	{
		member yeni;
		yeni.name = (char *)malloc(sizeof(char) * 50);
		yeni.password = (char *)malloc(sizeof(char) * 50);
		yeni.special_code = (char *)malloc(sizeof(char) * 50);
		printf("Kullanýcý adý: ");
		fflush(stdin);
		gets(uye->name);
		uye->name = (char *)realloc(uye->name, (strlen(uye->name) + 1));
		fclose(f);
		f = fopen("uyeler.txt", "r");
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(yeni.primary_key), &(yeni.yetki), yeni.name, yeni.password);
			fscanf(f, "%s %lf", yeni.special_code, &(yeni.fund));
			if(!strcmp(yeni.name, uye->name))
			{
				puts("Kullanýcý adý kullanýlýyor !\n");
				fclose(f);
				time(&nows);
				z = localtime(&nows);
				f = fopen("log.txt", "a+");
				fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullanýcý adý zaten kullanýlýyor.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
				fclose(f);
				free(yeni.name);
				free(yeni.password);
				free(yeni.special_code);
				return 0;
			}
		}
		free(yeni.name);
		free(yeni.password);
		free(yeni.special_code);
		fclose(f);
		f = fopen("uyeler.txt", "a+");
		printf("Þifre: ");
		fflush(stdin);
		gets(uye->password);
		printf("Özel kod: ");
		gets(uye->special_code);
		uye->fund = 0;
		uye->yetki = normal;
		uye->primary_key = n;
		setkey();
		fprintf(f, "%u %d %s %s %s %lf\n", uye->primary_key, uye->yetki, uye->name, uye->password, uye->special_code, uye->fund);
		fclose(f);
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullanýcý adý ile üye olundu.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
		fclose(f);
		return 1;
	}
	else
	{
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - Dosya açýlmadý.\n", z->tm_mday, z->tm_mon + 1,
		z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
		fclose(f);
		return 0;
	}
}

bool changepassword(member *uye)
{
	struct tm *z; time_t nows; FILE *f;
	char *src = (char *)malloc(sizeof(char) * 50);
	printf("Kullanýcý Adý: ");
	fflush(stdin);
	gets(src);
	src = (char *)realloc(src, sizeof(char) * (strlen(src) + 1));
	time(&nows);
	z = localtime(&nows);
	f = fopen("log.txt", "a+");
	fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullanýcý adý için þifre sýfýrlama talebi alýndý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
	fclose(f);
	f = fopen("uyeler.txt", "r");
	if(f != NULL)
	{
		while(!feof(f))
		{
			fscanf(f, "%u %d %s %s", &(uye->primary_key), &(uye->yetki), uye->name, uye->password);
			fscanf(f, "%s %lf", uye->special_code, &(uye->fund));
			if(!strcmp(src, uye->name))
			{
				char *inpsc = (char *)malloc(sizeof(char) * 50);
				printf("Özel Kod: ");
				fflush(stdin);
				gets(inpsc);
				inpsc = (char *)realloc(inpsc, sizeof(char) * (strlen(inpsc) + 1));
				if(!strcmp(inpsc, uye->special_code))
				{
					char *tempdata = (char *)malloc(sizeof(char) * 50);
					char *newpassword = (char *)malloc(sizeof(char) * 50);
					member yeni;
					yeni.name = (char *)malloc(sizeof(char) * 50);
					yeni.password = (char *)malloc(sizeof(char) * 50);
					yeni.special_code = (char *)malloc(sizeof(char) * 50);
					fseek(f, 0, SEEK_SET);
					FILE *temp = fopen("temp.txt", "w");
					while(!feof(f))
					{
						fscanf(f, "%u %d %s %s", &(yeni.primary_key), &(yeni.yetki), yeni.name, yeni.password);
						fscanf(f, "%s %lf", yeni.special_code, &(yeni.fund));
						if(strcmp(tempdata, yeni.name))
						{
							if(!strcmp(yeni.name, uye->name))
							{
								printf("Yeni Þifre: ");
								fflush(stdin);
								gets(newpassword);
								strcpy(yeni.password, newpassword);
							}
							fprintf(temp, "%u %d %s %s %s %lf\n", yeni.primary_key, yeni.yetki, yeni.name, yeni.password, yeni.special_code, yeni.fund);
						}
						strcpy(tempdata, yeni.name);
					}
					fclose(f);
					fclose(temp);
					f = fopen("uyeler.txt", "w");
					temp = fopen("temp.txt", "r");
					while(!feof(temp))
					{
						fscanf(temp, "%u %d %s %s", &(yeni.primary_key), &(yeni.yetki), yeni.name, yeni.password);
						fscanf(temp, "%s %lf", yeni.special_code, &(yeni.fund));
						if(strcmp(tempdata, yeni.name))
							fprintf(f, "%u %d %s %s %s %lf\n", yeni.primary_key, yeni.yetki, yeni.name, yeni.password, yeni.special_code, yeni.fund);
						strcpy(tempdata, yeni.name);
					}
					fclose(f);
					fclose(temp);
					remove("temp.txt");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullanýcý adý için þifre %s olarak deðiþtirildi.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min,
					z->tm_sec, src, newpassword);
					strcpy(uye->password, newpassword);
					fclose(f);
					free(tempdata);
					free(src);
					free(inpsc);
					free(yeni.name);
					free(yeni.password);
					free(yeni.special_code);
					free(newpassword);
					return 1;
				}
				else
				{
					puts("Özel kod yanlýþ !\n");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullanýcý adý için %s özel kod doðru deðil kayýtlý deðil.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour,
					z->tm_min, z->tm_sec, src, inpsc);
					fclose(f);
					free(src);
					free(inpsc);
					return 0;
				}
			}
		}
		puts("Kullanýcý adý kayýtlý deðil !\n");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s kullanýcý adý kayýtlý deðil.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
		fclose(f);
		free(src);
		return 0;
	}
	else
	{
		puts("Dosya açýlmadý !");
		time(&nows);
		z = localtime(&nows);
		f = fopen("log.txt", "a+");
		fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Dosya açýlmadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, src);
		free(src);
		fclose(f);
		return 0;
	}
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	printf("\t\t\t\t\tBU PROGRAM %s - %s TARÝH VE SAATÝNDE DERLENDÝ.\n\n", __DATE__, __TIME__);
	unsigned short int selection;
	struct tm *z; time_t nows;
	FILE *f = fopen("key.txt", "r");
	fscanf(f, "%d", &n);
	fclose(f);
	f = fopen("urun_id.txt", "r");
	fscanf(f, "%d", &urun_id);
	fclose(f);
	member *uye = (member *)malloc(sizeof(member));
	uye->name = (char *)malloc(sizeof(char) * 50);
	uye->password = (char *)malloc(sizeof(char) * 50);
	uye->special_code = (char *)malloc(sizeof(char) * 50);
	do
	{
		printf("Üye Giriþi[1]\nÜye Ol[2]\nParolamý Unuttum[3]\nÇýkýþ[4]\nSeçim: ");
		selection = getch() - '0'; /*getch - getchar*/
		switch(selection)
		{
			case 1:
				puts("Üye Giriþi");
				if(login(uye))
				{
					puts("Giriþ baþarýlý !\n");
					if(uye->yetki == admin)
					{
						puts("\tADMÝN");
						optimization(uye);
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Admin kullanýcý giriþ yaptý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						adminLogin();
						system("CLS");
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Admin kullanýcý çýkýþ yaptý.\n",  z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
						uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
						uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
						uye = (member *)realloc(uye, sizeof(member));
					}
					else
					{
						puts("\tÜYE");
						optimization(uye);
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Normal kullanýcý giriþ yaptý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						normalLogin(uye);
						system("CLS");
						time(&nows);
						z = localtime(&nows);
						f = fopen("log.txt", "a+");
						fprintf(f, "[%d.%d.%d %d:%d:%d] - %s Normal kullanýcý çýkýþ yaptý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec, uye->name);
						fclose(f);
						uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
						uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
						uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
						uye = (member *)realloc(uye, sizeof(member));
					}
				}
				else
				{
					uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
					uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
					uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
					uye = (member *)realloc(uye, sizeof(member));
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - üye giriþi yapýlmadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
					fclose(f);
					puts("Giriþ yapýlmadý !\n");
				}
				break;
			case 2:
				puts("Üye Ol");
				if(signup(uye))
					puts("Üye olundu !\n");
				else
					puts("Üye olma iþlemi baþarýsýz !\n");
				uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
				uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
				uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
				uye = (member *)realloc(uye, sizeof(member));
				break;
			case 3:
				puts("Parolamý Unuttum");
				if(changepassword(uye))
				{
					puts("Þifre sýfýrlandý !\n");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - Þifre sýfýrlandý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
					fclose(f);
				}
				else
				{
					puts("Þifre Sýfýrlanmadý !\n");
					time(&nows);
					z = localtime(&nows);
					f = fopen("log.txt", "a+");
					fprintf(f, "[%d.%d.%d %d:%d:%d] - Þifre sýfýrlanmadý.\n", z->tm_mday, z->tm_mon + 1, z->tm_year + 1900, z->tm_hour, z->tm_min, z->tm_sec);
					fclose(f);
				}
				uye->name = (char *)realloc(uye->name, sizeof(char) * 50);
				uye->password = (char *)realloc(uye->password, sizeof(char) * 50);
				uye->special_code = (char *)realloc(uye->special_code, sizeof(char) * 50);
				uye = (member *)realloc(uye, sizeof(member));
					
				break;
			case 4:
				puts("Çýkýþ");
				free(uye->name);
				free(uye->password);
				free(uye->special_code);
				free(uye);
				break;
			default:
				puts("Seçim yanlýþ !\n");
				break;
		}
	}while(selection != 4);
}
