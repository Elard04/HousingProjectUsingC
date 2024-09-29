#include<stdio.h>
#include<string.h>

int count = 1;

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

int min = 100000;
int maks = 1;
char namakotamaks[20];
char namakotamin[20];

void Swap1(char *a, char *b){
   char temp[100];
   strcpy(temp,a);
   strcpy(a,b);
   strcpy(b,temp);
}

void Swap2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort_Rooms(int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (Data[j].Rooms > Data[j + 1].Rooms)
                Swap2(&Data[j].Rooms, &Data[j + 1].Rooms);
}

void BubbleSort_Bathrooms(int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (Data[j].Bathrooms > Data[j + 1].Bathrooms)
                Swap2(&Data[j].Bathrooms, &Data[j + 1].Bathrooms);
}

void BubbleSort_CarParks(int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (Data[j].CarParks > Data[j + 1].CarParks)
                Swap2(&Data[j].CarParks, &Data[j + 1].CarParks);
}

void BubbleSort_Location1(int n){
    int i, j,flag=0;
    for(i=1; i<n; i++){
        flag = 1;
        for(j=n-1; j>=i; j--){
            if(strcmp(Data[j-1].Location1,Data[j].Location1)>0){
                flag = 0;
                Swap1(Data[j-1].Location1,Data[j].Location1);
            }
    }
}
}
void BubbleSort_Type(int n){
    int i, j,flag=0;
    for(i=1; i<n; i++){
        flag = 1;
        for(j=n-1; j>=i; j--)
            if(strcmp(Data[j-1].Type,Data[j].Type)>0){
                flag = 0;
                Swap1(Data[j-1].Type,Data[j].Type);
            }
    }
}

void BubbleSort_Furnish(int n){
    int i, j,flag=0;
    for(i=1; i<n; i++){
        flag = 1;
        for(j=n-1; j>=i; j--)
            if(strcmp(Data[j-1].Furnish,Data[j].Furnish)>0){
                flag = 0;
                Swap1(Data[j-1].Furnish,Data[j].Furnish);
            }
    }
}

void Frekuensi_Location1(int n){
    int j;
    int k;

    for(j=0; j<n; j++){
        count = 1;
        for(k=j+1; k<n; k++){
            if(strcmp(Data[j].Location1,Data[k].Location1)==0){
                count++;               
                for(int e=k; e<n; e++){
                    strcpy(Data[e].Location1, Data[e+1].Location1);
            }
            n--;
            k--;
            }
        }
        if(count > maks){
            maks = count;
            strcpy(namakotamaks, Data[j].Location1);
        }
        if(count <= min){
            min = count;
            strcpy(namakotamin, Data[j].Location1);
        }
        
    printf("%s : %d\n", Data[j].Location1, count);
    }
    printf("Maximum Value: %s with frequency: %d\n", namakotamaks, maks);
    printf("Minimum Value: %s with frequency: %d\n", namakotamin, min);
}

void Frekuensi_Location2(int n){
    int j;
    int k;

    for(j=0; j<n; j++){
        for(k=j+1; k<n; k++){
            if(strcmp(Data[j].Location2,Data[k].Location2)==0){
                count++;               
                for(int e=k; e<n; e++){
                    strcpy(Data[e].Location2, Data[e+1].Location2);
            }
            n--;
            k--;
            }
        }

        if(count > maks){
            maks = count;
            strcpy(namakotamaks, Data[j].Location2);
        }
        if(count <= min){
            min = count;
            strcpy(namakotamin, Data[j].Location2);
        }
    printf("%s : %d\n", Data[j].Location2, count);
    }
    printf("Maximum Value: %s with frequency: %d\n", namakotamaks, maks);
    printf("Minimum Value: %s with frequency: %d\n", namakotamin, min);
}

void Frekuensi_Rooms(int n){
    int j;
    int k;
    int roomsterbanyak;
    int roomsterdikit;
    for(j=0; j<=9; j++){
        count = 0;
        for(k=0; k<n; k++){
            if(Data[k].Rooms == j){
                count++;
            }
            if(count>maks){
                maks = count;
                roomsterbanyak = j;
            }
            if(count<=maks){
                min = count;
                roomsterdikit = j;
            }
        }
    printf("%d : %d\n", j, count);
    }
    printf("Maximum Value: %d with frequency: %d\n",roomsterbanyak, maks);
    printf("Minimum Value: %d with frequency: %d\n",roomsterdikit, min);
}

void Frekuensi_Bathrooms(int n){
    int j;
    int k;
    int bathroomsterbanyak;
    int bathroomsterdikit;
    for(j=0; j<=9; j++){
        count = 0;
        for(k=0; k<n; k++){
            if(Data[k].Bathrooms == j){
                count++;
            }
            if(count>maks){
                maks = count;
                bathroomsterbanyak = j;
            }
            if(count<=maks){
                min = count;
                bathroomsterdikit = j;
            }
        }
    printf("%d : %d\n", j, count);
    }
    printf("Maximum Value: %d with frequency: %d\n",bathroomsterbanyak, maks);
    printf("Minimum Value: %d with frequency: %d\n",bathroomsterdikit, min);
}

void Frekuensi_CarParks(int n){
    int j;
    int k;
    int carparksterbanyak;
    int carparksterdikit;
    for(j=0; j<=9; j++){
        count = 0;
        for(k=0; k<n; k++){
            if(Data[k].CarParks == j){
                count++;
            }
            if(count>maks){
                maks = count;
                carparksterbanyak = j;
            }
            if(count<=maks){
                min = count;
                carparksterdikit = j;
            }
        }
    printf("%d : %d\n", j, count);
    }
    printf("Maximum Value: %d with frequency: %d\n",carparksterbanyak, maks);
    printf("Minimum Value: %d with frequency: %d\n",carparksterdikit, min);
}

