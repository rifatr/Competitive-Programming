#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    char s, t;

    cin >> s >> t;

    if(s == 'Y')
    {
        if(t < 'a')
            cout << t << endl;
        else 
            cout << (char) (t - 32) << endl;
    }

    else
    {
        if(t >= 'a')
            cout << t << endl;
        else 
            cout << (char) (t + 32) << endl;
    }

    return 0;
}
