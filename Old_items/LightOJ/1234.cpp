#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define gamma 0.57721566490

const int N = 1e6 + 6;
double har[N];

int main()
{
    loop(i, 1, N) har[i] = har[i - 1] + ((double) 1.0 / i);

    int test, t = 1;
    cin >> test;

    while (test--)
    {
        cout << "Case " << t++ << ": ";

        int n;
        cin >> n;

        double ans = n;
        if (n < N)
            ans = har[n];
        else
        {
            ans += 0.5;
            ans = log(ans) + gamma;
        }

        cout << fixed << setprecision(10) << ans << '\n';
    }

    return 0;
}