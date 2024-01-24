#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void randomCharacter(char table[15][15]) //Tabloyu random harflerle dolduracak fonksipath.
{
    for (int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < 15; ++j)
        {
            table[i][j]=(97+rand()%26); //Tabloyu ASCII değerlerini temsil eden rastgele sayılarla dolduruyoruz.
        }
    }
}

void takeWord(char words[7][6]) //Dosyadan kelime okuyan fonksipath.
{
    int flag=1;
    int randomNumber=0; //Dosyadan okunacak kelimenin satır bilgisini tutacak değişken.
    int randarray[7]={0};

    FILE *file;
    file=fopen("wordlist.txt","r"); //Dosyayı okuma modunda açıyoruz.
    
    for (int k = 0; k < 7; ++k)
    {
        do{
            flag=1;        
            randomNumber = 1+rand()%50; //Kelime almak için kelimenin bulunduğu satırı random seçiyoruz.
            
            for(int i=0; i<7; i++)
            {
                if(randarray[i] == randomNumber)
                {
                    flag=0;
                }         
            }       
            randarray[k] = randomNumber;

        }while(!flag);   
    }

    for (int i = 0; i < 7; ++i)
    {
        for (int j = 0; j <= randarray[i]; ++j) //Seçilen random sayıs kadar dönecek ve en son aldığımız kelime tablodaki kelime olmuş olacak.
        {
            fscanf(file,"%s",words[j]); //Kelimeyi dosyadan okuyoruz.     
        } 
        words[7][6]='\0'; //Son elemana null değeri atıyoruz.   
    }
    fseek(file,0,SEEK_SET); //Dosya imlecini başa alıyoruz.
    
    fclose(file); //Dosyayı kapatıyoruz.
}

void printTable(char table[15][15]) //Oyunun tablosunu terminale basan fonksipath.
{
    for (int k = 0; k < 15; ++k)
    {
        for (int l = 0; l < 15; ++l)
        {
            if (table[k][l]=='X')
            {
                printf("\033[0;31m");
                printf("%c ",table[k][l]);
                printf("\033[0m");
            }

            else
            {
                printf("%c ",table[k][l]);                
            }
        }
        printf("\n");
    }
}

void printX(char table[15][15], int y, int x, int path, char answer[6])
{
    int length=0;

    for (int k=0; k<7; k++)
    {
        switch (path)
        {       
            case 1:
                
                length=strlen(answer);
                
                for(int j=0;j<length;j++)
                {    
                    table[y+j][x]='X';   
                }           
                break;
            
            case 2:
                
                length=strlen(answer);
                
                for(int j=0;j<length;j++)
                {    
                    table[y][x+j]='X';    
                }                   
                break;
                
            case 3:

                length=strlen(answer);
                
                for(int j=0;j<length;j++)
                {    
                    table[y+j][x+j]='X';    
                }
                break;
                
            case 4:
            
                length=strlen(answer);  

                for(int j=0;j<length;j++)
                {    
                    table[y-j][x]='X';   
                }
                break;
            
            case 5:
            
                length=strlen(answer);
                
                for(int j=0;j<length;j++)
                {    
                    table[y][x-j]='X';    
                }
                break;
            
            case 6:
            
                length=strlen(answer);  

                for(int j=0;j<length;j++)
                {    
                    table[y-j][x-j]='X';   
                }
                break;
            
            case 7:
            
                length=strlen(answer);
                
                for(int j=0;j<length;j++)
                {    
                    table[y-j][x+j]='X';   
                }
                break;
            
            case 8:
            
                length=strlen(answer);
                
                for(int j=0;j<length;j++)
                {    
                    table[y+j][x-j]='X';   
                }
                break;
        }
    }
}

