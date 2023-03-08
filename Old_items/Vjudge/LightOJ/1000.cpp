#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define Case(i) cout << "Case " << int(i) << ": "

int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, test, t = 1;

    cin >> test;

    while(test--)
    {
        cin >> n >> m;


        Case(t++);

        cout << n + m << '\n';
    }

    return 0;
}


