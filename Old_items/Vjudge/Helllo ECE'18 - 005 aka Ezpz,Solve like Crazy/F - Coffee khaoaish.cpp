#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, h, height, width = 0;

    cin >> n >> h;

    for(int i = 0; i < n; i++)
    {
        cin >> height;

        width += height > h ? 2 : 1;
    }

    cout << width << endl;

    return 0;
}
