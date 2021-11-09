#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

void uye_ekle()
{
	FILE *uye;
	char id[10], sifre[15], kod[15], bakiye[15];
	uye = fopen("Üye_Listesi.txt","a+");
	printf("Kullanýcý Adý: ");
	scanf("%s", id);
	printf("Þifre: ");
	scanf("%s", sifre);
	printf("Özel Kod: ");
	scanf("%s", kod);
	printf("Ýlk Bakiyeniz: ");
	scanf("%s", bakiye);
	fprintf(uye,"\nid %s\n",id);
	fprintf(uye,"password %s\n",sifre);
	fprintf(uye,"special %s\n",kod);
	fprintf(uye,"money %s*",bakiye);
	puts("Üye Olma Ýþlemi Baþarýlý");
	fclose(uye);
}

void stok_ekle()
{
	FILE *stok;
	char id[10], sayi[5], obj[10], urun[15], ch;
	int i, a, k;
	fpos_t pst;
	char *src;
	int j = 0;
	stok = fopen("Stok_Listesi.txt","r+");
	rewind(stok);
	printf("Ekleme yapacaðýnýz ürün id:"); // HANGÝ ÜRÜNE EKLEME YAPMAK ÝSTÝYOR SORDUK STOKTA VARSA EKLEYECEÐÝZ, YOKSA ÝLK DEFA YAZIP VERÝLEN ADEDÝ STOÐA GEÇECEÐÝZ
	scanf("%s",id); 
    while(!feof(stok)) // Dosya sonuna kadar arama
	{			
        fgets(obj,50,stok); 
        k = strlen(obj);
        strtok(obj," ");
    	if(strcmp(id,obj) == 0) // bulunan ile girilen karþýlaþtýrýlýyor, eðer bulunduysa 0 döndürür geriye.
		{
			// Bu kýsýmda stokta var olan bir ürünün stok sayýsýna ekleme yapacaðýz.
			src = strtok((char *)NULL, " ");
			a = atoi(src);
			printf("Stokta %d kg kadar var lütfen ekleme yap!\n", a);
			printf("Eklenecek Stok: ");
			scanf("%d",&i);
			printf("%d kg kadar ekleme yapýlacak\n", i);
			fgetpos(stok,&pst);
			pst -= k+1; 
			fsetpos(stok,&pst);
			pst += (strlen(id)+2); 
			fsetpos(stok,&pst);
			fprintf(stok,"%dkg", i+a);	
			printf("Son stok durumu %s = %d kg\n", obj, i+a);	
			puts("Ekleme iþlemi Baþarýlý");
			break;
    	}
    	else if(feof(stok))
    	{
    		puts("Ürün önceden yokmuþ ilk defa oluþturulacak");
    		puts("Stokta yazýlmasý istenen þeklini giriniz !");
    		scanf("%s", id);
    		printf("\nLütfen Eklenecek Stok Giriniz: ");
    		scanf("%d", &i);
    		printf("Lütfen Kg fiyatýný giriniz: ");
    		scanf("%d", &j);
    		fprintf(stok,"\n%s %dkg %dtl", id, i, j);
    		puts("Ekleme iþlemi baþarýlý!!");
    		break;
		}
    }
	fclose(stok);
}

void stok_listele()
{
	FILE *stok;
	char miktar[10]; char urun[15]; char ucret[15];
	stok = fopen("Stok_Listesi.txt","r");
	while(!feof(stok))
	{
		fscanf(stok, "%s", urun);
		fscanf(stok, "%s", miktar);
		fscanf(stok, "%s", ucret);
		printf("%s %s %s\n", urun, miktar, ucret);
	}
	fclose(stok);
}

void parola_unuttum()
{
	FILE *uye;
	int k;
	int i = 0; int j;
	char obj[21]; char *src; char sifre[15]; char id[10]; char kod[10];
	uye = fopen("Üye_Listesi.txt","r");
	puts("Lütfen kullanýcý adýnýzý giriniz");
	scanf("%s", &id);
	while(!feof(uye))
	{
		if(fgets(obj,20,uye) != NULL)
		{
			strtok(obj," ");
        	src = strtok((char *)NULL, "\n");
        	if(strcmp(id,src) == 0)
        	{
        		printf("Merhaba %s Hoþgeldin..\nLütfen özel kodunu gir: ", src);
        		scanf("%s", &kod);
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		if(strcmp(kod,src) == 0)
        		{
        			puts("Özel Kod Doðru!!");
        			rewind(uye);
        			while(j != 1)
        			{
        				fgets(obj,20,uye);
        				strtok(obj," ");
        				src = strtok((char*)NULL, "\n");
        				if(strcmp(id,src) == 0)
        				{
        					fgets(obj,20,uye);
        					strtok(obj," ");
        					src = strtok((char*)NULL, "\n");
        					printf("Þifreniz: %s\nLütfen Unutmamaya Çalýþ!!\n\n", src);
        					j++;
						}		
					}
        			break;
				}
				else
				{
					puts("Özel Kod Uyuþmuyor Lütfen Tekrar Dene!!");
					break;
				}	
			}
		}
	} 
	fclose(uye);
}

