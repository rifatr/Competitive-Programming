#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"
#define Case(i) cout << "Case #" << (int) i << ":";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, test, t = 1, n, k;

    multiset < pair<ll, ll>> L;

    cin >> test;

    while(test--)
    {
        cin >> n >> k;

        lop(n)
        {
            cin >> x;
            
            ll p = (x + k - 1) / k;

            L.insert({p, i + 1});
        }

        Case(t++);

        for(auto &f : L)
        {
            cout << ' ' << f.second;
        }

        cout << '\n';

        L.clear();
    }

    return 0;
}
