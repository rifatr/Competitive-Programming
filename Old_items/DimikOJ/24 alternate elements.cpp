#include<bits/stdc++.h>

using namespace std;

#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, n, x;

    cin >> test;

    while(test--)
    {
        cin >> n;

        lop(1, n + 1)
        {
            cin >> x;

            if(i & 1)
                cout << x;
            else if(i < n)
                cout << ' ';
        }

        cout << '\n';
    }

    return 0;
}


