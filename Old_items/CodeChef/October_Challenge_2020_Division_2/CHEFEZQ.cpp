#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int test;

    cin >> test;

    while(test--)
    {
        ll n, k;

        cin >> n >> k;

        ll Q[n + 1];

        loop(i, 1, n + 1) cin >> Q[i];
        Q[0] = 0;

        int f;

        loop(i, 1, n + 1)
        {
            Q[i] += Q[i - 1];
            Q[i] -= k;

            f = i;

            cout << i << ' ' << Q[i] << endl;

            if(Q[i] < 0)
            {
                cout << i << '\n';
                break;
            }
        }

        if(f == n and Q[f] >= 0)
        {
            ll x = ceil(Q[f] / k) + n;

            cout << x + 1 << '\n';
        }
    }

    return 0;
}
