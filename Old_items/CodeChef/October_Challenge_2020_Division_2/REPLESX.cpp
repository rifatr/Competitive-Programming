#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    

    int test;

    cin >> test;

    while(test--)
    {
        int n, x, p, k;

        cin >> n >> x >> p >> k;

        p--, k--;

        int a[n];

        lop(n) cin >> a[i];

        sort(a, a + n);

        int ans = 0;

        if(!binary_search(a, a + n, x))
        {
            a[k] = x;

            sort(a, a + n);

            ans++;
        }

        if(a[p] == x)
        {
            cout << ans << '\n';
            continue;
        }

        if(a[k] == x and k != p)
        {
            cout << -1 << '\n';
            continue;
        }

        if(a[p] < x and k > p)
        {
            cout << -1 << '\n';
            continue;
        }

        if(a[p] > x and k < p)
        {
            cout << -1 << '\n';
            continue;
        }

        int i1 = lower_bound(a, a + n, x) - a;
        int i2 = upper_bound(a, a + n, x) - a;
        i2--;


        cout << min(abs(p - i1), abs(p - i2)) + ans << '\n';
    }

    return 0;
}
