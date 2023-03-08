#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    ll n, cnt = 0, i, l, j;
    string s, sal;

    cin >> s;

    l = s.size();

    for(i = 0; i <= l - 4; i++)
    {
        sal.assign(s, i, i + 4);
        stringstream x(sal);
        x >> n;

        //cout << "sal = " << sal << " n = " << n << endl;

        if(n % 2019 == 0)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}



