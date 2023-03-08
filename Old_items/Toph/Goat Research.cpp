#include<bits/stdc++.h>

using namespace std;

int cnt(string s)
{
    int x = 0;

    for(int i = 0; i < s.size(); i++)
        x += s[i] == 'a';

    return x;
}

int main()
{
    int n, m = 0;

    cin >> n;

    string g;
    int sz[n];

    for(int i = 0; i < n; i++)
    {
        cin >> g;

        int x = cnt(g), y = g.size();

        if(x == 1) y++;
        else if(x & 1) y--;

        sz[i] = y;
        m = max(m, y);
    }

    for(int i = 0; i < n; i++)
    {
        string s((m  - sz[i]) / 2, ' ');

        cout << s << 'b';
        for(int j = 0; j < sz[i] - 1; j++)
            cout << 'a';
        cout << '\n';
    }

    return 0;
}
