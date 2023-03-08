#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

void solve();

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int test = 1;

    // cin >> test;

    while (test--)
    {
        solve();
    }

    return 0;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size(), c = 1, m = 0;

    lop(n - 1)
    {
        if (s[i] == s[i + 1])
            c++;
        else
        {
            m = max(m, c);
            c = 1;
        }
    }
    m = max(m, c);

    cout << m;
    return;
}