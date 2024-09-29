#include<stdio.h>
#include<string.h>

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

void Swap1(char *a, char *b){
   char temp[100];
   strcpy(temp,a);
   strcpy(a,b);
   strcpy(b,temp);
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

int main(){
    FILE *ptr;
    ptr = fopen("file.csv", "r");

    if(ptr == NULL){
        printf("File tidak ditemukan\n");
    }

    int i=0;
    while(!feof(ptr)){
        fscanf(ptr, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%s\n", &Data[i].Location1, &Data[i].Location2, &Data[i].Price, &Data[i].Rooms, &Data[i].Bathrooms, &Data[i].CarParks, &Data[i].Type, &Data[i].Area, &Data[i].Furnish);
        i++;
    }

    printf("Array Location1 setelah disorting:\n");
    BubbleSort_Location1(3939);
    for(int j=0; j<3939; j++){
        printf("%s\n", Data[j].Location1);
    }
    
    fclose(ptr);

    return 0;
}
