#include<bits/stdc++.h>

using namespace std;

int main()
{
    setbuf(stdout, NULL);

    int lo = 0, hi = 1000009, mid = (lo + hi) / 2;

    while(1)
    {
        mid = (lo + hi) / 2;

        cout << mid << endl;

        string in;

        cin >> in;

        if(in == "Bigger")
            lo = mid + 1;
        else if(in == "Smaller")
            hi = mid - 1;
        else
            break;
    }

    return 0;
}
