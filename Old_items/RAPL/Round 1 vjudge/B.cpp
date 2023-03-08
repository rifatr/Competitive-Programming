#include<bits/stdc++.h>

#define ll unsigned long long

#define lop(n) for(int i = 0; i < n; i++)
#define lopj(n) for(int j = 0; j < n; j++)
#define lopr(a, n) for(int i = 0; i < n; i++)

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main()
{
    fastio;

    ll tt, res;
    int n, c = 0;

    cin >> tt;

    bitset <64> b(tt);
    deque <bool> dd;

    for(int i=b._Find_first();i< b.size();i = b._Find_next(i)) {
        n = i;
        c++;
    }
    n++;

    lop(n)
        dd.push_back(b[i]);

//    cout << b << '\n' << n << " " << c << '\n';

    res = tt;

    lop(n)
    {
        bool x = dd[0];
        dd.pop_front();
        dd.push_back(x);

        bitset <64> tmp;

        lopj(n)
        {
            tmp[j] = dd[j];
        }

        res = max(res, tmp.to_ullong());
    }

    cout << res << endl;
//main();
    return 0;
}

