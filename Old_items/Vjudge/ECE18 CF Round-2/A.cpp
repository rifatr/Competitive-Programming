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

    int n, k;
    string s, rs;

    cin >> n >> k >> s;

    sort(s.begin(), s.end());

    int ss = s[0] - 'a' + 1, p = 1;
    rs += s[0];

    lop(1, n)
    {
        if(p == k) break;

        if(s[i] - rs[p - 1] > 1) {
            ss += s[i] - 'a' + 1;
            p++;
            rs += s[i];
            //cout << s[i];
        }
    }

    if(p < k) ss = -1;

    cout << ss << '\n';

    return 0;
}

