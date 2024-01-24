#include<stdio.h>
#include<string.h>
#include "utils.h"

int find_divisible(int x,int y,int z) //The function to find the first divisor.
{
   int f_i;
   
   for(int i=x+1 ; i<y ; ++i) //We find the desired number with the algorithm we set up in the for(loop).
   {
      if(i%z==0)
      {
         f_i=i;
         return f_i;
      }      
   }

   return (-1);
}

int find_nth_divisible(int n,int f_i,int z)
{
   int nth; //The variable to which the desired value is assigned.  
   
   nth=((f_i)+(n*z));
   
   return nth;
}  

int validate_identity_number(char identity_number[])
{
   int numDigit=strlen(identity_number); 
   int sum1=0,sum2=0,sumDigit=0;   //Variables to use to control the ID algorithm.
   int control1=0,control2=0,control3=0; //Variables that will act as flags in cases that do not fit the algorithm.
   
   for (int m = 0; m < 10; ++m)
   {
      sumDigit+=(identity_number[m]-48);
   }
   
   for (int j = 0; j <= 8; j+=2)
   {
      sum1+=identity_number[j]-48;
   }

   for (int k = 1; k <= 7; k+=2)
   {
      sum2+=identity_number[k]-48;
   }

   if ((sum1*7-sum2)%10 != identity_number[9]-48) //
   {
      control2=1;
   }

   if ((sumDigit%10)!=identity_number[10]-48) //Checking if the last digit is equal to the remainder of the sum of the other digit divided by ten. 
   {
      control3=1;
   }

   for (int i = 0; i < 11; ++i) //Checking for case character in the entered string.
   {
      if (identity_number[i]<48 || identity_number[i]>57)
      {
         control1=1;
         break;
      }
   }

   if (numDigit==11) //The eleven digit status of the ID number is checked.
   {
      if ((control1==0 && control2==0) && control3==0)
      {
         return 1;
      }
   }

   return (-1);
}

int create_customer(char identity_number[],int password)
{
   FILE *fp;

   if (fp=fopen("customeraccount.txt","w"))
   {
      fprintf(fp,"%s,%d",identity_number,password);
      fclose(fp);

      return 0;
   }

}

int check_login(char identity_number[],int password)
{  
   char IDtxt[11]; //The variable to which the ID number read from the files is assigned.
   int passwordtxt; //The variable to which the pasword read from the files is assigned.
   int control=0; 

   FILE *ftpr;
   ftpr=fopen("customeraccount.txt","r"); 
   fscanf(ftpr,"%[^,]%*c%d",IDtxt,&passwordtxt); 
   fclose(ftpr);

   for (int i = 0; i < 11; ++i) //Since ID is a string, we are comparing the characters one by one. 
   {
      if (IDtxt[i]==identity_number[i])
      {
         control++;
      }
   }

   if(password==passwordtxt && control==11)
   {
      printf("Login Succesfull\n");
      return 0;
   }
   
   else
   {
      return -1;
   }
}

int withdrawable_amount(float cash_amount)
{
   int decimalPart;

   decimalPart=cash_amount; //When float numbers are set to an integer number, only a multiple of ten is taken. The rest is not taken, this is what we want.

   if (decimalPart==cash_amount) //
   {
      return 0;
   }

   else   
   {
      printf("Withdrawable amount is: %d\n",decimalPart);
   }
}
