#include<bits/stdc++.h>

using namespace std;

string s;

bool checkvowel(int i)
{
    return s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y';
}

int main()
{
    cin >> s;

    int x = 0, maxa = 0, i = 0;

    while(i < s.size())
    {
        if(!checkvowel(i))
            x++;
        else {
            maxa = max(x, maxa);
            x = 0;
        }

        i++;
    }

    maxa = max(x, maxa);

    cout << maxa + 1 << '\n';

    return 0;
}
