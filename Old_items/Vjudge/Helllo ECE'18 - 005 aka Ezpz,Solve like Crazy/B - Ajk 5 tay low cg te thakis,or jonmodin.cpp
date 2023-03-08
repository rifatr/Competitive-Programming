#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b = 0;
    string s;

    cin >> n >> s;

    for(a = 0; a < n - 1; a += 2) {
        if(s[a] == 'a' && s[a + 1] == 'a') {
            b++;
            s[a + 1] = 'b';
        }
        else if(s[a] == 'b' && s[a + 1] == 'b') {
            b++;
            s[a + 1] = 'a';
        }
    }

    cout << b << '\n' << s << '\n';

    return 0;
}

