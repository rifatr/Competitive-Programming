#include<bits/stdc++.h>

using namespace std;

#define lop(a, b, c) for(int i = a; i <= b; i += c)
#define lopj(a, b, c) for(int j = a; j <= b; j += c)
#define Case(i) cout << "Case " << int(i) << ": "
#define pb push_back
#define N 1001
#define inf 9999999

vector <int> pf[N + 1];
bool mark[N + 1];
int s, t, f, mem[N];

void sieve();
int bfs(int n);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();

    int test, tt = 1;

    cin >> test;

    while(test--)
    {
        cin >> s >> t;

        Case(tt++);

        lop(0, t, 1)
            mem[i] = -1;

        f = bfs(s);

        cout << f << '\n';
    }

}

int bfs(int st)
{
    queue <int> qq;
    qq.push(st);
    mem[st] = 0;

    while(!qq.empty())
    {
        int u = qq.front();
        qq.pop();
        int saiz = pf[u].size();

        lop(0, saiz - 1, 1)
        {
            int v = u + pf[u][i];

            if(v <= t and mem[v] == -1)
            {
                qq.push(v);

                mem[v] = mem[u] + 1;
            }

            if(mem[t] != -1)
                return mem[t];
        }
    }

    return mem[t];
}

void sieve()
{
    int limit = sqrt(N * 1.0);

    lop(4, N, 2)
    {
        mark[i] = 1;
        pf[i].pb(2);
    }

    lop(3, N, 2)
    {
        if(!mark[i])
        {
            lopj(i + i, N, i)
            {
                mark[j] = 1;
                pf[j].pb(i);
            }
        }
    }
}
