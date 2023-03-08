#include<bits/stdc++.h>
#define ll long long

using namespace std;

int prime(ll n)
{
    if(n == 2)
        return 1;
    if(n < 2 || n % 2 == 0)
        return 0;

    ll limit = sqrt(n);

    for(ll i = 3; i <= limit; i += 2) {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
//    freopen("I input.txt", "r", stdin);
//    freopen("I output.txt", "w", stdout);
    ll n, i, limit;
    vector <ll> div;

    while(1)
    {
        scanf("%lld", &n);

        if(n == 0)
            return 0;

        if(n == 1 || n == -1) {
            printf("-1\n");
            continue;
        }

        //ll maxim = 3;

        limit = sqrt(abs(n));

//        if(n < 0) {
//            for(i = n; i > 0; i++)
//            {
//                if(n % i == 0 && prime(n / i) == 1)
//                    div.push_back(n / i);
//            }
//        }

        for(i = 1; i <= limit; i++)
        {
            if(n % i == 0)
            {
                if(i * i == n) {
                    if(prime(i) == 1)
                        div.push_back(i);
                }
                else {
                    if(prime(abs(i)) == 1)
                        div.push_back(abs(i));
                    if(prime(abs(n / i)) == 1)
                        div.push_back(abs(n / i));
                }
            }
        }

        ll l = div.size();
        sort(div.begin(), div.end(), greater <ll> ());

        for(i = 0; i <= l - 1; i++) {
            if(div[i] == div[i - 1])
                div.erase(div.begin() + i);
            //cout << "div = " << div[i] << endl;
        }

        l = div.size();

        if(l <= 1) {
            printf("-1\n");
            div.clear();
            continue;
        }

        printf("%lld\n", div[0]);

        div.clear();
    }

    return 0;
}

