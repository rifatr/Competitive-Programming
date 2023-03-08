#include<bits/stdc++.h>

using namespace std;

const int N = 2004;
int a[N], b[N];
int x, y;
int lcs[N][N];
vector <int> pth;

int lcs_dp(int p, int q)
{
    if(p >= x or q >= y)
        return 0;

    if(lcs[p][q])
        return lcs[p][q];

    if(a[p] == b[q])
        lcs[p][q] = 1 + lcs_dp(p + 1, q + 1);

    else
        lcs[p][q] = max(lcs_dp(p, q + 1), lcs_dp(p + 1, q));

    return lcs[p][q];
}

void path(int i, int j)
{
    while(i >= 0 and j >= 0)
    {
        if(a[i] == b[j])
            pth.push_back(a[i]), i--, j--;

        else if(lcs[i - 1][j] > lcs[i][j - 1])
            i--;

        else
            j--;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    for(int i = 0; i < x; i++)
        cin >> a[i];

    cin >> y;
    for(int j = 0; j < y; j++)
        cin >> b[j];

    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            lcs[i][j] = 0;

    int ans = 0;

    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            ans = max(ans, lcs_dp(i, j));

    cout << ans << '\n';
    path(x - 1, y - 1);
    for(int i = ans - 1; i >= 0; i--)
        cout << pth[i] << ' ';

    return 0;
}
