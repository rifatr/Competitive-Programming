#include<bits/stdc++.h>

using namespace std;

const int N = 1002;
string a, b;
int x, y;
int lcs[N][N];

int lcs_dp(int p, int q)
{
    if(p < 0 or q < 0)
        return 0;

    if(lcs[p][q] != -1)
        return lcs[p][q];

    if(a[p] == b[q]) {
        lcs[p][q] = 1 + lcs_dp(p - 1, q - 1);
        //cout << p << q << lcs[p][q] << endl;
    }

    else
        lcs[p][q] = max(lcs_dp(p, q - 1), lcs_dp(p - 1, q));

    return lcs[p][q];
}

int main()
{
    int tt;

    cin >> tt;

    while(tt--)
    {
        cin >> a >> b;

        x = a.size(), y = b.size();

        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                lcs[i][j] = -1;

        int ans = 0;

        for(int i = x - 1; i >= 0; i--)
            for(int j = y - 1; j >= 0; j--) {
                ans = max(ans, lcs_dp(i, j));
                //cout << i << j << ans << endl;
            }

        cout << ans << '\n';
    }

    return 0;
}

