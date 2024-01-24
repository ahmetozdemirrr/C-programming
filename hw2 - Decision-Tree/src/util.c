#include <stdio.h>
#include <math.h>
#include "util.h"


char dt1a(double PedalLength,double PedalWight)
{
    char a,b,c;

    if (PedalLength<2.45)
    {
        return 'a'; //For Setosa.
    }

    else
    {
        if (PedalWight<1.75)
        {
            if (PedalLength<4.95)
            {
                if (PedalWight<1.65)
                {
                    return 'b'; //For Versicolor.
                }

                else
                {
                    return 'c'; //For Virginica.
                }
            }
            
            else
            {
                return 'c';
            }
        }

        else
        {
            return 'c';
        }
    }

}

char dt1b(double PedalLength,double PedalWight)
{
    char a,b,c;

    if (PedalLength<2.55)
    {
        return 'a'; //For setosa.
    }

    else
    {
        if (PedalWight<1.69)
        {
            if (PedalLength<4.85)
            {
                return 'b'; //For versicolor.
            }

            else
            {
                return 'c'; //For virginica.
            }
        }

        else
        {
            return 'c';
        }
    }
}

double dt2a(double x1,double x2,double x3,int x4,int x5)
{

    if (x1<31.5)
    {
        if (x2>-2.5)
        {
            return 5.0;
        }

        else if (x2-0.1 <= x1 && x1<=x2+0.1)
        {
            return 2.1;
        }

        else
        {
            return -1.1;
        }

    }

    else if (x3>=-1 && x3<=2)
    {
        return 1.4;
    }

    else if (x4&&x5)
    {
        return -2.23;
    }

    else
    {
        return 11.0;
    }
}

double dt2b(double x1,double x2,double x3,int x4,int x5)
{
   double kok=sqrt(2); //Here we calculate the root two expression at the last node.

    if (x1>12 && x1<22)
    {
        if (x3>(float)5/(float)3) //We do type casting so that the result is not an integer.
        {
            return -2.0;
        }

        else if (x1-0.1<=x3 && x3<=x1+0.1)
        {
            return 1.01;
        }

        else
        {
            return -8;
        }
    }

    else if (x4 && x5)
    {
        return -1;
    }

    else if (x2>=-1 && x2<=2)
    {
        return (float)-1/(float)7; //We do type casting so that the result is not an integer.
    }

    else
    {
        return (double)kok/(double)3; //We do type casting so that the result is not an integer.
    }
}


int dt3a(int binary,int categorical1,int categorical2,double weight,double height)
{

    if (binary) //We check whether it's a male or female in the first node.
    {
        if (categorical2!=5) //If the blood group is 0rh-, we do not accept them for gym.
        {
            if (categorical1!=6 || categorical1!=7) //We don't accept customers who want to come on weekends, as it is closed.
            {
                if (weight>60 && height>160) //We make appropriate weight and height checks.
                {
                    return 1;
                }

                else if (weight<60 && height>170) //We make appropriate weight and height checks.
                {
                    return 1;
                }

                else if (weight<50 && height>175) //We make appropriate weight and height checks.
                {
                    return 1;
                }

                else
                {
                    return 0;
                }            
            }

            else
            {
                return 0;
            }  
        }

    }

    else
    {
        if (categorical2!=5) //If the blood group is 0rh-, we do not accept them for gym.
        {
            if (categorical1!=6 || categorical1!=7) //We don't accept customers who want to come on weekends, as it is closed.
            {
                if (weight>50 && height>155) //We make appropriate weight and height checks.
                {
                    return 1;
                }

                else if (weight<45 && height>165) //We make appropriate weight and height checks. 
                {
                    return 1;
                }

                else if (weight<40 && height>170) //We make appropriate weight and height checks.
                {
                    return 1;
                }

                else
                {
                    return 0;
                }            
            }

            else
            {
                return 0;
            }  
        }
    }
}

int dt3b(int binary,int categorical1,int categorical2,double weight,double height)
{
    if (binary)
    {
        if (weight<35 || weight>100) //We make appropriate weight and height checks.
        {
            return 0;
        }

        else if (height<120 || height>200) //We make appropriate weight and height checks.
        {
            return 0;
        }

        else
        {
            if (categorical1!=6 || categorical1!=7) //We don't accept customers who want to come on weekends, as it is closed.
            {
                if (categorical2==5) //If the blood group is 0rh-, we do not accept them for gym.
                {
                    return 0;
                }

                else
                {
                    return 1;
                }
            }

            else
            {
                return 0;
            }
        }
    }

    else
    {
        if (weight<30 || weight>95) //We make appropriate weight and height checks.
        {
            return 0;
        }

        else if (height<110 || height>190) //We make appropriate weight and height checks.
        {
            return 0;
        }

        else
        {
            if (categorical1!=6 || categorical1!=7) //We don't accept customers who want to come on weekends, as it is closed.
            {
                if (categorical2==5) //If the blood group is 0rh-, we do not accept them for gym.
                {
                    return 0;
                }

                else
                {
                    return 1;
                }
            }

            else
            {
                return 0;    
            }
        }
    }
}