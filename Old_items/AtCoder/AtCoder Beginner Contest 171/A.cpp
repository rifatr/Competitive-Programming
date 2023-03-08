#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    char c;

    cin >> c;

    if(c >= 'A' and c <= 'Z')
        cout << 'A' << endl;
    else
        cout << 'a' << endl;

    return 0;
}

