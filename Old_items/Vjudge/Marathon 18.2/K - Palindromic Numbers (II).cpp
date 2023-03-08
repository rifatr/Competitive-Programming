#include<bits/stdc++.h>

using namespace std;

int pall(long long x)
{
    long long sum = 0, temp = x, tran = 0;

    while(temp > 0) {
        tran = temp % 10;
        sum = sum * 10 + tran;
        temp /= 10;
    }

    if(sum == x)
        return 1;
    return 0;
}

int main()
{
    int t, i;
    long long n;

    cin >> t;

    for(i = 1; i <= t; i++) {
        cin >> n;
        cout << "Case " << i << ": ";
        if(pall(n) == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
