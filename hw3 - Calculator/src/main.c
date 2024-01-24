#include<stdio.h>
#include<math.h>

//We write prototypes of functions.

int sum(int n1,int n2,int flag);
int multi(int n1,int n2,int flag);
int isprime(int a);
void write_file(int number);
void print_file();
void sort_file();

int main(int argc, char const *argv[])
{
	int selectOperation;       //We ask the user for the menu wants to choose.
	int n1,n2,flag,flag2;      //flag2=> Variable to use for selection of sum and multiplication operations.
	int resultSum,resultMulti; //Variables to assign values to be returned from functions.
    int N;                     //The variable to assign for (isprime) function.
    int resultPrime;

	printf("\n\n");
	printf("Select operation \n");
	printf("1. Calculate sum/multiplication between two numbers \n");
	printf("2. Calculate prime numbers \n");
	printf("3. Show number sequence in file \n");
	printf("4. Sort number sequence in file \n");
	scanf("%d",&selectOperation);

    switch(selectOperation)
    {
    	case 1:

    	    printf("Please enter '0' for sum,'1' for multiplication.\n");
    	    scanf("%d",&flag2);
            
            if (flag2==1)
            {
            	printf("Please enter '0' to work on even number, '1' to work on odd numbers.\n");
            	scanf("%d",&flag);
                
                switch(flag)
                {
                	case 0:
                	    printf("Please enter two different number.\n");
            	        printf("Number 1:");
           		        scanf("%d",&n1);
           		        printf("Number 2:");
           		        scanf("%d",&n2);
                        
            	        resultMulti=multi(n1,n2,flag);
                        write_file(resultMulti); //We print the result with the write function.

                        break;

                    case 1:
                        printf("Please enter two different number.\n");
            	        printf("Number 1:");
           		        scanf("%d",&n1);
           		        printf("Number 2:");
           		        scanf("%d",&n2);

            	        resultMulti=multi(n1,n2,flag);
                        write_file(resultMulti); //We print the result with the write function.

                        break;   

                    default:

                        printf("ERROR: Invalid value! Enter '1' or '0'.\n");  

                        break;  
                }
            }

            else if(flag2==0)
            {
                printf("Please enter '0' to work on even number, '1' to work on odd numbers.\n");
            	scanf("%d",&flag);

            	switch(flag)
                {
                	case 0:
                	    printf("Please enter two different number.\n");
            	        printf("Number 1:");
           		        scanf("%d",&n1);
           		        printf("Number 2:");
           		        scanf("%d",&n2);

            	        resultSum=sum(n1,n2,flag);
                        write_file(resultSum); //We print the result with the write function.

                        break;

                    case 1:
                        printf("Please enter two different number.\n");
            	        printf("Number 1:");
           		        scanf("%d",&n1);
           		        printf("Number 2:");
           		        scanf("%d",&n2);

            	        resultSum=sum(n1,n2,flag);
                        write_file(resultSum); //We print the result with the write function.

                        break;   

                    default:

                        printf("ERROR: Invalid value! Enter '1' or '0'.\n");  

                        break;  
                }      	
            }

            else
            {
            	printf("ERROR: Invalid value! Enter '1' or '0'.\n\n");
            }

	        break;

	    case 2:
	        
	        printf("Please enter an integer:\n");
	        scanf("%d",&N);
	        	        	        
            for (int i = 2; i < N; ++i)
            {
            	resultPrime=0;
            	resultPrime=isprime(i);
                
            	if (resultPrime==1)
            	{
            		printf("%d is a prime number.\n",i);
            	}

            	else
            	{
            		printf("%d is not a prime number, it is dividible by %d.\n",i,resultPrime);
            	}
            }

	        break;

	    case 3:
	    
            print_file();

	        break;

	    case 4:
	    
	        sort_file();

	        break;

	    default:

	        printf("Invalid value!!\n\n");
	        break;
	                    
    }

	return 0;
}

