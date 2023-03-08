#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int t, i, u, p, cc;

    cin >> t;
    cin.ignore();

    while(t--)
    {
        cin >> s;

        u = count(s.begin(), s.end(), 'U');
        p = count(s.begin(), s.end(), 'P');
        cc = count(s.begin(), s.end(), 'C');

        cc /= 2;

        cout << min(u, min(p, cc)) << endl;
    }

    return 0;
}
