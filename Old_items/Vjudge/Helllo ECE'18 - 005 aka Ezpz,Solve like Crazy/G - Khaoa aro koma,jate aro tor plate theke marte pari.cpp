#include<bits/stdc++.h>

using namespace std;

int ways(int n)
{
    //return n % 2 == 1 ? n / 2 :(n - 1) / 2;

    return min(n / 2, (n - 1) / 2);
}

int main()
{
    int test, n;

    cin >> test;

    while(test--)
    {
        cin >> n;

        cout << ways(n) << '\n';
    }

    return 0;
}
