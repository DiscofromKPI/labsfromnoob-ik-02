#include <stdio.h>
#include <conio.h>


int check_year(int year);
int main() {
    do {
        int day, month, year, date, n, correct;
        printf("Enter a date like day.month.year:\n ");
        correct = scanf("%d.%d.%d", &date, &month, &year);
        fflush(stdin);
        if(correct != 3){
            printf("error, type the right date!\n");
            fflush(stdin);
        }
        else if((date < 1 || date > 31)
        || (month < 1 || month > 12)
        || (year < 1 || year > 9999)
        || (check_year(year) && month ==2 && date > 29)
        || (!check_year(year) && month == 2 && date > 28)
        || ((month != 1 && month != 3 && month != 5 && month != 8 && month != 9 && month != 10 && month != 12) && date > 30)) {
            printf("incorrect date!\n");
            fflush(stdin);
        } else {
            if (month > 2){
                n = 0;
            }
            else if(month <= 2){
                if(check_year(year)) {
                    n = 1;
                }else{
                    n = 2;
                }
            }

            day = ((int)(365.25 * year) + (int)(30.56 * month) + date + n) % 7;

            switch (day) {
                case 0:
                    printf("Monday\n");
                    break;
                case 1:
                    printf("Tuesday\n");
                    break;
                case 2:
                    printf("Wednesday\n");
                    break;
                case 3:
                    printf("Thursday\n");
                    break;
                case 4:
                    printf("Friday\n");
                    break;
                case 5:
                    printf("Saturday\n");
                    break;
                case 6:
                    printf("Sunday\n");
                    break;
            }
        }
    }while (getch() != 27);
    return 0;
}

int check_year(int year){
    return((year % 100 !=0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0));
}
