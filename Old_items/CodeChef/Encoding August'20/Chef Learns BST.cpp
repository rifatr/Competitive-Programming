#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

#define N 100005

int cnt[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    ll x, test, n, p;

    cin >> test;

    while(test--)
    {
        cin >> n;

        int a[n];

        lop(0, n)
        {
            cin >> a[i];
        }

        if(n == 1) {
            yes;
            continue;
        }

        x = 1, p = 0;

        bool f = 1;
        lop(0, n) {
            cnt[a[i]]++;
            if(cnt[a[i]] > 1)
            {
                f = 0;
                break;
            }
        }

        if(f) yes;
        else no;

        memset(cnt, 0, sizeof cnt);
    }

    return 0;
}


