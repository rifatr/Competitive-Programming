#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

#define yes cout << "yes\n"
#define no cout << "no\n"
#define ret return 0

int moo[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    ll n, k;

    cin >> n >> k;

    if(k == 1) {
        yes; ret;
    }

    if(n % 2 == 0) {
        no; ret;
    }

    if(k >= n - 1 and k > 2) {
        no; ret;
    }

    if(k >= n - 1 and k <= 2) {
        yes; ret;
    }

    if(n == 3 or n == 5) {
        yes; ret;
    }

    if(k >= n / 2) {
        no; ret;
    }

    ll mo, l = sqrt(n);
    bool f = 0;

    for(ll i = 1; i <= min(k, l); i++) {
        mo = n % i;

        moo[mo]++;

        if(moo[mo] > 1) {
            f = 1; break;
        }
    }

    if(f) no;
    else yes;

    return 0;
}

