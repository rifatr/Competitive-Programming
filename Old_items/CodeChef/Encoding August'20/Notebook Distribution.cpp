#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

#define N 100005

int a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x, test, n, p;

    cin >> test;

    while(test--)
    {
        cin >> n >> x;

        ll sum = 0;

        lop(0, n)
        {
            cin >> a[i];
            sum += a[i];
        }

        if(sum < x) {
            cout << 0 << '\n';
            continue;
        }

        ll lo = 1, hi = (sum / x), mid, pre = 0;

        while(lo < hi)
        {
            mid = (lo + hi) / 2;

            if(mid == pre)
                mid++;
            pre = mid;

            sum = 0;
            lop(0, n) sum += a[i] / mid;

            if(sum >= x)
                lo = mid;
//            else if(sum == x)
//                lo = mid;
            else
                hi = mid - 1;

            //cout << lo << ' ' << mid << ' ' << hi << '\n';
        }

        cout << lo << '\n';
    }

    return 0;
}


/*
2
4 11
802 743 457 539
4 8
802 743 457 539
*/
