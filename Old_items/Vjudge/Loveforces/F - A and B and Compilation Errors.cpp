#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, f, i, j;
    vector <int> a, b, c;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    for(i = 0; i < n - 1; i++)
    {
        cin >> t;
        b.push_back(t);
    }
    sort(b.begin(), b.end());

    for(i = 0; i < n - 2; i++)
    {
        cin >> t;
        c.push_back(t);
    }
    sort(c.begin(), c.end());

    f = 0;
    for(i = 0; i < n - 1; i++)
    {
        if(a[i] != b[i]) {
            cout << a[i] << endl;
            f = 1;
            break;
        }
    }
    if(f == 0)
        cout << a[n - 1] << endl;

    f = 0;
    for(i = 0; i < n - 2; i++)
    {
        if(c[i] != b[i]) {
            cout << b[i] << endl;
            f = 1;
            break;
        }
    }
    if(f == 0)
        cout << b[n - 2] << endl;

    return 0;
}
