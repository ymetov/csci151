#include <stdio.h>
#include <stdlib.h>
void clean_stdin(void)
{
int c;
do {
c = getchar();
} while (c != '\n' && c != EOF);
}
char *my_func(char *s){
    fflush(stdin);
    char * ch = s;
    int k;
	
    /* until we read a newline */
    while ((k = getchar ()) != '\n') {

        if (k == EOF) {
           
            if (ch == s || !feof(stdin)) 
                return NULL;

            break;
        }
		
      
        *ch++ = k;
    }
		
    *ch = '\0';
		
   
    return s; 
}
int toUp(int cha)
{
        if(cha >= 'a' && cha <= 'z')
                return ('A' + cha - 'a');
        else
                return cha;
}

int main() {
    
    
    printf("==========================================\n");
    printf("==              TASK 1:              	==\n");
    printf("==========================================\n");
    char s[80];
    int count, i;
    
    printf("Input some words: ");
    my_func(s);
    s[0] = toUp(s[0]);
    printf("%c", s[0]);
    
    for (i = 1; s[i] != '\0'; i++)
    {
        if(s[i] == ' ' && s[i+1] != ' ' && s[i] != '\0')
            printf(" ");
        else if(s[i] != ' ' && s[i-1] == ' ' && s[i] != '\0')
            printf("%c", toUp(s[i]));
        else if(s[i] != ' ' && s[i-1] != ' ' && s[i] != '\0')
            printf("%c", s[i]);
    }
    printf("\n");  
    
    
    
    printf("==========================================\n");
    printf("==              TASK 2:              	==\n");
    printf("==========================================\n");
      
    int ch; 
    while (ch!='q') 
    { 
        printf("please provide one char: "); 
        ch = getchar(); 
        if(ch >= 48 && ch <= 57) 
            { 
                printf("The entered character is a digit."); 
                ch = getchar(); 
            } 
        else if(ch == 'q') 
            break; 
        else if(ch >=65 && ch <= 90)
            {
               printf("The entered character is a letter.");  
               ch = getchar();
            }
        else if(ch >= 97 && ch <= 122)
             {
               printf("The entered character is a letter.");  
               ch = getchar();
            }
        else
            { 
                printf("The entered character is not a letter neither a digit."); 
                ch = getchar(); 
            } 
        printf("\n"); 
    } 
    
    printf("Buy, thanks for using.\n"); 
    printf("==========================================\n");
    printf("==              TASK 3:              	==\n");
    printf("==========================================\n");
    
    char lin[100];
    printf("Please provide a sentence: ");
    clean_stdin();
    my_func(lin);
    for(i = 0; lin[i] != '\0'; i++)
        {
            if(lin[i] != ' ' && lin[i+1] != ' ')
                printf("%c", lin[i]);
            else
                printf("%c\n", lin[i]);
        }
    
    printf("\n"); 
    
    char ch_list[100];
    
    printf("==========================================\n");
    printf("==              TASK 4:              	==\n");
    printf("==========================================\n");
    
    printf("Please provide two strings: ");
    
    
    my_func(ch_list);
    int leng = 0, j = 0;
    for(i = 1; ch_list[i] != ' '; i++)
        leng++;
    
    for( i = 0; ch_list[i] != ' '; i++)
        {
            if(ch_list[i] != ch_list[i+leng+2])
                j++;
        }
    if(j != 0)
        printf("These two words are not equal.");
    else
        printf("These two words are equal.");
    printf("\n");
    
   
    return 0;

        
        
        
}

