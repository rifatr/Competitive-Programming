#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "YES\n"
#define no cout << "NO\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int n, m;
    string a, b;
    cin >> a >> b;
    n = a.size(), m = b.size();

    int cnt[26] = {0};

    lop(n) cnt[a[i] - 'a']++;

    lop(m)
    {
        if (cnt[b[i] - 'a'])
        {
            yes;
            return 0;
        }
    }

    no;

    return 0;
}