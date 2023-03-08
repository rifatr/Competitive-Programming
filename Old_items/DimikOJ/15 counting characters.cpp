#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, fq[26];
    string word;

    cin >> test;

    while(test--)
    {
        memset(fq, 0, sizeof(fq));

        cin >> word;

        for(auto &z : word)
            fq[z - 'a']++;

        for(int i = 0; i < 26; i++)
            if(fq[i])
                cout << (char) (i + 'a') << " = " << fq[i] << '\n';

        if(test) cout << '\n';
    }

    return 0;
}



