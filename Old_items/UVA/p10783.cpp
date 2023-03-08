#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, i, j, sum;
    cin >> t;

    for(i = 0; i < t; i++) {
        cin >> a >> b;
        sum = 0;
        for(j = a; j <= b; j++) {
            if(j % 2 != 0)
                sum += j;
        }
        cout << "Case " << i + 1 << ": " << sum << endl;
    }

    return 0;
}
