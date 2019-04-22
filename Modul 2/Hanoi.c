#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>

void hanoi(int n, char x, char y, char z);
void reset();
int input();

int main() {
    int cakram,pilihan,hasil,x;
	printf("===============================\n");
	printf("||     PROGRAM TOWER HANOI   ||\n");
	printf("||         Kelompok 13       ||\n");
	printf("===============================\n");
    printf ("\n[1] Hanoi Rekursif\n");
	printf ("[2] Hanoi Iteratif\n");
	printf ("[3] Keluar\n");
	printf ("Pilihan [1-3] : ");
	fflush(stdin);
	pilihan=input();
	
	switch(pilihan){
		case 1 :  {
			system("cls");
			angka:
			printf("-- HANOI REKURSIF --\n\n");
			printf("Masukan Jumlah Cakram : ");
			fflush(stdin);
			cakram=input();
			
	    	printf("\nLangkah-langkah pemindahan cakram :\n\n");
    		hanoi(cakram,'1','2','3');
    		hasil=pow(2,cakram)-1;
			printf ("\nMaka jumlah langkah minimum menara Hanoi adalah %d\n",hasil);
	    	reset();		
			break;
		} 
		case 2 :  {
			system("cls");
			printf("-- HANOI ITERATIF --\n\n");
			printf("Masukan Jumlah Cakram : ");
			fflush(stdin);
			cakram=input();
	    	printf("\nLangkah-langkah pemindahan cakram :\n\n");
    		for(x=1;x<(1 << cakram);x++){
				printf("Pindahkan cakram paling atas dari tiang %d ke tiang %d\n",((x&(x-1))%cakram )+ 1,(((x|(x-1))+1)%cakram) + 1);
			}
    		hasil=pow(2,cakram)-1;
			printf ("\nMaka jumlah langkah minimum menara Hanoi adalah %d\n",hasil);
	    	reset();	
			break;
		} 
		case 3: {
			break;
	 }
		default: {
			system("cls");
			printf ("Input Pilihan Salah!");
			getch();
			main();
			break;
		}			
	}
}

void hanoi(int n, char x, char y, char z){ 
  	if (n==1) {
    	printf("Pindahkan cakram paling atas dari tiang %c ke tiang %c\n",x,z);  
	}
	else {
        hanoi(n-1,x,z,y);
        hanoi(1,x,y,z);
        hanoi(n-1,y,x,z);
    }
}

int input(){
    int angka;
    char karakter;
    if (scanf("%d%c",&angka,&karakter)!= 2 || angka<=0  || karakter != '\n' || karakter == ','){
        fflush(stdin);
        printf("Input invalid! Masukkan angka yang benar : ");
        return input();
    } else {
        return angka;
    }
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("Kembali mencari?[Y/N] ");
    gets(parameter);
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        main();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Input Invalid!\n\a");
        reset();
    }
}

