#include <stdio.h>
#include <conio.h>
#include <string.h>


void swap(char **a,char **b); // ** - указатель на массив строк

int main() {
    do {
        int length, n;

        do{
            printf("Enter the length of array: ");
            n = scanf("%d", &length);
            if(n != 1) {printf("type a number!\n");
                fflush(stdin);}
            else if(length <= 0) printf("type a positive length!\n");
                fflush(stdin);
            }while(n != 1 || length <= 0);
        char list[length][200];         //массив массив символов
        char *arr[length];
        for(int i = 0; i < length; i++){
            printf("Enter string <200 [%d] : ", i + 1);
            fgets(list[i], 200, stdin);
            fflush(stdin); // очищает остаток
            //if(strlen(arr[i]) < 2) i--;
        }
        for(int i = 0; i < length; i++) arr[i] = list[i];  //передаем количество значений

        for(int a = 0; a < length - 1; a++)
            for(int b = a + 1; b < length; b++){
                if(strcmp(arr[a], arr[b]) > 0){
                    swap(&arr[a], &arr[b]);
                }
            }
        printf("Sorted array: \n");
        for(int i = 0; i < length; i++) printf("Element [%d]: %s\n", i + 1, arr[i]);
        printf("You can Press any key to continue and ESC to exit:)");
    }while(getch() != 27);
    return 0;
}

void swap(char **a, char **b){
    char *c;
    c = *a;
    *a = *b;
    *b = c;
}
