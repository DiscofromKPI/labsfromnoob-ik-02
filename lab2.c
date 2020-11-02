#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    while (1) {
        float a, b, c;   //3 sides

        printf("Type 3 sides using 'space' or type '0 0 0' to exit: ");
        int correct = scanf("%f %f %f", &a, &b, &c);
        fflush(stdin);

        if (a == 0 && b == 0 && c == 0) {
            exit(0);
        } else if (correct != 3) {
            printf("Error, type the right numbers1!\n");
            fflush(stdin);
        } else if (a + b <= c || a + c <= b || b + c <= a) {
            printf("Error, wrong sides, type the right sides! \n");
            fflush(stdin);

        } else if (a <= 0 || b <= 0 || c <= 0) {
            printf("Error, type the right sides! \n");
            fflush(stdin);
        } else {
            float p = a + b + c;
            printf("P = %f\n", p);

            float halfp = (a + b + c) / 2;
            printf("halfperimeter = %f\n", halfp);

            double s = sqrt(halfp * (halfp - a) * (halfp - b) * (halfp - c));
            printf("s = %.10lf\n", s);

            float ha = 2 * s / a;
            printf("height a = %f\n", ha);

            float hb = 2 * s / b;
            printf("height b = %f\n", hb);

            float hc = 2 * s / c;
            printf("height c = %f\n", hc);

            float ma = 0.5 * sqrt(2 * powf(b, 2) + 2 * powf(c, 2) - powf(a, 2));
            printf("Median a = %f\n", ma);

            float mb = 0.5 * sqrt(2 * powf(a, 2) + 2 * powf(c, 2) - powf(b, 2));
            printf("Median b = %f\n", mb);

            float mc = 0.5 * sqrt(2 * powf(a, 2) + 2 * powf(b, 2) - powf(c, 2));
            printf("Median c = %f\n", mc);

            float ga = 2 / (b + c) * sqrt(b * c * halfp * (halfp - a));
            printf("Bisector a = %f\n", ga);

            float gb = 2 / (a + c) * sqrt(a * c * halfp * (halfp - b));
            printf("Bisector b= %f\n", gb);

            float gc = 2 / (a + b) * sqrt(a * b * halfp * (halfp - c));
            printf("Bisector c = %f\n", gc);
        }
    }
}
