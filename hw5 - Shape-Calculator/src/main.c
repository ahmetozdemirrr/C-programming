#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14

enum Shapes
{
    Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder
};

enum Calculators
{
	Area=1,Perimeter,Volume
};

double my_absolute_value_function(float x,float y) //Üçgenin kenar kuralları için gereken mutlak değer fonksiyonunu yazıyoruz.
{
	float absoluteValue;
	
	if (x>y)
	{
		absoluteValue=(double)(x-y);
	}

	else
	{
		absoluteValue=(double)(y-x);
	}

    return (double)absoluteValue;	
}

int calc_triangle(int islem)
{
	float area,perimeter;
    float side1,side2,side3; //Üçgenin kenar uzunlukları.
    float s; //Üçgen alan hesabında kullanılacak olan değişken.
    int flag1=1,flag2=1; //Eğer girilen kenar uzunlukları üçgen tanımına uymuyorsa bu flaglar yardımıyla kullanıcıdan aynı değerler tekrar istenecek.
    int ret1,ret2,ret3;  //scanf'in return değerine eşitlenen bu değişkenlere bakarak kullanıcının harf ya da geçersiz karakter girip girmediğini kontrol ediyoruz.
    int FLAG; //return 1,2 ve 3'ün birlikte test edildiği flag.

    switch(islem)
    {
    	case Area:
    	    do
    	    {
               do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter three sides of Triangle:\n");
                    ret1 = scanf("%f",&side1);
                    ret2 = scanf("%f",&side2);
                    ret3 = scanf("%f",&side3);
                    FLAG=ret1+ret2+ret3;
                    s=((float)side1+(float)side2+(float)side3)/(float)2;
                    
                    if(FLAG!=3) //Eğer scanf fonksiyonu float tipinde 3 değer alamamışsa bu if bloğuna gir.
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.
                    }  
                } 
                while (FLAG!=3);

                if ((side1>0 && side2>0 && side3>0) && (side1>my_absolute_value_function(side2,side3)) && (side1)<(side2+side3) && (side2>my_absolute_value_function(side1,side3)) && (side2)<(side1+side3) && (side3>my_absolute_value_function(side1,side2)) && (side3)<(side1+side2) && (s>side1) && (s>side2) && (s>side3))
                {                   
                	area=sqrt((float)s*((float)s-(float)side1)*((float)s-(float)side2)*((float)s-(float)side3));
                	printf("Area of a TRIANGLE:%.2f\n",area);
                	flag1=0;
                }

                else
                {
                    printf("ERROR! Please enter a valid value.\n");
                }
    	    }
    	    while(flag1);
    	break;

    	case Perimeter:
    	    do
    	    {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter three sides of Triangle:\n");
                    ret1 = scanf("%f",&side1);
                    ret2 = scanf("%f",&side2);
                    ret3 = scanf("%f",&side3);
                    FLAG=ret1+ret2+ret3;
                    s=((float)side1+(float)side2+(float)side3)/(float)2;

                    if(FLAG!=3) //Eğer scanf fonksiyonu float tipinde 3 değer alamamışsa bu if bloğuna gir.
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.            
                    }  
                } 
                while (FLAG!=3);

    	    	if ((side1>0 && side2>0 && side3>0) && (side1>my_absolute_value_function(side2,side3)) && (side1)<(side2+side3) && (side2>my_absolute_value_function(side1,side3)) && (side2)<(side1+side3) && (side3>my_absolute_value_function(side1,side2)) && (side3)<(side1+side2) && (s>side1) && (s>side2) && (s>side3))
    	    	{                  
    	    		perimeter=((float)side1+(float)side2+(float)side3);
    	            printf("Perimeter of TRIANGLE:%.2f\n",perimeter);

    	            flag2=0;
    	    	}

    	    	else
                {
                	printf("ERROR! Please enter a valid value.\n");
                }
    	    }
    	    while(flag2);    
    	break;

    	case Volume:
    	    printf("ERROR! You cannot calculate the volume of triangle. Please try again.\n");
    	break;
    }
    return 0;
}

