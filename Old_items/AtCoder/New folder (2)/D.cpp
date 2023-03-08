#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;


ll pow5(ll n)
{
    return n * n * n * n * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, i, j, a, b;

    cin >> n;

    for(i = -120; i <= 120; i++)
        for(j = -120; j <= 120; j++)
            if(pow5(i) - pow5(j) == n) {
                cout << i << " " << j << endl;
                return 0;
            }

    return 0;
}


