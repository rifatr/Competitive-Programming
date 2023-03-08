#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

#define N 1000005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll test, n;

    cin >> test;

    while(test--)
    {
        cin >> n;

        cout << (ll) (sqrt(n / 2)) * 2 << '\n';
    }

    return 0;
}
