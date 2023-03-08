#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    string s;

    freopen("input_o.txt", "r", stdin);
    freopen("output_o.txt", "w", stdout);

    cin >> t;
    cin.ignore();

    while(t--)
    {
        getline(cin, s);

        stack <char> q;

        for(i = 0; i < s.size(); i++)
        {
            if(!q.empty() && s[i] == ')' && q.top() == '(')
                q.pop();
            else if(!q.empty() && s[i] == ']' && q.top() == '[')
                q.pop();
            else if(s[i] != ' ')
                q.push(s[i]);
        }

        if(q.empty())
            cout << "Yes\n";
        else
            cout << "No\n";

        s.clear();
//        q.clear();
    }

    return 0;
}
