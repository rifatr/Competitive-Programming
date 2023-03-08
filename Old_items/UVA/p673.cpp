#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, bracket_1s, bracket_1e, bracket_2s, bracket_2e, flag;
    string line;

    cin >> t;
    getchar();

    while(t--) {
        getline(cin, line);

        if(line.size() == 0) {
            cout << "Yes\n";
            return 0;
        }

        bracket_1s = 0; bracket_1e = 0; bracket_2s = 0; bracket_2e = 0; flag = 0;

        for(i = 0; i < line.size(); i++) {
            if(line[i] == '(')
                bracket_1s++;
            else if(line[i] == ')')
                bracket_1e++;
            else if(line[i] == '[')
                bracket_2s++;
            else if(line[i] == ']')
                bracket_2e++;
            if((line[i] == '(' && line[i + 1] == ')') || (line[i] == '[' && line[i + 1] == ']'))
               flag = 1;
        }

        if(bracket_1s == 0 && bracket_1e == 0 && bracket_2s == 0 && bracket_2e == 0 )
            flag = 1;

        if(bracket_1s == bracket_1e && bracket_2s == bracket_2e && flag == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
