#include<bits/stdc++.h>

using namespace std;

string decode(string s)
{
    for(int i = 0; i < s.size(); i++)
        s[i] -= 7;

    return s;
}

int main()
{
    //freopen("458 input.txt", "r", stdin);

    string code;

    while(getline(cin, code))
        cout << decode(code) << '\n';

    return 0;
}
