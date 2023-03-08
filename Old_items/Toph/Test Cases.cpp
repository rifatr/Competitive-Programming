#include<bits/stdc++.h>

using namespace std;

struct TC
{
    int d, c, m;
};

#define ver(v) {cout << v << '\n'; return 0;}

int main()
{
    int n, cl, ml;

    cin >> n >> cl >> ml;

    TC tt[n];

    for(int i = 0; i < n; i++)
        cin >> tt[i].d >> tt[i].c >> tt[i].m;

    for(int i = 0; i < n; i++)
    {
        if(tt[i].c > cl) ver("CLE");

        if(tt[i].m > ml) ver("MLE");

        if(tt[i].d) ver("WA");
    }

    ver("AC");
}