int calc_quadrilateral(int islem)
{
	float side1,side2,side3,side4; //Dikdörtgenin kenarlarının atanacağı değişkenler.
	float area, perimeter;
    float s; //Dikdörtgen alan hesabı için kullanılan değişken.
	int flag1=1,flag2=1; //Dikdörtgenin tanımına uymayan kenar uzunlukları girildiği zamanlar için kullanılan flaglar.
    int ret1,ret2,ret3,ret4; //scanf'in return değerine eşitlenen bu değişkenlere bakarak kullanıcının harf ya da geçersiz karakter girip girmediğini kontrol ediyoruz.
    int FLAG; //return 1,2,3 ve 4'ün birlikte test edildiği flag.

	switch(islem)
    {
    	case Area:
            do
            {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter four sides of Quadrilateral:\n");
                    ret1 = scanf("%f",&side1);
                    ret2 = scanf("%f",&side2);
                    ret3 = scanf("%f",&side3);
                    ret4 = scanf("%f",&side4);
                    FLAG=ret1+ret2+ret3+ret4;

                    if(FLAG!=4) //scanf 4 tane float değer alamamışsa bu if bloğuna gir.
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.
                    }  
                } 
                while (FLAG!=4);

            	if (side1>0 && side2>0 && side3>0 && side4>0) 
            	{
                    s=((float)side1+(float)side2+(float)side3+(float)side4)/(float)2;
            		area=sqrt(((float)s-(float)side1)*((float)s-(float)side2)*((float)s-(float)side3)*((float)s-(float)side4));
    	            printf("Area of Quadrilateral:%.2f\n",area);
    	            flag1=0;
            	}

            	else
            	{
            		printf("ERROR! Please enter a valid value.\n");
            	}
            }
            while(flag1);	    
    	break;

    	case Perimeter:
    	    do
    	    {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter four sides of Quadrilateral:\n");
                    ret1 = scanf("%f",&side1);
                    ret2 = scanf("%f",&side2);
                    ret3 = scanf("%f",&side3);
                    ret4 = scanf("%f",&side4);
                    FLAG=ret1+ret2+ret3+ret4;

                    if(FLAG!=4) //scanf 4 tane float değer alamamışsa bu if bloğuna gir.
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.         
                    }  
                } 
                while (FLAG!=4);

        	    if (side1>0 && side2>0 && side3>0 && side4>0)
        	    {
        	    	perimeter=((float)side1+(float)side2+(float)side3+(float)side4);
                    printf("Perimeter of Quadrilateral:%.2f \n",perimeter);
                    flag2=0;
        	    }

        	    else
            	{
            		printf("ERROR! Please enter a valid value.\n");
            	}    
    	    }
    	    while(flag2);       
    	break;

    	case Volume:
    	    printf("ERROR! You cannot calculate the volume of triangle. Please try again.\n");
    	break;
    }
    return 0;
}

int calc_circle(int islem)
{
	float radius; //Dairenin yarıçap uzunluğunu almak için kullanılan değişken.
	float area,perimeter;
	int flag1=1,flag2=1; //Dairenin yarıçap özelliklerinin sağlanmadığı durumlar için kullanılan flaglar.
    int ret1; //scanf'in return değerine eşitlenen bu değişkenlere bakarak kullanıcının harf ya da geçersiz karakter girip girmediğini kontrol ediyoruz.
    int FLAG;

    switch(islem)
    {
    	case Area:
    	    do 
    	    {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter radius of circle:\n");
                    ret1 = scanf("%f",&radius);
                    FLAG=ret1;

                    if(FLAG!=1) //Eğer scanf 1 tane float değer alamamışsa if bloğuna gir.
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.          
                    }  
                } 
                while (FLAG!=1);

                if (radius>0)
                {
              	    area=((float)PI*(float)radius*(float)radius);
                    printf("Area of Circle:%.2f\n",area);
                    flag1=0;
                }

                else
                {
                	printf("ERROR! Please enter a valid value.\n");
                }             
    	    }
    	    while(flag1);            
    	break;

    	case Perimeter:
    	    do
    	    {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter radius of circle:\n");
                    ret1 = scanf("%f",&radius);
                    FLAG=ret1;

                    if(FLAG!=1) //Eğer scanf 1 tane float değer alamamışsa if bloğuna gir.
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.          
                    }  
                } 
                while (FLAG!=1);

                if (radius>0)
                {
                	perimeter=((float)PI*(float)radius*(float)2);
                    printf("Perimeter of Circle:%.2f\n",perimeter);
                    flag2=0;
                }

                else
                {
                	printf("ERROR! Please enter a valid value.\n");
                }  	        
    	    }
    	    while(flag2);      
    	break;

    	case Volume:
    	    printf("ERROR! You cannot calculate the volume of triangle. Please try again.\n");
    	break;
    }
    return 0;
}

