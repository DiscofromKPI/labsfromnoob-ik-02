#include <stdio.h> 
#include <stdlib.h> 


int roman(int, int, char);

int main() {
    while(1) {

        int a, correct; 

        printf("Type arabic number 1<a<30000 or 0 to exit: ");

             // scanf Возвращает количество правильных введеных параметров 
        while ((correct = scanf("%d", &a)) != 1      
               || a < 1
               || a > 30000) {
            fflush(stdin);       //очистка буфера входного буфера(пишешь фразу, оно очищает, можешь писать новую)
            if (a == 0 && correct == 1)     
                exit(0);
            printf("Error, type a number from 1 to 30000!: ");
        }
        
        a = roman(a, 1000, 'M');
        a = roman(a, 500, 'D');
        a = roman(a, 100, 'C');
        a = roman(a, 50, 'L');
        a = roman(a, 10, 'X');
        a = roman(a, 5, 'V');
        a = roman(a, 1, 'I');
        printf("\n\n");
    }
     
}
int roman(int k, int t, char p) {
    while (k >= t) {
        putchar(p);   //выводит один символ(p)
        k -= t;      //k = k - t


    }
    return k;
}
