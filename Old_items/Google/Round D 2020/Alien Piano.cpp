#include<bits/stdc++.h>

using namespace std;

#define ll              long long
#define lop(a, b)       for(int i = a; i < b; i++)
#define lopj(a, b)      for(int j = a; j < b; j++)
#define Case(i)         cout << "Case #" << int(i) << ": "

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
        int n = x, a[n];

        lop(0, x) cin >> a[i];

        int c = 0;

        lop(1, x)
        {
            if(a[i] == a[i - 1])
                continue;

            if(a[i] > a[i - 1])
            {
                c++;
            }
            else c--;
        }

        c = abs(c);
        int ans = ceil(c / 4.0);
        Case(t++);
        cout << ans - 1 << '\n';
    }

    return 0;
}
