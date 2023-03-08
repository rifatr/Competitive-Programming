#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n, q, i, j, k, x, y, z;
    string s;

    cin >> n >> q;
    cin.ignore();

    cin >> s;

    while(q--)
    {
        cin >> i >> j >> k;
        i--;

        if(k == 0)
            sort(s.begin() + i, s.begin() + j, greater <char> ());
        else
            sort(s.begin() + i, s.begin() + j);

        //cout << s << endl;
    }

    cout << s << endl;
}
