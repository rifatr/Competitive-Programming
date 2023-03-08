#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
    int i, in;
    vector <int> num, pum;

    for(i = 0; i < 3; i++) {
        cin >> in;
        pum.push_back(in);
    }

    num = pum;
    sort(num.begin(), num.end());

    for(i = 0; i < 3; i++) {
        cout << num.at(i) << endl;
    }
    cout << endl;
    for(i = 0; i < 3; i++) {
        cout << pum.at(i) << endl;
    }
    return 0;
}
