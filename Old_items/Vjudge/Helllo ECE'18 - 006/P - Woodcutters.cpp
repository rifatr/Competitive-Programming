#include<bits/stdc++.h>

#define ll long long
#define lop(n) for(int i = 0; i < n; i++)
#define lop1(n) for(int i = 1; i < n - 1; i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    ll x[n], h[n];

    lop(n)
        cin >> x[i] >> h[i];

    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    int c = 0;

    lop1(n)
    {
        if(x[i] - h[i] > x[i - 1])
            c++;
        else if(x[i] + h[i] < x[i + 1]) {
            c++;
            x[i] += h[i];
        }
    }

    cout << c + 2 << '\n';

    return 0;
}
