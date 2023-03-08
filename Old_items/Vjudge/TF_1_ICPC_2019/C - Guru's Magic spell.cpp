#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, angle = 0, counter = 0;
    string S;

    cin >> S;

    for(i = 0; S[i] != '\0'; i++) {
        if(S[i] == 'R')
            angle += 90;
        if(angle == 360) {
            counter++;
            angle = 0;
        }
        if(S[i] == 'L')
            angle -= 90;
        if(angle == -360)
            angle = 0;
    }

    cout << counter << endl;

    return 0;
}
