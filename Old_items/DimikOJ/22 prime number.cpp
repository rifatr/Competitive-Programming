#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b, c) for(int i = a; i < b; i += c)
#define lopj(a, b) for(int j = a; j < b; j++)

bool prime(int n)
{
    if(n == 2)
        return 1;
    if(n < 2 or n % 2 == 0)
        return 0;

    int limit = sqrt(n * 1.0) + 1;

    lop(3, limit, 2)
        if(n % i == 0)
            return 0;

    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, test, y;

    cin >> test;

    while(test--)
    {
        cin >> x >> y;

        int c = 0;

        lopj(x, y + 1) {
            c += prime(j);
            //cout << j << ' ' << prime(j) << '\n';
        }

        cout << c << '\n';
    }

    return 0;
}
