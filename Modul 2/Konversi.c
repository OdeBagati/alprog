#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void menu();
void BinerKeDesimal();
void DesimalKeBiner();
void hapus_buffer();
void reset();
double input();

int main(){
	printf("===============================\n");
	printf("||      PROGRAM Konversi     ||\n");
	printf("||         Kelompok 13       ||\n");
	printf("===============================\n");
    menu();
    return 0;

}

void menu(){
    int pilihan;
    
    printf("\n[1]Biner ke Desimal\n[2]Desimal ke Biner\n\nPilihan :");
    pilihan = input();
    if (pilihan>2 || pilihan < 1){
        system("cls");
        printf("Input invalid !\n");
        menu();
    } else {
        switch(pilihan){
            case 1:
                BinerKeDesimal();
                break;
            case 2 :
                DesimalKeBiner();
                break;
        }
    }
    reset();
}

void BinerKeDesimal(){
    char *p = malloc(sizeof(char)*(4));
    int len = 0;
	int i=1;
    int sum = 0;
    hapus_buffer();
    printf("Masukkan bilangan biner : ");
    do{
        scanf("%c",&p[len]);
        len++;
    } while(p[len-1] != '\n');
    p[len-1] = '\0';
    int count = len-2;
    for ( i = 0 ; i < len-1 ; i ++ ){
        if (p[i] == '1' || p[i] == '0' ){
            continue;
        } else {
            printf("Bilangan tidak valid!");
            return;
        } 
    }
    for (i = 0 ; i < len ; i ++ ){
        if (p[i] == '1'){
            sum = sum + pow(2,count);
        } 
        count--;
    }
    printf("Nilai Desimal : %d",sum);
}

void DesimalKeBiner(){
    double angka;
    int sum = 0;
	int i=1;
    int count = 0;
    int *array;
    array = malloc(sizeof(int)*10);
    printf("Masukkan Angka Desimal : ");
    angka = input();
    printf("Nilai Biner : ");
    if (angka == 0 || angka == 1){
        printf("%d",angka);
    } else {
        int sumDiv = (int)angka;
        int sumMod = (int)angka;
        while(sumDiv != 0){
            sumMod = sumDiv % 2;
            sumDiv = sumDiv / 2;
            array[count] = sumMod;
            count ++;
        }    
        int bagi = 0;
        for (i = count-1; i >= 0; i--){
            printf("%d",array[i]);
            bagi++;
            if (bagi%4 == 0){
                printf(" ");
            }
        }
        free(array);
    }
}

void hapus_buffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ; 
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("\n\n\t\tKembali ke menu awal?[Y/N] ");
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

double input(){
    double angka;
    char karakter;
    int cek;
    if (scanf("%lf%c",&angka,&karakter)!= 2  || karakter != '\n' || karakter == ','){
        hapus_buffer();
        printf("Input invalid! Masukkan angka : ");
        return input();
    } else {
        cek = angka;
        if (cek == angka){
            return angka;
        } else {
            printf("Input invalid! Masukkan angka bulat : ");
            return input();
        }
    }
}

