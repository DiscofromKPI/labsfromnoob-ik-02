#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() {
    do {
        float y = 1, delta = 1, x, k, e;

        printf("type x, k and e: \n");
        int correct = scanf("%f %f %f", &x, &k, &e);
         // fix-0.25 9 1e-20
        int alexchecks = fmodf(k, 2);
        if (correct != 3) {
            printf("error! type a numbers!\n");
            fflush(stdin);
        } else if (fabsf(e) >= 1 || e == 0 || e < 1e-4) {
            printf("error! incorrect e\n");
            fflush(stdin);
        } else if (fabsf(k) <= 0.1) {
            printf("error, k is incorrect\n");
            fflush(stdin);
        }else if (k == 0) {
            printf("error! k must not be a 0\n");
            fflush(stdin);
        } else if (k < 0 && alexchecks != 0 && x == 0) {
            printf("error! incorrect numbers\n");
            fflush(stdin);
        } else if (k < 0 && alexchecks == 0 && x <= 0) {
            printf("error! incorrect numbers1\n");
            fflush(stdin);
        }else if (k > 0 && alexchecks == 0 && x < 0) {
            printf("error! incorrect numbers2\n");
            fflush(stdin);
        }
        else if(x == 0 && k > 0) printf("Result = 0");
        else {                                          //k > 0 && e <= 1 && e != 0
            while (fabsf(delta) >= fabsf(e)) {
                                                        //k = fabsf(k);
                delta = (1 / fabsf(k)) * ((x) / powf(y, (fabsf(k) - 1)) - y);
                y += delta;
        }
        if (k > 0) printf("%f\n", y);
        else if (k < 0) printf("%f\n", 1 / y);
    }
}while(getch() != 27);
        return 0;
}
