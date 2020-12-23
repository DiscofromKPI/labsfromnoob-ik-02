#include <stdio.h>
#include <conio.h>
#include <math.h>
double get_cos(double angle, double eps);
int main() {
    do{
        double x1, x2, step, eps;
        printf("type angle 'from', angle 'to', step, accuracy using ENTER \n");
        printf("Remember! Angles must be |<9999|, step > 0, accuracy <1 and >0.0001 \n");
        printf(": ");
        int correct = scanf("%lf %lf %lf %lf", &x1, &x2, &step, &eps);
        if(correct != 4){
            printf("error, type a number!\n");
            fflush(stdin);
        }else if((x1 == 0 && x2 == 0) || fabs(x1) > 9999 || fabs(x2) > 9999){
            printf("error! incorrect angles\n");
            fflush(stdin);
        }else if(step <= 0 ){
            printf("error! Incorrect step\n");
            fflush(stdin);
        }else if(eps < 0 || eps > 1 || eps <= 0.0001){
            printf("error! incorrent accuracy\n");
            fflush(stdin);
        }else if(x1 <= x2) {
            printf("angle\t\t angle1\t\t angle2\t\t difference\t\n");
            double x;
            for (x = x1; x <= x2; x += step ) {

                 printf("%lf\t %lf\t %lf\t %lf\t\n", x, get_cos(fmod(x, 360) * M_PI / 180, eps), cos(x * M_PI / 180), cos(x * M_PI / 180) - get_cos(fmod(x, 360) * M_PI / 180, eps));

            }if (fabs(x - step - x2) >= 0.00001)
                printf("%lf\t %lf\t %lf\t %lf\t\n", x2, get_cos(fmod(x2, 360) * M_PI / 180, eps), cos(x2 * M_PI / 180), cos(x2 * M_PI / 180) - get_cos(fmod(x2, 360) * M_PI / 180, eps));

            //printf("%lf\t %lf\t %lf\t %lf\t\n", x2, get_cos(fmod(x2, 360) * M_PI / 180, eps), cos(x2 * M_PI / 180), cos(x2 * M_PI / 180) - get_cos(fmod(x2, 360) * M_PI / 180, eps));
        }else if(x1 >= x2){
            printf("angle\t\t angle1\t\t angle2\t\t difference\t\n");
            double x;
            for ( x = x1; x >= x2 + step; x -= step) {
                printf("%lf\t %lf\t %lf\t %lf\t\n", x, get_cos(fmod(x, 360) * M_PI / 180, eps), cos(x * M_PI / 180), cos(x * M_PI / 180) - get_cos(fmod(x, 360) * M_PI / 180, eps));
            }
            if(fabs(x - step - x1)) printf("%lf\t %lf\t %lf\t %lf\t\n", x2, get_cos(fmod(x2, 360) * M_PI / 180, eps), cos(x2 * M_PI / 180), cos(x2 * M_PI / 180) - get_cos(fmod(x2, 360) * M_PI / 180, eps));
        }
            printf("You can Press any key to continue and ESC to exit:)");
    }while(getch() != 27);
    return 0;
}
double get_cos(double angle, double eps){
    double delta = 1, result = 1, n = 1;
    while(fabs(delta) >= eps){
        delta *= -pow(angle, 2) / 2 / n / (2 * n - 1);
        result += delta;
        n++;
    }

    return result;
}
