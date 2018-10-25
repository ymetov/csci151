#include <stdio.h>
#include <time.h>
int main() {
    char var;                                   //var - menu option
    int rn, ans, ng_f = 0, ng = 0, j = 0, dl = 9999;  //rn - random number; dl- default limit; ng_f -final number of guesses; ng-number of guesses
    double average;
    srand(time(NULL));                        //set the "seed" of the random generator
    printf("WELCOME to the guessing game!\n");
    printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
    do{
        scanf("\n%c", &var);
        if(var == 's'){
            rn = rand() % dl;
            printf("The secret number is BETWEEN 0 AND %i. Guess:\n", dl);
            do{
                ng += 1;
                scanf("%i", &ans);
                if(ans < rn)
                    printf("Too LOW! Guess:\n");
                else if(ans > rn)
                    printf("Too HIGH! Guess:\n");
            }while(ans != rn);
            printf("Correct: You TOOK %i guesses!\n", ng);
            printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
            ng_f = ng_f + ng;
            ng = 0;
            j +=1;
        }
        else if(var == 'n'){
            printf("Enter a new MAXIMUM:\n");
        	scanf("%i", &dl);
        	printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
        }
        else if(var != 'q' && var != 's' && var != 'n'){
            printf("UNRECOGNIZED command.\n");
            printf("MENU: (s) to start a game, (n) to set a new range, or (q) to quit:\n");
        }
    }while(var != 'Q' && var != 'q');
    average = ng_f / (float)j;
    printf("Thanks for playing. Your guess count AVERAGE %.1f", average);
    return 0;
}
