#include <stdio.h>
#include <conio.h>
#include <math.h>


int main() {
    do {
        float a = 0, b = 0, c = 0, correct;
        printf("type a, b, c using space: \n");
        correct = scanf("%f %f %f", &a, &b, &c);
        fflush(stdin);

        if(correct != 3){
            printf("Error");
            fflush(stdin);
        } else {
            float p = b - powf(a, 2) / 3;
            float q = 2 * powf(a, 3) / 27 - (a * b / 3) + c;
            float d = powf(p, 3) / 27 + powf(q, 2) / 4;
            float x1, x2, x3;

            if (d > 0) {
                float u = cbrtf(-(q / 2) + sqrtf(d));
                float v = -p / (3 * u);
                x1 = u + v;
                x2 = -(u + v) / 2;
                x3 = sqrtf(3) * (u - v) / 2;
                printf("X1 = %f\n", x1 - a / 3);
                printf("X2 = %f + %f * i\n ", x2 - a / 3, x3);
                printf("X3 = %f  - %f * i\n", x2 - a / 3, x3);
            } else if (d == 0) {
                x1 = 3 * q / p;
                x2 = (-3 * q) / (2 * p);
                printf("X1 = %f\n", x1 - a / 3);
                printf("X2 = X3 = %f\n", x2 - a / 3);
            } else if (d < 0) {
                float r = sqrtf(-powf(p, 3) / 27);
                float f = acosf(-q / 2 * r);
                x1 = 2 * fabsf(cbrtf(r)) * cos(f / 3);
                x2 = 2 * fabsf(cbrtf(r)) * cos((f + 2 * M_PI) / 3);
                x3 = 2 * fabsf(cbrtf(r)) * cos((f + 4 * M_PI) / 3);
                printf("X1 = %f\n", x1 - a / 3);
                printf("X2 = %f\n", x2 - a / 3);
                printf("X3 = %f\n", x3 - a / 3);
            }
        }
    } while (getch() != 27);
    return 0;
}
