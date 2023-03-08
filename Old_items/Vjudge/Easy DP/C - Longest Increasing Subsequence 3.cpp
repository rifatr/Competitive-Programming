#include<bits/stdc++.h>

using namespace std;

const int N = 5009;
int n;
int ara[N], lis[N], parent[N];
vector <int> path;

int lis_dp(int x)
{
    if(x < 0)
        return 0;

    if(lis[x])
        return lis[x];

    int is = 0;

    for(int i = 0; i < x; i++) {
        if(ara[i] < ara[x]) {
            int s = lis_dp(i);
            if(s > is)
            {
                is = s;
                parent[x] = i;
            }
        }
    }

    return lis[x] = is + 1;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> ara[i], lis[i] = 0, parent[i] = i;

    int ans = 0, p;

    for(int i = 0; i < n; i++) {
        int x = lis_dp(i);
        if(x > ans)
            ans = x, p = i;
    }

    while(p != parent[p])
    {
        path.push_back(p);
        p = parent[p];
    }

    path.push_back(p);

    cout << ans << '\n';
    for(int i = ans - 1; i >= 0; i--)
        cout << ara[path[i]] << ' ';


    return 0;
}
