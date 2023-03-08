#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int x, test, n;

    cin >> test;

    while(test--)
    {
        cin >> n;

        int a;
        ll sum = 0;

        lop(0, n)
        {
            cin >> a;

            if(a % 2 == 0)
                sum += a;
        }

        cout << sum << '\n';
    }

    return 0;
}

