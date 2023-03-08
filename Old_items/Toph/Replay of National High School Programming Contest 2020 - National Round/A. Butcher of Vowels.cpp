#include<bits/stdc++.h>

using namespace std;

bool is_monster(char c)
{
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main()
{
    int tt;

    cin >> tt;

    while(tt--)
    {
        string s, res = "No\n";

        cin >> s;

        for(int i = 0; i < s.size(); i++)
        if(is_monster(s[i])) {
            res = "Yes\n";
            break;
        }

        cout << res;
    }

    return 0;
}
