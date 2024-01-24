#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
     *n3= n1*n2;
     *d3= d1*d2;
     fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
     *n3= n1*d2;
     *d3= n2*d1;
     fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {

    int gecici1,gecici2;
    gecici1 = *n;
    gecici2 = *d;
    
    if(gecici1<0)
    {
       gecici1 *= -1;
    }
    
    if(gecici2<0)
    {
       gecici2 *= -1;
    }
    
    int i=0,buyuksayi,ebob;
    
    while((i<=gecici1) && (i<=gecici2))
    {
       i++;
       
       if((gecici1%i==0)&&(gecici2%i==0))
       {
         ebob=i;
       }    
    }
    
     *n/=ebob;
     *d/=ebob;  
   
} /* end fraction_div */
