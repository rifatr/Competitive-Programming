
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, i;

    cin >> t;

    for(i = 1; i <= t; i++) {
        cin >> a >> b;
        cout << "Case " << i << ": " << (abs(b - a) + a) * 4 + 19 << "\n";
    }

    return 0;
}
