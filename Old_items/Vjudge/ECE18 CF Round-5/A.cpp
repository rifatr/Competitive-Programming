#include<bits/stdc++.h>

using namespace std;

int main()
{
    int y, w;

    cin >> y >> w;

    int d = max(y, w);

    if(d == 1)
        cout << "1/1" << endl;
    else if(d == 2)
        cout << "5/6" << endl;
    else if(d == 3)
        cout << "2/3" << endl;
    else if(d == 4)
        cout << "1/2" << endl;
    else if(d == 5)
        cout << "1/3" << endl;
    else
        cout << "1/6" << endl;

    return 0;
}
