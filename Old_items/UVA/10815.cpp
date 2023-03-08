#include<bits/stdc++.h>

using namespace std;

string lower(string s)
{
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            continue;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        else
            s[i] = ' ';
    }

    return s;
}

int main()
{
    freopen("10815 input.txt", "r", stdin);

    string line, word;
    set <string> dic;

    while(getline(cin, line))
    {
//        transform(line.begin(), line.end(), line.begin(), ::tolower);
//
//        for(int i = 0; i < line.size(); i++)
//        {
//            if(line[i] >= 'a' and line[i] <= 'z') continue;
//            else line[i] = ' ';
//        }

        line = lower(line);
        cout << line << endl;
        stringstream words(line);

        while(words >> word)
            dic.insert(word);
    }

    for(auto i = dic.begin(); i != dic.end(); i++)
        cout << *i << '\n';

    return 0;
}
