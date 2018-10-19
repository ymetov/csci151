#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char Gender;
	int Adult;
	int Weight;
	int Height;
	int Dob;
	int Mob;
	int Yob;
	int Age;
}patient;



int main() {
    
    
    printf("==========================================\n");
    printf("==              TASK 1:              	==\n");
    printf("==========================================\n");
    
	int n, i = 0, j;	
    printf("Please provide a positive integer: ");
    scanf("%i", &n);
    for(; i != 1;){
	    if(n < 0){
	    	printf("The value is invalid please provide again: ");
	    	scanf("%i", &n);}
	    else if(n > 0)
	    	i++;}
	int a[n+1];
	a[0] = 0, a[1] = 1, a[2] = 1;
	for(i = 3; i < n+1; i++)
		a[i] = a[i-2] + a[i-1];
	printf("Fibonacci for %i: ", n+1);
	for(i = 0; i < n+1; i++)
		printf("%i ", a[i]);
	printf("\n");
		
	printf("==========================================\n");
    printf("==              TASK 2:              	==\n");
    printf("==========================================\n");	
	int size_m;	
	printf("Input the size for the matrix (less than 6): ");
	scanf("%i", &size_m);
	int b[size_m][size_m], c[size_m][size_m];
	printf("Input elements in the first matrix:\n");	
	for(i = 0; i < size_m; i++){
		for(j = 0; j < size_m; j++){
			printf("element - [%i],[%i]: ", i, j); 
			scanf("%i", &b[i][j]);
		}
	}
	printf("Input elements in the second matrix:\n");	
	for(i = 0; i < size_m; i++){
		for(j = 0; j < size_m; j++){
			printf("element - [%i],[%i]: ", i, j); 
			scanf("%i", &c[i][j]);
		}
	}	
	printf("The first matrix is:\n");	
		for(i = 0; i < size_m; i++){
			for(j = 0; j < size_m; j++){
				printf("%i ", b[i][j]);}
			printf("\n");}	
	printf("The second matrix is:\n");	
		for(i = 0; i < size_m; i++){
			for(j = 0; j < size_m; j++){
				printf("%i ", c[i][j]);}
			printf("\n");}	
	printf("The Subtraction of two matrices is:\n");
	for(i = 0; i < size_m; i++){
		for(j = 0; j < size_m; j++){
			b[i][j] -= c[i][j];
		}
	}
	for(i = 0; i < size_m; i++){
			for(j = 0; j < size_m; j++){
				printf("%i ", b[i][j]);}
			printf("\n");}
	printf("\n");
		
	printf("==========================================\n");
    printf("==              TASK 3:              	==\n");
    printf("==========================================\n");	
	
	patient nur;
	printf("Gender: ");
	scanf("\n%c", &nur.Gender);
	for(; nur.Gender != 'm' && nur.Gender != 'f';){
			printf("Gender: ");	
	    	scanf("\n%c", &nur.Gender);}
	
	printf("Adult or not: ");	
	scanf("%i", &nur.Adult);
	for(; nur.Adult != 0 && nur.Adult != 1;){
	    	printf("Adult or not: ");
	    	scanf("%i", &nur.Adult);}
				
	printf("Weight:");	
	scanf("%i", &nur.Weight);
	for(; nur.Weight < 2;){
	    	printf("Weight:");	
	    	scanf("%i", &nur.Weight);}
			
	printf("Height:");	
	scanf("%i", &nur.Height);
	for(; nur.Height < 40;){
	    	printf("Height:");	
	    	scanf("%i", &nur.Height);}
	    	
	printf("Date of Birth:");	
	scanf("%i", &nur.Dob);
	for(; nur.Dob > 31;){
	    	printf("Date of Birth:");		
	    	scanf("%i", &nur.Dob);}
	    	
	printf("Month of Birth:");	
	scanf("%i", &nur.Mob);
	for(; nur.Mob > 12;){
	    		printf("Month of Birth:");	
				scanf("%i", &nur.Mob);}
			 	
	printf("Year of Birth:");	
	scanf("%i", &nur.Yob);
	for(; nur.Yob > 2018;){
	    		printf("Year of Birth:");	
				scanf("%i", &nur.Yob);}
				
	nur.Age = 2018 - nur.Yob; 
	if(nur.Gender == 'f' && nur.Adult == 0)
			printf("There is a girl with %i kg, %i cm and %i years old.\n", nur.Weight, nur.Height, nur.Age);
	else if(nur.Gender == 'f' && nur.Adult == 1)
			printf("There is a woman with %i kg, %i cm and %i years old.\n", nur.Weight, nur.Height, nur.Age);
	else if(nur.Gender == 'm' && nur.Adult == 1)
			printf("There is a man with %i kg, %i cm and %i years old.\n", nur.Weight, nur.Height, nur.Age);
	else
			printf("There is a boy with %i kg, %i cm and %i years old.\n", nur.Weight, nur.Height, nur.Age);	
			
			
			
			  	
    return 0;

        
        
        
}

