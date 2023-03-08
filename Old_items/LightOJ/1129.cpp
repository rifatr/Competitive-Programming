#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        int n;
        cin >> n;

        string s[n];
        lop(n) cin >> s[i];

        bool f = 1;
        sort(s, s + n);
        lop(n - 1)
        {
            x = s[i].size();
            if (x > s[i + 1].size())
                continue;

            if (s[i] == s[i + 1].substr(0, x))
            {
                f = 0;
                break;
            }
        }

        if (f) yes;
        else no;
    }

    return 0;
}