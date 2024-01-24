#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int dice()
{
    srand(time(NULL));

    return (1+rand()%6); 
}

int startGame(int (*dice)())
{
    printf("To start to game, players should dice and decide who is going to start first according to it...\n");
    char a,b;
    int gamer1,gamer2;

    do
    {
        printf("\033[0;32m");
        printf("Player 1... Press enter to dice\n");
        printf("\033[0m");
        scanf("%c",&a);
        gamer1=dice();
        printf("\033[0;32m");
        printf("DICE: %d\n",gamer1);
        printf("\033[0m");
        
        printf("\033[0;34m");
        printf("Player 2... Press enter to dice\n");
        printf("\033[0m");
        scanf("%c",&b);
        gamer2=dice();
        printf("\033[0;34m");
        printf("DICE: %d\n\n",gamer2);
        printf("\033[0m");

        if (gamer1>gamer2)
        {
            printf("\033[0;34m");
            printf("***Player 1 will start the game***\n");
            printf("\033[0m");
            return 1;
        }

        else if(gamer2>gamer1)
        {
            printf("\033[0;34m");
            printf("***Player 2 will start the game***\n");
            printf("\033[0m");  
            return 0;
        }

        if (gamer1==gamer2)
        {
            printf("\033[0;36m");
            printf("Same Dice Value...Try Again\n");
            printf("\033[0m");
        }
    }
    while(gamer1==gamer2);
}

int printMap(int array[][30],int row,int column)
{
    for (int i = 0; i < row; ++i)
    {
    	for (int j = 0; j < column; ++j)
    	{
            if (array[i][j]=='x')
            {
                printf("\033[0;31m");
                printf("X");
                printf("\033[0m");
            }

    		else if ((i==0 || i==14) || ((i==2 || i==12) && (j>1 && j<28)) || ((i==4 || i==10) && (j>3 && j<26)))
    		{
    			printf(".");
    		}

    		else if ((j==0 || j==29) || ((j==2 || j==27) && (i>1 && i<13)) || ((j==4 || j==25) && (i>3 && i<11)))
    		{
    			printf(":");
    		}
            
            else if (array[i][j]=='a')
            {
                printf("\033[0;33m");
                printf("1");
                printf("\033[0m");
            }

            else if (array[i][j]=='b')
            {
                printf("\033[0;34m");
                printf("2");
                printf("\033[0m");
            }
    		
            else if (array[i][j]=='c')
    		{
    			printf("\033[0;32m");
                printf("_");
                printf("\033[0m");
    		}

    		else
    		{
    			printf(" ");
    		}
    	}
    	printf("\n");
    }
}

