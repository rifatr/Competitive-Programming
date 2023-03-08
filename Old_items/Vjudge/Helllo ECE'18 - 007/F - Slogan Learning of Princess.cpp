#include<bits/stdc++.h>

using namespace std;

#define lop(b) for(int i = 0; i < b; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    string slogan1, slogan2;
    map <string, string> slogans;

    cin >> x;
    cin.ignore();

    lop(x)
    {
        getline(cin, slogan1);
        getline(cin, slogan2);

        slogans[slogan1] = slogan2;
    }

    cin >> x;
    cin.ignore();

    lop(x)
    {
        getline(cin, slogan1);

        cout << slogans[slogan1] << '\n';
    }


    return 0;
}

