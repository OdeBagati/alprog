#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE  0

typedef struct tanggal{
    int hari;
    int bulan;
} struct_tanggal;

char zodiak_user[20];
struct_tanggal input_tanggal();
char * get_zodiac(int bulan,int hari);
struct_tanggal cek_tanggal(int hari,int bulan);
void print_error(int cek_hari,int cek_bulan);
void reset();
void menu();
void hapus_buffer();

int main(){
	printf("===============================\n");
	printf("||        PROGRAM ZODIAK     ||\n");
	printf("||         Kelompok 13       ||\n");
	printf("===============================\n");
    menu();
    return 0;
}

void menu(){
    char zodiak_saya[20];
    struct_tanggal tanggal_ini;
    struct_tanggal cek;
    tanggal_ini = input_tanggal();
    hapus_buffer();
    cek = cek_tanggal(tanggal_ini.hari,tanggal_ini.bulan);
    
	if ((!cek.hari) || (!cek.bulan)){   
        print_error(cek.hari,cek.bulan);
    } else {
        get_zodiac(tanggal_ini.bulan,tanggal_ini.hari);
        strcpy(zodiak_saya,zodiak_user);
        printf("%s",zodiak_saya);
    }
    reset();    
}

struct_tanggal input_tanggal(){
    struct_tanggal tanggal;
    printf ("Masukkan tanggal lahir (DD)  : ");
    scanf("%d",&tanggal.hari);
    printf ("Masukkan bulan lahir (MM)  : ");
    scanf("%d",&tanggal.bulan);
    printf("\n");
    return tanggal;
}

char * get_zodiac(int bulan,int hari){
    if ((hari >= 21 && bulan == 3) || (hari<=19 && bulan == 4)) {
        strcpy(zodiak_user,"Aries");
    } else if ((hari >= 20 && bulan == 4) || (hari <= 20 && bulan == 5)) {
        strcpy(zodiak_user,"Taurus");
    } else if ((hari >= 21 && bulan == 5) || (hari <= 20 && bulan == 6)) {
        strcpy(zodiak_user,"Gemini");
    } else if ((hari >= 21 && bulan == 6) || (hari <= 22 && bulan == 7)) {
        strcpy(zodiak_user,"Cancer");
    } else if ((hari >= 23 && bulan == 7) || (hari <= 22 && bulan == 8)) {
        strcpy(zodiak_user,"Leo");
    } else if ((hari >= 23 && bulan == 8) || (hari <= 22 && bulan == 9)) {
        strcpy(zodiak_user,"Virgo");
    } else if ((hari >= 23 && bulan == 9) || (hari <=22 && bulan == 10)) {
        strcpy(zodiak_user,"Libra");
    } else if ((hari >= 23 && bulan == 10) || (hari <=21 && bulan == 11)) {
        strcpy(zodiak_user,"Scorpio");
    } else if ((hari >= 22 && bulan == 11) || (hari <= 21 && bulan == 12)) {
        strcpy(zodiak_user,"Sagitarius");
    } else if ((hari >= 22 && bulan == 12 ) || (hari <= 19 && bulan == 1)) {
        strcpy(zodiak_user,"Capricorn");
    } else if ((hari >= 20 && bulan == 1 ) || (hari <=18 && bulan == 2)) {
        strcpy(zodiak_user,"Aquarius");
    } else {
        strcpy(zodiak_user,"Pisces");
    }
    return zodiak_user;
}

struct_tanggal cek_tanggal(int hari,int bulan){
    struct_tanggal valid;
    valid.hari = TRUE;
    valid.bulan = TRUE;
    if (hari > 31 || hari < 1 || hari < 0)  {
        valid.hari = FALSE;
    } if (hari > 30 && bulan == 4) {
        valid.hari = FALSE;
    } if (hari > 30 && bulan == 6) {
        valid.hari = FALSE;
    } if (hari > 30 && bulan == 9) {
        valid.hari = FALSE;
    } if (hari > 30 && bulan == 11) {
        valid.hari = FALSE;
    } if (hari > 29 && bulan == 2){ 
        valid.hari = FALSE;
    } if (bulan > 12 || bulan < 1 || bulan < 0){
        valid.bulan = FALSE;
    } 
    return valid;
}

void print_error(int cek_hari,int cek_bulan){
    printf("\n\t\t            [PESAN ERROR :]\n\n");
    if (!cek_hari) { //error pada bagian hari
        printf("\t    - Maaf tanggal yang anda masukkan tidak valid -\n\a");
    }
    if (!cek_bulan) { //error pada bagian bulan
        printf("\t     - Maaf bulan yang anda masukkan tidak valid -\n\a");
    }    
    return;
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
        printf("Invalid Input !\n\a");
        reset();
    }
}

void hapus_buffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ; 
}
