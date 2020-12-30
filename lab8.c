#include <stdio.h>
#include <conio.h>
#include <math.h>
typedef struct { double fp, sp;}
complex;
double input();
int main() {
    do{
        double R1, R2, C, L, fmin, fmax, step, f0, a, b, c, d;
        int cir;
        int correct;
        complex Z;
        do {
            printf("Choose a circuit. Type 1,2,3 or 4: ");
           correct = scanf("%d", &cir);
           if (correct != 1){
               printf("type a number: \n");
               fflush(stdin);
           }
           else if(cir < 1 || cir > 4) {
               printf("type a number from 1 to 4!\n");
               fflush(stdin);
           }

        }while (correct != 1 || cir < 1 || cir > 4);
            printf("Type R1: ");
            R1 = input();
            if(cir == 3 || cir == 4){
                printf("Type R2: ");
                R2 = input();
            }
            printf("\n>>>C = ");
            C = input();
            printf("\n>>>L = ");
            L = input();
            printf("\n>>>fmin = ");
            fmin = input();
            printf("\n>>>fmax = ");
            fmax = input();
            printf("\n>>>step = ");
           do{
                step = input();
                if(step <fmin || step > fmax){
                    printf ("Type a right step: ");
                    fflush(stdin);
                }
            }while(step <fmin || step > fmax);
        f0 = 1 / (2 * M_PI * sqrt(L * C));
        printf("\n\nResonanse frequancy: %lf Hz\n", f0);
        printf("Frequancy, Hz\tResistance, Ohm\n");
        for (;fmin <= fmax; fmin += step){
            double w = 2 * M_PI * fmin;
            if(cir == 1){
                a = L / C;
                b = -R1 / (w * C);
                c = R1;
                d = w * L - 1 / (w * c);
            }
            else if(cir == 2){
                a = L / C;
                b = R1 / (w * C);
                c = R1;
                d = w * L - 1 / (w * C);
            }
            else if(cir == 3){
                a = R1 * R2;
                b = R1 * (w * L - 1 / (w * C));
                c = R1 + R2;
                d = w * L - 1 / (w * C);
            }
            else if(cir == 4){
                a = R1 * R2 + L / C;
                b = w * L * R1 - R2 / (w * C);
                c = R1 + R2;
                d = w * L - (1 / (w * C));
            }
            Z.fp = (a * c + b * d) / (c * c + d * d);
            Z.sp = (b * c - a * d) / (c * c + d * d);
            printf("%lf\t %e + i * %e\n", fmin, Z.fp, Z.sp);
        }
        printf("Type ESC to exit or another key to continue!:-)");
    }while(getch() != 27);
    return 0;
}
double input(){
    double n;
    int correct;
    do{
        fflush(stdin);
        correct = scanf("%lf", &n);

        if(correct != 1){
            printf("type a number:");
            fflush(stdin);
        }else if(n == 0) {
        printf("A number must be >0: ");
        fflush(stdin);
        }
    }while(correct != 1 || n == 0);
        return n;
}
