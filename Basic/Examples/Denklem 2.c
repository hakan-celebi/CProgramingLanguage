#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define disk(a, b, c) ((b * b) - (4 * a * c))

void main()
{
	setlocale(LC_ALL, "Turkish");
	char *denk; char buf[50]; char op[3] = {'+', '+', '+'}; char *src; char *temp;
	int i = 1; int opc = 1; int katsayi[3] = {0, 0, 0};
	printf("Denklem girin: ");
	gets(buf);
	denk = (char *)malloc(sizeof(char) * strlen(buf));
	strcpy(denk, buf);
	strcpy(buf, "");
	temp = denk;
	if(*denk == '-')
	{
		op[0] = '-';
		denk++;
	}
	else if(*denk == '+')
		denk++;
	printf("Denklem: %s\n", denk);
	for(i = 1; i < strlen(denk), opc < 3; i++)
	{
		if(ispunct(*(denk + i)) && *(denk + i) != '^')
			op[opc++] = *(denk + i);	
	}
	src = strtok(denk, " +-");
	if(*src == 'x')
		katsayi[0] = 1;
	else
		katsayi[0] = atoi(src);
	src = strtok((char *)NULL, " +-");
	if(*src == 'x')
		katsayi[1] = 1;
	else
		katsayi[1] = atoi(src);
	src = strtok((char *)NULL, " +-");
	katsayi[2] = atoi(src);
	for(i = 0; i < 3; i++)
	{
		if(op[i] == '-')
			katsayi[i] *= -1;
	}
	for(i = 0; i < 3; i++)
		printf("%d.Katsayý: %d\n", i + 1, katsayi[i]);
	printf("Diskriminant: %d", disk(katsayi[0], katsayi[1], katsayi[2]));
	free(temp);
}
