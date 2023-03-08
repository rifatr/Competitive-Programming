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

    int x, test, tt, y;

    cin >> test >> tt;

    bool a[tt + 1] = {0};
    a[0] = 1;
    while(test--)
    {
        cin >> x >> y;

        lop(x + 1, y + 1)
            a[i] = 1;

//        for(auto &z : a) cout << z;
//        cout << endl;
    }

    if(count(a, a + tt + 1, 0))
        no;
    else
        yes;

    return 0;
}

