#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int n, k, x, s = 0;

    cin >> n >> k >> x;

    int a[n];
    lop(0, n) cin >> a[i];

    lop(0, n - k) s += a[i];

    cout << s + (k * x) << '\n';

    return 0;
}

