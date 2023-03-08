#include<bits/stdc++.h>

using namespace std;

int main()
{
    int p;
    int i;

    cin >> p;

   // cout << p / 10;

    cout << "[";

    int x = p / 10;
    for(i = 0; i < x; i++)
        cout << "+";
    for(i = 0; i < 10 - x; i++)
        cout << ".";

    cout << "] " << p << "%\n";

    return 0;
}
