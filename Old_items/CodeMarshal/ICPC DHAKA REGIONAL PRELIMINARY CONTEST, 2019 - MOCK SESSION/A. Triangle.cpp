#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> t;
    int in;

    for(int i = 0; i < 3; i++)
    {
        cin >> in;
        t.push_back(in);
    }
    sort(t.begin(), t.end());

    if(t[0] == t[1] && t[1] == t[2])
        cout << "Equilateral Triangle" << endl;
    else if(t[0] == t[1] || t[1] == t[2])
        cout << "Isosceles Triangle" << endl;
    else
        cout << "Bad Triangle" << endl;

    return 0;
}
