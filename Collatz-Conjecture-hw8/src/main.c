#include<stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char const *argv[])
{	
	int xs,seqlen,*h,digit;
    int *loop,looplen;
    
    printf("\n");
	printf("Please enter the sequence length: ");
	scanf("%d",&seqlen);

	printf("Please enter the first element: ");
	scanf("%d",&xs);
    
    looplen=seqlen/2;
    
    //Arraylerimize callocla yer ayırıyoruz.

    h=(int *)calloc(9, sizeof(int));
    loop =(int *)calloc(seqlen, sizeof(int));

    digit=xs; //İlk elemanımızı digite atıyoruz.

    check_loop_iterative(generate_sequence,xs,seqlen,loop,&looplen); //Fonksiyonu çağırıyoruz.
    
    if(looplen<2) //Loop yoksa.
    {
        printf("No loop found\n\n");
    } 

    else //Bu blokta eğer loop varsa bastırıyoruz.
    {
        printf("Loop: {");

        for(int i =0;i<looplen;i++)
        {                    
            if(i==looplen-1)
            {
                printf("%d}\n\n",loop[i]);       
            }

            else
            {
                printf("%d, ",loop[i]);
            } 
        }
    }  

    hist_of_firstdigits((* generate_sequence),xs,seqlen,h,digit); //Histogram fonksiyonunu çağırıyoruz.
    
    printf("\n");
    
    printf("Histogram of sequence: {");

    for (int i = 0; i < 9; ++i) //Bulunan histogramı bastırıyoruz.
    {
        if (i==8)
        {
            printf("%d}",h[i]);
        }

        else
        {
            printf("%d, ",h[i]);
        }  
    }
    printf("\n");
    
	return 0;
}