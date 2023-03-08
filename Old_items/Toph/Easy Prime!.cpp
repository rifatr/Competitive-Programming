#include<bits/stdc++.h>
#define MAX 10000007

using namespace std;

bool mark[MAX];
//vector <int> primes;
//int prime[10000];

void sieve()
{
    int i, j, l = sqrt(MAX * 1.0);

    mark[1] = true;

    for(i = 4; i <= MAX; i += 2)
        mark[i] = true;

    for(i = 3; i <= l; i += 2) {
        if(mark[i] == false) {
            for(j = i * i; j <= MAX; j += i * 2)
                mark[j] = true;
        }
    }

//    primes.push_back(2);
//    //prime[0] = 2;
//    for(i = 3, j = 1; i <= MAX; i += 2)
//    {
//        if(mark[i] == false) {
//            primes.push_back(i);
//            //prime[j] = i;
//            //j++;
//        }
//           // primes.push_back(i);
//    }
}

int main()
{
    sieve();

    //cout << mark[15];

    int n, q, x, c, d, i, cx = 0, j;

    cin >> n;
    int arr[n + 1];

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> q;

    while(q--)
    {
        cin >> x >> c >> d;

        if(x == 1)
        {
            cx = 0;
            for(j = c; j <= d; j++) {
                if(!mark[arr[j]]) {
                    //cout << "p = " <<
                    cx++;
                }
            }
            cout << cx << endl;
        }

        else
        {
            arr[c] = d;
        }
    }

    return 0;
}
