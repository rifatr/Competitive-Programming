#include<bits/stdc++.h>
using namespace std;

int mark[100000003];
vector <int> primes;

void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.0);

    mark[0] = 1;
    mark[1] = 1;

    primes.push_back(2);

    for(i = 4; i <= n; i += 2)
        mark[i] = 1;

    for(i = 3; i <= n; i += 2) {
        if(!mark[i]) {
            primes.push_back(i);

            if(i <= limit)
            {
                for(j = i * i; j <= n; j += i * 2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

int odds(int n)
{
    if(n == 2)
        return 0;

    int x = n / 10, f = 1;
    while(x > 0)
    {
        int p = x % 10;
        x = x / 10;
        if(p % 2 == 0) {
            f = 0;
            break;
        }
    }

    return f;
}

int main()
{
    int x, y, i, z, q, ans, n = 100000002, l, r;
    scanf("%d", &q);

    sieve(n);
    while(q--)
    {
        scanf("%d %d", &x, &y);

        l = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
        r = lower_bound(primes.begin(), primes.end(), y) - primes.begin();

        if(primes[r] > y)
            r--;

        //printf("l = %d r = %d\n", l, r);

        ans = 0;
        for(z = l; z <= r; z++)
        {
            //cout << "mark = " << mark[z] << endl;
            //printf("prime[%d] = %d\n", z, primes[z]);
            ans += odds(primes[z]);
        }

        printf("%d\n", ans);
    }

    return 0;
}
