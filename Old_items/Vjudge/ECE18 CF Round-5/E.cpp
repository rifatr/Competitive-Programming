#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    ll n, m, k, r, c;

    cin >> n >> m >> k;

    ll tt[m], mn[m], s = 0;

    lop(0, m) mn[i] = 999999999;

    lop(0, n)
    {
        cin >> r >> c;
        tt[r-1] = min(c, mn[r-1]);
        mn[r-1] = min(c, mn[r-1]);
    }

    lop(0, m) s += tt[i];

    cout << min(k, s) << '\n';

    return 0;
}

