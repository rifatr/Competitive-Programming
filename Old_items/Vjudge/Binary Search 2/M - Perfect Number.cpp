#include<bits/stdc++.h>

using namespace std;

#define N 10000000000000000

long long digit_sum(long long x);

int main()
{
    long long tt, t = 1, n;

    vector <int> p;

    for(int i = 19; i < 100000000; i++)
        if(digit_sum(i) == 10)
            p.push_back(i);

    cout << p.size() << " " << p[p.size() - 1];

//    cin >> tt;
//
//    while(tt--)
//    {
//        cin >> n;
//
//        long long lo = 1, hi = N, mid, x = -1, res;
//
//        while(lo < hi)
//        {
//            mid = lo + ((hi - lo) / 2);
//
//            x = digit_sum(mid);
//
//            if(x > n)
//                hi = mid - 1;
//            else
//                lo = mid + 1;
//        }
//
//        if(x == n)
//        {
//            res = mid % 5 == 0 ? mid : mid - (mid % 5);
//
//            printf("Case %lld: %lld\n", t++, res);
//        }
//
//        else
//            printf("Case %lld: impossible\n", t++);
//    }

    return 0;
}

long long digit_sum(long long x)
{
    long long n = 0;
    while(x)
    {
        n += x % 10;
        x /= 10;;
    }

    return n;
}

