#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, n, result, test;

    cin >> test >> n;

    result = n;

    for(i = 1; i < test; i++)
    {
        cin >> n;

        result ^= n;
    }
    cout << result << endl;

    return 0;
}
