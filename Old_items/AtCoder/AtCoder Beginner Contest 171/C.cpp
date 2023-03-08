#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    ll n, digits = 0;

    cin >> n;

    string ch = "abcdefghijklmnopqrstuvwxyz", res = "";

    while(n)
    {
        n--;
        ll x = n % 26;

        //if(n < 26 and k % 26 == 0) x = n - 1;
        n /= 26;

        //if(x == 0) x = 26;

        res += ch[x];
    }

    //for(int i = digits - 1; i >= 0; i--) cout << nam[i];

    reverse(res.begin(), res.end());

    cout << res << '\n';
//main();
    return 0;
}

