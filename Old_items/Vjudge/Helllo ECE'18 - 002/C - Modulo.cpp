#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int i, j = 10, t;
    vector <int> mods;
    vector <int> :: iterator it;

    while(j--)
    {
        for(i = 0; i < 10; i++) {
            cin >> t;
            t %= 42;
            mods.push_back(t);
        }

        sort(mods.begin(), mods.end());

        t = 1;
        for(i = 1; i < 10; i++) {
            if(mods[i] != mods[i - 1])
                t++;
        }

        cout << t << endl;

        mods.clear();
    }

    return 0;
}
