#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tt, n, a, b, t = 1, p;

    cin >> tt;

    while(tt--)
    {
        cin >> n;

        int x[n];

        for(int i = 1; i < n; i++)
            cin >> x[i];

        long long ans , sum, sum2;

        ans = sum = 0;
        a = b = p = 1;
        for(int i = 1; i < n; i++)
        {
            sum += x[i];

            if(ans <= sum)
            {
                if(ans == sum)
                    if(b - a == i + 1 - p)
                        if(a < p)
                            continue;

                ans = sum;
                a = p;
                b = i + 1;
            }

            if(sum < 0) {
                sum = 0;
                p = i + 1;
            }

        }

        if(ans)
            cout << "The nicest part of route " << t++ << " is between stops " << a << " and " << b << '\n';

        else
            cout << "Route " << t++ << " has no nice parts\n";
    }

    return 0;
}
