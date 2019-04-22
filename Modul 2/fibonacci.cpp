#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n);
void rekursif(int n);
void iteratif(int n);
void menu();
void hapus_buffer();
double input();
void reset();

int main(){
	printf("===============================\n");
	printf("||      PROGRAM Fibonacci    ||\n");
	printf("||         Kelompok 13       ||\n");
	printf("===============================\n");
	menu();
    return 0;
}

void menu(){
    double pilihan;
    int n,check;
    printf("\n\t[1]Fibonacci Iteratif\n\t[2]Fibonacci Rekursif\n\nMasukkan Pilihan : ");
    pilihan = input();
    if (pilihan>2 || pilihan < 1){
           {
                system("cls");
                printf("Input invalid !\n");
                menu();
            }
    } else {
        printf("Masukkan Panjang Deret : ");
        n = input();
        switch((int)pilihan){
            case 1:
                iteratif(n);
                break;
            case 2:
                rekursif(n);
                break;
        }
    }
	reset();
}

int fibonacci(int n){
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
       return fibonacci(n-2) + fibonacci(n-1);
    }
}

void rekursif(int n){
    int array[n];
    int i;
    printf("%d Deret Bilangan Fibonacci : ",n);
    for (i = 1;i <= n; i++){
        array[i] = fibonacci(i);
        printf("%d ",array[i]);
    }
}

void iteratif(int n){
    int array[n];
    int i;
	for ( i = 1 ; i <= n ; i++){
        if(i == 1){
            array[i] = 1;
        } else if (i == 2){
            array[i] = 1;
        } else {
            array[i] = array[i-1] + array[i-2];
        }
        printf("%d ",array[i]);
    }
}

double input(){
    double angka;
    char karakter;
    int cek;
    if (scanf("%lf%c",&angka,&karakter)!= 2  || karakter != '\n' || karakter == ','){
        hapus_buffer();
        printf("Input invalid! Masukkan angka : ");
        return input();
    } else {
        cek = (angka);
        if (cek == angka){
            return angka;
        } else {
            printf("Input invalid! Masukkan angka bulat : ");
            return input();
        }
    }
}

void hapus_buffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ;
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("\nKembali ke menu awal?[Y/N] ");
    gets(parameter);
    
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        menu();

    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Input Invalid!\n\a");
        reset();
    }
}
