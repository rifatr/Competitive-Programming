#include<bits/stdc++.h>

using namespace std;


int total_prime_factors(int x)
{
    int i, c = 1, divisors = 0;

    //cout << "Factors of " << x << endl;
    if(x % 2 == 0)
    {
        while(x % 2 == 0)
        {
            x /= 2;
        }
        //cout << " 2";
        divisors++;
    }

    int limit = sqrt(x * 1.0);

    for(int j = 3; j <= limit; j += 2)
    {
        c = 1;

        if(x % j == 0)
        {
            divisors++;
            // cout << " " << j;
        }

        while(x % j == 0)
        {
            x /= j;
        }
    }

    if(x != 1)
    {
        divisors++;
        //   cout << " " << x;
    }

    //cout << endl;

    return divisors;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q, n, k, a, b, z, counter;

    scanf("%d", &q);

    for(k = 1; k <= q; k++)
    {
        scanf("%d %d %d", &a, &b, &n);

        counter = 0;
        for(z = a; z <= b; z++)
        {
            int factors = total_prime_factors(z);
            if(factors == n)
            {
//                cout << "z = " << z << endl;
//                cout << "n = " << n << " factors = " << factors << endl;
                counter++;
            }
        }

        printf("%d\n", counter);
    }

    return 0;
}