int uye_kontrol(char id[15])
{
	FILE *uye;
	char password[15]; char obj[21]; char *src;
	uye = fopen("Üye_Listesi.txt", "r");
	while(!feof(uye))
	{
		if(fgets(obj,20,uye) != NULL)
		{
			strtok(obj," ");
        	src = strtok((char *)NULL, "\n");
        	if(strcmp("admin",id) == 0)
        	{
        		if(strcmp(id,src) == 0)
        		{
        			printf("Merhaba %s Hoþgeldin\nLütfen Þifreni Gir: ", src);
        			scanf("%s", &password);
        			fgets(obj,20,uye);
        			strtok(obj," ");
        			src = strtok((char *)NULL, "\n");
        			if(strcmp(password,src) == 0)
        			{
        				puts("Þifre Doðru Hoþgeldin Admin.. Devam Ediliyor");
        				return 2;
					}
					else
					{
						puts("Þifre Yanlýþ!!  Lütfen Tekrar Dene..");
						return 0;
					}
				}
			}
        	else if(strcmp(id,src) == 0)
        	{
        		printf("Merhaba %s Hoþgeldin\nLütfen Þifreni Gir: ", src);
        		scanf("%s", &password);
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		if(strcmp(password,src) == 0)
        		{
        			puts("Þifre Doðru Hoþgeldiniz..  Devam Ediliyor");
        			return 1;
				}
				else
				{
					puts("Þifre Yanlýþ!!\nLütfen Tekrar Dene..");
					return 0;
				}
			}
		}
	}
	puts("Böyle Bir Kullanýcý Bulunamadý!!\n");
	return 0;
	fclose(uye);	
}

void bakiye_goster(char id[15])
{
	FILE *uye;
	char obj[21]; char *src;
	int k = 0;
	uye = fopen("Üye_Listesi.txt","r");
	while(k != 1)
	{
		if(fgets(obj,20,uye) != NULL)
		{
			strtok(obj," ");
        	src = strtok((char *)NULL, "\n");
        	if(strcmp(id,src) == 0)
        	{
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		printf("Güncel Bakiye = %s\n", src);
        		k++;
			}
		}
	}
	fclose(uye);
}

void bakiye_yukle(char id[15])
{
	FILE *uye;
	char obj[21]; char *src;
	int k = 0; int ekle; int suan;
	fpos_t pst;
	uye = fopen("Üye_Listesi.txt","r+");
	printf("Eklemek Ýstediðiniz Tutarý Giriniz: ");
    scanf("%d", &ekle);
	while(k != 1)
	{
		if(fgets(obj,20,uye) != NULL)
		{
			strtok(obj," ");
        	src = strtok((char *)NULL, "\n");
        	if(strcmp(id,src) == 0)
        	{
        		fgets(obj,20,uye);
        		strtok(obj," ");                                                         
        		src = strtok((char *)NULL, "\n");
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		suan = atoi(src);
        		fgetpos(uye,&pst);
				pst -= strlen(src);
				fsetpos(uye,&pst);
				fprintf(uye,"%d", ekle + suan);	
				printf("Güncel Bakiye = %d\n", ekle + suan);	
				puts("Ekleme iþlemi Baþarýlý");
				break;
			}
		}
	}
	fclose(uye);
}

void kart_dogrula(char id[15])
{
	int kartno[16]; int i; int cifttop = 0; int tektop = 0; int ikihane = 0; int ilkhane = 0; int ikincihane = 0; int top = 0;
	printf("Kartinizin on yuzunde bulunan 16 haneli kart numaranizi girin: \n");
	for(i = 0 ; i<16 ;++i)
	{
		printf("16 Haneli Kart Numaranizin %d.hanesini girin: ", i + 1);
		scanf("%d", &kartno[i]);
	}
	for(i=0; i < 16 ;++i)
	{
		if(i % 2 == 0)
		{
			if((kartno[i] * 2) > 9)
			{
				ikihane = (kartno[i] * 2);
				ilkhane = ikihane % 10;
				ikincihane = (ikihane - ilkhane) / 10;
				top = ilkhane + ikincihane;
				cifttop += top;
			}
			else
			{
				cifttop += (kartno[i] * 2);
			}
		}
		else
			tektop += kartno[i]; 
	}
	if((cifttop + tektop) % 10 == 0)
	{
		puts("Kart numaraniz dogrudur.");
		bakiye_yukle(id);
	}
	else
	{
		puts("Kart numaraniz yanlistir.");
	}
				
}