void Frekuensi_Type(int n){
    int j;
    int k;
    char typeterbanyak[20];
    char typeterdikit[20];

    for(j=0; j<n; j++){
        for(k=j+1; k<n; k++){
            if(strcmp(Data[j].Type,Data[k].Type)==0){
                count++;               
                for(int e=k; e<n; e++){
                    strcpy(Data[e].Type, Data[e+1].Type);
            }
            n--;
            k--;
            }
        }

        if(count > maks){
            maks = count;
            strcpy(typeterbanyak, Data[j].Type);
        }
        if(count <= min){
            min = count;
            strcpy(typeterdikit, Data[j].Type);
        }
    printf("%s : %d\n", Data[j].Type, count);
    }
    printf("Maximum Value: %s with frequency: %d\n", typeterbanyak, maks);
    printf("Minimum Value: %s with frequency: %d\n", typeterdikit, min);
}

void Frekuensi_Furnish(int n){
    int j;
    int k;
    char furnishterbanyak[20];
    char furnishterdikit[20];

    for(j=0; j<n; j++){
        for(k=j+1; k<n; k++){
            if(strcmp(Data[j].Furnish,Data[k].Furnish)==0){
                count++;               
                for(int e=k; e<n; e++){
                    strcpy(Data[e].Furnish, Data[e+1].Furnish);
            }
            n--;
            k--;
            }
        }

        if(count > maks){
            maks = count;
            strcpy(furnishterbanyak, Data[j].Furnish);
        }
        if(count <= min){
            min = count;
            strcpy(furnishterdikit, Data[j].Furnish);
        }
    printf("%s : %d\n", Data[j].Furnish, count);
    }
    printf("Maximum Value: %s with frequency: %d\n", furnishterbanyak, maks);
    printf("Minimum Value: %s with frequency: %d\n", furnishterdikit, min);
}

void MaxMinPrice(int n){
    int maxprice = Data[0].Price;
    int minprice = Data[0].Price;
    int sumprice=0;
    for(int j=0; j<n; j++){
        sumprice = sumprice+Data[j].Price;
    }
    sumprice = sumprice / 3939;

    for(int j=0; j<n; j++){
        if(Data[j].Price>maxprice){
            maxprice = Data[j].Price;
        }
        if(Data[j].Price<=minprice){
            minprice = Data[j].Price;
        }
    }
    printf("Maximum Value: %d\n", maxprice);
    printf("Minimum Value: %d\n", minprice);
    printf("Average Value: %d\n", sumprice);
}

void MaxMinArea(int n){
    int maxarea = Data[0].Area;
    int minarea = Data[0].Area;
    int sumarea = 0;
    for(int j=0; j<n; j++){
        sumarea = sumarea + Data[j].Area;
    }
    sumarea = sumarea / 3939;
    for(int j=0; j<n; j++){
        if(Data[j].Area>maxarea){
            maxarea = Data[j].Area;
        }
        if(Data[j].Price<=minarea){
            minarea = Data[j].Area;
        }
    }
printf("Maximum Value: %d\n", maxarea);
printf("Minimum Value: %d\n", minarea);
printf("Average Value: %d\n", sumarea);

}
void Describe(char *NamaKolom){
        if(strcmp(NamaKolom,"Location1")==0){
            BubbleSort_Location1(3939);
            Frekuensi_Location1(3939);
        }else if(strcmp(NamaKolom,"Location2")==0){
            Frekuensi_Location2(3939);
        }else if(strcmp(NamaKolom,"Rooms")==0){
            BubbleSort_Rooms(3939);
            Frekuensi_Rooms(3939);
        }else if(strcmp(NamaKolom,"Bathrooms")==0){
            BubbleSort_Bathrooms(3939);
            Frekuensi_Bathrooms(3939);
        }else if(strcmp(NamaKolom,"CarParks")==0){
            BubbleSort_CarParks(3939);
            Frekuensi_CarParks(3939);
        }else if(strcmp(NamaKolom,"Type")==0){
            BubbleSort_Type(3939);
            Frekuensi_Type(3939);
        }else if(strcmp(NamaKolom,"Furnish")==0){
            BubbleSort_Furnish(3939);
            Frekuensi_Furnish(3939);
        }else if(strcmp(NamaKolom,"Price")==0){
            MaxMinPrice(3939);
        }else if(strcmp(NamaKolom,"Area")==0){
            MaxMinArea(3939);
        }else{
        printf("Nama kolom tidak ada!\n");
        }
}

int main(){
    FILE *ptr;
    ptr = fopen("file.csv", "r");

    if(ptr == NULL){
        printf("File tidak ditemukan\n");
    }

    char NamaKolom[15];

    printf("Nama kolom yang bisa Anda input (ketik nama kolom):\n");
    printf("Location1\n");
    printf("Location2\n");
    printf("Price\n");
    printf("Rooms\n");
    printf("Bathrooms\n");
    printf("CarParks\n");
    printf("Type\n");
    printf("Area\n");
    printf("Furnish\n");
    printf("Silakan input nama kolom yang ingin dideskripsikan: ");

    scanf("%s", &NamaKolom);
    getchar();

    //buat skip header
    char header[71];
    fscanf(ptr, "%[^\n]\n", &header);

    int i=0;
    while(!feof(ptr)){
        fscanf(ptr, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%s\n", &Data[i].Location1, &Data[i].Location2, &Data[i].Price, &Data[i].Rooms, &Data[i].Bathrooms, &Data[i].CarParks, &Data[i].Type, &Data[i].Area, &Data[i].Furnish);
        i++;
    }

    Describe(&NamaKolom);

    fclose(ptr);

    return 0;
}