int testFunction(int y, int x, char answer[6],char table[15][15])
{
    int flag=0;
    int length=strlen(answer);
    
    if(answer[0]==table[y][x])
    {
        if(answer[1]==table[y+1][x])
        {   
            for(int k=2; k<length; k++)
            {        
                if(answer[k]!=table[y+k][x])
                { 
                    flag=1;
                    break; 
                }
        
                if (!flag)
                {
                    printX(table,y,x,1,answer);
                    return 1;
                }    
            }   
        }
        flag=0;

        if(answer[1]==table[y][x+1])
        {       
            for(int k=2; k<length; k++)
            {      
                if(answer[k]!=table[y][x+k])
                { 
                    flag=1;
                    break;
                }
                
                if (!flag)
                {
                    printX(table,y,x,2,answer);
                    return 1;
                }
            }    
        }  
        flag=0;

        if(answer[1]==table[y+1][x+1])
        {               
            for(int k=2; k<length; k++)
            {
                if(answer[k]!=table[y+k][x+k])
                { 
                    flag=1;
                    break; 
                }
                
                if (!flag)
                {
                    printX(table,y,x,3,answer);
                    return 1;
                }       
            }    
        } 
        flag=0;  

        if(answer[1]==table[y-1][x])
        {     
            for(int k=2; k<length; k++)
            {       
                if(answer[k]!=table[y-k][x])
                { 
                    flag=1;
                    break;
                }
                
                if (!flag)
                {
                    printX(table,y,x,4,answer);
                    return 1;
                }
            }   
        } 
        flag=0;
        
        if(answer[1]==table[y][x-1])
        { 
            for(int k=2; k<length; k++)
            {      
                if(answer[k]!=table[y][x-k])
                { 
                    flag=1;
                    break;
                }
                
                if (!flag)
                {
                    printX(table,y,x,5,answer);
                    return 1;
                }         
            }   
        }
        flag=0;
        
        if(answer[1]==table[y-1][x-1])
        {    
            for(int k=2; k<length; k++)
            {        
                if(answer[k]!=table[y-k][x-k])
                { 
                    flag=1;
                    break; 
                }
                
                if (!flag)
                {
                    printX(table,y,x,6,answer);
                    return 1;
                }         
            }   
        }  
        flag=0;     
    
        if(answer[1]==table[y-1][x+1])
        {    
            for(int k=2; k<length; k++)
            {      
                if(answer[k]!=table[y-k][x+k])
                { 
                    flag=1;
                    break;
                }
                
                if (!flag)
                {
                    printX(table,y,x,7,answer);
                    return 1;
                }        
            }  
        }            
        flag=0;

        if(answer[1]==table[y+1][x-1])
        {        
            for(int k=2; k<length-1; k++)
            {       
                if(answer[k]!=table[y+k][x-k])
                { 
                    flag=1;
                    break; 
                }
                
                if (!flag)
                {
                    printX(table,y,x,8,answer);
                    return 1;
                }         
            }   
        }
    }
    return 0;
}

