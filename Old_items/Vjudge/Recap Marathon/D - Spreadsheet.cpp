#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int r, c, sum, i, j;

    scanf("%d %d", &r, &c);

    int mat[r + 1][c + 1];

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
    }

    for(i = 0; i <= c; i++)
        mat[r][i] = 0;
    for(j = 0; j <= r; j++)
        mat[j][c] = 0;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++)
            mat[r][j] += mat[i][j];
    }

    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++)
            mat[j][c] += mat[j][i];
    }

    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++)
            mat[r][c] += mat[j][i];
    }


    for(i = 0; i <= r; i++) {
        for(j = 0; j <= c; j++) {
            if(j < c)
                printf("%d ", mat[i][j]);
            else
                printf("%d", mat[i][j]);
        }
            //printf("%d ", mat[i][j]);
        printf("\n");
    }









    /*for(i = 0; i < r; i++) {
        sum = 0;
        for(j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
            sum += mat[i][j];
        }
        printf("%d\n", sum);
    }
    for(i = 0; i < r; i++) {
        sum = 0;
        for(j = 0; j < c; j++) {
           // printf("%d ", mat[i][j]);
            sum += mat[j][i];
        }
        printf("%d ", sum);
    }*/

    return 0;
}
