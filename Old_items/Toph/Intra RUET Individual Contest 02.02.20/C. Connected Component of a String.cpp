#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a;

    int i, x = 0;

    cin >> a;

    //sort(a.begin(), a.end());

    for(i = 0; i < a.size(); i++)
    {
        if(a[i] != a[i + 1])
            x++;
    }

    cout << x << endl;

    return 0;
}
