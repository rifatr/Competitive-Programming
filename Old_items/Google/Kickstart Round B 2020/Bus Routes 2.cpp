#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t, k, d, inp, u, v;
    vector <ll> x, div, m, n, p;

    scanf("%lld", &t);

    for(int i = 1; i <= t; i++)
    {
        scanf("%lld %lld", &k, &d);

        for(int j = 0; j < k; j++)
        {
            cin >> inp;
            x.push_back(inp);

            v = d / inp;
            div.push_back(v);
            u = inp * v;
            m.push_back(u);
        }


        for(int j = k - 2; j >= 0; j--)
        {
            if(m[j] > m[j + 1])
            {
                //cout << m[j] << m[j+1] << endl;;
                u = m[j] - m[j + 1];
                v = ceil(u / (x[j] * 1.0));
                m[j] -= x[j] * v;
            }
        }

        printf("Case #%d: %lld\n", i, m[0]);

        x.clear();
        m.clear();
        div.clear();
    }


    return 0;
}