void putWord(int controlArray[15][15],char words[7][6],char table[15][15]) //Kelimelerin yönü ve indislerinin belirlendiği fonksipath.
{
    /*
       Kelimelerin Doğrultuları:
       -------------------------
       path==1-> Bu doğrultuda kelime yukardan aşağı şekilde yazılacak.
       path==2-> Bu doğrultuda kelime soldan sağa doğru yazılacak.
       path==3-> Bu doğrultuda kelime sol üstten sağ alta doğru yazılacak.
       path==4-> Bu doğrultuda kelime aşağıdan yukarıya doğru yazılacak.
       path==5-> Bu doğrultuda kelime sağdan sola doğru yazılacak.
       path==6-> Bu doğrultuda kelime sağ alttan sol üste doğru yazılacak.
       path==7-> Bu doğrultuda kelime sol alttan sağ üste doğru yazılacak.
       path==8-> Bu doğrultuda kelime sağ üstten sol ata doğru yazılacak.
    */ 

    int path[8],x=0,y=0,flag=0,length;

    for (int i = 0; i < 7; ++i)
    {
        path[i]=(1+rand()%8);
    }

    for (int j = 0; j < 7; ++j) 
    {       
        switch(path[j])
        {
            case 1:

                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=(rand()%(15-(length-1)));
                    x=(rand()%15);

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y+k][x]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y+m][x]=words[j][m];
                            controlArray[y+m][x]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;

            case 2:
            
                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=(rand()%15);
                    x=(rand()%(15-(length-1)));

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y][x+k]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y][x+m]=words[j][m];
                            controlArray[y][x+m]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;

            case 3:

                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=(rand()%(15-(length-1)));
                    x=(rand()%(15-(length-1)));

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y+k][x+k]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y+m][x+m]=words[j][m];
                            controlArray[y+m][x+m]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;

            case 4:

                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=((length-1)+rand()%(15-(length-1)));
                    x=rand()%15;

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y-k][x]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y-m][x]=words[j][m];
                            controlArray[y-m][x]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;

            case 5:

                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=(rand()%15);
                    x=((length-1)+rand()%(15-(length-1)));

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y][x-k]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y][x-m]=words[j][m];
                            controlArray[y][x-m]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;

            case 6:

                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=((length-1)+rand()%(15-(length-1)));
                    x=((length-1)+rand()%(15-(length-1)));

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y-k][x-k]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y-m][x-m]=words[j][m];
                            controlArray[y-m][x-m]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;

            case 7:

                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=((length-1)+rand()%(15-(length-1)));
                    x=(rand()%(15-(length-1)));

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y-k][x+k]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y-m][x+m]=words[j][m];
                            controlArray[y-m][x+m]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;

            case 8:

                length=strlen(words[j]);

                do
                {
                    flag=1;

                    y=(rand()%(15-(length-1)));
                    x=((length-1)+rand()%(15-(length-1)));

                    for (int k = 0; k < length; ++k)
                    {
                        if (controlArray[y+k][x-k]==1)
                        {
                            flag=0;
                        }
                    }

                    if (flag)
                    {
                        for (int m = 0; m < length; ++m)
                        {
                            table[y+m][x-m]=words[j][m];
                            controlArray[y+m][x-m]=1;
                        }
                    }
                }
                while(!flag);

                printf("%d-%d->%s\n",y,x,words[j]);
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    char words[7][6];              //Her bir kelimenin atanacağı array.
    char table[15][15];            //Oyunun terminalde oyuncuya görüneceği array.
    int controlArray[15][15]={0};  //Kelimelerin üst üste gelmesini engellemek için kullanılacak array.
    int firstIndis,secondIndis;    //Bulunan kelimenin ilk harfinin koordinatları.
    char answer[6];                //Girilen cevabın atandığı array.
    int claim=3;                   //Oyuncunun yapabileceği maksimum hata hakkı.
    int point=0;                   //Oyuncunun toplayacağı puanların tutulacağı değişken.
    char a,b;

    srand(time(NULL)); //Her seferinde farklı değer üretmek için srand(time(NULL)) kalıbını kullanıyoruz.

    printf("\n");
    
    takeWord(words);                   //Kelimelerin alınacağı fonksipathu çağırıyoruz.
    randomCharacter(table);            //Kelimelerin random karakterlerle doldurulacağı fonksipathu çağırıyoruz.
    putWord(controlArray,words,table); //Kelimelerin yerlerinin belirlendiği fonksipathu çağırıyoruz.
    
    printf("\n");

    printTable(table); //Tabloyu basacak fonksiyonu çağırıyoruz.

    do
    {
        printf("\nEnter coordinates and word:\n");
        scanf("%d%d%s",&firstIndis,&secondIndis,answer);   
        
        a=getchar();
        
        if (a==':')
        {
            b=getchar();

            if (b=='q')
            {
                break;
            }    
        }

        if(testFunction(firstIndis,secondIndis,answer,table))
        {                      
            point+=2;        
            printf("Founded! You got 2 points, your total points: %d\n",point);
        
            if(point==14)
            {
                printf("\033[0;31m");
                printf("Congrutilations! You found every word.\n\n");
                printf("\033[0m");      
            }
        }

        else
        {
            printf("Wrong choice! You have only %d lefts.\n", --claim);
        } 
    
        printf("\n------------------------------\n\n");
        printTable(table);

    }while(claim && point!=14);  

    printf("\nYour total point: %d\n\n",point);           

	return 0;
}
