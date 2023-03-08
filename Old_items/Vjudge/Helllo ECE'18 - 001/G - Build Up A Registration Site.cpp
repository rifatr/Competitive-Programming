#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, x, j;
    string s;
    map <string, int> user;

    cin >> t;
    cin.ignore();

    for(i = 0; i < t; i++)
    {
        cin >> s;
        user[s]++;

        if(user[s] == 1)
            cout << "OK\n";
        else
            cout << s << user[s] - 1 << endl;

        s.clear();
    }

    return 0;
}
