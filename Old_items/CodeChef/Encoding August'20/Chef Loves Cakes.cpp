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

    int x, test;

    ll n, m;

    cin >> test;

    while(test--)
    {
        cin >> n >> m;

        cout << (n * m) / __gcd(n, m)  << '\n';
    }

    return 0;
}

