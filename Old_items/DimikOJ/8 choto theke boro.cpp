#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x[3], test, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> x[0] >> x[1] >> x[2];

        sort(x, x + 3);

        Case(t++);
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
    }

    return 0;
}

