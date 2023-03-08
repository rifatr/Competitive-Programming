#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if((b < a && c < a) || (b > a && c > a))
        cout << "Chocolate\n";
    else {
        if(b < a)
            cout << "Chocolate\n";
        else
            cout << "Ice-cream\n";
    }

    return 0;

}
