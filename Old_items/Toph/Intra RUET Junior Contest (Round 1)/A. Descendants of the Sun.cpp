#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

bool vowel(char c)
{
    if(c < 97)
        c += 32;

    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int x, test;
    string a, b;

    cin >> test;

    while(test--)
    {
        cin >> x >> a >> b;

        int s = 0, ss = 0;

        lop(0, x)
        {
            s += vowel(a[i]);
            ss += vowel(b[i]);
        }

        if(s > ss)
            cout << "First String\n";
        else if(ss > s)
            cout << "Second String\n";
        else
            cout << "Equal\n";
    }

    return 0;
}

