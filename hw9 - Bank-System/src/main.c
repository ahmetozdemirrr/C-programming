#include<stdio.h>
#include<stdlib.h>
#include<string.h>

union Person //Person unionumuzu oluşturuyoruz.
{
	char name[50];
	char address[50];
	int phone;
};

union Loan  //Loan unionumuzu oluşturuyoruz.
{
	float amount;
	float interestRate;
	int period;
};

struct BankAccount
{
	union Person Customer;
	union Loan Loans[3];
};


float calculateLoan(float amount, int period, float interestRate) //Kredi hesaplama fonksiyonu.
{
    if (period!=0)
    {
	    return (amount*(1+interestRate))*calculateLoan(1, period-1, interestRate); //Fonksiyonu recursive bir şekilde tekrar çağırıyoruz.
    }   

    else
    {
    	return amount;
    } 
}

void listCustomers(struct BankAccount custom)  //Müşteri bilgilerinin listelendiği fonksiyon.
{
    int i=1,period; //Kullanıcı ID'si için kullanılacak değişken.
    char x;  //Dosyanın boş olma durumu için kullanılacak değişken.
    float amount,interestRate,loan=0,totalLoan=0; //Kullanıcı loans bilgilerini basmak için kullanılan değişkenler.
    char name[50],custName[50]; //isim kontrolleri için kullanılan stringler.

    FILE *fp;   //Dosyaya ait pointerı tanımlıyoruz.
    FILE *file;

    fp=fopen("customers.txt","a+");  //Dosyayı okuma modunda açıyoruz.
    file=fopen("loan.txt","a+");

    if (fscanf(fp,"%c",&x)==-1)  //Eğer dosya bu anda boşsa bu uyarı mesajı verilecek.
    {
    	printf("\n'customers.txt' file is null!\n");
    }
    
    else  //Dosya boş değilse istenilen bilgileri terminale bas.
    {	
    	while(!feof(fp))  //Bu döngü dosyayı sona kadar kontrol edip istenilen bilgileri terminale basacak.
	    {
	        printf("Customer ID: %d\n",i);

	        fscanf(fp," %[^\n]%*c",custName);
	        printf("Customer Name: %s\n",custName);

	        fscanf(fp,"%d",&custom.Customer.phone);
	        printf("Customer Phone: %d\n",custom.Customer.phone);

	        fscanf(fp," %[^\n]%*c",custom.Customer.address);
	        printf("Customer Address: %s\n",custom.Customer.address);
            
            /* Kullanıcının loans bilgisini bastıracağımız döngü*/

            printf("Loans [  ");
			while(!feof(file))
			{
				fscanf(file," %[^\n]%*c",name);	
				
				if(strcmp(name,custName) == 0) //İki isim aynıysa gir ve değerleri al.
				{
					fscanf(file,"%f",&amount);
					fscanf(file,"%d",&period);
					fscanf(file,"%f",&interestRate);
					
					loan = calculateLoan(amount,period,interestRate); //calculateLoan fonksiyonunu çağırıyoruz.
					totalLoan += loan;
					printf("%f + ",loan);					
		        }
		
	        }
	        printf("\b\b ] => %f\n",totalLoan); //En sondaki + işaretinin silinmesi için \b koyuyoruz.
			loan=0;
			totalLoan=0;

  	        printf("\n");
	        i++; //Her seferinde i'yi arttırıyoruz.
	        fseek(file,0,SEEK_SET); //Loan.txt imlecini başa alıyoruz.
	    }
	}    
    fclose(fp);  //Dosyaları kapatıyoruz.
    fclose(file);
}

void addCustomers(struct BankAccount custom)  //Sisteme müşteri eklemek için kullanılacak fonksiyon.
{    
	int flag=1; //Maksimum 50 kullanıcı girilmesi için bu değişkeni kullanacağız.

    FILE *file;  //Dosyaya ait pointerı tanımlıyoruz.
    file=fopen("customers.txt","a+");  //Dosyayı "a" modunda açıyoruz.
    
    /*Aşağıdaki kısımda dosyaya yazdırılacak bilgileri kullanıcıdan alıyoruz.*/
    
    while(!feof(file))
    {
    	fscanf(file,"%s",custom.Customer.name);
    	fscanf(file,"%d",&custom.Customer.phone);
    	fscanf(file,"%s",custom.Customer.address);
    	flag++;
    }
    	
    if (flag<=50)
	{
		printf("\n\nPlease Enter Your Name: ");
	    scanf(" %[^\n]%*c",custom.Customer.name);
	    fprintf(file,"\n%s",custom.Customer.name);

	    printf("Please Enter Your Phone Number: ");
	    scanf("%d",&custom.Customer.phone);
	    fprintf(file,"\n%d",custom.Customer.phone);

	    printf("Please Enter Your Address: ");
	    scanf(" %[^\n]%*c",custom.Customer.address);
	    fprintf(file,"\n%s",custom.Customer.address);
	}	
	
	else  //50 kullanıcıyı aşılmışsa uyarı mesajı veriyoruz.
	{
		printf("\nMaximum Customer Limit!\n");
	}
    fclose(file); //Dosyayı kapatıyoruz.
}

