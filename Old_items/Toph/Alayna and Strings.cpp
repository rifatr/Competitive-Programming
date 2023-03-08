#include<bits/stdc++.h>
using namespace std;
int main()
{
    string l;
    int c = 0, s = 0;
    cin >> l;
    for(int i = 0; i < l.size(); i++) {
        if(l[i] >= 'A' && l[i] <= 'Z')
            c++;
        else if(l[i] >= 'a' && l[i] <= 'z')
            s++;
    }
    cout << c << " " << s << endl;
    return 0;
}
