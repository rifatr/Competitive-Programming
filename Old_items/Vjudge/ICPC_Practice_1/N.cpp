#include<bits/stdc++.h>

using namespace std;

int trailing(int n)
{
    int x = 0, p = 5;
    while (p <= n)
    {
        x += n / p;
        p *= 5;
    }

    return x;
}

int main()
{
    int x, test, t = 1;;

    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        int n;
        cin >> n;

        int l = 1, h = 1e9, m, ans = 0;
        while (l <= h)
        {
            m = l + ((h - l) / 2);

            int k = trailing(m);
            if (k >= n)
                h = m - 1;
            else if (k < n)
                l = m + 1;
            if (k == n)
                ans = m;
        }

        if (ans) cout << ans << '\n';
        else cout << "impossible\n";
    }

    return 0;
}
