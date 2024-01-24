#include <stdio.h>
#include <stdlib.h>
#include <math.h> //We include math.h library for the sqrt() function.
#include "util.h"

int main() 
{
    printf("\n\n");

    int menuSelection; //The variable to which the selected menu will be assigned.

    printf("||^^^^^^^^^Please Select a Menu^^^^^^^^^||\n\n"); //We create our main menu here and divide the body of our main function into three parts as if, else if and else according to the menu selected by the user. 
    printf("-For first menu enter (1)\n");
    printf("-For second menu enter (2)\n");
    printf("-For third menu enter (3)\n");
    scanf("%d",&menuSelection);

    if (menuSelection==1)
    {
        double Pl,Pw;

        printf("Enter Pl values:");
        scanf("%lf",&Pl);

        printf("Enter Pw values:");
        scanf("%lf",&Pw);

        char character1 = dt1a(Pl,Pw); //The variable to which the return value from the first tree will be assigned.
        char character2 = dt1b(Pl,Pw); //The variable to which the return value from the second tree will be assigned.

        if (character1=='a')
        {
            printf("\nSetosa\n");
        }

        else if (character1=='b')
        {
            printf("Versicolor\n");
        }

        else if (character1=='c')
        {
            printf("Virginica\n");
        }

        if (character1!=character2) //If the result of the two trees is the same, we make it print once in this way.
        {
            if (character2=='a')
            {
                printf("Setosa\n");
            }

            else if (character2=='b')
            {
                printf("Versicolor\n");
            }

            else if (character2=='c')
            {
                printf("Virginica\n");
            }
        } 
    
    }

    else if (menuSelection==2)
    {
        double x1,x2,x3;
        double result1,result2;
        int x4,x5;
    
        printf("Enter a real number:\n");
        scanf("%lf",&x1);

        printf("Enter a real number:\n");
        scanf("%lf",&x2);

        printf("Enter a real number:\n");
        scanf("%lf",&x3);
  
        printf("Enter a binary number (1 or 0):\n");
        scanf("%d",&x4);

        printf("Enter a binary number (1 or 0):\n");
        scanf("%d",&x5);
  
        result1=dt2a(x1,x2,x3,x4,x5); //We assign function results to these values.
        result2=dt2b(x1,x2,x3,x4,x5);

        if (result1>result2 && ((double)result1-(double)result2)<=CLOSE_ENOUGH)
        {
            printf("Result of both function: %.3lf\n",((double)result1 + (double)result2)/(double)2);
        }

        else if (result2>result1 && ((double)result2-(double)result1)<=CLOSE_ENOUGH)
        {
            printf("Result of both function: %.3lf\n",((double)result1 + (double)result2)/(double)2);
        }

        else
        {
            if (result1==1.4 || result1==11) //We set this condition do that the + sign appears when the results 1.4 and 11 are received.
            {
                printf("Result of first tree: +%.2lf\n",result1);
                printf("Result of second tree: %.2lf\n",result2);
            }

            else
            {
                printf("Result of first tree: %.2lf\n",result1);
                printf("Result of second tree: %.2lf\n",result2);
            }
        }        

    }

    else
    {
        double real1,real2;
        int binary1,categorical1,categorical2;

        printf("Enter your gender. For male(1) and for female(0):\n");
        scanf("%d",&binary1);

        printf("Enter your weight (kg):\n");
        scanf("%lf",&real1);

        printf("Enter your height (cm):\n");
        scanf("%lf",&real2);

        printf("*******Section1*******\n\n");
        printf("Days you want to exercise, please choose.\n");
        printf("For Monday enter (1).\n");
        printf("For Tuesday enter (2).\n");
        printf("For Wednesday enter (3).\n");
        printf("For Thursday enter (4).\n");
        printf("For Friday enter (5).\n");
        printf("For Saturday enter (6).\n");
        printf("For Sunday enter (7).\n");
        scanf("%d",&categorical1);

        printf("*******Section2*******\n\n");
        printf("Your blood type, please select:\n");
        printf("For Arh+ (1)\n");
        printf("For Arh- (2)\n");
        printf("For Brh+ (3)\n");
        printf("For Brh- (4)\n");
        printf("For 0rh- (5)\n");
        scanf("%d",&categorical2);

        int exerciseCase1=dt3a(binary1,categorical1,categorical2,real1,real2);
        int exerciseCase2=dt3b(binary1,categorical1,categorical2,real1,real2);

        if (exerciseCase1==1 && exerciseCase2==1) //If the result of the two trees is the same, we make it print once in this way.
        {
            printf("Your information is available for our gym.\n");
        }

        else
        {
            printf("Your information is not available for our gym.\n");
        }
    }   

    return 0;
}

