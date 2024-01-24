#include <stdio.h>

//Functions declarations.
int print_coefficient(int a,int b,int c);
void drawing_graph();
void print_graph_file();

int main()
{   
    int coefficent1,coefficent2,coefficent3;
    int selectOperation=0;
  
    while(selectOperation!=3) 
    {        
        printf("Select an operation...\n\n");
        printf("0 -> Enter the coefficients.\n");
        printf("1 -> Draw the graph.\n");
        printf("2 -> Print the graph into a .txt file.\n");
        printf("3 -> Exit.\n");
        scanf("%d",&selectOperation);

        if (selectOperation==0)
        {
            printf("Please enter the coefficient for the following equation x=a*(y*y) + b*y + c\n\n");
            printf("a:");
            scanf("%d",&coefficent1);
            printf("b:");
            scanf("%d",&coefficent2);
            printf("c:");
            scanf("%d",&coefficent3);
            print_coefficient(coefficent1,coefficent2,coefficent3);
        }

        if (selectOperation==1)
        {
            FILE *file;
            file=fopen("coefficients.txt","r");
            
            if (file==NULL)
            {
                printf("File not found!");
                break;
            }

            else
            {
                drawing_graph();
            }
            fclose(file);           
        }

        if (selectOperation==2)
        {
            FILE *file;
            file=fopen("coefficients.txt","r");
            
            if (file==NULL)
            {
                printf("coefficient.txt file is not found!");
                break;
            }

            else
            {
                print_graph_file();
            }
            fclose(file);            
        }

        if (selectOperation<0 || selectOperation>3)
        {
            printf("Invalid choice!\n\n");

        }
    }
    return 0;
}

int print_coefficient(int a,int b,int c) //Bu fonksiyonda kullanıcının denklem için girdiği katsayıları dosyaya yazdırıyoruz.
{
    FILE *file;
    file=fopen("coefficients.txt","w");             
    fprintf(file,"%d\n%d\n%d",a,b,c);
    fclose(file);
    printf("coefficient.txt file has been created.\n\n");

    return 0;
}

