#include<bits/stdc++.h>
#define N 1010

using namespace std;

bool mark[N];
vector <int> primes;

void sieve()
{
    int i, j, limit = sqrt(N * 1.0);

    mark[0] = mark[1] = true;

    primes.push_back(2);

    for(i = 4; i <= N; i += 2)
        mark[i] = true;

    for(i = 3; i <= N; i += 2)
    {
        if(mark[i] == false)
        {
            primes.push_back(i);

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
   // cout << mark[5] << primes[5];

//   if(mark[0])
//    cout << "false\n";

    int t, n, i, j;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n > 0)
            cout << 1 << endl;

        for(i = 0; i <= n ; i++)
        {
            if(primes[i] > n)
                break;

            cout << primes[i] << endl;
        }

        cout << endl;
    }

    return 0;
}
