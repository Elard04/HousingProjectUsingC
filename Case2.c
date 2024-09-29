#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Housing{
    char Location1[105];
    char Location2[105];
    int Price;
    int Rooms;
    int Bathrooms;
    int CarParks;
    char Type[30];
    int Area;
    char Furnish[30];
}Data[3939];

void SearchByString(int n){
    char bagian[105];
    char kolom[30];

    printf("Silakan input bagian yang ingin dicari dan kolomnya (contoh Partly in Furnish): \n");
    scanf("%s in %s", bagian, kolom);

    if(strcmp(kolom, "Location1")==0){
        for(int j=0; j<n; j++){
            if(strstr(Data[j].Location1, bagian)){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di Location1\n");
    }

    if(strcmp(kolom, "Location2")==0){
        for(int j=0; j<n; j++){
            if(strstr(Data[j].Location2, bagian)){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di Location2\n");
    }

    if(strcmp(kolom, "Rooms")==0){
        int bagian2 = atoi(bagian);
        for(int j=0; j<n; j++){
            if(bagian2 == Data[j].Rooms){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di Rooms\n");
    }

    if(strcmp(kolom, "Rooms")==0){
        int bagian2 = atoi(bagian);
        for(int j=0; j<n; j++){
            if(bagian2 == Data[j].Rooms){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di Rooms\n");
    }

    if(strcmp(kolom, "Bathrooms")==0){
        int bagian2 = atoi(bagian);
        for(int j=0; j<n; j++){
            if(bagian2 == Data[j].Bathrooms){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di Bathrooms\n");
    }

    if(strcmp(kolom, "CarParks")==0){
        int bagian2 = atoi(bagian);
        for(int j=0; j<n; j++){
            if(bagian2 == Data[j].CarParks){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di CarParks\n");
    }

    if(strcmp(kolom, "Type")==0){
        for(int j=0; j<n; j++){
            if(strstr(Data[j].Type, bagian)){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di Type\n");
    }

    if(strcmp(kolom, "Furnish")==0){
        for(int j=0; j<n; j++){
            if(strstr(Data[j].Furnish, bagian)){
                printf("%-35s | %s | %d | %d | %d | %d | %s | %d | %s\n", Data[j].Location1, Data[j].Location2, Data[j].Price, Data[j].Rooms, Data[j].Bathrooms, Data[j].CarParks, Data[j].Type, Data[j].Area, Data[j].Furnish);
            }
        }
    }else{
        printf("Data yang dicari tidak ada di Furnish\n");
    }
}

int main(){
    FILE *ptr;
    ptr = fopen("file.csv", "r");

    if(ptr == NULL){
        printf("File tidak ditemukan\n");
    }
    //skip header
    char header[71];
    fscanf(ptr, "%[^\n]\n", header);

    // char MetodeSearching[15];

    // printf("Metode searching yang tersedia:\n");
    // printf("String\n");
    // printf("Sub-string\n");
    // printf("Silakan input metode searching yang diinginkan(ketik nama searching): \n");

    // scanf("%s", MetodeSearching);
    // getchar();

    int i=0;
    while(!feof(ptr)){
        fscanf(ptr, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%s\n", Data[i].Location1, Data[i].Location2, &Data[i].Price, &Data[i].Rooms, &Data[i].Bathrooms, &Data[i].CarParks, Data[i].Type, &Data[i].Area, Data[i].Furnish);
        i++;
    }

        SearchByString(3939);
    

    fclose(ptr);

    return 0;
}