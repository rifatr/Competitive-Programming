#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x, m, n, l, k, p;

    cin >> x >> m >> n;

//    if(x == 0) {
//        cout << 0 << " " << 0 << endl;
//        return 0;
//    }

    l = x / (m + n);

    cout << l << endl;

    cout << m * l << " " << n * l << endl;
main();
    //return 0;
}
