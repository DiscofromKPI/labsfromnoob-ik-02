#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    do {
        int counts = 0, c, error = 1, serror;
        double s = 0, e, n, p;
        char check_scan;
        label: do {
            printf("Enter the number of lines of system\n(Remeber that this is must be a number from 2 to 10):\n ");
            scanf("%d", &c);
            check_scan = getchar();
            serror = (check_scan != '\n' || c < 2 || c > 10);
            if (serror) {
                printf("Type a right number of system!\n");
                fflush(stdin);
            }

        } while (serror);
        do {
            printf("Enter accuracy [1e-15; 1): ");
            scanf("%lf", &e);
            check_scan = getchar(); // Ловим ошибку
            serror = (check_scan != '\n' || e >= 1 || e < 1e-15);
            if (serror) {
                printf("Type a right E!\n");
                fflush(stdin);
            }


        } while (serror);
        double **a = (double **) malloc(c * sizeof(double *)); //malloc выделяет блок памяти и возвращает указатель на начало блока
        double *b = (double *) malloc(c * sizeof(double));
        double *x = (double *) malloc(c * sizeof(double));      //sizeof - это унарный оператор, возвращающий длину в байтах переменной или типа, помещенных в скобки.
        double *tx = (double *) malloc(c * sizeof(double));
        for (int i = 0; i < c; i++) {
            a[i] = (double *) malloc(c * sizeof(double));
            for (int j = 0; j < c; j++) {
                do {
                    printf(" type element at 'x' [%d] [%d] [-200;200] = ", i + 1, j + 1);
                    scanf("%lf", &a[i][j]);
                    check_scan = getchar();
                    serror = (check_scan != '\n' || a[i][j] > 200 || a[i][j] < -200);
                    if (serror) {
                        printf("Type correct numbers!\n");
                        fflush(stdin);
                    }
                } while (serror);
            }
        }
        for (int i = 0; i < c; i++) {
            do {
                printf("type free element [%d] from -200 to 200: ", i + 1);
                scanf("%lf", &b[i]);
                check_scan = getchar();
                serror = (check_scan != '\n' || b[i] > 200 || b[i] < -200);
                if (serror) {
                    printf("Type a right numbers!\n");
                    fflush(stdin);
                }
            } while (serror);
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++)
                if (i != j) s += fabs(a[i][j]);
            if(fabs(a[i][i]) < s) {
                printf("Can not solve the system.\n");
                error = 0;
                goto label;
            }
            s = 0;
        }

        for (int i = 0; i < c; i++) x[i] = b[i] / a[i][i];
        do {
            for (int i = 0; i < c; i++) {
                n = 0;
                for (int j = 0; j < c; j++)
                    if (i != j)
                        n = n + a[i][j] * x[j];
                n = (b[i] - n) / a[i][i];
                tx[i] = n;
            }
            p = 0;
            for (int i = 0; i < c; i++) {
                if (fabs(x[i] - tx[i]) > p) {
                    p = fabs(x[i] - tx[i]);
                    x[i] = tx[i];
                }
            }
            counts++;
            if (counts > 1500) {
                printf("Has no solutions\n");
                error = 0;
                goto label;
            }
            } while (p > e && (error != 0));

             for (int i = 0; i < c; i++) {
                printf("x%d = %lf\n", i + 1, x[i]);
            }

    } while (getch() != 27);
    return 0;
}
