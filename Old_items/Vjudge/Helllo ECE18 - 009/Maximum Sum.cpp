#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("Maximum Sum in.txt", "r", stdin);

    int n;

    cin >> n;

    int mat[n][n], colsum[n + 1][n + 1];
    memset(colsum, 0, sizeof colsum);

    lop(n) loop(j, 0, n) cin >> mat[i][j];

    loop(i, 1, n + 1) loop(j, 1, n + 1) colsum[j][i] = colsum[j - 1][i] + mat[j - 1][i - 1];

//    loop(i, 1, n + 1) {
//        loop(j, 1, n + 1)
//            cout << colsum[i][j] << ' ';
//        cout << endl;
//    }

    int res = -INT_MAX, sum;

    loop(a, 1, n + 1)
    {
        loop(b, a, n + 1)
        {
            sum = 0;
            loop(i, 1, n + 1)
            {
                sum += colsum[b][i] - colsum[a - 1][i];
                res = max(res, sum);
                if(sum < 0)
                    sum = 0;
            }
            // cout << a << ' ' << b << ' ' << sum << ' ' << res << '\n';
        }
    }

    cout << res << '\n';

    return 0;
}
