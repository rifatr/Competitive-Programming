#include<bits/stdc++.h>
#define N 900000

using namespace std;

int mark[N];
int primes[90000];
int np = 1;

void sieve()
{
    int i, j, limit = sqrt(N * 1.0);

    mark[0] = mark[1] = 1;

    primes[0] = 2;

    for(i = 4; i <= N; i += 2)
        mark[i] = 1;

    for(i = 3; i <= N; i += 2)
    {
        if(mark[i] == 0)
        {
            primes[np++] = i;

            if(i <= limit)
            {
                for(j = i * i; j <= N; j += i * 2)
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    sieve();

    //cout << primes[0];

    int i, j, z;

    for(i = 2; i <= 10; i++)
    {
        cout << i << ":";

        if(mark[i] == 0) {
            cout << " " << i << endl;
            continue;
        }

        for(j = 0; j < (i / 2) + 2 ; j++)
        {
            z = primes[j];

            if(z > i)
                break;

            if(i % z == 0)
                cout << " " << z;
        }

        cout << endl;
    }

    return 0;
}
