#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;

    cin >> n >> k;

    if(n < k)
    {
        cout << min(n, k - n) << endl;
//main();
        return 0;
    }

    if(n % k == 0)
        cout << 0 << endl;
    else
    {
        long long x = n % k;

        if(x < k)
        {
            cout << min(x, k - x) << endl;
        }
    }
 //main();
    return 0;
}
