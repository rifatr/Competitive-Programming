#include<bits/stdc++.h>

using namespace std;

int main()
{
    int l, i, n, s, u, p;
    string line;

    cin >> l;
    cin.ignore();
    cin >> line;

    n = s = u = p = 0;
    for(i = 0; i < l; i++)
    {
        if(line[i] == 'N')
            n++;
        else if(line[i] == 'S')
            s++;
        else if(line[i] == 'U')
            u++;
        else if(line[i] == 'P')
            p++;
    }

    s = ceil(s / 2.0);

    cout << n * s * u * p << endl;

    return 0;
}