int sum(int n1,int n2,int flag)
{
	int temp;
	int sum=0;

	if (n1>n2) //We find the small number to make our easier.
	{
		temp=n1;
		n1=n2;
		n2=temp;
	}
    
    if(flag) //We will deal with odd numbers.
    {	
    	if (n1%2==0) //If the number is even, it's initialized with (n1+1) as odd numbers are desired. 
    	{
    		for (int i = n1+1; i < n2; i+=2)  
	        {       
	    	    sum+=i;
		        printf("%d",i);

		        if (i<(n2-1)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("+");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",sum);
    	}

    	else
    	{
    		for (int i = n1+2; i < n2; i+=2) //If the number is odd, it's initialized with (n1+2) as odd numbers are desired.
	        {       
	    	    sum+=i;
		        printf("%d",i);
		        
		        if (i<(n2-2)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("+");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",sum);
    	}
         		    
    }

    else //We will deal with even numbers.
    {
        if (n1%2==0) //If the number is even, it's initialized with (n1+2) as even numbers are desired.
    	{
    		for (int i = n1+2; i < n2; i+=2)
	        {       
	    	    sum+=i;
		        printf("%d",i);
		        
		        if (i<(n2-2)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("+");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",sum);
    	}

    	else
    	{
    		for (int i = n1+1; i < n2; i+=2) //If the number is odd, it's initialized with (n1+1) as odd numbers are desired.
	        {       
	    	    sum+=i;
		        printf("%d",i);
		        
		        if (i<(n2-2)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("+");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",sum);
    	}
    }

    return sum;
}

int multi(int n1,int n2,int flag)
{
	int temp;
	int multi=1;

	if (n1>n2)
	{
		temp=n1;
		n1=n2;
		n2=temp;
	}
    
    if(flag) //We will deal with odd numbers.
    {	
    	if (n1%2==0) //If the number is even, it's initialized with (n1+1) as odd numbers are desired.
    	{
    		for (int i = n1+1; i < n2; i+=2)
	        {       
	    	    multi*=i;
		        printf("%d",i);
		        
		        if (i<(n2-1)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("*");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",multi);
    	}

    	else
    	{
    		for (int i = n1+2; i < n2; i+=2) //If the number is odd, it's initialized with (n1+2) as odd numbers are desired.
	        {       
	    	    multi*=i;
		        printf("%d",i);
		        
		        if (i<(n2-2)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("*");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",multi);
    	}
         		    
    }

    else //We will deal with even numbers.
    {
        if (n1%2==0) //If the number is even, it's initialized with (n1+2) as even numbers are desired.
    	{
    		for (int i = n1+2; i < n2; i+=2)
	        {       
	    	    multi*=i;
		        printf("%d",i);

		        if (i<(n2-2)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("*");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",multi);
    	}

    	else
    	{
    		for (int i = n1+1; i < n2; i+=2) //If the number is odd, it's initialized with (n1+1) as even numbers are desired.
	        {       
	    	    multi*=i;
		        printf("%d",i);
		        
		        if (i<(n2-2)) //To put the '=' sign, we perform substraction according to the even or odd condition.
		        {
		        	printf("*");
		        }

		        else
		        {
		        	printf("=");
		        }
	        }
	        printf("%d\n",multi);
	        
    	}
    }

    return multi;
}

int isprime(int a)
{    

    for (int i = 2; i <= sqrt(a); ++i)
    {
    	if (a%i==0)
    	{
    		return i;
    		break;
    	}

    }

    return 1;
}

void write_file(int number)
{
	FILE *file;
    file=fopen("results.txt","a");             
    fprintf(file,"%d ",number);
    fclose(file);

    printf("The result is written to the results.txt file.\n\n\n");
}

void print_file()
{
	int temp; //We print the values to the results.txt file.

    FILE *file;
    file=fopen("results.txt","r");
    
    printf("Result:\n");

    while(fscanf(file,"%d",&temp)==1)
    {
    	printf("%d ",temp);
    }

    fclose(file);
}



void sort_file()
{
	int temp=0,counter=0;
    int min1=2147483647, min2=2147483647, min3=2147483647;

	FILE *file;
    file=fopen("results.txt","r");

	while(feof(file)==0)
	{
		fscanf(file,"%d",&temp);

		counter++;
	}
    fclose(file);

    file=fopen("results.txt","r");

	while(feof(file)==0)
	{
		fscanf(file,"%d",&temp);

		if (temp<min1)
        {
    	   min1=temp;
    	
        }       
	}
	fclose(file);

	file=fopen("results.txt","r");

	while(feof(file)==0)
	{		
		fscanf(file,"%d",&temp);

		if (temp<min2 && temp>min1)
        {
    	    min2=temp;
        }       
	}
	fclose(file);

	file=fopen("results.txt","r");

	while(feof(file)==0)
	{		
		fscanf(file,"%d",&temp);

		if (temp<min3 && temp>min2)
        {
    	    min3=temp;
        }        
	}
	fclose(file);

	FILE *temporary;
	temporary=fopen("temporary.txt","w");

	fprintf(temporary,"%d %d %d ",min1,min2,min3);
	fclose(temporary);
    
    int takenValue;
    int temp2=min3;

	temporary=fopen("temporary.txt","aw");

    for (int i = 0; i < counter/3; ++i)
    {
    	FILE *file;   
        file=fopen("results.txt","r");

        min1=2147483647;
        min2=2147483647;
        min3=2147483647;
 
	        while (feof(file) == 0)
            {
                fscanf(file,"%d",&temp);
                if (temp <min1 && temp> temp2) 
                {
                	min1 = temp;
                }	
            }
	        fclose(file);

	        file=fopen("results.txt","r");

	        while(feof(file)==0)
	        {		
		        fscanf(file,"%d",&temp);

		        if (temp<min2 && temp>min1)
                {
    	            min2=temp;
                }       
	        }
	        fclose(file);

	        file=fopen("results.txt","r");

	        while(feof(file)==0)
	        {		
		        fscanf(file,"%d",&temp);

		        if (temp<min3 && temp>min2)
                {
    	            min3=temp;
                }        
	        }
	        fclose(file);
	         
            //We print the remaining numbers for the (counter%3) states.

	        if(min3!=2147483647 && min1!=2147483647 && min2!=2147483647)
            {
                fprintf(temporary,"%d %d %d ",min1,min2,min3);
            }	
         
            if(min2!=2147483647 && min3==2147483647 && min1!=2147483647)
            {
	            fprintf(temporary,"%d %d",min1,min2);
            }	
      	
            if(min3==2147483647 && min1!=2147483647)
            {
	            fprintf(temporary,"%d",min1);
            } 
	        
        temp2=min3;   
    }
    fclose(temporary);

    temporary=fopen("temporary.txt","r");
    file=fopen("results.txt","w");
    while(!feof(temporary))
    {
        fscanf(temporary,"%d ",&takenValue);
        fprintf(file,"%d ",takenValue);
    }
    fclose(temporary);

    fclose(file);
    
    file=fopen("results.txt","r");

    while(!feof(file))
    {
   	    fscanf(file,"%d ",&takenValue);
     	printf("%d ",takenValue);
    }

}

     	