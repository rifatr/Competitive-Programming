#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long s;
    vector <char> v;

    cin >> s;

    if(!s)
    {
        cout << 0 << endl;
        return 0;
    }

    int p = 0;

    while(s)
    {
        v.push_back('0' + (s % 10));

        if(p == 2 and s > 9) {
            v.push_back(',');
            p = 0;
        }
        else p++;

        s /= 10;
    }

    for(int i = v.size() - 1; i >= 0; i--)
        cout << (char) v[i];
    cout << endl;

    return 0;
}
