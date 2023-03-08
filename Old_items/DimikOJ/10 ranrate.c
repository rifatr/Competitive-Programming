#include<stdio.h>

int main()
{
    double opposite_ran, team_ran, crr, rrr, ball;
    int t, i;
    scanf("%d", &t);

    for(i = 0; i < t; i++) {
        scanf("%lf %lf %lf", &opposite_ran, &team_ran, &ball);

        if(ball == 300)
            crr = 0.00;
        else
            crr = (team_ran / (300 - ball)) * 6.0;

        if(team_ran > opposite_ran)
            rrr = 0.00;
        else
            rrr = ((opposite_ran + 1 - team_ran) / ball) * 6.0;

        printf("%.2f %.2f\n", crr, rrr);
    }

    return 0;
}
