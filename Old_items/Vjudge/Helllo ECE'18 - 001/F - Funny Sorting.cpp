#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, q, m, n, i, j, inp, k;
    vector <int> a, p, b;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i < n; i++)
        {
            cin >> inp;
            a.push_back(inp);
        }

        for(i = 0; i < m; i++)
        {
            cin >> inp;
            p.push_back(--inp);
        }

        b = a;
        sort(b.begin(), b.end());

        for(i = 0; i < m; i++)
        {
            for(j = p[i]; j < n - 1; j++)
            {
                if(a[j] >= a[j + 1]) {
                    if(p[i + 1] == j + 1)
                            p[i + 1]--;

                    swap(a[j], a[j + 1]);
                }
                else
                    break;
            }

        }

        if(b == a)
            cout << "YES\n";
        else
            cout << "NO\n";

        a.clear();
        b.clear();
        p.clear();
    }

    return 0;
}
