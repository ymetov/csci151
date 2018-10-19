#include <stdio.h>
#include <string.h>
void encrypt(FILE *fin, FILE *fout, char subarr[], char pass[]){
	int i, f_data;													// even if f_data int variable, it will be used to store characters from fin 
	for(i = 0; !feof(fin); i++){									//Take the first character from the plain text file
		f_data = fgetc(fin);
		if(f_data == EOF) //Keep going until the end of the plain text file
			break;
		if(i == strlen(pass)) //If the end of the password is reached, start over at the first character of the password. 
			i = 0;
		putc(subarr[((f_data + pass[i]) % 255)], fout); //Add it to the first character from the password
	} //Take modulo 255 of the sum to get a number between 0 and 254
	fclose(fin);
	fclose(fout);
}
void decrypt(FILE *fin, FILE *fout, char subarr[], char pass[]){
	int i; 
	char f_data;													// char variable that will be used to store characters from fin 
	for(i = 0; !feof(fin); i++){ 									//Take the first character from the encrypted file.
		f_data = fgetc(fin);										
		if(f_data == EOF)	//Keep going until the end of the plain text file
			break;
		if(i == strlen(pass)) //If the end of the password is reached, start over at the first character of the password.
			i = 0;
		putc(((subarr[f_data] - pass[i]) % 255), fout);
	} //Take that index and subtract the first password character from it. Take modulo 255 of that result to get the plain text character
	fclose(fin);
	fclose(fout);
}
void reading_keyfile(FILE *enc, char enc_key[], char dec_key[]){
	size_t t = 0, temp;
	enc = fopen("key.254", "r");										//constant file name reading
	for(; (temp = fgetc(enc)) != EOF; t++){
		enc_key[t] = temp;
		dec_key[enc_key[t]] = t;
	}
	fclose(enc);
}
int main() {
	FILE *enc, *dec;
	char enc_key[254], dec_key[254], pass[256], m[256], fname[256];
	reading_keyfile(enc, enc_key, dec_key);
	printf ("WELCOME to the encryption service.\n");
	printf ("ENTER your password\n"); //Before showing the user the menu, you must ask the user for the password. 
	scanf("%s", pass); //The same password is used to encrypt/decrypt all the files during one session.
	while(1 > 0){
		printf("MENU: <e>ncode , <d>ecode , or <q>uit\n");				//main menu
		scanf("%s", m);
		if(m[0] == 'q'){
			printf("BYE!");
			exit(0);
		}
		else if(m[0] == 'e'){
			printf("ENTER a file to encrypt\n");	
			scanf("%s", fname);
			enc = fopen(fname, "r");
			if(enc == NULL){ //The input and output files should be opened and checked for validity before calling encrypt or decrypt
				printf("CANNOT open %s \n", fname);
				continue;
			}
			printf ("ENTER a filename for the encrypted file\n");	
			scanf("%s", fname);
			dec = fopen(fname, "w");
			if(dec == NULL){  //The input and output files should be opened and checked for validity before calling encrypt or decrypt
				printf("CANNOT open %s \n", fname);
				continue;
			}
			encrypt(enc, dec, enc_key, pass); //The encryption process:
		}
		else if(m[0] == 'd'){
			printf("ENTER a file to decrypt\n");
			scanf("%s", fname);
			enc = fopen(fname, "r");
			if(enc == NULL){	//The input and output files should be opened and checked for validity before calling encrypt or decrypt
				printf("CANNOT open %s \n", fname);
				continue;
			}
			printf("ENTER a filename for the decrypted file.\n");
			scanf("%s", fname);
			dec = fopen(fname, "w");
			if(dec == NULL){ //The input and output files should be opened and checked for validity before calling encrypt or decrypt
				printf("CANNOT open %s \n", fname);
				continue;
			}
			decrypt(enc, dec, dec_key, pass); //The decryption process is just the opposite:
		}
		else
			printf("UNRECOGNIZED %c \n", m[0]);
	}
}
