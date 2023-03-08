#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n, b, inp, sum, i, j, k;
    vector <long long> p;
    cin >> t;

    for(i = 1; i <= t; i++)
    {
        cin >> n >> b;
        for(j = 0; j < n; j++) {
            cin >> inp;
            p.push_back(inp);
        }

        sort(p.begin(), p.end());

        sum = 0;
        k = 0;

        for(j = 0; j < n; j++) {
            if(sum + p[j] <= b){
                sum += p[j];
                k++;
               // cout << "sum = " << sum << "\t";
            }
            else
                break;
        }

        cout << "Case #"<< i << ": " << k << endl;
        p.clear();
    }

    return 0;
}
