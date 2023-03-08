#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)

void yes(char a, string s, int n)
{
    cout << "Occurrence of '" << a << "' in '" << s << "' = " << n << '\n';
}

void no(char a)
{
    cout << "'" << a << "' is not present\n";
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int test;
    string line;
    char c;

    cin >> test;
    cin.ignore();

    while(test--)
    {
        getline(cin, line);
        scanf("%c", &c);
        getchar();

        int k = 0;

        for(auto &z : line)
            k += (z == c);

        if(k) yes(c, line, k);

        else no(c);
    }

    return 0;
}


