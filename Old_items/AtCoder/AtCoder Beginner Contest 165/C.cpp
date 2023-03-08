#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

struct X
{
    ll a, b, c, d;

    bool operator < (const X & b) const {
        return d > b.d;
    }
};

int main()
{
    ll n, m, q, i;
    //string s;

    cin >> n >> m >> q;
    ll A[n + 1] = {0};
    X x[q + 1];


    for(i = 1; i <= q; i++)
        cin >> x[i].a >> x[i].b >> x[i].c >> x[i].d;

    sort(x + 1, x + q + 1);

    //cout << x[1].a << x[1].b << x[1].c << x[1].d;

    ll sum = 0;

    for(i = 1; i <= q; i++) {
        if(A[x[i].a] == 0 && A[x[i].b] == 0)
        {
            A[x[i].a] = x[i].a;
            A[x[i].b] = x[i].a + x[i].c;
            sum += x[i].d;
        }
        else if(A[x[i].b] == 0)
        {
            //if(x[i].b - A[x[i].a] == x[i].c) {
                A[x[i].b] = x[i].c + A[x[i].a];
                sum += x[i].d;
            //}
        }
        else if(A[x[i].a] == 0)
        {
            //if(A[x[i].b] - x[i].a == x[i].c) {
                A[x[i].a] = x[i].c - A[x[i].b];
                sum += x[i].d;
            //}
        }
        else
        {
            if(A[x[i].b] - A[x[i].a] == x[i].c)
                sum += x[i].d;
        }
    }

    cout << sum << endl;

    return 0;
}



