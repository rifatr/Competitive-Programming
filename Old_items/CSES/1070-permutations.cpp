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
    int n;
    cin >> n;

    if (n == 2 or n == 3)
    {
        cout << "NO SOLUTION\n";
        return;
    }

    for (int i = 2; i <= n; i += 2)
        cout << i << ' ';
    for (int i = 1; i <= n; i += 2)
        cout << i << ' ';

    return;
}