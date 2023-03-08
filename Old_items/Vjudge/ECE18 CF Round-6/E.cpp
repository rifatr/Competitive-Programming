#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int k, a, b, v, box = 0;

    cin >> k >> a >> b >> v;

    while(a > 0)
    {
        if(b >= k - 1)
        {
            b -= k - 1;
            a -= k * v;
        }

        else if(b > 0)
        {
            a -= (b + 1) * v;
            b = 0;
        }

        else
            a -= v;

        box++;
    }

    cout << box << '\n';

    return 0;
}

