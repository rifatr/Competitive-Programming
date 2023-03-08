#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test, d;
    double am;

    cin >> test;

    while(test--)
    {
        cin >> am;

        d = 0;

        while(am > 1)
            am /= 2, d++;

        cout << d << " days" << '\n';
    }

    return 0;
}


