#include <stdio.h>
#include <math.h>
#include <conio.h>

double fun1(double t, double x){
    return cos(t / x) - 2 * sin(1 / x) + 1 / x;
}
double fun2(double t, double x) {
    return sin(log(x)) - cos(log(x)) + t * log(x);
}
int main() {
    do {
        fflush(stdin);
        double t, x = 1, x1, x2, (*fun)(double, double), delta, eps, derivative ;
        char method;
        int correct, correct2;

        char selection;
        do{
            //fflush(stdin);
            printf("Choose function:\n"
                   "1.cos(y / x) - 2 * sin(1 / x) + 1 / x \n "
                   "2.sin(log(x)) - cos(log(x)) + y * log(x)\n ");
            selection = getchar();
            if(selection == '1'){
                fun = fun1;
            }
            else if(selection == '2'){
                fun = fun2;
            }else
                printf("type 1 or 2\n");
                fflush(stdin);
        }while(selection != '1' && selection != '2');
        do{
            printf("Choose method:\n"
                   "1. half division\n"
                   "2. Newton\n");
            method = getchar();

            if(method != '1' && method != '2') {
                printf("error! 1 or 2");
                fflush(stdin);
            }
        }while(method != '1' && method != '2');


        int correct1;
        do{
            printf("x1 = ");
            correct1 = scanf("%lf", &x1);
            if(selection == '2' && x1 < 0){
                printf("error number! Type a number >0\n");
                fflush(stdin);
            }
            else if(correct1 != 1){
                printf("Type a number!\n");
                fflush(stdin);
            }else if(x1 == 0){
                printf("type not a zero!\n");
                fflush(stdin);
            }
        }while(correct1 != 1 || x1 == 0 ||(selection == '2' && x1 < 0));

        int correct3;
        for(int valid = 0; !valid;){
            do{
                printf("x2 = ");
                correct3 = scanf("%lf", &x2);
                if(correct3 != 1){
                    printf("type a number!\n");
                    fflush(stdin);
                }
                else if(x2 == 0 ||(selection == '2' && x2 < 0)){
                    printf("Error number! Type a number >0\n");
                    fflush(stdin);
                }
            }while(correct3 != 1 || x2 == 0 ||(selection == '2' && x2 < 0));
            if(x2 - x1 > 0) valid = 1;
            else {
                printf("type a right num! ");
                fflush(stdin);
            }
        }
        do{
            printf("t: = ");
            correct = scanf("%lf", &t);
            if(correct != 1){
                printf("error, type a right number!\n");
                fflush(stdin);
            }
        }while(correct != 1);
        for(int valid = 0; !valid;){
            do {
                printf("type accuracy from 1e-7 to 0.5: ");
                correct2 = scanf("%lf", &eps);
                if(correct2 != 1){
                    printf("error");
                    fflush(stdin);
                }
            }while(correct2 != 1);
            if(eps < 1e-7){
                printf("type a right number!\n");
                fflush(stdin);
            } else if(eps > 0.5) {
                printf("type a right accuracy!\n");
                fflush(stdin);
            }
            else valid = 1;
        }
        double tz = 0.099;
        if(method == '2') x = x2;
        double funx = -fun(t, x);
        do{
            if(method == '1'){
                x = (x1 + x2) / 2;
                if(fun(t, x1) * fun(t, x) > 0) x1 = x;
                else x2 = x;
                delta = fabs(x2 - x1);
            }else if(method == '2'){
                derivative = (fun(t, x + tz) - funx) / tz;
                delta = fun(t, x) / derivative;
                x -=delta;
            }
        }while(fabs(delta) > eps);
         printf("x = %lf", x);
    }while(getch() != 27);
    return 0;
}
