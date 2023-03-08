/*
* rifatrraazz
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k, x, i, j, p, inp;
    vector <int> v;

    cin >> t;

    for(i = 1; i <= t; i++)
    {
        cin >> n >> k >> x;

        string res = "YES\n";
        for(j = 0; j <n; j++)
        {
            cin >> inp;
            v.push_back(inp);
        }

        for(j = 1; j <n; j++)
        {
            //cout << "pre = " << v[j] << " " << k << endl;

            p = abs(v[j] - v[j - 1]);
            p = ceil(p / (x * 1.0));

            v[j] += (p * x);
            k -= p;

            //cout << v[j] << "\t" << k << endl;

            if(k < 0) {
                res = "NO\n";
                break;
            }
        }

        cout << "Case " << i << ": " << res;
        v.clear();
    }

    return 0;
}

