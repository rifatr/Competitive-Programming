#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r;
    string s;
    bool f = false;

    cin >> n >> s;

    for(int i = 1; i < n; i++)
        if(s[i] < s[i - 1])
        {
            f = true;
            l = i;
            r = l + 1;
            break;
        }

    f == true ? cout << "YES\n" << l << " " << r << '\n' : cout << "NO\n";


    return 0;
}
