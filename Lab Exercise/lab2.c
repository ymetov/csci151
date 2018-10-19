#include <stdio.h> 
#include <math.h>
int main(){
printf("==========================================\n");
printf("==              TASK 1:                 ==\n");
printf("==========================================\n");

const double PI = 3.14;
double r = 6;

printf("Perimeter of the circle = %g inches \n",2 * PI * r);
printf("Area of the circle = %g square inches \n", PI * r * r);

printf("==========================================\n");
printf("==              TASK 2:                 ==\n");
printf("==========================================\n");

printf("Please	provide	the	number	of	days: ");
int days;
scanf("%i", &days);
printf("Years: %i\n", days / 365);
printf("Weeks: %i\n", days % 365 / 7);
printf("Days: %i\n", days % 365 % 7);


printf("==========================================\n");
printf("==              TASK 3:                 ==\n");
printf("==========================================\n");

printf("######\n#\n#\n#####\n#\n#\n######\n");


printf("==========================================\n");
printf("==              TASK 4:                 ==\n");
printf("==========================================\n");

double a, b, c;
printf("Input	the	first	number	(a): ");
scanf("%lf", &a);
printf("Input	the	second	number	(b): ");
scanf("%lf", &b);
printf("Input	the	third	number	(c): ");
scanf("%lf", &c);
printf("Root1 = %g\n", (- b - sqrt(b * b - 4 * a * c)) / (2 * a));
printf("Root2 = %g\n", (- b + sqrt(b * b - 4 * a * c)) / (2 * a));

printf("==========================================\n");
printf("==              TASK 5:                 ==\n");
printf("==========================================\n");
/*
printf("           ___     ___        \n");
printf("          /   \\~~~/   \\           \n");
printf("    ,----(       ..    )          \n");
printf("   /   	 \\___     ____/                \n");	
printf("  /|   	     (\\  |(       \n");
printf(" ^ \\   /___\\  /\\ |\n");
printf("    |__|   |__|-\"");
*/	
//done only with one printf()
printf("           ___     ___        \n          /   \\~~~/   \\           \n    ,----(       ..    )          \n   /   	 \\___     ____/                \n  /|   	     (\\  |(       \n ^ \\   /___\\  /\\ |\n    |__|   |__|-\"");		
return 0;
}

