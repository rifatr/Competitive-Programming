#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll k, i, in, n, q;
    vector <ll> v;
    //pair <vector <ll> :: iterator, vector <ll> :: iterator> lu;

    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> in;
        v.push_back(in);
    }

    cin >> q;
    while(q--)
    {
        cin >> k;

        auto lu = equal_range(v.begin(), v.end(), k);

        cout << lu.first - v.begin() << " " << lu.second - v.begin()<< endl;
    }

    return 0;
}


