#include<bits/stdc++.h>

using namespace std;

int main()
{
    string one, two, thri, four;

    cin >> one >> two >> thri;

    four = one + two;

    sort(thri.begin(), thri.end());
    sort(four.begin(), four.end());

    if(thri == four)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
