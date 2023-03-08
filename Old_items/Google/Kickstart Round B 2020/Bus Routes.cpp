#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll t, k, d, inp, u, v;
    vector <ll> x, div, m, n, p;

    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cin >> k >> d;

        for(int j = 0; j < k; j++) {
            cin >> inp;
            x.push_back(inp);

            v = d / inp;
            div.push_back(v);
            u = inp * v;
            m.push_back(u);
        }

        while(1) {
        n = m;
        sort(n.begin(), n.end());

        if(m != n) {
            //cout << "not eq\n";
            for(int j = 0; j < k - 1; j++) {
                if(m[j] > m[j + 1]) {
                    //cout << m[j] << m[j+1] << endl;;
                    while(1) {
                        div[j]--;
                        m[j] = x[j] * div[j];
                        //cout << "change " << m[j] << endl;
                        if(m[j] <= m[j + 1])
                            break;
                    }
                }
            }
            n.clear();
        }
        else
            break;
        }

//        for(int j = 0; j < k; j++)
//            printf("%lld %lld %lld\n", x[j], div[j], m[j]);

        printf("Case #%d: %lld\n", i, m[0]);

        x.clear(); m.clear(); div.clear(); n.clear();
    }

    return 0;
}
