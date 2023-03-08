#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

ll n, m, p, q;
map <pair <ll, ll>, bool> vis;
set <int> res;

void dfs(ll x, ll y, int m);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int test;

    cin >> test;

    while(test--)
    {
        cin >> n >> m >> p >> q;

        dfs(n, m, 0);

        cout << *res.begin() << '\n';

        //for(auto it = dp.begin(); it != dp.end(); it++)
          //cout << it -> first.first << ' ' << it -> first.second << ' ' << it -> second << endl;

        vis.clear(); 
        res.clear();   
    }

    return 0;
}

void dfs(ll x, ll y, int m)
{
    if(x == p and y == q)
    {
        res.insert(m);
        //cout << m << endl;
        return;
    }

    if(y > 7 * q and abs(x) > 7 * abs(p))
    {
        //cout << p << ' ' << q << '\n';
        return;
    }

    if(vis[{x, y}])
        return;

    vis[{x, y}] = 1;

    if(m < 11)
    {
        ll a, b, c, d;

        dfs(x + (2 * y), y, m + 1);
        dfs(x - (2 * y), y, m + 1);

        if(y + (2 * x) > 0)
            dfs(x, y + (2 * x), m + 1);
        else
            dfs(-x, -(y + (2 * x)), m + 1);

        if(y - (2 * x) > 0)
            dfs(x, y - (2 * x), m + 1);
        else
            dfs(-x, -(y - (2 * x)), m + 1);

        //cout << x << ' ' << y << ' ' << m << '\t';
        //printf("%lld %lld %lld %lld\n", a, b, c, d);

        return;
    }

    return ;
}