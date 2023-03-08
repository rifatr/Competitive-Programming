#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

map <char, int> a2n;

void init()
{
    lop(1, 27)
        a2n[(char) (i + 64)] = i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int test;
    string s;

    cin >> test;

    while(test--)
    {
        cin >> s;

        lop(0, s.size())
            cout << a2n[s[i]];

        cout << '\n';
    }

    return 0;
}

