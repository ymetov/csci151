#include <stdio.h>
#include <string.h>

//functions
void decrypt(FILE *fin, FILE *fout, char subarr[], char pass[]);
void encrypt(FILE *fin, FILE *fout, char subarr[], char pass[]);
void set_parameters(char pass[], char key[], FILE *ifstream, char *repeat);
int take_index(char subarr[], char ch){
	int i = -1;
	while((i++) < 254){
		if(subarr[i] == ch)
			return i;
	}
}

//variables for program
FILE *ifstream, *ofstream;
char pass[256], key[254], variant[256], repeat[3] = {'Y', 'E' ,'S'}, f_name[256];

//main called recursively 
int main(){
setvbuf(stdout, NULL, _IONBF, 0);
set_parameters(pass, key, ifstream, repeat);
printf("MENU: <e>ncode , <d>ecode , or <q>uit\n");
scanf("%s", variant);
switch(*variant){
	case 'd':
		printf("ENTER a file to decrypt\n");
		scanf("%s", f_name);
		ifstream = fopen(f_name, "r");
		while(ifstream == NULL){
		printf("CANNOT open %s\n", f_name);
		main();
		}
		printf("ENTER a filename for the decrypted file.\n");
		scanf("%s", f_name);
		ofstream = fopen(f_name, "w");
		while(ofstream == NULL){
		printf("CANNOT open %s\n", f_name);
		main();
		}
		decrypt(ifstream, ofstream, key, pass);
		break;
	case 'q':
		printf("Bye!\n");
		return 0;
	case 'e':
		printf("ENTER a file to encrypt\n");
		scanf("%s", f_name);
		ifstream = fopen(f_name, "r");
		while(ifstream == NULL){
		printf("CANNOT open %s\n", f_name);
		main();
		}
	
		printf("ENTER a filename for the encrypted file.\n");
		scanf("%s", f_name);
		ofstream = fopen(f_name, "w");
		while(ofstream == NULL){
		printf("CANNOT open %s\n", f_name);
		main();
		}
		encrypt(ifstream, ofstream, key, pass);
		break;
	default:
		printf("UNRECOGNIZED option %c\n", *variant);
		break;
}
return (main());
}

//decryption algorithm
void decrypt(FILE *fin, FILE *fout, char subarr[], char pass[]){
	int i = -1, j, k;
	while((j = fgetc(fin)) != EOF && (i++) > (-3)){
		if(i == strlen(pass))
			i = 0;
		putc(((take_index(subarr, j) - pass[i]) % 255), fout);
	}
	fclose(fin);
	fclose(fout);
}

//encryption algorithm
void encrypt(FILE *fin, FILE *fout, char subarr[], char pass[]){
	int i = -1, j;
	while((j = fgetc(fin)) != EOF && (i++) > (-3)){
		if(i == strlen(pass))
			i = 0;
		putc(subarr[((j + pass[i]) % 255)], fout);
	}
	fclose(fin);
	fclose(fout);
}

void set_parameters(char pass[], char key[], FILE *ifstream, char repeat[]){
if(repeat[0] == 'N')
	return;
printf ("WELCOME to the encryption service.\n");   
printf ("ENTER your password:\n");                         //in this function password and 
scanf("%s", pass);										  //symbols of ASCII copied to the pass and key arrays
ifstream = fopen("key.254", "r");
int i, j;
for(i = 0; (j = fgetc(ifstream)) != EOF; i++)
	key[i] = j;
repeat[0] = 'N';
fclose(ifstream);	
}
