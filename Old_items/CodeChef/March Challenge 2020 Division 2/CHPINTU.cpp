#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, m, n, i, j;
    int frts[55], price[55], total[55], vain[55];
    vector <int> x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i < 55; i++) {
            total[i] = 100000;
            vain[i] = 100000;
        }

        for(i = 0; i < n; i++)
            cin >> frts[i];
        for(i = 0; i < n; i++)
            cin >> price[i];
        for(i = 0; i < n; i++)
            total[frts[i]] = 0;
        for(i = 1; i <= m; i++) {
            if(total[i] != 0)
                vain[i] = i;
        }
        for(i = 0; i < n; i++)
        {
            total[frts[i]] += price[i];
        }

        for(i = 1; i <= m; i++) {
            int f = 1;
            for(j = 1; j <= m; j++) {
                if(vain[j] == i) {
                    f = 0;
                    break;
                }
            }
            if(f == 1)
                x.push_back(total[i]);
                //cout << i << "\tx = " << x[i - 1] << "\ttotal = " << total[i] << endl;
        }
        sort(x.begin(), x.end());

//        for(i = 0; i != x.size(); i++)
//            cout << x[i] << endl;

        cout << x[0] << endl;

        x.clear();
    }

    return 0;
}
