#include <stdio.h>
#include <conio.h>
void sort(double *ar, int num);
int main() {
do{
    int length = 0, n;

    do{
        printf("type the length of array: ");
        n = scanf("%d", &length);
        fflush(stdin);
        if(n != 1 || length <= 0){

            if(n != 1) {
                printf("type a number!\n");
                fflush(stdin);
            }else if(length < 1){
                printf("type the right amount of numbers!\n");
                fflush(stdin);
            }
        }
    }while(n != 1 || length < 1);

    double ar[length];
    for(int i = 0; i < length; i++ ){
        printf("type element (%d): ", i + 1);
        if (!scanf("%lg", &ar[i])){
            printf("error! type the number\n");
            fflush(stdin);
            i--;
        }
    }
    sort(ar, length);
    printf("result: \n ");
    for(int i = 0; i < length; i++){
        printf("%lg\n", ar[i]);
    }
    printf("You can Press any key to continue and ESC to exit:)");
}while(getch() != 27);
    return 0;
}
void sort(double *ar, int num)
{
    for(int a = 0; a < num - 1; a++)
        for(int b = a + 1; b < num; b++)
        { if(ar[a] > ar[b]){
             double t = ar[a];
                ar[a] = ar[b];
                ar[b] = t;
            }
        }
}
