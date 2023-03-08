#include <bits/stdc++.h>

using namespace std;

int cc(string a, string b)
{
    int i, j = 0;
    for(i = 0; i < a.size(); i++)
    {
        if(a[i] == '#' && b[i] == '#')
            j++;
    }
    return j;
}

int main()
{
    int i, j, k;
    string a, b;

    cin >> a >> b;

    if(0 == cc(a, b))
        cout << "NO\n";
    else
        cout << "YES\n##..\n.##.\n";

    return 0;
}