int main(int argc, const char *argv[])
{
    int FLAG=1; //Oyun kazananını kullanmak için tanımladığımız değişken.
    int array[15][30]; //ARRAYimizi tanımlıyoruz.
    int gamer1,gamer2;
    int adim1,adim2,toplam1=0,toplam2=0; //adim1 ve adim2'yi her döngüde atılan zarları atamak için tanımlıyoruz. toplam1 ve toplam2'yi de atılan tüm adımların toplamı için tanımlıyoruz.
    char a,b; //Enterla oyun hamlesi yapmak için tanımlıyoruz.
        
    //Buradaki x karakterinin anlamı penalty noktalarıdır.
    array[1][14]='x';
    array[13][14]='x';
    array[3][10]='x';
    array[3][18]='x';
    array[11][10]='x';
    array[11][18]='x';
    array[5][26]='x';
    array[10][26]='x';
    array[7][28]='x';

    //Buradaki a ve b karakterinin anlamı başlangıç noktalarıdır.
    array[1][1]='a';
    array[3][3]='b';

    //Buradaki c karakterinin anlamı bitiş noktalarıdır.
    array[2][1]='c';
    array[4][3]='c';

    printMap(array,15,30); //Oyun başlamadan önce haritayı basıyoruz.
    int starter=startGame(dice); //Hangi oyuncunun başladığını belirten değişken.

    do
    {
        if (starter==1)
        {
            printf("\033[0;32m");
            printf("Player 1... Press enter to dice\n");
            printf("\033[0m");
            scanf("%c",&a);
            adim1=dice(); //Adim zarları atılıyor.
            printf("\033[0;32m");
            printf("DICE: %d\n",adim1);
            printf("\033[0m");
            toplam1+=adim1; //Her turda atılan zarların değeri toplanıyor.
        
            printf("\033[0;34m");
            printf("Player 2... Press enter to dice\n");
            printf("\033[0m");
            scanf("%c",&b);
            adim2=dice(); //Adim zarları atılıyor.
            printf("\033[0;34m");
            printf("DICE: %d\n\n",adim2);
            printf("\033[0m");
            toplam2+=adim2; //Her turda atılan zarların değeri toplanıyor.
        }

        else
        {   
            printf("\033[0;34m");
            printf("Player 2... Press enter to dice\n");
            printf("\033[0m");
            scanf("%c",&b);
            adim2=dice(); //Adim zarları atılıyor.
            printf("\033[0;34m");
            printf("DICE: %d\n\n",adim2);
            printf("\033[0m");      
            toplam2+=adim2; //Her turda atılan zarların değeri toplanıyor.
            
            printf("\033[0;32m");
            printf("Player 1... Press enter to dice\n");
            printf("\033[0m");
            scanf("%c",&a);
            adim1=dice(); //Adim zarları atılıyor.
            printf("\033[0;32m");
            printf("DICE: %d\n",adim1);
            printf("\033[0m");   
            toplam1+=adim1;  //Her turda atılan zarların değeri toplanıyor.
        }

        if (toplam1<=27 || toplam2<=23) //Parkurun ilk kısmı için penalty kontrolü ve adım manipülasyonu.
        {
            if (toplam1<=27)
            {
                if (toplam1==13)
                {
                    printf("\033[0;32m");
                    printf("Penalty for player 1 !!!\n");
                    printf("\033[0m"); 
                    toplam1-=2; //Penaltı noktalarına denk gelinirse toplamı 2 azaltıyoruz.(ceza olarak)
                    adim1-=2;  //Aynı şekilde adımı da ceza olarak azaltıyoruz.
                }

                array[1][(1+toplam1)-adim1]='z'; // 1 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                array[1][1+toplam1]='a'; // 1 simgesinin yeni indisi tanımlanıyor.
            }

            if (toplam2<=23)
            {
                if (toplam2==7 || toplam2==15)
                {
                    printf("\033[0;34m");
                    printf("Penalty for player 2 !!!\n");
                    printf("\033[0m");
                    toplam2-=2; //Penaltı noktalarına denk gelinirse toplamı 2 azaltıyoruz.(ceza olarak)
                    adim2-=2; //Aynı şekilde adımı da ceza olarak azaltıyoruz.
                }

                array[3][3+toplam2-adim2]='z'; // 2 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                array[3][3+toplam2]='b'; // 2 simgesinin yeni indisi tanımlanıyor.
            }           
        }

        if ((toplam1>27 && toplam1<39) || (toplam2>23 && toplam2<=31))
        {
            if (toplam1>27 && toplam1<39)
            {
                if (toplam1==33)
                {
                    printf("\033[0;32m");
                    printf("Penalty for player 1 !!!\n");
                    printf("\033[0m"); 
                    toplam1-=2; //Penaltı noktalarına denk gelinirse toplamı 2 azaltıyoruz.(ceza olarak)
                    adim1-=2; //Aynı şekilde adımı da ceza olarak azaltıyoruz.
                }

                if (((1+toplam1)-adim1)>0 && ((1+toplam1)-adim1)<29)
                {
                    array[1][(1+toplam1)-adim1]='z'; //Üstteki if bloğunda silinen değerin arrayi taşırmaması için aynı komutu eğer array taşma durumundaysa yine yaptırıyoruz.
                }
                
                array[(toplam1-26)-adim1][28]='z'; // 1 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                array[toplam1-26][28]='a'; // 1 simgesinin yeni indisi tanımlanıyor.
            }

            if (toplam2>23 && toplam2<=31)
            {
                if (toplam2==25 || toplam2==30)
                {
                    printf("\033[0;34m");
                    printf("Penalty for player 2 !!!\n");
                    printf("\033[0m");
                    toplam2-=2; //Penaltı noktalarına denk gelinirse toplamı 2 azaltıyoruz.(ceza olarak)
                    adim2-=2; //Aynı şekilde adımı da ceza olarak azaltıyoruz.
                }

                if ((3+toplam2-adim2)>0 && (3+toplam2-adim2)<29)
                {
                    array[3][3+toplam2-adim2]='z'; //Üstteki if bloğunda silinen değerin arrayi taşırmaması için aynı komutu eğer array taşma durumundaysa yine yaptırıyoruz.
                }
                
                if (((toplam2-20)-adim2)>0 && ((toplam2-20)-adim2)<14)
                {
                    array[(toplam2-20)-adim2][26]='z'; // 2 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                }
                
                array[toplam2-20][26]='b'; // 2 simgesinin yeni indisi tanımlanıyor.
            }           
        }

        if ((toplam1>=39 && toplam1<=66) ||(toplam2>31 && toplam2<=54))
        {
            if (toplam1>=39)
            {
                if (toplam1==53)
                {
                    printf("\033[0;32m");
                    printf("Penalty for player 1 !!!\n");
                    printf("\033[0m"); 
                    toplam1-=2; //Penaltı noktalarına denk gelinirse toplamı 2 azaltıyoruz.(ceza olarak)
                    adim1-=2; //Aynı şekilde adımı da ceza olarak azaltıyoruz.
                }

                if (((toplam1-26)-adim1)>0 && ((toplam1-26)-adim1)<14)
                {
                    array[(toplam1-26)-adim1][28]='z'; //Üstteki if bloğunda silinen değerin arrayi taşırmaması için aynı komutu eğer array taşma durumundaysa yine yaptırıyoruz.
                }
                
                array[13][(28-(toplam1-39)+adim1)]='z'; // 1 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                array[13][28-(toplam1-39)]='a'; // 1 simgesinin yeni indisi tanımlanıyor.
            }

            if (toplam2>31 && toplam2<=54)
            {
                if (toplam2==39 || toplam2==47)
                {
                    printf("\033[0;34m");
                    printf("Penalty for player 2 !!!\n");
                    printf("\033[0m");
                    toplam2-=2; //Penaltı noktalarına denk gelinirse toplamı 2 azaltıyoruz.(ceza olarak)
                    adim2-=2; //Aynı şekilde adımı da ceza olarak azaltıyoruz.
                }

                if (((toplam2-20)-adim2)>0 && ((toplam2-20)-adim2)<14)
                {
                    array[(toplam2-20)-adim2][26]='z'; //Üstteki if bloğunda silinen değerin arrayi taşırmaması için aynı komutu eğer array taşma durumundaysa yine yaptırıyoruz.
                }
                
                if (((26-(toplam2-31))+adim2)>0 && ((26-(toplam2-31))+adim2)<30)
                {
                    array[11][(26-(toplam2-31))+adim2]='z'; // 2 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                }
                
                array[11][26-(toplam2-31)]='b'; // 2 simgesinin yeni indisi tanımlanıyor.
            }
        }
            
        if ((toplam1>66 || toplam2>54) && (toplam1<77 || toplam2<61))
        {
            if (toplam1>66)
            { 
                if ((28-(toplam1-39)+adim1)>0 && (28-(toplam1-39)+adim1)<29)
                {
                    array[13][(28-(toplam1-39)+adim1)]='z'; //Üstteki if bloğunda silinen değerin arrayi taşırmaması için aynı komutu eğer array taşma durumundaysa yine yaptırıyoruz.
                }
                
                if (((13-(toplam1-66))+adim1)>0 && ((13-(toplam1-66))+adim1)<14)
                {
                    array[(13-(toplam1-66))+adim1][1]='z'; // 1 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                }   

                if (toplam1<77)
                {
                    array[13-(toplam1-66)][1]='a'; // 1 simgesinin yeni indisi tanımlanıyor.
                }
            }

            if (toplam2>54)
            {
                if(((26-(toplam2-31))+adim2>0) && (26-(toplam2-31)+adim2)<29)
                {
                    array[11][(26-(toplam2-31))+adim2]='z'; //Üstteki if bloğunda silinen değerin arrayi taşırmaması için aynı komutu eğer array taşma durumundaysa yine yaptırıyoruz.
                }
                
                if ((11-(toplam2-54)+adim2)>0 && (11-(toplam2-54)+adim2)<14)
                {
                    array[11-(toplam2-54)+adim2][3]='z'; // 2 simgesinin yerine boş bi değer atanıyor ki eski yerinden silinsin.
                }

                if (toplam2<61)
                {
                    array[11-(toplam2-54)][3]='b'; // 2 simgesinin yeni indisi tanımlanıyor.
                }
            }            
        }

        if (toplam1>=77 || toplam2>=61)
        {
            if (starter==1)
            {
                if (toplam1>=77)
                {
                    array[1][1]='a'; //Eğer birinci oyuncu kazanırsa 1 belirteci ilk başladığı yerde görünsün diye indisi ilk baştaki haline getiriyoruz.
                    array[2][1]='c';
                    printf("\033[0;35m");
                    printf("***Player 1 Won The Game***\n");
                    printf("\033[0m");
                }

                else if (toplam2>=61)
                {
                    array[3][3]='b'; //Eğer ikinci oyuncu kazanırsa 2 belirteci ilk başladığı yerde görünsün diye indisi ilk baştaki haline getiriyoruz.   
                    array[4][3]='c';
                    printf("\033[0;35m");               
                    printf("***Player 2 Won The Game***\n");
                    printf("\033[0m");
                }               
            }

            if (starter==0)
            {
                if (toplam2>=61)
                {
                    array[3][3]='b'; //Eğer ikinci oyuncu kazanırsa 2 belirteci ilk başladığı yerde görünsün diye indisi ilk baştaki haline getiriyoruz.   
                    array[4][3]='c';
                    printf("\033[0;35m");               
                    printf("***Player 2 Won The Game***\n");
                    printf("\033[0m");  
                }

                else if (toplam1>=77)
                {
                    array[1][1]='a'; //Eğer birinci oyuncu kazanırsa 1 belirteci ilk başladığı yerde görünsün diye indisi ilk baştaki haline getiriyoruz.
                    array[2][1]='c';
                    printf("\033[0;35m");
                    printf("***Player 1 Won The Game***\n");
                    printf("\033[0m");
                }                
            }
            FLAG=0; //Eğer herhangi bir oyuncu kazanırsa kontrol değişkenimizi sıfırlayarak sonsuz döngüyü bitiriyoruz.        
        }
        printMap(array,15,30); //Haritayı son kez bastırıyoruz.
    }
    while(FLAG);

	return 0;
}