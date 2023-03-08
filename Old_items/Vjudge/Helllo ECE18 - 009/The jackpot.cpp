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

    int x, test;

    cin >> test;

    while(test)
    {
        ll a[test];
        lop(0, test) cin >> a[i];

        ll sum = 0, mxsum = -INT_MIN;

        lop(0, test)
        {
            sum += a[i];

            mxsum = max(mxsum, sum);

            if(sum < 0)
                sum = 0;
        }

        if(mxsum > 0)
            cout << "The maximum winning streak is " << mxsum << '.' << '\n';
        else
            cout << "Losing streak.\n";

        cin >> test;
    }

    return 0;
}

