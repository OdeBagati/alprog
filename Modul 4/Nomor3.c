#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CekDiFile(char nama[],char nim[]);
void MasukinFile(char nama[],char nim[]);
void trimString(char str[]);

int main(){
    int len = 0;
    int valid;
    char *nama = malloc( sizeof(char) * (255) );
    char *nim = malloc( sizeof(char) * (255) );
    printf("Masukkan nama Mahasiswa: " );
    do{
        scanf("%c",&nama[len]);
        len++;
    } while(nama[len-1] != '\n');
    nama[len-1] = '\0';
    len = 0;
    printf("Masukkan nim Mahasiswa: " );
     do{
        scanf("%c",&nim[len]);
        len++;
    } while(nim[len-1] != '\n');
    nim[len-1] = '\0';
    valid = CekDiFile(nama,nim);
    if(valid){
        MasukinFile(nama,nim);
        printf("Data mahasiswa :\nNama : %s\nNim : %s\nBerhasil di simpan ke file database.txt!",nama,nim);
    }
    return 0;
}

void MasukinFile(char nama[],char nim[]){
    FILE * fw;
    fw = fopen("database.txt","a+");
    fprintf(fw,"%s\n",nama);
    fprintf(fw,"%s\n",nim);
    fclose(fw);
    return;
}

int CekDiFile(char nama[],char nim[]){
    int compareNim,compareNama, valid=1;
    char *databaseName = malloc( sizeof(char) * (255) );
    char *databaseNim = malloc( sizeof(char) * (255) );
    FILE * fr;
    fr = fopen("database.txt","r");
    if (fr == NULL){
        fclose(fr);
        return valid;
    }else{
        while(fgets(databaseName,255,fr)){
            trimString(databaseName);
            fgets(databaseNim,255,fr);
            trimString(databaseNim);
            compareNim = strcmp(databaseNim,nim);
            if (!compareNim){
                printf("Data sudah ada di database!");
                valid = 0;
                fclose(fr);
                return valid;
            }
        }
        fclose(fr);
        return valid;
    }
} 

void trimString(char str[]){
    int i;
    for(i = 0; str[i] != '\n' ; ++i);
    str[i] = '\0';
}

