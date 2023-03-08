#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll mod = 1e9 + 181, base = 45674;

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        int n;
        cin >> n;

        string s[n];
        lop(n) cin >> s[i];

        unordered_map <ll, int> pre;
        int ans = 0;
        lop(n)
        {
            x = s[i].size();
            ll p = 0;
            loop(j, 0, x)
            {
                p = ((p * base) + s[i][j]) % mod;
                pre[p]++;
                ans = max(ans, pre[p] * (j + 1));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}