#include<bits/stdc++.h>
#define ll unsigned long long
#define N 10000000

using namespace std;

bool mark[N];
//int primes[100000000];
int nP;
vector <int> primes;

void sieve()
{
    int i, j, limit = sqrt(N * 1.0);

    mark[0] = mark[1] = true;

    primes.push_back(2);
    //primes[nP] = 2;
    //cout << primes[nP];

    for(i = 4; i <= N; i += 2)
        mark[i] = true;

    for(i = 3; i <= N; i += 2)
    {
        if(mark[i] == false)
        {
            primes.push_back(i);
            nP++;
            //primes[nP] = i;

            if(i <= limit)
            {
                for(j = i * i; j <= N; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}

bool isPrime(ll n)
{
    if(n == 2)
        return true;

    if (n < 2 || n % 2 == 0)
        return false;

    for(ll i = 3; i * i <= n; i += 3)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    //ll o = primes.size();

    //cout << o << endl << primes[o-1];

    //cout << primes[0] << endl << primes[1] << endl << primes[nP-1];

    ll t, n, p, i, j, divisors, counter;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &n);

        divisors = 1;

        for(i = 0; ; i++)
        {
            counter = 1;
            ll p = primes[i], z = n;

            if(p * p * p > n)
            {
                //cout << "break\n";
                break;
            }

            while(n % p == 0)
            {
                n /= p;
                counter++;
                //cout << "d " << p << endl;
            }

            divisors *= counter;

            //cout << "divisors after while loop = " << divisors << endl;
        }

        ll x = sqrt(n);
        ll y = ceil(sqrt(n * 1.0));

//        cout << "n = " << n << endl;
//        cout << "square " << x << "\t" << y << endl;

        if(n >= N)
        {
            if(isPrime(n) == true)
            {
                divisors *= 2;
                //cout << n << " is a prime & > N\n";
            }
            else if(x == y && isPrime(n) == true)
            {
                divisors *= 3;
                //cout << n << " is a square prime & > N\n";
            }
            else if(n != 1)
            {
                divisors *= 4;
                //cout << n << " is not one & > N\n";
            }
        }
        else
        {
            if(mark[n] == false)
            {
                divisors *= 2;
                //cout << n << " is a prime\n";
            }
            else if(x == y && mark[x] == false)
            {
                divisors *= 3;
                //cout << n << " is a square prime\n";
            }
            else if(n != 1)
            {
                divisors *= 4;
                //cout << n << " is a not one\n";
            }
        }

        printf("%lld\n", divisors);
    }

    return 0;
}
