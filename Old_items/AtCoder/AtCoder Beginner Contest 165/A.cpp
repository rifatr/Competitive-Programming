#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ll n, i, j, a, b;
    string s = "NG\n";

    cin >> n >> a >> b;

    for(i = 1; ; i++) {
        j = n * i;
        if(j >= a) {
            if(j <= b)
                s = "OK\n";
            break;
        }
    }


    cout << s;

    return 0;
}
