/******************************************************************************

                            Nurlan Umetov
						 Week 4 Lab Exercise

*******************************************************************************/

#include <stdio.h> 
#include <math.h>
int factorial(int n){
	int i;
    for( i = n - 1; i > 0; i--)
        n *= i;
    return n;
}
int main(){
    
printf("==========================================\n");
printf("==              TASK 1:                 ==\n");
printf("==========================================\n");

printf("Please provide the number: ");
int num;
scanf("%i", &num);
do{
    printf("The factorial of %i is: %i\n", num, factorial(num));
    printf("Please provide the number: ");
    scanf("%i", &num);
}while(num > 0);
printf("Done.\n");

printf("==========================================\n");
printf("==              TASK 2:                 ==\n");
printf("==========================================\n");

printf("Please	provide	an	integer number:");
	int i = 0, j, k = 1, height;
	scanf("%i", &height);
	while(i < height){
		j = 1;
		while(j < height - i)
		{
		    			printf(" ");
		j++;}
		j = 0;
		while(j <= i){
		                printf("%i ", k);
		j++;}
		k++;
		i++;
		printf("\n");
	}
	
printf("==========================================\n");
printf("==              TASK 3:                 ==\n");
printf("==========================================\n");

int a, b;
printf("please provide two integers: ");
scanf("%i%i", &a, &b);
while(a != 0 && b != 0)
{
    if(a == b)
        printf("%i and %i are equal\n", a, b);
    else
        printf("%i and %i are not equal\n", a, b);
    printf("please provide two integers: ");
    scanf("%i%i", &a, &b);
}
printf("Done.\n");	
printf("==========================================\n");
printf("==              TASK 4:                 ==\n");
printf("==========================================\n");	
int v1 = -1, v2 = -1;
printf("Please provide a Cost Price: ");
scanf("%i", &v1);
do{
    if(v1 < 0){
        printf("The value is invalid please provide again.\n");
        printf("Please provide a Cost Price: ");
        scanf("%i", &v1);}
}while(v1 < 0);
printf("Please provide a Selling Price: ");
scanf("%i", &v2);
do{
    if(v2 < 0){
        printf("The value is invalid please provide again.\n");
        printf("Please provide a Selling Price: ");
        scanf("%i", &v2);}
}while(v2 < 0);	
if(v1 > v2)
    printf("Your loss amount: %i", v1 - v2);
else
    printf("Your profit amount: %i", v2 - v1);
return 0;
}
