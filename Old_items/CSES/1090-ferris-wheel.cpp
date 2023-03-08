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
    ll n, x, ans = 0;
    cin >> n >> x;

    deque <ll> p;
    lop(n)
    {
        int in; cin >> in;
        p.push_back(in);
    }

    sort(p.rbegin(), p.rend());

    while (p.size() > 1)
    {
        if (p.front() + p.back() <= x)
        {
            p.pop_back();
            p.pop_front();
        }
        else
            p.pop_front();

        ans++;
    }

    ans += (int) p.size();

    cout << ans << '\n';

    return;
}