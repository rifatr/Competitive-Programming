#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, i, j, sum, r, c, k, f;
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

        cout << "row count" << endl;
        for(i = 0; i < n; i++) {
            f = 0;
            for(j = 0; j < n - 1; j++) {
                start = &mat[i][j];
                endd = &mat[i][n - 1];
                if(count(start, endd, *start) > 1) {
                    cout << "position = " << i << " " << j << " " << *start << " = " << count(start, endd, *start) << endl;
                    f = 1;
                }
            }
            r += f;
        }
        cout << "column count" << endl;
        for(i = 0; i < n; i++) {
            f = 0;
            for(j = 0; j < n; j++) {
                start = &mat[j][i];
                endd = &mat[n - 1][i];
                if(count(start, endd, *start) > 1) {
                    cout << "position = " << i << " " << j << " " << *start << " = " << count(start, endd, *start) << endl;
                    f = 1;
                }
            }
            c += f;
        }

        printf("Case #%d: %d %d %d\n", k, sum, r, c);
    }
}
