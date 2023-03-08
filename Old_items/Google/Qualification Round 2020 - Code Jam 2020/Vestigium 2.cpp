#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, j, sum, r, c, k, f, z;
    int mat[101][101];
    int *start, *endd;

    scanf("%d", &t);

    for(k = 1; k <= t; k++)
    {
        scanf("%d", &n);

        sum = 0; r = 0; c = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &mat[i][j]);
                if(i == j)
                    sum += mat[i][j];
            }
        }

        for(i = 0; i < n; i++) {
            f = 0;
            for(j = 0; j < n - 1; j++) {
                for(z = j + 1; z < n; z++) {
                    if(mat[i][z] == mat[i][j]) {
                        f = 1;
                        break;
                    }
               }
            }
            r += f;
        }

        for(i = 0; i < n; i++) {
            f = 0;
            for(j = 0; j < n; j++) {
               for(z = j + 1; z < n; z++) {
                    if(mat[z][i] == mat[j][i]) {
                        f = 1;
                        break;
                    }
               }
            }
            c += f;
        }

        printf("Case #%d: %d %d %d\n", k, sum, r, c);
    }
}
