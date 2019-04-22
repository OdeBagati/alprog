#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

double input_nilai();
double input_absen();
void reset();

int main(){
	double absensi,tugas1,tugas2,tugas3,quiz,uts,uas,nilai;
	char indeks[5];
	printf("===============================\n");
	printf("||     PROGRAM INDEX NILAI   ||\n");
	printf("||         Kelompok 13       ||\n");
	printf("===============================\n");	
	printf("\nmasukkan absensi  =  ");
	absensi=input_absen();
	printf("masukan nilai tugas 1 = ");
	tugas1=input_nilai();
	printf("masukkan nilai tugas 2 = ");
	tugas2=input_nilai();
	printf("masukkan nilai tugas 3 = ");
	tugas3=input_nilai();
	printf("masukkan nilai quiz = ");
	quiz=input_nilai(); 
	printf("masukkan nilai uts   = ");
	uts=input_nilai(); 
	printf("masukkan nilai uas   = ");
	uas=input_nilai(); 
	
	nilai=(((absensi*100)/15)*0.05)+(quiz*0.15)+(((tugas1+tugas2+tugas3)/3)*0.2)+(uts*0.3)+(uas*0.3);
	if(nilai>=0 && nilai<45 ){
		strcpy(indeks,"E");
	}
	else if(nilai>=45 && nilai<50 ){
		strcpy(indeks,"D");
	}
	else if(nilai>=50 && nilai<55 ){
		strcpy(indeks,"D+");
	}
	else if(nilai>=55 && nilai<60 ){
		strcpy(indeks,"C");
	}
	else if(nilai>=60 && nilai<65 ){
		strcpy(indeks,"C+");
	}
	else if(nilai>=65 && nilai<75){
		strcpy(indeks,"B");
	}
	else if(nilai>=75 && nilai<80){
		strcpy(indeks,"B+");
	}
	else if(nilai>=80){
		strcpy(indeks,"A");
	}
	printf ("\nNilai akhir = %.2lf \nIndeks nilai %s\n",nilai,indeks);
	reset();
}

double input_nilai(){
    double angka;
    char karakter;
    if (scanf("%lf%c",&angka,&karakter)!= 2 || angka<0 || angka>100 || karakter != '\n' || karakter == ','){
        fflush(stdin);
        printf("Input invalid!\nMasukkan nilai yang benar (Max 100) : ");
        return input_nilai();
    } else {
        return angka;
    }
}

double input_absen(){
    double absen;
    char karakter;
    if (scanf("%lf%c",&absen,&karakter)!= 2 || absen<0 || absen>15 || karakter != '\n' || karakter == ','){
        fflush(stdin);
        printf("Input invalid!\nMasukkan jumlah absen yang benar (Max 15) : ");
        return input_absen();
    } else {
        return absen;
    }
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("Kembali menghitung?[Y/N] ");
    gets(parameter);
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){   
        system("cls");
        main();
    }	 else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Invalid Input !\n\a");
        reset();
    }
}
