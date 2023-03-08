#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, i;
    vector <int> v;

    cin >> t;
    for(i = 0; i < t; i++) {
        cin >> n;
        v.push_back(n);
    }

    reverse(v.begin(), v.end());

    for(i = 0; i < t; i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}
