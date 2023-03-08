#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

char small(char a)
{
    if (a >= 'a')
        return a;
    return a + 32;
}

int main()
{
    int x, test, t = 1;;

    cin >> test;
    cin.ignore();

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        string v1, v2, s;
        getline(cin, s);
        lop(s.size())
        {
            if (s[i] == ' ') continue;
            v1.push_back(small(s[i]));
        }
        getline(cin, s);
        lop(s.size())
        {
            if (s[i] == ' ') continue;
            v2.push_back(small(s[i]));
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        v1 == v2 ? yes : no;
    }

    return 0;
}