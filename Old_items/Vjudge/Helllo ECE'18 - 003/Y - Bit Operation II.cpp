
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b;

    cin >> a >> b;

    bitset <32> bita(a), bitb(b);

    cout << (bita & bitb) << endl;
    cout << (bita | bitb) << endl;
    cout << (bita ^ bitb) << endl;

    return 0;
}
