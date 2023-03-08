#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;

    cin >> s >> t;

    string res = "Yes\n";

    for(int i = 0; i < s.size(); i++)
        if(s[i] != t[i])
            res = "No\n";

    cout << res;

    return 0;
}
