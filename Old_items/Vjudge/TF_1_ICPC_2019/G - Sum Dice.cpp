#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, n, m, small = 0, big = 0;

    cin >> n >> m;

    if(n > m) {
        big = n;
        small = m;
    }
    else if (m > n) {
        big = m;
        small = n;
    }

    else{
        big = n;
        small = m;
    }

    for(i = small; i <= big; i++)
        cout << i + 1 << endl;
    return 0;
}
