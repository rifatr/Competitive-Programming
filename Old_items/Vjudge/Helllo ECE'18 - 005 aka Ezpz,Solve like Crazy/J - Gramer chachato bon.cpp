#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tri[3];

    cin >> tri[0] >> tri[1] >> tri[2];

    sort(tri, tri + 3);

    if(tri[0] + tri[1] > tri[2]) {
        cout << 0 << endl;
        return 0;
    }

    cout << tri[2] + 1 - tri[0] - tri[1] << endl;

    return 0;
}

