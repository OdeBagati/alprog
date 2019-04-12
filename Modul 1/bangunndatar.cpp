#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bangun_datar{
    double luas;
    double keliling; 
    char nama[20];
}bangun_datar;

double PHI=3.14;
void menu();
	bangun_datar persegi();
	bangun_datar segitiga();
	bangun_datar lingkaran();
	bangun_datar jajar_genjang();
	bangun_datar trapesium();
double input();
void hapus_buffer();
void reset();

int main(){
	printf("===============================\n");
	printf("||    PROGRAM BANGUN DATAR   ||\n");
	printf("||         Kelompok 13       ||\n");
	printf("===============================\n");
    menu();
}

void menu(){
    float pilihan;
    int cek;
    bangun_datar pilih;
    printf("\nPilih bangun datar:\n\n\t1.Persegi\n\t2.Segitiga\n\t3.Lingkaran\n\t4.Trapesium\n\t5.Jajar Genjang\n\t6.Keluar Program\n\nPilihan : ");
    pilihan = input();
    cek = pilihan;
    if (cek == pilihan){
        if (pilihan>5 || pilihan < 1){
                if (pilihan == 6){
                    return;
                }else{
                    system("cls");
                    printf("Input Salah !\n");
                    menu();
                }
        } else {
        //Validasi (kalo input float gagal,isi huruf di belakang error)
            switch ((int)pilihan)
            {
                case 1:
                    pilih = persegi();
                    break;
                case 2:
                    pilih = segitiga();
                    break;
                case 3:
                    pilih = lingkaran();
                    break;
                case 4:
                    pilih = trapesium();
                    break;
                case 5:
                    pilih = jajar_genjang();
                    break;
            }
            printf("\n\nBangun datar %s : \nLuas : %.2lf satuan\nKeliling : %.2lf satuan\n\n",pilih.nama,pilih.luas,pilih.keliling);
            reset();
        }
    }else{
        system("cls");
        printf("Input Salah!\n");
        menu();
    }
}

bangun_datar persegi(){
    bangun_datar persegi;
    double panjang,lebar;
    printf("Masukkan panjang : ");
    panjang = input();
    printf("Masukkan lebar : ");
    lebar=input();
    persegi.luas=panjang*lebar;
    persegi.keliling=2*(panjang+lebar);
    strcpy(persegi.nama,"Persegi");
    return persegi;
}

bangun_datar lingkaran(){
    bangun_datar lingkaran;
    double r;
    printf("Masukkan panjang jari-jari : ");
    r=input();
    lingkaran.luas = PHI*r*r;
    lingkaran.keliling = 2*PHI*r;
    strcpy(lingkaran.nama,"Lingkaran");
    return lingkaran;
}

bangun_datar segitiga(){
    bangun_datar bangunSegitiga;
    double s1,s2,s3,s;
    printf("Masukkan sisi 1 : ");
    s1 = input();
    printf("Masukkan sisi 2 : ");
    s2 = input();
    printf("Masukkan sisi 3 : ");
    s3 = input();
    if(s1+s2 == s3 || s1+s3 == s2 || s2+s3 ==s1){
        system("cls");
        printf("Input Salah\n");
        bangunSegitiga = segitiga();
    }else{
        bangunSegitiga.keliling = s1 + s2 + s3;
        s = 0.5 * bangunSegitiga.keliling;
        bangunSegitiga.luas = sqrt(s*(s-s1)*(s-s2)*(s-s3)); 
        strcpy(bangunSegitiga.nama,"Segitiga");
    }
    return bangunSegitiga;
}

bangun_datar jajar_genjang(){
    bangun_datar jajar_genjang;
    double s1,s2,t;
    printf("Masukkan sisi alas jajar genjang : ");
    s1 = input();
    printf("Masukkan sisi miring jajar genjang : ");
    s2 = input();
    printf("Masukkan tinggi jajar genjang : ");
    t = input();
    jajar_genjang.luas = s1*t;
    jajar_genjang.keliling = 2*s1+2*s2 ;
    strcpy(jajar_genjang.nama,"Jajar Genjang");
    return jajar_genjang;
}

bangun_datar trapesium(){
    bangun_datar trapesium;
    double alas,sisiSejajar,sisiLain1,sisiLain2,tinggi;
    printf("Masukkan alas : ");
    alas = input();
    printf("Masukkan sisi sejajar dengan alas : ");
    sisiSejajar = input();
    printf("Masukkan 2 buah sisi lainnya : ");
    sisiLain1 = input();
    sisiLain2 = input();
    printf("Masukkan tinggi :");
    tinggi = input();
    trapesium.keliling = alas+sisiSejajar+sisiLain1+sisiLain2;
    trapesium.luas = 1.0/2.0*(alas+sisiSejajar)*tinggi;
    strcpy(trapesium.nama,"Trapesium");
    return trapesium;
}

double input(){
    double angka;
    char karakter;
    if (scanf("%lf%c",&angka,&karakter)!= 2  || karakter != '\n' || karakter == ','){
        hapus_buffer();
        printf("Input Salah! Masukkan angka : ");
        return input();
    } else {
        return angka;
    }
}

void hapus_buffer(){
    char c;
    while ((c=getchar())!='\n' && c!=EOF); 
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("Kembali menghitung?[Y/N] ");
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


