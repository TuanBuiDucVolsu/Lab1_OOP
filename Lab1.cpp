#include <iostream>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
using namespace std;
struct state                                             // Создать структуру 
{
char country[50];
char capital[50];
char government[50];
char language[50];
char religion[50];
char continent[30];
float area;
int population;

}; 
const int N = 5;
typedef struct state cty; 

void input(cty a[],int N);                                  
void output(cty a[],int N);
int main(int argc, char** argv) {
	int i;
	cty ct[N];
	input(ct,N);
	output(ct,N);
	
	char tmp[15];                             // Рассчитать суммарную площадь и население государств Северной Америки                                 
        printf("\n+Enter the continent: ");   
        gets(tmp);  
        printf("\n%-15s %-15s \n","Sum Area","Sum Population ");
        float sumarea = 0;
        int sumpop = 0;
        for (i = 0; i < N; i++)
	{
        if (strcmp(ct[i].continent , tmp) == 0 )                    
	    {
	    	sumarea += ct[i].area;
	    	sumpop += ct[i].population;  
        }
        }
         printf("\n%-15.2f %-15d \n",sumarea,sumpop);
    
         char temp[15];                                  //Вывести на экран название и столицу самого крупного по численности населения испано-язычного государства
         printf("\n+Enter the language: ");
         gets(temp);
         printf("\nName and capital of the largest Spanish-speaking state in terms of population : \n");
         printf("\n%-15s %-15s \n","Country","Capital");
         int max = ct[0].population ;
         int j = 0;
         for(i = 1; i <= N; i++)
         {
           if(strcmp(ct[i].language,temp) == 0)
    	 {
    		if(max < ct[i].population)
    		{
    		  max = ct[i].population;
    		  j = i;
		}
	  }
	  }
	  printf("\n%-15s  %-15s\n",ct[j].country,ct[j].capital);
	  return 0;
}
void input(cty a[],int N)                                        // Введите данные с клавиатуры
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("\nEnter state number %d \n",i+1);
		printf("\n +Country : ");
		SetConsoleCP(1000);
		gets(a[i].country);
		
		
		printf("\n +Capital : ");
                SetConsoleCP(1251);
                gets(a[i].capital);
       
        
		printf("\n +Government : ");
		gets(a[i].government);
	
		
		printf("\n +Language : ");
		gets(a[i].language);
		
		printf("\n +Religion : ");
		gets(a[i].religion);
		
		printf("\n +Continent : ");
		gets(a[i].continent);
		
		printf("\n +Area : ");
		scanf("%f",&a[i].area);
		getchar();
		
		printf("\n +Population : ");
		scanf("%d",&a[i].population);
		getchar();
	}
}

void output(cty a[],int N)                       // Вывод данных
{
	int i,j;
	cty temp;
	for(i = 0 ; i < N ; i++)
        for( j = i+1 ; j <= N ; j++)
            if(strcmp(a[i].country ,a[j].country)>0)          
            {   
	            temp = a[i] ;
                a[i] = a[j] ;
                a[j] = temp;
            }
            
    printf("\n%-15s %-15s %-10s %-15s %-15s %-15s %-10s %-10s"," Country","Capital","Government","Language", "Religion","Continent","Area","Population");
    for(i = 0;i < N;i++)
    {
    	printf("\n %-15s %-15s %-10s %-15s %-15s %-15s %-15.1f %-15d ",a[i].country,a[i].capital,a[i].government,a[i].language,a[i].religion,a[i].continent,a[i].area,a[i].population);
    }
}
