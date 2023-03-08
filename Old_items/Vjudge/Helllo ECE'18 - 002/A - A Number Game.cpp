#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int t, n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n % 2 == 0)
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }

    return 0;
}
