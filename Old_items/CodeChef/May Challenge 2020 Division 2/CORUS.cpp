#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll t, n, i, j, k, q, c, alpha[26];
    string s;

    cin >> t;

    while(t--)
    {
        for(i = 0; i < 26; i++)
            alpha[i] = 0;

        cin >> n >> q >> s;

        for(i = 0; i < n; i++)
        {
            k = s[i] % 97;
            alpha[k]++;
        }

        while(q--)
        {
            cin >> c;
            k = 0;
            for(i = 0; i < 26; i++)
                if(alpha[i] > c)
                k += alpha[i] - c;
            cout << k << endl;
        }
    }

    return 0;
}