void newLoan(struct BankAccount custom)  //Kredi almak isteyen müşteriler için çalışacak fonksiyon.
{	
	int flagName=0;        //Herhangi bir müşterinin 3 krediden fazla almamasını kontrol edecek değişken.
    char name[50];         //Kullanıcının girdiği isimin atanacağı string array.
    char controlName[50];  //Kredi alacak kişinin bankaya ait bir müşteri olup olmadığının kontrol edileceği değişken.
    int controlFlag=0;     //Eğer kredi almak isteyen kişi banka müşterisi değilse bu bayrak sayesinde uyarı verilecek.

    /*Her iki dosya için iki pointer tanımlıyoruz.*/
    /*ve dosyaları a+ modunda açıyoruz.*/

    FILE *file;
    FILE *fp;

    file=fopen("loan.txt","a+");
    fp=fopen("customers.txt","a+");

    printf("Please Enter Your Name: ");
    scanf(" %[^\n]%*c",custom.Customer.name); //Kullanıcıdan ismini alıyoruz.
    
    while(!feof(fp))
    {
    	fscanf(fp," %[^\n]%*c",controlName);

    	if (strcmp(custom.Customer.name,controlName)==0) //Eğer girilen isim customers dosyasında mevcut değilse uyarı ver.
		{    
			do 
		    {
		    	fscanf(file," %[^\n]%*c",name);
		        
		        if (strcmp(custom.Customer.name,name)==0) //Kullanıcının alacağı her kredi için flagName birer artar.
		        {
		        	flagName++;
		        }
		    }
		    while(!feof(file));
		    
		    if (flagName<3) //Kullanıcı kredi almaya uygunsa girilen bilgileri dosyaya yazdır.
		    {
		    	fprintf(file,"\n%s",custom.Customer.name);

			    printf("Please Enter Money Amount: ");
			    scanf("%f",&custom.Loans[0].amount);
			    fprintf(file,"\n%.4f",custom.Loans[0].amount);

			    printf("Please Enter Period: ");
			    scanf("%d",&custom.Loans[0].period);
			    fprintf(file,"\n%d",custom.Loans[0].period);

			    printf("Please Enter Interest Rate: ");
			    scanf("%f",&custom.Loans[0].interestRate);
			    fprintf(file,"\n%.4f",custom.Loans[0].interestRate);
		    }

		    else  //flagName 3 veya 3'ten büyükse bu uyarıyı ver.
		    {
		    	printf("\nMaximum Credit Limit!\n");
		    }
		    controlFlag=1;
		}

    }
    fclose(file);
    fclose(fp);  
    
    if (!controlFlag) //Eğer girilen isimde bir kullanıcı yoksa uyarı mesajı bastırıyoruz.
    {
    	printf("There is no customer name '%s' in the records.\n",custom.Customer.name);
    }
}

