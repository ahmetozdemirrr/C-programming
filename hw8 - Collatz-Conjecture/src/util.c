#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void generate_sequence(int xs, int currentlen, int seqlen, int *seq)
{
    if (currentlen!=seqlen)
    {
        if (currentlen==1)
        {
            *seq=xs; //İlk elemanı eşitliyoruz.
        }

        if (seq[currentlen-1]%2==0) //Eğer çift sayıysa bu işlemi yapıyoruz.
        {
            seq[currentlen]=seq[currentlen-1]/2;
        }

        if (seq[currentlen-1]%2!=0) //Tek sayıysa bu işlemi yapıyoruz.
        {
            seq[currentlen]=3*seq[currentlen-1]+1;
        }

        generate_sequence(xs,currentlen+1,seqlen,seq); //Fonksiyonu recursive olarak çağırıyoruz.
    }
}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    int flag=0; 

    for (int i = 1; i <= looplen; i++)
    {
        *le = n-i; //Son indeksi ona karşılık gelen ilk indeksle karşılaştırmak için ayarlıyoruz.
        *ls = n-looplen-i; //İlk indeksi ona karşılık gelen sondaki indeksle karşılaştırmak için ayarlıyoruz. 
        
        if(arr[*le]!=arr[*ls]) //Elemanlar eşit değilse buraya girsin.
        {  
            flag++;
            break;
        }
    }

    if(flag==0)
    {
        return 1; //Loop varsa 1 döndürüyoruz.
    }  

    else
    {
        return 0; //Loop yoksa 0 döndürüyoruz.
    } 
}

void check_loop_iterative(void (*f)(int xs, int currentlen, int seqlen, int *seq), int xs, int seqlen, int *loop, int *looplen)
{ 
    int *seq,ls,le;

    seq = (int*)calloc(seqlen,sizeof(int)); //Seq arrayine mallocla yer ayırıyoruz.

    static int number=0; //Diziyi yazdırmak için kullanacağımız değişken.
    
    if(number==0) //Diziyi yazdırmak için aldığımız açtığımız for.
    {
        generate_sequence(xs,0,seqlen,seq);

        printf("\nSequence: {"); 

        for (int i = 0; i < seqlen-1; i++)
        {
            printf("%d, ",seq[i]);   
        }    
        printf("%d}\n",seq[seqlen-1]);

        printf("\n");
        number++;
    }

    generate_sequence(xs,0,seqlen,seq);

    if(has_loop(seq,seqlen,*looplen,&ls,&le)==1) //Eğer loop varsa bu bloğa giriliyor.
    {
        printf("Checking if there is a loop of length of %d.\n",*looplen);
        printf("\nLoop detected with a length of %d.\n",*looplen);
        printf("The indexes of loop's first occurance: %d (first digit) , %d (last digit)\n",ls,le-1);
        
        for(int i =ls ; i<le ; i++)
        {
            loop[i-ls]=seq[i]; //Loop olarak bulduğumuz dizinin elemanlarını loop arrayina atıyoruz.
        }    
    }

    else if(has_loop(seq,seqlen,*looplen,&ls,&le)==0 && *looplen>=2) //Bulunan uzunlukta loop yoksa uzunluk azaltılıp bir sonraki uzunlukta döngü aranıyor.
    {
        printf("Checking if there is a loop of length of %d...\n",*looplen);
        *looplen-=1;
        check_loop_iterative(generate_sequence,xs,seqlen,loop,looplen);
    }
}

void hist_of_firstdigits(void (*f)(int xs, int currentlen, int seqlen, int *seq), int xs, int seqlen, int *h, int digit)
{
	int *seq;
	int currentlen=1;
    
    if (digit>=10) //Sayıyı 10'a yeterince bölüp(recursive yardımıyla) sayının ilk basamağını bırakıyoruz.
    {
        digit=digit/10;
    }

    if (digit<10) //Sayının ilk elemanı bulunduğu zaman bu bloğa girilir.
    {
        *(h+digit-1)+=1; //Histogramın elemanlarını kaydırıyoruz.

        if (seqlen>1)
        {
        	seq=(int *)malloc(seqlen * sizeof(int)); //seq arrayine mallocla yer ayırıyoruz.

            generate_sequence(xs,currentlen,seqlen,seq);
	
          	digit=seq[seqlen-1];
          	
          	free(seq);
          	hist_of_firstdigits((* generate_sequence),xs,seqlen-1,h,digit); //Recursive için fonksiyonu tekrar çağırıyoruz.
        }        
    }
    
    else
    {
        hist_of_firstdigits((* generate_sequence),xs,seqlen,h,digit); //Recursive için fonksiyonu tekrar çağırıyoruz.
    }
}


