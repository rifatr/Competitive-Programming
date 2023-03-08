#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    if(n == 24)
    {
        if(s[0] > '2')
            s[0] = '0';
        if(s[0] > '1' and s[1] > '3')
            s[0] = '0';
        if(s[3] > '5')
            s[3] = '0';
    }

    else
    {
        if(s[0] > '1')
            s[0] = '0';
        if(s[0] > '0' and s[1] > '2')
            s[0] = '0';
        if(s[0] == '0' and s[1] == '0')
            s[0] = '1';
        if(s[3] > '5')
            s[3] = '0';
    }

    cout << s << '\n';

    return 0;
}
