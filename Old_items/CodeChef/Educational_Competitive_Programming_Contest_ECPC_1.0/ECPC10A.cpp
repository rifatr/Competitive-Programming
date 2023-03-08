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

    int x, test;

    cin >> test;

    while (test--)
    {
        cin >> x;
        ll a[x];

        lop(x) cin >> a[i];

        int ans = 0;

        lop(x)
        {
            loop(j, i + 1, x)
            {
                if ((a[i] ^ a[j]) > max(a[i], a[j]))
                {
                    ans++;
                    cout << a[i] << ' ' << a[j] << ' ' << (a[i] ^ a[j]) << '\n';
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
