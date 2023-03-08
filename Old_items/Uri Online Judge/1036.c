#include<stdio.h>
#include<math.h>>
main()
{
    double a, b, c, x, y;
    scanf("%lf %lf %lf", &a, &b, &c);

    x = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
    y = (- b - sqrt(b * b - 4 * a * c)) / (2 * a);

    if (a != 0 && (b * b - 4 * a * c) >= 0)
        printf("R1 = %.5lf\nR2 = %.5lf\n", x, y);
    else
        printf("Impossivel calcular\n");
}
