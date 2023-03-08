#include<bits/stdc++.h>
using namespace std;

int main()
{
    for(int i = 1; ; i++)
    {
        string s;
        cin >> s;
        if(s == "*")
            break;
        if(s[0] == 'H')
            printf("Case %d: Hajj-e-Akbar\n", i);
        else
            printf("Case %d: Hajj-e-Asghar\n", i);
    }

    return 0;
}
