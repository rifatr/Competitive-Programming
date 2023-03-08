#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int solve();

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
        cout << solve() << '\n';
    }

    return 0;
}

int solve()
{
    int n;
    cin >> n;
    n--;

    int a[n];
    lop(n) cin >> a[i];
    sort(a, a + n);

    lop(n) if (a[i] != i + 1) return i + 1;
    return n + 1;
}