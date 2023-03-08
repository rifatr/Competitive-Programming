#include<bits/stdc++.h>

#define ll long long
#define bg begin
#define en end

using namespace std;

void print(vector <ll> ar, ll n)
{
    for(ll i = 0; i < n; i++)
    {
        cout << ar[i];
        if(i < n - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x, i;

    cin >> n;

    vector <ll> v, ar, s;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    ar = s = v;

    sort(s.bg(), s.en());

    if(s != v)
    {
        prev_permutation(ar.bg(), ar.en());

        print(ar, n);
    }

    print(v, n);

    s = v;

    sort(s.bg(), s.en(), greater <ll> ());

    if(s != v)
    {
        next_permutation(v.bg(), v.en());

        print(v, n);
    }

    return 0;
}

