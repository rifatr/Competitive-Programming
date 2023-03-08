#include<bits/stdc++.h>
#define ll long long

using namespace std;


vector <ll> prime;
int mark[100000000];

void sieve(ll n)
{
    ll i, j, limit = sqrt(n * 1.);

    mark[1] = 0;

    for(i = 4; i <= n; i += 2)
        mark[i] = 0;
    prime.push_back(2);

    for(i = 0; i <= n; i += 2){
        if(!mark[i])
        {
            prime.push_back(i);

            if(i <= limit) {
                for(j = i * i; j <= n; j += i * 2)
                    mark[j] = 0;
            }
        }

    }
}

int main()
{
    ll i, n, limit;
    vector <ll> div;

    while(1)
    {
        cin >> n;
        if(n == 0)
            return 0;
        if(n == 1 || n == -1) {
            printf("-1\n");
            continue;
        }

        sieve(n);

        for(i = 0; i < prime.size(); i++) {
            if(n % prime[i] == 0)
                div.push_back(prime[i]);
        }

        sort(div.begin(), div.end(), greater <ll> ());

        if(div.size() < 2)
            printf("-1\n");
        else
            printf("%lld\n", div[0]);

        div.clear();
    }
}
