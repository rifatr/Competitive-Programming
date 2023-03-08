#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    string line, w;

    cin >> test;
    cin.ignore();

    while(test--)
    {
        getline(cin, line);

        stringstream ss(line);

        ss >> w;
        reverse(w.begin(), w.end());
        cout << w;

        while(ss >> w)
        {
            reverse(w.begin(), w.end());

            cout << ' ' << w;
        }

        cout << '\n';
    }

    return 0;
}
