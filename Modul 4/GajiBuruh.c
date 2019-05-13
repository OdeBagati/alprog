#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double input();
void clear_buffer();
void reset();

typedef struct gaji{
    int gajiHarian;
    int gajiPerJam;
    int jamKerja; 
    int jamLembur;
} Gaji;

int main(){
    Gaji gajikaryawan;
    gajikaryawan.gajiPerJam = 10625;
    printf("Masukkan jam kerja pegawai :");
    gajikaryawan.jamKerja = input();
    if(gajikaryawan.jamKerja > 8){ 
        gajikaryawan.jamLembur = gajikaryawan.jamKerja - 8;
        gajikaryawan.gajiHarian = gajikaryawan.gajiPerJam * 8 + gajikaryawan.gajiPerJam * 8 * gajikaryawan.jamLembur;
    } else {
        gajikaryawan.gajiHarian = gajikaryawan.gajiPerJam * gajikaryawan.jamKerja;
    }
    printf("Gaji per jam : %d\nGaji harian pegawai : %d\n",gajikaryawan.gajiPerJam,gajikaryawan.gajiHarian);
    reset();
}

double input(){
    double num;
    char chara;
    if (scanf("%lf%c",&num,&chara)!= 2 || num<=0 || chara != '\n' || chara == ','){
        clear_buffer();
        printf("Input invalid! Masukkan angka yang benar : ");
        return input();
    } else {
        return num;
    }
}

void clear_buffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ; 
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("\n\nKembali menghitung?[Y/N] ");
    gets(parameter);
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        main();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Invalid Input !\n\a");
        reset();
    }
}

