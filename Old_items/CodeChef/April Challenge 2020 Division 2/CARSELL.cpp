#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

int main()
{
    int t, n, i;
    ll price, profit;
    vector <ll> all_price;

    cin >> t;

    while(t--)
    {
        all_price.clear();

        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> price;
            all_price.push_back(price);
        }

        sort(all_price.begin(), all_price.end(), greater <ll> ());
        profit = 0;

        for(i = 0; i < n; i++)
        {
            price = all_price[i] - i;
            if(price > 0)
                profit = ((price % mod) + (profit % mod)) % mod;
        }

        cout << profit << endl;
    }

    return 0;
}
