#include<bits/stdc++.h>

using namespace std;

int main()
{
    int c, o, d, e, n;

    c = d = o = e = 0;

    string s;

    cin >> n >> s;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'c')
            c++;
        else if(s[i] == 'o')
            o++;
        else if(s[i] == 'd')
            d++;
       else if(s[i] == 'e')
        e++;
    }

    cout << min(c, min(o, min(d, e))) << '\n';

    return 0;
}
