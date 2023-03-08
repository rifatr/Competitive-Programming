#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    long long t, x, s, l, minm, maxm;

    while(cin >> t and t)
    {
        s = maxm = 0;
        long long a[t], sum[t + 1];
        sum[0] = 0;

        for(int i = 0; i < t; i++)
        {
            cin >> a[i];
        }

        sort(a, a + t);

        for(int i = 0; i < t; i++)
            sum[i + 1] = sum[i] + a[i];

        maxm = a[t - 1]; s = sum[t];

        long long check[s + 1];
        bool cc[s + 1];
        for(int i = 0; i <= s; i++) {check[i] = 0; cc[i] = 0;}
        for(int i = 0; i <= t; i++) cc[sum[i]] = 1;

        for(int i = 1; i <= t; i++)
        {
            for(int j = i; j <= t; j++)
            {
                check[sum[j] - sum[i - 1]]++;

                long long p = a[i - 1] + a[j - 1];
                if(!cc[p]) {
                    check[p]++;
                }
            }
        }

//        for(int i = 0; i <= s; i++)
//            cout << i << " " << check[i] << endl;

        l = (long long) sqrt(s);
        x = 9999999999;

        for(long long i = 1; i <= l; i++)
        {
            if(s % i == 0) {
                long long xx = s / i;

                if(i >= maxm and check[i] >= xx)
                    x = min(x, i);
                if(xx >= maxm and check[xx] >= i)
                    x = min(x, xx);

//                cout << i << " " << check[i] << endl;
//                cout << xx << " " << check[xx] << endl;

            }
        }

        cout << x << '\n';
    }

    return 0;
}

