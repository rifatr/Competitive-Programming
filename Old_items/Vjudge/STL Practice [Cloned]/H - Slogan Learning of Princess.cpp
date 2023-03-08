#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, i, j;
    string first, second;
    map <string, string> slogan;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        getline(cin, first);
        getline(cin, second);

        slogan[first] = second;
    }
    cin >> q;
    cin.ignore();
    while(q--)
    {
        getline(cin, first);
        cout << slogan[first] << endl;
    }

    return 0;
}
