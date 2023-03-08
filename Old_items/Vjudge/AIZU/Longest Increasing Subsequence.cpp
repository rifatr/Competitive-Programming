#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct pii
{
    ll x, y;

    bool operator < (const pii & B) const
    {
        return x < B.x and y < B.y;
    }
};

int main()
{
    int n;

    cin >> n;

    pii a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    vector <pii> lis;

    for(int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);

        if(it == lis.end())
            lis.push_back(a[i]);

        else
            lis[it - lis.begin()] = a[i];
    }

    cout << lis.size() << '\n';

    return 0;
}
