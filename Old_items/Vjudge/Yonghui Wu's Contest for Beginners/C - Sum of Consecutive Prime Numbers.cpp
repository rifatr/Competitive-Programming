#include<iostream>
#include<math.h>


#define N 11000

using namespace std;

bool mark[N];
int primes[10000];
int p;


void sieve()
{
    int i, j, limit = sqrt(N * 1.0);

    mark[0] = mark[1] = true;

    primes[p++] = 2;

    for(i = 4; i <= N; i += 2)
        mark[i] = true;

    for(i = 3; i <= N; i += 2)
    {
        if(mark[i] == false)
        {
            primes[p++] = i;

            if(i <= limit)
            {
                for(j = i * i; j <= N; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}

int main()
{
    sieve();

    //for(int i = 0; i < 20; i++) cout << primes[i] << " ";

    int n, c, s;

    while(cin >> n and n)
    {
        c = 0;
        for(int i = 0; primes[i] <= n; i++)
        {
            s = 0;
            for(int j = i; primes[j] <= n; j++)
            {
                s += primes[j];

                if(s == n) {
                    c++; break;
                }

                if(s > n) break;
            }
        }

        cout << c << '\n';
    }
}