int calc_pyramid(int islem)
{
	int flag1=1,flag2=1,flag3=1; //Sayı dışında başka karakter girilen durumlarda kullanılacak flaglar.
	float baseArea,lateralArea,area,basePerimeter,volume;
    float side,height,l; //Alınacak kenar ve yükseklik değerleri.
    int ret1,ret2; //scanf'in return değerine eşitlenen bu değişkenlere bakarak kullanıcının harf ya da geçersiz karakter girip girmediğini kontrol ediyoruz.
    int FLAG;    

	switch(islem)
    {
    	case Area:
    	    do
    	    {
    	    	do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter the base side and slant height of a Pyramid:\n");
                    ret1 = scanf("%f",&side);
                    ret2 = scanf("%f",&height);
                    FLAG=ret1+ret2;

                    if(FLAG!=2)
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.         
                    }  
                } 
                while (FLAG!=2);

    	    	if (side>0 && height>0)
    	    	{
                    l=sqrt(((float)height*(float)height)+((float)side*(float)side/(float)4));
    	    		baseArea=((float)side*(float)side);
    	    		lateralArea=((float)2*(float)side*(float)l);
    	    		area=(float)baseArea+(float)lateralArea;

    	    		printf("Base Surface Area of a PYRAMID:%.2f\n",baseArea);
    	    		printf("Lateral Surface Area of a PYRAMID:%.2f\n",lateralArea);
    	    		printf("Surface Area of a PYRAMID:%.2f\n",area);
    	    		flag1=0;
    	    	}

    	    	else
    	    	{
    	    		printf("ERROR! Please enter a valid value.\n");
    	    	}
    	    }
    	    while(flag1);
    	break;

    	case Perimeter:
    	    do
    	    {
    	    	do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter the base side and slant height of a Pyramid:\n");
                    ret1 = scanf("%f",&side);
                    ret2 = scanf("%f",&height);
                    FLAG=ret1+ret2;

                    if(FLAG!=2)
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.           
                    }  
                } 
                while (FLAG!=2);

    	    	if (side>0 && height>0)
    	    	{
    	    		basePerimeter=((float)4*(float)side);
    	    		printf("Base Surface Perimeter of a PYRAMID:%.2f\n",basePerimeter);
    	    		flag2=0;
    	    	}

    	    	else
    	    	{
    	    		printf("ERROR! Please enter a valid value.\n");
    	    	}
    	    }
    	    while(flag2);
    	break;

    	case Volume:
    	    do
    	    {
    	    	do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter the base side and slant height of a Pyramid:\n");
                    ret1 = scanf("%f",&side);
                    ret2 = scanf("%f",&height);
                    FLAG=ret1+ret2;

                    if(FLAG!=2)
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.          
                    }  
                } 
                while (FLAG!=2);

    	    	if (side>0 && height>0)
    	    	{
    	    		volume=((float)side*(float)side*(float)height)/(float)3;
    	    		printf("Volume of a PYRAMID:%.2f\n",volume);
    	    		flag3=0;
    	    	}

    	    	else
    	    	{
    	    		printf("ERROR! Please enter a valid value.\n");
    	    	}
    	    }
    	    while(flag3);    	
    	break;
    }
    return 0;
}

int calc_cylinder(int islem)
{
	float baseArea,lateralArea,area,basePerimeter,volume;
	int flag1=1,flag2=1,flag3=1;
	float radius,height;
    int ret1,ret2;
    int FLAG;

	switch(islem)
    {
    	case Area:
    	    do
    	    {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter the base side and slant height of a Pyramid:\n");
                    ret1 = scanf("%f",&radius);
                    ret2 = scanf("%f",&height);
                    FLAG=ret1+ret2;

                    if(FLAG!=2)
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.         
                    }  
                } 
                while (FLAG!=2);

                if (radius>0 && height>0)
                {
                	baseArea=((float)PI*(float)radius*(float)radius);
                	lateralArea=((float)2*(float)PI*(float)radius*(float)height);
                	area=(((float)2*(float)PI*(float)radius))*(((float)radius+(float)height));

                	printf("Base Surface Area of a CYLINDER:%.2f\n",baseArea);
                	printf("Lateral Surface Area of a CYLINDER:%.2f\n",lateralArea);
                	printf("Surface Area of a CYLINDER:%.2f\n",area);
                	flag1=0;
                }

                else
                {
                	printf("ERROR! Please enter a valid value.\n");
                }
    	    }
    	    while(flag1);
    	break;

    	case Perimeter:
    	    do
    	    {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter the base side and slant height of a Pyramid:\n");
                    ret1 = scanf("%f",&radius);
                    ret2 = scanf("%f",&height);
                    FLAG=ret1+ret2;

                    if(FLAG!=2)
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.           
                    }  
                } 
                while (FLAG!=2);

                if (radius>0 && height>0)
                {
                    basePerimeter=((float)2*(float)PI*(float)radius);
                    printf("Base Surface Perimeter of a CYLINDER:%.2f\n",basePerimeter);

                	flag2=0;
                }

                else
                {
                	printf("ERROR! Please enter a valid value.\n");
                }
    	    }
    	    while(flag2);
    	break;

    	case Volume:
    	    do
    	    {
                do //Bu döngüde float veya integer dışında başka bir karakter girilmesi durumu kontrol ediliyor.
                {
                    printf("Please enter the base side and slant height of a Pyramid:\n");
                    ret1 = scanf("%f",&radius);
                    ret2 = scanf("%f",&height);
                    FLAG=ret1+ret2;

                    if(FLAG!=2)
                    {
                        printf("ERROR! Please enter a valid value.\n");
                        int c;
                        do 
                        {
                            c=getchar(); //Klavye bufferını boşalt.            
                        } 
                        while (c != '\n' && c != EOF); //İki karakter girildiiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.          
                    }  
                } 
                while (FLAG!=2);

                if (radius>0 && height>0)
                {
                	volume=((float)PI*(float)radius*(float)radius*(float)height);
                	printf("Volume of a CYLINDER:%.2f\n",volume);
                	flag3=0;
                }

                else
                {
                	printf("ERROR! Please enter a valid value.\n");
                }
    	    }
    	    while(flag3);   	
    	break;
    }
    return 0;
}

