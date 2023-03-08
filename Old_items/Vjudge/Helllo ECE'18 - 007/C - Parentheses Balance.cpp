#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;

    cin >> test;
    cin.ignore();

    while(test--)
    {
        string seq;
        stack <char> parenthesis;

        getline(cin, seq);

        int n = seq.size();

        lop(0, n)
        {
            if(!parenthesis.empty() and seq[i] == ')' and parenthesis.top() == '(')
                parenthesis.pop();

            else if(!parenthesis.empty() and seq[i] == ']' and parenthesis.top() == '[')
                parenthesis.pop();

            else if(seq[i] != ' ')
                parenthesis.push(seq[i]);
        }


        cout << (parenthesis.empty() == true ? "Yes" : "No") << '\n';
    }

    return 0;
}

