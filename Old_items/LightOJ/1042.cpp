#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, tt = 1;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        bitset <32> b(n);
        string p;
        bool f = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(!f and b[i])
                p.push_back('0'), f = 1;
            if(!f) continue;

            p.push_back(b[i] + '0');
        }
        next_permutation(p.begin(), p.end());
        bitset <32> bt(p);

        printf("Case %d: %d\n", tt++, bt.to_ulong());
    }
}
