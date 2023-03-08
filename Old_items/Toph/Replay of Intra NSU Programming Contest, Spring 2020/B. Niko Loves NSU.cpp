/*
* rifatrraazz
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0, l,  i, s = 0, u = 0;
    char x;

    cin >> l;
    cin.ignore();

    for(i = 0; i < l; i++)
    {
        cin >> x;

        if(x == 'N')
            n++;
        if(x == 'S')
            s++;
        if(x == 'U')
            u++;
    }

    cout << min(n, min(s, u)) << endl;


    return 0;
}

