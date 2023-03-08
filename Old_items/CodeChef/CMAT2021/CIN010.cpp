#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(ll i = 0; i < b; i++)
#define loop(j, a, b) for(ll j = a; j < b; j++)

const int N = 1e5 + 8;
vector <ll> prime;
bool mark[N + 2];

void sieve();
void segsieve(ll l, ll r);

int main()
{
    sieve();

    int test, t = 1;;

    cin >> test;

    while (test--)
    {
        ll l, r;
        cin >> l >> r;

        segsieve(l, r);
    }

    return 0;
}

void sieve()
{
    mark[1] = 1;
    for (ll i = 4; i <= N; i += 2)
        mark[i] = 1;

    for (ll i = 3; i * i <= N; i += 2)
    {
        if (!mark[i])
        {
            for (ll j = i * i; j <= N; j += 2 * i)
                mark[j] = 1;
        }
    }

    loop(i, 1, N + 1)
    if (!mark[i])
        prime.push_back(i);
}

void segsieve(ll l, ll r)
{
    bool mrk[r - l + 2] = {0};
    if (l == 1)
        mrk[0] = 1;

    for (ll i = 0; prime[i] * prime[i] <= r; i++)
    {
        ll z = prime[i];
        ll j = z * z;
        if (j < l) j = ((l + z - 1) / z) * z;
        //cout << z << ' ' << j << '\n';

        for (; j <= r; j += z)
            mrk[j - l] = 1;
    }

    vector <ll> ans;
    lop(r - l + 1)
    {
        if (!mrk[i])
        {
            ans.push_back(l + i);
        }
    }

    int n = ans.size();
    lop(n)
    cout << ans[i] << (i < n - 1 ? ' ' : '\n');
}