void getReport(struct BankAccount custom, float credit[])
{
	char name[50],custName[50],custAddress[50];
	int i=0,controlFlag2=0,controlFlag3=0,flag=0,period[3],phoneNumber,selection;
    float credi[3]={0};
    
    /* Dosya pointerlarını tanımlıyoruz.*/

    FILE *file;
    FILE *fp;

    file=fopen("loan.txt","a+");
    fp=fopen("customers.txt","a+");
    
	printf("\t1. Customer Information\n");
	printf("\t2. Credit Information\n");
	printf("\t3. Return to Main Menu\n");
	scanf("%d",&selection);

	switch(selection)
	{
		case 1:

		    printf("Please Enter Your Name: ");
		    scanf(" %[^\n]%*c",custName);

		    do 
		    {
		    	fscanf(fp," %[^\n]%*c",custom.Customer.name);
		        
		        if (strcmp(custom.Customer.name,custName)==0) //Girilen isim dosyada varsa gir.
		        {
		        	fscanf(fp,"%d",&phoneNumber);
		        	fscanf(fp," %[^\n]%*c",custAddress);
                   
                    /*Bilgileri bas*/
		        	printf("Customer Name: %s\n",custName);
		        	printf("Customer Phone Number: %d\n",phoneNumber);
		        	printf("Customer Address: %s\n\n",custAddress);	

		        	controlFlag3=1;	//Girilen ismin bulunamaması durumu için bu flag'de ayarlama yapıyoruz.	            
		        }     
		    }
		    while(!feof(fp));

		    if (!controlFlag3) //Girilen isim dosyanın sonuna kadar bulunamamışsa gir.
		    {
		    	printf("\nThere is no customer name '%s' in the records.\n\n",custName);
		    }    	    				    
		break;

		case 2:

		    printf("Please Enter Your Name: ");
		    scanf(" %[^\n]%*c",name);		    
			
			do 
		    {
		    	fscanf(file," %[^\n]%*c",custom.Customer.name);
		        
		        if (strcmp(custom.Customer.name,name)==0) //Girilen isim dosyada varsa gir.
		        {
		        	/*Değerleri al ve calculateloan fonksiyonuna gönder*/

                    fscanf(file,"%f",&custom.Loans[0].amount);
		        	fscanf(file,"%d",&custom.Loans[1].period);
		        	fscanf(file,"%f",&custom.Loans[2].interestRate);
		            
		            period[i]=custom.Loans[1].period;
		            credi[i]=calculateLoan(custom.Loans[0].amount, custom.Loans[1].period, custom.Loans[2].interestRate);
		            
		            i++;
		            controlFlag2=1;
		        }			        
		    }
		    while(!feof(file));

		    if (!controlFlag2)  //Girilen isim dosyada yoksa uyarı ver.
	        {
                printf("\nThere is no customer name '%s' in the records.\n\n",name);
	        }
            
            if (controlFlag2==1)  //Girilen isim dosyada varsa 3 krediden birini seçtirip ona göre kredi bilgilerini basıyoruz.
            {
            	int select;
                printf("\nSelect a Credit (1-2-3)\n");
                scanf("%d",&select);

                if (select==1)
                {
                	for (int i = 0; i < period[0]; ++i)
		            {
		            	credit[i]=(float)credi[0]/(period[0]);
		            } 

		            printf("\nTotal Credit Value: %f\n\n",credi[0]);

				    for (int j = 0; j < 12; ++j)
				    {
				    	printf("  %d. Month Installment = %f\n",j+1,credit[j]);
				    }
				    printf("\n\n");
                }

                else if (select==2)
                {
                	for (int i = 0; i < period[1]; ++i)
		            {
		            	credit[i]=(float)credi[1]/(period[1]);
		            }

		            printf("\nTotal Credit Value: %f\n\n",credi[1]);

				    for (int j = 0; j < 12; ++j)
				    {
				    	printf("  %d. Month Installment = %f\n",j+1,credit[j]);
				    }
				    printf("\n\n");
                }

                else if (select==3)
                {
                	for (int i = 0; i < period[2]; ++i)
		            {
		            	credit[i]=(float)credi[2]/(period[2]);
		            }

		            printf("\nTotal Credit Value: %f\n\n",credi[2]);

				    for (int j = 0; j < 12; ++j)
				    {
				    	printf("  %d. Month Installment = %f\n",j+1,credit[j]);
				    }
				    printf("\n\n");
                }

                else
                {
                	printf("\nPlease Enter a Valid Value!\n");
                }
            }              
		break;

		case 3:
		break;
	}

    fclose(file);
    fclose(fp);
}

int main(int argc, char const *argv[])
{
	int selection;  //Menü için kullanacağımız değişken.
    struct BankAccount custom;

    printf("\n=====================================\n");
	printf("Welcome to the Bank Management System\n");
	printf("=====================================\n");

    do
    {   
    	float credit[12]={0}; //4. Menü her çalıştırıldığında array içindeki değerlerin sıfırlanması için burda tanımlıyoruz.

		printf("\n1. List All Customers\n");
		printf("2. Add New Customers\n");
		printf("3. New Loan Application\n");
		printf("4. Report Menu\n");
		printf("5. Exit System\n\n");
		scanf("%d",&selection);

        switch(selection)
        {
	        case 1:

                listCustomers(custom);
	        break;

	        case 2: 

	            addCustomers(custom);
	        break;

	        case 3:

	            newLoan(custom);
	        break;

	        case 4:

                getReport(custom,credit);
	        break;
        }
    }
    while(selection!=5);

	return 0;
}                           	