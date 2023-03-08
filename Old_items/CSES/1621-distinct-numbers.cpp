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
    int n, a;
    set <int> s;

    cin >> n;
    lop(n) cin >> a, s.insert(a);

    cout << s.size() << '\n';

    return;
}