#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    stack <char> e;

    for(int i = 0; i < s.size(); i++)
    {
        bool f = !e.empty();

        if(f and s[i] == ')' and e.top() == '(')
                e.pop();

        else if(f and s[i] == ']' and e.top() == '[')
                e.pop();

        else if(f and s[i] == '}' and e.top() == '{')
                e.pop();

        else
            e.push(s[i]);
    }

    cout << (e.empty() ? "Yes\n" : "No\n");

    return 0;
}
