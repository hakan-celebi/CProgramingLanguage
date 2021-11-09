#include <stdio.h>
#include <stdlib.h> /*Malloc kullanabilmek için ekledim.*/
#include <locale.h> /*konum belirterek konsol ekranýnda Türkçe karakterlerin var olabilmesi için.*/

typedef struct /*n isminde bir struct oluþturduk*/
{
    int data;
    struct n * next; /*n struct'ý tipinde bir next pointer'ý oluþturdum.*/
}n;
/*typedef struct n node; /*node düðüm anlamýna gelir n structýný gösteren tip isimlendirdim.*/

int main()
{
    setlocale(LC_ALL, "Turkish");
    n * root = (n *)malloc(sizeof(n));
    /*
    node tipinde yaný n struct'ý tipinde bir kök yani root pointer'ý oluþturup yer ayýrdýk. root pointer'ý
	bizim basit baðlý listemiszin ilk elemanýný gösterecek. (node *)malloc(); þeklinde tanýmladýk çünkü malloc
	geriye void tipinde bir deðer dönderir. Bizim node tipinde döndermesini istiyoruz ve n struct'ý kadar yer
	ayýrdýk.
    */
    n * iter;
    iter = root;
    /*
    iter -> iterator þeklinde bir node tipinde pointer oluþturduk çünkü bu pointer bizim basit baðlý
	listemizde serbeste gezinmesini ve bizim iþimizi kolaylaþtýrmasýný istiyoruz root -> next -> next -> ...
	þeklinde uzatmak yerine
    iter -> data = 5;
    iter = iter -> next; Þeklinde bir adým ilerleme yapabiliyoruz*/
    /*Þimdi 10 kutuluk baðlý liste oluþturacaðýz ve bu 10 kutuluk baðlý listemize 1 - 10'a kadar olan sayýlarý
    atýp yazdýracaðýz.*/
    int i;
    for(i = 0; i < 10; i++)/*Bu for döngüsünde yer ayýrmasý yapýyoruz.*/
    {
        iter = (n *)iter -> next;
        iter = (n *)malloc(sizeof(n));
    }
    iter = (n *)root; /*iter son kutuya kadar ilerlemiþti tekrar ilk kutuya aldýk.*/
    for(i = 1; i <= 10; i++)/*Burada deðer atamasýný yaptýk.*/
    {
    	sleep(1);
    	printf("%d ", i);
        iter -> data = i;  
        iter = (n *)iter -> next;
        printf("- ");
    }
    iter = (n *)root;
    for(i = 0; i < 10; i++)
    {
        printf("\n%d.Kutu = %d", i + 1, iter -> data);
        iter = (n *)iter -> next;
    }
    free(iter);
    free (root);
    return 0;
}
