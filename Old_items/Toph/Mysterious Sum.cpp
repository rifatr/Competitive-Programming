#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, caseno = 0;

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        cout << "Case " << ++caseno << ": ";
        cout << a + b << max(a, b) - min(a, b) << endl;
    }

    return 0;
}

