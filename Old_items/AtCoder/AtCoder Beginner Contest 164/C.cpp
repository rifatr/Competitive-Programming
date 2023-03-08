#include<bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    int n;
    string s;

    set <string> item;

    cin >> n;

    while(n--) {
        cin >> s;
        item.insert(s);
    }

    cout << item.size() << "\n";

    return 0;
}


