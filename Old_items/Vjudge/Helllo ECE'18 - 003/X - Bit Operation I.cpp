#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long x;

    cin >> x;

    bitset <32> bit(x), fbits(x), lsbits(x), rsbits(x);

    cout << bit << endl;
    cout << fbits.flip() << endl;
    cout << (lsbits <<= 1) << endl;
    cout << (rsbits >>= 1) << endl;

    return 0;
}
