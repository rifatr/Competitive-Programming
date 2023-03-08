#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k, m, n, x, y;

    while(scanf("%d", &k) and k)
    {
        scanf("%d %d", &m, &n);

        while(k--)
        {
            string res;
            scanf("%d %d", &x, &y);

            if(x == m or y == n)    res = "divisa";

            else if(x > m and y > n)    res = "NE";

            else if(x < m and y > n)    res = "NO";

            else if(x < m and y < n)    res = "SO";

            else    res = "SE";

            cout << res << '\n';
        }
    }

    return 0;
}
