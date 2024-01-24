#include<stdio.h>
#include<string.h>
#include "utils.h"

int main(int argc, const char *argv[])
{
   int x,y,z; //We get three number from the user. For first function.
   int f_i;  //divisorNumber will be the variable to which the desired result will be assigned.
   int n; //The variables to which the divisor in the desired order will be assigned. For second function.
   int nthDivisor; //We assign the divisor in the desired order to this variable.
   
   printf("\n\n-----------------------------PART 1-----------------------------\n\n");

   printf("Enter the first integer:\n");
   scanf("%d",&x);
   printf("Enter the second integer: \n");
   scanf("%d",&y);
   printf("Enter the divisor: \n");
   scanf("%d",&z);
   
   f_i=find_divisible(x,y,z);

   if(f_i==-1) 
   {
      printf("There is not any integer between %d and %d can be divided by %d.\n",x,y,z);
   }

   else
   {
      printf("The first integer between %d and %d divided by %d is %d.\n\n",x,y,z,f_i);  //If there is no divisible number in the specified range,we put both in the same else so that it does not want the next divisor.
      printf("Enter the number how many next:");
      printf("\n");
      scanf("%d",&n); 

      nthDivisor=find_nth_divisible(n,f_i,z);

      if(nthDivisor<y) //We don't print if the value found is greater than the upper limit.
      {
         printf("The %d. integer between %d and %d divided by %d is %d\n\n",n+1,x,y,z,nthDivisor);
      }   
   
      else if(f_i!=-1)
      {
         printf("No possible to find Nth divisible between %d and %d divided by %d.\n\n",x,y,z);
      }
   }

   
   
   printf("\n\n-----------------------------PART 2-----------------------------\n\n");

   char identity_number[11]; //The identity number the user wants to create.
   char kimlik[11]; //The variable to which the identity number is assigned to be compared with the password read from the file.
   float withdraw; //The amount of money the user wants to withdraw.
   int password; //The password the user wants to create.
   int valid; //The variable to which the value returned by the validate_identity_number function will be assigned.
   int sifre; //The variable to which the login password is assigned to be compared with the password read from the file.
   int flag;  //The variable to which the value returned by the check_login function will be assigned.

   printf("Enter your identity number:");
   printf("\n");
   scanf("%s",identity_number);
   printf("Enter your password:");
   scanf("%d",&password);

   valid=validate_identity_number(identity_number);

   if (valid==1) //We call (create_customer),(check_login) and (withdrawable_amount) functions inside this if block because if the condition in the if is not met, the other values will be null.
   {
      create_customer(identity_number,password);

      printf("\n\n-----------------------------PART 3-----------------------------\n\n");
      
      printf("Enter your identity number:\n");
      scanf("%s",kimlik);
      printf("Enter your password:\n");
      scanf("%d",&sifre);

      flag=check_login(kimlik,sifre);
      
      if (flag==0)
      {
         printf("Enter your withdraw amount:\n");
         scanf("%f",&withdraw);

         int controlWithdraw = withdrawable_amount(withdraw);

         if (controlWithdraw==0)
         {
            printf("Withdrawal is succesfull.\n");
         }
      }

      else
      {
         printf("Invalid identity number or password.\n");
      }
   }

   else
   {
      printf("Invalid identity number.\n");
   }

   

   return 0;
}