int select_shape()
{
	enum Shapes select1;
    int FLAG;

	printf("Select a shape to calculate:\n");
	printf("----------------------------\n");
	printf("1. Triangle\n");
	printf("2. Quadrilateral\n");
	printf("3. Circle\n");
	printf("4. Pyramid\n");
	printf("5. Cylinder\n");
	printf("0. Exit\n");
	printf("----------------------------\n");
	printf("Input:");

    do
    {   
        FLAG = scanf("%u",&select1);

        if(FLAG!=1)
        {
            printf("ERROR! Please enter a valid value.\n");
            int c;
            do 
            {
                c=getchar(); //Klavye bufferını boşalt.            
            } 
            while (c != '\n' && c != EOF); //İki karakter girildiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.                 
        }  
    } 
    while (FLAG!=1);
    
	return select1;
}

int select_calc()
{
	enum Calculators select2;
    int ret1,FLAG;

	printf("Select calculator:\n");
	printf("----------------------------\n");
    printf("1. Area\n");
    printf("2. Perimeter\n");
    printf("3. Volume\n");
    printf("0. Exit\n");
	printf("----------------------------\n");
	printf("Input:");

    do
    {   
        FLAG = scanf("%u",&select2);

        if(FLAG!=1)
        {
            printf("ERROR! Please enter a valid value.\n");
            int c;
            do 
            {
                c=getchar(); //Klavye bufferını boşalt.            
            } 
            while (c != '\n' && c != EOF); //İki karakter girildiğinde tek bir kere hata vermesi için bu şartı koyuyoruz. Örneğin 'aa' girilirse bir kere hata kodunu yazsın.                
        }  
    } 
    while (FLAG!=1);

	return select2;
}

int calculate(int (*select_shape)(),int (*select_calc)())
{
	int shape,process;
    
    do 
    {
    	shape=select_shape();

    	while(shape<0 || shape>5)
    	{
    		printf("ERROR! Please enter a valid value.\n");
    		shape=select_shape();
    	}

    	if (shape==0)
    	{
    		break;
    	}

        process=select_calc();

        while(process<0 || process>3)
    	{
    		printf("ERROR! Please enter a valid value.\n");
    		process=select_calc();
    	}

    	if (process==0)
        {
        	break;
        }
        
        switch(shape)
        {
    	    case Triangle:
                calc_triangle(process);
            break;

   	        case Quadrilateral:
    	        calc_quadrilateral(process);
    	    break;

            case Circle: 
    	        calc_circle(process);
            break;

    	    case Pyramid:
    	        calc_pyramid(process);
    	    break;

    	    case Cylinder:
    	        calc_cylinder(process);
    	    break;
        }
    }
    while(1);  

    return 0;
}

int main(int argc, const char *argv[])
{
	printf("\nWelcome to the geometric calculator!\n\n");	
	calculate(select_shape, select_calc);
	return 0;
}

/*NOT: Kodun neredeyse her fonksiyonunda kullanılan 'ret=scanf("%d",side);'gibi 
  ifadeler scanf fonksiyonunun return değerinden faydalanılarak kurulmuştur. 
  scanf fonskiyonu input olarak aldığı değişken sayısı kadar return değeri verir. 
  Kurduğumuz ifadeler de istenilen sayıda input alınmama durumu üzerine şekillendirilmişir.*/
