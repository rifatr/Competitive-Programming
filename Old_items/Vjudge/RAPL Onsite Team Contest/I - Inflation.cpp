#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j;
    double amm;
    vector <double> gas, smp;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> j;
        gas.push_back(j);
    }
    sort(gas.begin(), gas.end());

    for(i = 0; i < n; i++) {
        amm = gas[i] / (i + 1);
        if(amm > 1) {
            cout << "impossible\n";
            return 0;
        }
        smp.push_back(amm);
    }
    sort(smp.begin(), smp.end());

    cout << smp[0] << endl;
    return 0;
}
