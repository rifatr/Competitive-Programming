#include<bits/stdc++.h>

using namespace std;


string cipher(string s, int n)
{
    int l = s.size();

    for(int i = 0; i < l; i++)
    {
        if(s[i] == ' ')
            continue;

        if(s[i] - n < 'a')
            s[i] = 'z' + (s[i] - 'a') - n + 1;
        else
            s[i] -= n;
    }

    return s;
}

int main()
{
    int n;
    string s;

    cin >> n;
    cin.ignore();

    getline(cin, s);

    cout << cipher(s, n) << endl;

    return 0;
}
