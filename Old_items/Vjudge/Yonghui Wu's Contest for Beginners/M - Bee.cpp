#include<iostream>

#define N 100
#define ll long long
using namespace std;

ll male[N + 1];

ll bfibo(ll n)
{
    if(n < 2) return male[n];

    if(male[n]) return male[n];

    return male[n] = bfibo(n - 1) + bfibo(n - 2) + 1;
}

int main()
{
    male[1] = 1;

    long long t, m = bfibo(80), f;

    //for(int i = 0; i < 50; i++) cout << male[i] << endl;

    while(cin >> t and t != -1)
    {
        m = male[t];

        f = male[t - 1] + 1;

        cout << m << " " << m + f << '\n';
    }

    return 0;
}
