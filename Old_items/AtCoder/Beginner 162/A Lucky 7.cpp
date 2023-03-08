#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    string s = "No";

    cin >> x;

    while(x > 0)
    {
        int y = x % 10;
        x /= 10;

        if(y == 7)
            s = "Yes";
    }

    cout << s << endl;

    return 0;
}
