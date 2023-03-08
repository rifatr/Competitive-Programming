#include<bits/stdc++.h>

using namespace std;

bool vowel(char c)
{
    if(c < 'a') c += 32;

    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    string s;

    cin >> test;
    cin.ignore();

    while(test--)
    {
        getline(cin, s);

        string v, c;

        for(auto &z : s)
            if(isalpha(z))
                vowel(z) == 1 ? v += z : c += z;

        cout << v << "\n" << c << '\n';
    }

    return 0;
}
