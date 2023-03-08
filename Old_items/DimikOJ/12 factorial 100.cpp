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

    int x, test, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> x;

        int facto = 0;
        int n = 5;

        while(n <= x) {
            facto += x / n;
            n *= 5;
        }

        cout << facto << '\n';

    }

    return 0;
}



