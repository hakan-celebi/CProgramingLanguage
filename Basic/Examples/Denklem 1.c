#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define diskriminant(a, b, c) ((b*b) - (4 * a * c))

void main()
{
	//3x^2 + 5x + 3
	setlocale(LC_ALL, "Turkish");
	char *denklem; char buf[100]; 
	int basamakDeger = 1; int i; int opt = 2; int katsayi[3] = {0, 0, 0}; int dis;
	printf("Denklem girin: ");
	gets(buf);
	denklem = (char *)malloc(sizeof(char) * strlen(buf));
	strcpy(denklem, buf);
	strcpy(buf, " ");
	for(i = strlen(denklem) - 1; i >= 0; i--)
	{
		if(opt == 2)
		{
			if(*(denklem + i) == ' ' || *(denklem + i) == '+' || *(denklem + i) == '-')
			{
				if(*(denklem + i) == '-' || *(denklem + (i - 1)) == '-')
					katsayi[opt] *= -1;
				opt--;
				basamakDeger = 1;
				if(*(denklem + (i - 2)) == ' ')
					i -= 2;
				else
					i--;
			}
			else
			{
				katsayi[opt] += (int)(*(denklem + i) - '0') * (basamakDeger);
				basamakDeger *= 10;
			}
		}
		else if(opt == 1)
		{
			if(*(denklem + i) == 'x')
				i--;
			if(*(denklem + i) == ' ' || *(denklem + i) == '+' || *(denklem + i) == '-')
			{
				if(*(denklem + i) == '-' || *(denklem + (i - 1)) == '-')
					katsayi[opt] *= -1;
				opt--;
				basamakDeger = 1;
				if(*(denklem + (i - 2)) == ' ')
					i -= 2;
				else
					i--;
			}
			else
			{
				katsayi[opt] += (int)(*(denklem + i) - '0') * (basamakDeger);
				basamakDeger *= 10;
			}
		}
		else
		{
			if(i == 0)
			{
				if(*(denklem) == '-')
				{
					katsayi[opt] *= -1;
					break;
				}
				else if(*(denklem) == '+')
					break;
			}
			if(*(denklem + i) == '2' && *(denklem + (i - 1)) == '^' && *(denklem + (i - 2)) == 'x')
				i -= 3;
			katsayi[opt] += (int)(*(denklem + i) - '0') * (basamakDeger);
			basamakDeger *= 10;
		}
	}
	dis = diskriminant(katsayi[0], katsayi[1], katsayi[2]);
	printf("Bu denklemin Diskriminant'ý: %d\n", dis);
	if(dis < 0)
		puts("KARMAÞIK KÖKLER");
	else if(dis == 0)
		puts("REEL AYNI KÖKLER");
	else
		puts("REEL FARKLI KÖKLER");
	free(denklem);
}
