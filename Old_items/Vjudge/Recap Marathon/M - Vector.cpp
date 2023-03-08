#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int q, i, x, p;

    vector <int> v;

    cin >> q;

    for(i = 0; i < q; i++) {
        cin >> x;
        if(x != 2)
            cin >> p;
        if(x == 0)
            v.push_back(p);
        else if(x == 1)
            cout << v[p] << endl;
        else
            v.pop_back();
    }

    return 0;
}
