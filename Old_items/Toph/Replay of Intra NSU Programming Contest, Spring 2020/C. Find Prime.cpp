/*
* rifatrraazz
*/


#include<bits/stdc++.h>
#define N 510

using namespace std;


bool mark[N];
int primes[500];
int nP;

void sieve()
{
    int i, j, limit = sqrt(N * 1.0);

    mark[0] = mark[1] = true;

    primes[nP] = 2;

    for(i = 4; i < N; i += 2)
        mark[i] = true;

    for(i = 3; i < N; i += 2)
    {
        if(mark[i] == false)
        {
            nP++;
            primes[nP] = i;

            if(i <= limit)
            {
                for(j = i * i; j < N; j += i * 2)
                    mark[j] = true;
            }
        }
    }
}


int main()
{
    sieve();

    nP++;

//    cout << nP << endl;
//
//    for(int i = 0; i < nP; i++)
//        cout << primes[i] << ' ';

    int t, n, x, y;

    cin >> t;

    while(t--)
    {
        cin >> n;

        x = lower_bound(primes, primes + nP, n) - primes;
        y = upper_bound(primes, primes + nP, n) - primes;

        if(primes[x] >= n)
            x--;

        cout << primes[x] << " ";
        cout << primes[y] << "\n";
    }

    return 0;
}

