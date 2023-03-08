#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, c;

    cin >> c >> n;

    if(n == 0 or (n == 1 and c > 0)) {
        cout << "No\n";
        return 0;
    }

    c -= (n - 1);

    if(c < 0 or c & 1) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}

