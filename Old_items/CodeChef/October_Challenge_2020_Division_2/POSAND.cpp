#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x, test;

    cin >> test;

    while(test--)
    {
        cin >> x;

        if(x == 1)
        {
            cout << 1 << '\n';
            continue;
        }

        if(!(x & (x - 1))) // power of 2
        {
            cout << -1 << '\n';
            continue;
        }

        deque <int> f;

        int k = 1, n = 0, z;

        while(n < x)
        {
            z = (1 << k) - 1; k++;

            if(z >= x)
                break;

            for(int i = min(z, x); i > n; i--)
                f.push_back(i);

            n = z;
        }

        int p = f.size();

        if(x & f[p - 1])
        {
            for(int i = x; i > n; i--)
                f.push_back(i);
        }

        else
        {
            if(x & 1)
            {
                for(int i = x; i > n; i--)
                    f.push_front(i);
            }

            else
            {
                for(int i = p - 1; i >= 0; i--)
                {
                    if(f[i] & x)
                    {
                        swap(f[i], f[p - 1]);
                        break;
                    }
                }

                for(int i = x; i > n; i--)
                    f.push_back(i);
            }
        }

        for(int i = 0; i < x; i++)
            cout << f[i] << ' ';
        cout << '\n';
    }

    return 0;
}
