#include<bits/stdc++.h>

#define Case(i)         c
using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int x, test, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> x;

        int mn, c = 0;

        int a[x], b[x];

        mn = 0;

        lop(0, x) {
            cin >> a[i];
            b[i] = a[i];
        }

        cout << "Case #" << t++ << ": ";

        sort(b, b + x);

        if(x == 1)
            cout << 1 << '\n';

        else if(b[0] == b[x - 1])
            cout << 0 << '\n';

        else
        {
            lop(1, x)
            {
                if(a[i] < a[i - 1] and a[i - 1] > mn)
                {
                    c++;
                    mn = a[i - 1];
                }
            }
            if(a[x - 1] > mn)
                c++;
            cout << c << '\n';
        }





    }

    return 0;
}

