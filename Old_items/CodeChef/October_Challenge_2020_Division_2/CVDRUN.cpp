#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int test;

    cin >> test;

    while(test--)
    {
        int n, k, x, y;

        cin >> n >> k >> x >> y;

        bool f[n] = {0};

        while(1)
        {
            if(f[x])
                break;

            f[x] = 1;
            x = (x + k) % n;
        }

        cout << (f[y] ? "YES" : "NO") << '\n';
    }

    return 0;
}
