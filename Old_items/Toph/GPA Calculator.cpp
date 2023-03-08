#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i, q, j;
    double p, cg;

    cin >> t;

    for(j = 1; j <= t; j++)
    {
        cin >> q;

        cg = 0.0;
        for(i = 0; i < q; i++)
        {
            cin >> p;
            cg += p;
        }

        printf("Case %d: %.3lf\n", j, cg / (q * 1.0));
        //cout << setprecision(3) << cg / (q * 1.0) << endl;
    }

    return 0;
}

