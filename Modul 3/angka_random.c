#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
float countInsertionSort(int arr[], int n);
float countBubbleSort(int arr[], int n);
float countQuickSort(int arr[],int n);
float countSequentialSearch(int arr[],int n,int angka);
float countBinarySearch(int arr[],int n,int angka);
int sequentialSearch(int arr[],int n,int angka);
int binarySearch(int arr[],int low,int high, int angka);
int partition (int arr[], int low, int high);
void printArray(int arr[], int n);
void seedArray(int arr[],int n);
void menu();
void menu2(int arr[],int n);
void reset();
double validasi();
void dupArray(int source[],int target[], int n);
void hapus_buffer();

int main(){
	printf("========================================\n");
	printf("||     PROGRAM SORTING & SEARCHING    ||\n");
	printf("||              Kelompok 13           ||\n");
	printf("========================================\n");
    menu();
    return 0;
}

void seedArray(int arr[],int n){
	int i;
    srand(0);
    for (i = 0; i < n ; i++)
        arr[i] = rand();
}

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(int arr[], int n){
    int i, j,temp;
    for (i = 0; i < n-1; i++)      
         for (j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
    }
}

int sequentialSearch(int arr[],int n,int angka){
	int i;
    for(i = 0; i < n ; i++){
        if(arr [i] == angka){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int low,int high, int angka){
    bool inArray;
    if (high >= low)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == angka)  
            return mid;
        if (arr[mid] > angka) 
            return binarySearch(arr, low, mid-1, angka);
        return binarySearch(arr, mid+1, high, angka);
   }
   return -1;
}

float countBinarySearch(int arr[],int n,int angka){
    int inArray;
    quickSort(arr,0,n-1);
    clock_t start = clock();
    inArray = binarySearch(arr,0,n-1,angka);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    if(inArray == -1){
        printf("Angka %d tidak terdapat di aray",angka);  
    } else {
        printf("Angka %d berada di aray di indeks ke %d",angka,inArray);    
    }
    return detik;
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];    
    int temp;
    int i = (low - 1);  
	int j;
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

float countBubbleSort(int arr[],int n){
    clock_t start = clock();
    bubbleSort(arr,n);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    return detik;
}

float countInsertionSort(int arr[],int n){
    clock_t start = clock();
    insertionSort(arr,n);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    return detik;
}

float countQuickSort(int arr[],int n){
    clock_t start = clock();
    quickSort(arr,0,n-1);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    return detik;
}

float countSequentialSearch(int arr[],int n,int angka){
    int inArray;
    clock_t start = clock();
    inArray = sequentialSearch(arr,n,angka);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    if(inArray == -1){
        printf("Angka %d tidak terdapat di array",angka); 
    } else {
        printf("Angka %d berada di array di indeks ke %d",angka,inArray);    
    }
    return detik;
}

void printArray(int arr[], int n){
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

void menu(){
    int pilihan;
    int cek;
    int n;
    
    printf("Pilih banyak data :\n\n[1]1000\n[2]16000\n[3]64000\n[4]Exit Program\nPilihan : ");
    pilihan = validasi();
    cek = pilihan;
    if (cek == pilihan){
        if (pilihan>3 || pilihan < 1){
                if (pilihan == 4){
                        return;
                } else {
                    system("cls");
                    printf("Input Salah!!!\n");
                    menu();
                }
        } else {
            switch ((int)pilihan)
            {
                case 1: 
                    n = 1000;
                    break;
                case 2: ;
                    n = 16000;
                    break;
                case 3: ;
                    n = 100000;
                    break;
            }
        }
        
        int arr[n];
        seedArray(arr,n);
        menu2(arr,n);
    } else {
        system("cls");
        printf("Input Salah!!!\n");
        menu();
    }
}

void menu2(int arr[],int n){
    float pilihan;
    int cek;
    float detik1,detik2,detik3;
    int angka;
    int arr2[n];
    int arr3[n];
    printf("Pilih metode :\n\n[1]Sorting(Bubble Sort,Insertion Sort,Quick Sort)\n[2]Searching(Binary Search,SequentialSearch)\n[3]Exit Program\n\nPilihan :");
    pilihan = validasi();
    cek = pilihan;
    if (cek == pilihan){
        if (pilihan>2 || pilihan < 1){
                if (pilihan == 3){
                        return;
                } else {
                    system("cls");
                    printf("Input Salah!\n");
                    menu();
                }
        } else {
            printf("Array %d data random sebelum di sort :\n");
            printArray(arr,n);
            if(pilihan ==2){
                printf("Masukkan angka yang dicari : ");
                angka = validasi();
            }
            dupArray(arr,arr2,n);
            dupArray(arr,arr3,n);
            switch ((int)pilihan)
            {
                case 1:
                    detik1 = countInsertionSort(arr,n);
                    detik2 = countBubbleSort(arr2,n);
                    detik3 = countQuickSort(arr3,n);
                    break;
                case 2:
                    detik1 = countSequentialSearch(arr,n,angka);
                    detik2 = countBinarySearch(arr2,n,angka);
                    break;
            }
        }

        if(pilihan == 1){
            printf("Array %d data random sesudah di sort :\n");
            printArray(arr2,n);
            printf("Waktu Quick Sort : %lf\nWaktu Insertion Sort : %lf\nWaktu Bubble Sort : %lf",detik3,detik1,detik2);
        } else if(pilihan == 2) {
            printf("Waktu Sequential Search : %lf\nWaktu Binary Search :%lf",detik1,detik2);
        }
        reset();
    } else {
        system("cls");
        printf("Inpu Salah!!!\n");
        menu();
    }
}

double validasi(){
    double angka;
    char karakter;
    if (scanf("%lf%c",&angka,&karakter)!= 2 || angka<=0 || karakter != '\n' || karakter == ','){
        hapus_buffer();
        printf("Inpu Salah!!! Masukkan angka yang benar : ");
        return validasi();
    } else {
        return angka;
    }
}


void dupArray(int source[],int target[], int n){
	int i;
    for(i = 0; i < n ; i++)
        target[i] = source[i];
}

void hapus_buffer(){
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
        menu();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Inpu Salah!!!\n\a");
        reset();
    }
}

