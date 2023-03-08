#include<bits/stdc++.h>

using namespace std;

#define bit bitset <32>
#define finish(x) {cout << x << endl; return 0;}

int main()
{
    int n;

    cin >> n;

    bit a(n);

    int x = a.count();

    for(int i = 1; i <= n; i++)
    {
        bit b(i);

        if(b.count() == x)
            finish(i);
    }
}