void drawing_graph() //Bu fonksiyonda istenilen denklemin grafiğini terminal ekranına bastırıyoruz.
{
    int coef1,coef2,coef3;   

    printf("Coefficients has been read from the coefficient.txt file.\n\n");

    FILE *file;
    file=fopen("coefficients.txt","r");    
    fscanf(file,"%d",&coef1);
    fscanf(file,"%d",&coef2);
    fscanf(file,"%d",&coef3);
    fclose(file);

    printf("Printing the graph of x=%d*(y*y)+ %d*y+ %d\n\n",coef1,coef2,coef3);
    
    for (int i = 0; i < 31; ++i)
    {
        for (int j = 0; j < 102; ++j)
        {
            //İstenilen grafiğin çizileceği if.
            if (j-50==(coef1*(15-i)*(15-i))+(coef2*(15-i))+coef3)
            {
                if (i==16 && j<50)
                {
                    printf("\033[0;33m");
                    printf("\b\b#");
                    printf("\033[0m");
                    printf("  ");
                }

                else if (i==16 && j>50)
                {
                    printf("\033[0;33m");
                    printf("#");
                    printf("\033[0m");
                    printf(" ");
                }

                else
                {
                    printf("\033[0;33m");
                    printf("#");
                    printf("\033[0m");   
                }                             
            }
            //x ekseni çizgileri için açılan else if.
            else if (i==15) //X eksenindeki < > ve - sembollerinin basıldığı blok. Ayrıca 0 noktası için özel olarak | karakteri basılmıştır.
            {
                if (j==0)
                {
                    printf("\033[0;32m");
                    printf("<");
                    printf("\033[0m");
                }

                else if (j==101)
                {
                    printf("\033[0;32m");
                    printf(">");
                    printf("\033[0m");
                }

                else if (j==50)
                {
                    printf("\033[0;32m");
                    printf("|");
                    printf("\033[0m");
                }

                else
                {
                    printf("\033[0;32m");
                    printf("-");
                    printf("\033[0m");
                }
            }
            //y ekseni çizgileri için açılan else if.            
            else if (j==50)
            {
                if (i==0)
                {
                    printf("\033[0;32m");
                    printf("^");
                    printf("\033[0m");
                }

                else if (i!=15) //0'a 0 noktasında | karakterinin zaten bastırdığı için bir daha basmasını engelledik.
                {
                    if (i==16)
                    {   

                        if (j-50==(coef1*(15-i)*(15-i))+(coef2*(15-i))+coef3+1 || j-50==(coef1*(15-i)*(15-i))+(coef2*(15-i))+coef3+2)
                        {
                            printf("\b\b");
                        } 

                        else if (1)
                        {
                            printf("\033[0;32m");
                            printf("\b\b\b%d",j-50);
                            printf("\033[0m");
                        }                    
                        
                    }
                    printf("\033[0;32m");
                    printf("|");
                    printf("\033[0m");
                }                
            }
            //x ekseni koardinatlarını yazdırmak için açılan else if.           
            else if (i==16)
            {
                if (j%10==0 && j<50)
                {
                    printf("\033[0;32m");
                    printf("\b\b%d",j-50);
                    printf("\033[0m");
                }

                else if(j%10==0 && j>50)
                {
                    printf("\033[0;32m");
                    printf("\b%d",j-50);
                    printf("\033[0m");
                }

                else
                {
                    printf(" ");
                }               
            }
            //y ekseni koordinatlarını yazdırmak için açılan else if. 
            else if (j==49 && i%5==0)
            {
                if (j-50==(coef1*(15-i)*(15-i))+(coef2*(15-i))+coef3+1)
                {
                    printf(" ");
                }

                else if (15-i>5)
                {
                    printf("\033[0;32m");
                    printf("\b%d",15-i);
                    printf("\033[0m");                   
                }

                else if (15-i<=5 && 15-i>0)
                {
                    printf("\033[0;32m");
                    printf("%d",15-i);
                    printf("\033[0m");                    
                }

                if (j-50==(coef1*(15-i)*(15-i))+(coef2*(15-i))+coef3+1 || j-50==(coef1*(15-i)*(15-i))+(coef2*(15-i))+coef3+2)
                {
                    
                }

                else if (15-i>-10 && 15-i<0)
                {                 
                    printf("\033[0;32m");
                    printf("\b%d",15-i);
                    printf("\033[0m");                    
                }

                else if (15-i<=-10)
                {
                    printf("\033[0;32m");
                    printf("\b\b%d",15-i);
                    printf("\033[0m");
                }         
            }
            //Kalan yerlere boşluk atmak için açılan else.
            else
            {
                printf(" ");
            }   
        }
        printf("\n");
    }       
}

void print_graph_file() //Bu fonksiyonda grafiğimizi bir dosyaya bastırıyoruz.
{
    int coef1,coef2,coef3;

    FILE *file;
    file=fopen("coefficients.txt","r");    
    fscanf(file,"%d",&coef1);
    fscanf(file,"%d",&coef2);
    fscanf(file,"%d",&coef3);
    fclose(file);

    printf("coefficients has been read from the coefficient file.\n\n");
    printf("The graph of x=%d*(y*y)+%d*y+%d has been written to graph.txt file.\n\n",coef1,coef2,coef3);
    
    file=fopen("graph.txt","w");

    for (int i = 0; i < 31; ++i)
    { 
        for (int j = 0; j < 102; ++j)
        {
            //İstenilen grafiğin çizileceği if.
            if (j-50==(coef1*(15-i)*(15-i))+(coef2*(15-i))+coef3)
            {
                fprintf(file,"#");
            }
            //x ekseni çizgileri için açılan else if.
            else if (i==15) //X eksenindeki < > ve - sembollerinin basıldığı blok. Ayrıca 0 noktası için özel olarak | karakteri basılmıştır.
            {
                if (j==0)
                {
                    fprintf(file,"<");
                }

                else if (j==101)
                {
                    fprintf(file,">");
                }

                else if (j==50)
                {
                    fprintf(file,"|");
                }

                else
                {
                    fprintf(file,"-");
                }
            }
            //y ekseni çizgileri için açılan else if.            
            else if (j==50)
            {
                if (i==0)
                {
                    fprintf(file,"^");
                }

                else if (i!=15) //0'a 0 noktasında | karakterinin zaten bastırdığı için bir daha basmasını engelledik.
                {
                    fprintf(file,"|");
                }                
            }
            //Kalan yerlere boşluk atmak için açılan else.
            else
            {
                fprintf(file," ");
            }   
        }
        fprintf(file,"\n");
    }   
    fclose(file);    
}
