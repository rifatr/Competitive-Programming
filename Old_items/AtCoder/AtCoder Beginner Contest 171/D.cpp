
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

    //freopen("input.txt", "r", stdin)

    ll n, k, sum = 0, l, r;

    cin >> n;

    ll a[n + 1];

    lop(1, n + 1) { cin >> a[i]; sum += a[i];}

    cin >> k;

    lop(0, k)
    {
        cin >> l >> r;

//        if(a[l] < a[r]) sum += (a[r] - a[l]);
//        else sum -= (a[l] - a[r]);

        sum += (a[r] - a[l]);
        a[l] = a[r];

        cout << sum << '\n';
    }

    return 0;
}

