#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, inp, sum = 0;
    vector <int> w;

    cin >> n >> k;

    while(n--)
    {
        cin >> inp;
        w.push_back(inp);
    }

    sort(w.begin(), w.end(), greater <int> ());

    //for(int i = 0; i < k; i++)
        cout << w[k - 1] << endl;
        //sum += w[i];

    //cout << sum << endl;

    return 0;
}
