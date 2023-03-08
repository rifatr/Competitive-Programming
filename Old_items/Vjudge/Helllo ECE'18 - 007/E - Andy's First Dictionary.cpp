#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)

void lower(string &s)
{
    int l = s.size();

    lop(0, l)
    {
        if(s[i] >= 'a' and s[i] <= 'z')
            continue;

        if(s[i] >= 'A' and s[i] <= 'Z')
            s[i] += 32;

        else
            s[i] = ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line, word;
    set <string> dictionary;

    while(getline(cin, line))
    {
        lower(line);

        stringstream words(line);

        while(words >> word)
            dictionary.insert(word);
    }

    for(auto &z : dictionary)
        cout << z << '\n';

    return 0;
}

