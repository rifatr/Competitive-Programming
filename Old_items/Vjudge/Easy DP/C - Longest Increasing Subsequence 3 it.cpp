#include<bits/stdc++.h>

using namespace std;

const int N = 5009;
int n;
int ara[N], lis[N], parent[N];
vector <int> path;

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> ara[i], parent[i] = i;

    for(int i = 0; i < n; i++)
    {
        int is = 0;

        for(int j = 0; j < i; j++)
            if(ara[i] > ara[j]) {
                if(is < lis[j])
                    is = lis[j], parent[i] = j;
            }

        lis[i] = is + 1;
    }

    int ans = 0, p;

    for(int i = 0; i < n; i++)
        if(lis[i] > ans)
            ans = lis[i], p = i;

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


