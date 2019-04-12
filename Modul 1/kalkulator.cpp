#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void menu();

double tambah(double angka1,double angka2);
double kurang(double angka1,double angka2);
double kali(double angka1,double angka2);
double bagi(double angka1,double angka2);
int modulus(double angka1,double angka2);
void hapus_buffer();
void kalkulator(int pilihan);
double input();
void reset();

double tambah(double angka1,double angka2){
    return angka1 + angka2;
}

double kurang(double angka1,double angka2){
    return angka1-angka2;
}

double kali(double angka1,double angka2){
    return angka1*angka2;
}

double bagi(double angka1,double angka2){
    return angka1/angka2;
}

int modulus(double angka1,double angka2){	
    return (int) angka1 % (int) angka2;
}

int main(){
	printf("===============================\n");
	printf("||     PROGRAM KALKULATOR    ||\n");
	printf("||         Kelompok 13       ||\n");
	printf("===============================\n");
    menu();
}

void menu(){
    double pilihan;
    int check;
    printf("\n\nPilih operasi:\n\n\t1.Tambah\n\t2.Kurang\n\t3.Kali\n\t4.Bagi\n\t5.Modulus\n\t6.Keluar\n\nPilihan : ");
    pilihan = input();
	check = pilihan;
    if (check == pilihan){
        if (pilihan>5 || pilihan < 1){
            if (pilihan == 6){
                    return;
            } else {
                printf("Input Salah!");
                menu();
            }
        } else {
            kalkulator(pilihan);
            reset();
        }
    }
    else {
        printf("Input Salah!");
        menu();
    }
}

void kalkulator(int pilihan){
    double angka1;
    double angka2;
    double hitung;
	printf("\nMasukkan angka pertama : ");
    angka1 = input();
    printf("Masukkan angka kedua : ");
    angka2 = input();
    if(pilihan == 4 && angka2 == 0){
        printf("Pembagi nol tidak diperbolehkan \n");
    }  
	else if(pilihan == 5){
        if(ceil(angka1) != angka1 || ceil(angka2) != angka2){
            printf("Untuk perhitnungan modulus input integer! \n");
        }
        else {
        	hitung = modulus(angka1,angka2);
        	printf("Hasil Perhitungan : %.2lf",hitung);
		}
    } else {
        switch(pilihan){
                case 1 :
                    hitung = tambah(angka1,angka2);
                    break;
                case 2 :
                    hitung = kurang(angka1,angka2);
                    break;
                case 3:
                    hitung = kali(angka1,angka2);
                    break;
                case 4:
                    hitung = bagi(angka1,angka2);
                    break;
            }
        printf("Hasil Perhitungan : %.2lf",hitung);
    }
}

double input(){
    double angka;
    char huruf;
    if (scanf("%lf%c",&angka,&huruf)!= 2 || huruf!='\n' || huruf==','){
        hapus_buffer();
        printf("Input Salah! Masukkan angka : ");
        return input();
    } else {
        return angka;
    }
}

void hapus_buffer(){
    char c;
    while ((c=getchar())!='\n'&& c!=EOF); 
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("\n\nKembali menghitung?[Y/N] ");
    gets(parameter);
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        menu();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Input Salah!\n\a");
        reset();
    }
}
