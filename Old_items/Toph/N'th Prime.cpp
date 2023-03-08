#include<bits/stdc++.h>
using namespace std;

int mark[10000003];
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
            //mark[i] = 1;
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

int main()
{
    int x, n = 10000002;
    scanf("%d", &x);

    //cout << x;

    sieve(n);

    cout << primes[x - 1] << endl;

    return 0;
}