void satinal(char id[15])
{
	FILE *uye;
	FILE *stok;
	char urun[10]; char obj[10]; char *src;
	int miktar; int k; int a = 0; int para = 0;
	fpos_t pst;
	uye = fopen("Üye_Listesi.txt","r+");
	stok = fopen("Stok_Listesi.txt","r+");
	printf("Satýn almak istediðiniz ürünü giriniz lütfen: ");
	scanf("%s", urun);
	printf("%s ürününden kaç kg almak istediðinizi giriniz: ", urun);
	scanf("%d", &miktar);
	while(k != 1)
	{
		fgets(obj,50,stok); 
        k = strlen(obj);
        strtok(obj," ");
        if(strcmp(urun,obj) == 0)
        {
        	src = strtok((char *)NULL, " ");
			a = atoi(src);
			printf("%d kg kadar satýn alýnacak\n", miktar);
			fgetpos(stok,&pst);
			pst -= strlen(src);
			fsetpos(stok,&pst);
			fprintf(stok,"%dkg", a - miktar);		
			puts("Satýn Alma iþlemi Baþarýlý");
			src = strtok((char *)NULL, "tl");
			a = atoi(src);
			a = a * miktar;
			k = 1;
			break;
		}
	}
	fclose(stok);
	while(!feof(uye))
	{
		if(fgets(obj,20,uye) != NULL)
		{
			strtok(obj," ");
        	src = strtok((char *)NULL, "\n");
        	if(strcmp(id,src) == 0)
        	{
        		fgets(obj,20,uye);
        		strtok(obj," ");                                                         
        		src = strtok((char *)NULL, "\n");
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		fgets(obj,20,uye);
        		strtok(obj," ");
        		src = strtok((char *)NULL, "\n");
        		para = atoi(src);
        		fgetpos(uye,&pst);
				pst -= strlen(src);
				fsetpos(uye,&pst);
				fprintf(uye,"%d", para - a);	
				printf("Güncel Bakiye = %d TL\n", para - a);
				break;
			}
		}
	}
	fclose(uye);	
}

void main()
{
	setlocale(LC_ALL, "Turkish");
	int secim; int control = -1; int secim_2;
	char uye[15];
	do
	{
		printf("Üye Giriþ[1]\nÜye Ol[2]\nParolamý Unuttum[3]\nÇýkýþ[4]\nSeçiminiz: ");
		scanf("%d", &secim);
		switch(secim)
		{
			case 1:
				system("CLS");
				printf("Lütfen Kullanýcý Adý Griniz: ");
				scanf("%s", uye);
				control = uye_kontrol(uye);
				if(control == 1)
				{
					do
					{
						printf("Alýþveris Yap[1]\nBakiye Göster[2]\nBakiye Yükle[3]\nOturum Kapat[4]\nSeçiminiz: ");
						scanf("%d", &secim_2);
						switch(secim_2)
						{
							case 1:
								stok_listele();
								satinal(uye);
								break;
							case 2:
								bakiye_goster(uye);
								break;
							case 3:
								kart_dogrula(uye);
								break;	
							case 4:
								puts("Oturum Kapatýlýyor!!");
								break;	
							default:
								puts("Yanlýþ Seçim");
								break;	
						}
					}while(secim_2 != 4);
				}
				else if(control == 2)
				{
					do
					{
						printf("Stok Listele[1]\nStok Ekle[2]\nOturum Kapat[3]\nSeçiminiz: ");
						scanf("%d", &secim_2);
						switch(secim_2)
						{
							case 1:
								stok_listele();
								break;
							case 2:
								stok_ekle();
								break;
							case 3:
								puts("Oturum Kapatýlýyor!!");
								break;
							default:
								puts("Yanlýþ Seçim");
								break;			
						}
					}while(secim_2 != 3);
				}
				break;
			case 2:
				uye_ekle();
				break;
			case 3:
				parola_unuttum();
				break;	
			case 4:
				puts("Çýkýþ Yapýlýyor Teþekkürler!");
				break;	
			default:
				puts("Yanlýþ Secim!!");
				break;		
		}
	}while(secim != 4);
}
