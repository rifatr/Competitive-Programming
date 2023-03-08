#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "
#define yes cout << "yes\n"
#define no cout << "no\n"

map <string, int> lst;

ll facto(ll x)
{
    ll i = 1;
    for(int p = 2; p <= x; p++) {
        i *= p;
    }

    return i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    string s, w;

    cin >> test;
    cin.ignore();

    while(test--)
    {
        getline(cin, s);

        ll n = 0, k = 1;
        stringstream ss(s);
        while(ss >> w) {
            lst[w]++;
            n++;
        }

        n = facto(n);

        for(auto it = lst.begin(); it != lst.end(); it++)
            k *= facto((ll) it -> second);

        cout << "1/" << n / k << '\n';

        lst.clear();
    }

    return 0;
}
