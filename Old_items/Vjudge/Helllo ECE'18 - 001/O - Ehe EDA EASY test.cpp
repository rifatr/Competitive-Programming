#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int i, j, k, z, m = 0;
    for(i = 5, k = 1; ; i += 5, k++)
    {
        z = 0;
        for(j = 5; j <= i; j *= 5) {
            z += (i / j);
            m++;
        }

        if(z > 100000002)
            break;
    }

    cout << k << endl << m << endl;;
}
