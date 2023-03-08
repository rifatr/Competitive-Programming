
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

    ll n, k;

    cin >> n >> k;

    ll a[n];

    lop(0, n) cin >> a[i];

    sort(a, a + n);

    ll sum = 0;

    lop(0, k) sum += a[i];

    cout << sum << endl;

    return 0;
}
