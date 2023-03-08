#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

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

        int v = 0;

        for(auto &z : s)
            v += vowel(z);

        cout << "Number of vowels = " << v << '\n';
    }

    return 0;
}

