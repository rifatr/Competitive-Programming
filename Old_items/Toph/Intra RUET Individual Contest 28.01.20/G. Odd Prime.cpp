#include<bits/stdc++.h>
using namespace std;

int is_prime(int n)
{
    int i;

    if(n % 2 == 0) {
        return 0;
    }

    for(i = 3; i * i <= n; i = i + 2) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int odds(int n)
{
    int x = n, f = 1;
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
    int x, y, i, z, q, ans;
    vector <int> primes;
    for(i = 3; i < 100000002; i++) {
        primes.push_back(is_prime(i));
    }
    scanf("%d", &q);

    while(q--)
    {
        scanf("%d %d", &x, &y);

        if(x < 3)
            x = 3;
        ans = 0;
        for(z = x; z <= y; z++)
        {
            if(primes[z] == 0)
                continue;

            else
                ans += odds(z);
        }

        printf("%d\n", ans);
    }

    return 0;
}
