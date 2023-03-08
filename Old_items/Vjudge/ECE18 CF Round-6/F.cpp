#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int n, m, l, r, x;

    cin >> n >> m;

    int a[n + 1];

    lop(1, n + 1)
    {
        cin >> a[i];
    }

    while(m--)
    {
        cin >> l >> r >> x;

        int p = 0, q = 0;
        lop(x + 1, r + 1)
            if(a[i] < a[x])
                p++;
        lop(l, x)
            if(a[i] > a[x])
                q++;

        if(q == p)
            yes;
        else
            no;
    }

    return 0;
}

