#include<bits/stdc++.h>
#define ll long long
#define mx 100000

using namespace std;
bool bs[100005];
vector<int>vs[100005];

void sieve()
{
    bs[1]=1;bs[2]=0;

    for(int i=2;i<=mx;i+=2)
        vs[i].push_back(2);

    for(int i=3;i<=mx;i+=2){
        bs[i+1]=1;
        if(!bs[i]){
            for(ll j=i+i;j<=mx;j+=i){
                bs[j]=1;
                vs[j].push_back(i);
            }
        }
    }
}

using namespace std;

int main()
{
    sieve();

    ll q, n, i, c, limit;

    scanf("%lld", &q);

    while(q--)
    {
        scanf("%lld", &n);

        c = 0;
        limit = sqrt(n);

        for(i = 1; i <= limit; i++)
        {
            if(n % i == 0)
            {
                if(i * i == n)
                    c++;
                else
                    c += 2;
            }
        }

        printf("%lld\n", c);
    }

    return 0;
}


