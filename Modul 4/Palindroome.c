#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool PalindromeGak(char str[]);

void put_to_file(char str[]){
    FILE * fw;
    fw = fopen("kamuskata.txt","a+");
    fprintf(fw,"%s\n",str);            
    fclose(fw);
    return;
}

int main(){
    int len = 0;
    int i;
	int counts[256] = {0};
    bool palindrome;
	printf("==============================\n");
	printf("||    PROGRAM PILINDROME     ||\n");
	printf("||        Kelompok 13        ||\n");
	printf("==============================\n");
    char *hasil = malloc(sizeof(char)*(255));
    printf("Masukkan sebuah kalimat : ");
    char *string = malloc(sizeof(char)*(255));
    do{
        scanf("%c",&string[len]);
        len++;
    } while(string[len-1] != '\n');
    string[len-1] = '\0';
    palindrome = PalindromeGak(string);
    for (i = 0; i < len-1; i++) {
        counts[(int)(string[i])]++;
    }
    sprintf(hasil,"%s",string);
    for (i = 0; i < 256; i++) {
        if (counts[i] != 0) {
            if (i == 32){
                sprintf(hasil,"%s %s=%d",hasil,"Spasi",counts[i]);
            } else {
            sprintf(hasil,"%s %c=%d",hasil,i,counts[i]);
            }
        }
    }

    if(palindrome){
        sprintf(hasil,"%s %s",hasil," Palindrome");
    } else {
        sprintf(hasil,"%s %s",hasil," Tidak Palindrome");
    }
    printf("%s",hasil);
    put_to_file(hasil);
    free(hasil);
    free(string);
}

bool PalindromeGak(char str[]){
    int left = 0;
    int last = strlen(str) - 1;
    while (last > left)
    {
        if (str[left++] != str[last--])
        {
            return false;
        }
    }
    return true;
}
