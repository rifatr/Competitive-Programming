#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"
#define Case(i) cout << "Case #" << (int) i << ": ";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, test, t = 1, n, k, y;

    vector <pair <ll, ll>> L;

    cin >> test;

    while(test--)
    {
        cin >> n >> k;

        lop(n)
        {
            cin >> x >> y;
            
            L.push_back({x, y});
        }

        Case(t++);

        sort(L.begin(), L.end());

        ll ans = 1, p = L[0].first + k;

        lop(n)
        {
            ll q = L[i].second;

            if(q > p)
            {
                if(p < L[i].first)
                    p = L[i].first;

                ll m = q - p;

                ll o = (m + k - 1) / k;

                ans += o;

                p += (o * k);
            }
        }

        cout << ans << '\n';

        L.clear();
    }

    return 0;
}
