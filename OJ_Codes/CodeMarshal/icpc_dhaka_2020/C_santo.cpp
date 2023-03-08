#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " , "<< #y << "=" << y<< endl
#define _                                                                                                              \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
#define pp pop_back

const ll N = 1000, M = (1LL << 60);
ll grid[N+5][N+5], d[N+5][N+5], e[N+5][N+5],n ,m ;
bool vis[N+5][N+5];

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

ll update_seed(ll seed){
	return seed = (seed * 1000003 + 10007) % 1000000009;
}

void djsk(pair<ll,ll>p)
{
	for(ll i=0 ; i<=n ; i++) for(ll j=0 ; j<=m ; j++) d[i][j] = M;
	priority_queue<pair<ll,pair<ll,pair<ll,ll>>>>q;
	d[p.ff][p.ss] = 0;
	q.push({0, {p.ff, {p.ss, 0}}});
	
	while(!q.empty())
	{
		auto u = q.top();
		q.pop();
		ll x = u.ss.ff, y = u.ss.ss.ff, move = u.ss.ss.ss;
		for(ll i=0 ; i<4 ; i++)
		{
			ll nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				ll cost = grid[nx][ny];
				if(d[x][y] + cost + 1 < d[nx][ny])
				{
					d[nx][ny] = d[x][y] + cost + 1;
					q.push({-d[nx][ny], {nx, {ny, move + 1}}});
				}
			}
		}
	}
}

// void djsk2(pair<ll,ll>p)
// {
	// for(ll i=0 ; i<=n ; i++) for(ll j=0 ; j<=m ; j++) e[i][j] = M;
	// priority_queue<pair<ll,pair<ll,ll>>>q;
	// e[p.ff][p.ss] = 0;
	// q.push({0, {p.ff, p.ss}});
// 	
	// while(!q.empty())
	// {
		// auto u = q.top();
		// q.pop();
// 		
		// for(ll i=0 ; i<4 ; i++)
		// {
			// ll nx = u.ss.ff + dx[i], ny = u.ss.ss + dy[i];
			// if(nx >= 0 && nx < n && ny >= 0 && ny < m)
			// {
				// ll cost = grid[nx][ny];
				// if(e[u.ss.ff][u.ss.ss] + cost < e[nx][ny])
				// {
					// e[nx][ny] = e[u.ss.ff][u.ss.ss] + cost;
					// q.push({-e[nx][ny], {nx, ny}});
				// }
			// }
		// }
	// }
// }

void solve()
{
    ll cx, cy, mx, my, seed;
    
    cin >> n >> m >> cx >> cy >> mx >> my >> seed;
    cx --, cy--, mx--, my--;
    
    for(ll i=0 ; i<n ; i++)
    {
    	for(ll j=0 ; j<m ; j++)
    	{
    		if((i == cx && j == cy)||(i==mx && j==my)) 
    		{
    			grid[i][j] = 0;
    			continue;
    		}
    		
    		seed = update_seed(seed);
    		grid[i][j] = seed%63;
    	}
    }
    
    ll res = M;
    
    djsk({cx, cy});
    //djsk2({mx, my});
    
    
    cout << d[mx][my] << '\n'; 
    
}

int main()
{_
    int t = 1, cs = 1;
    cin >> t;
    while (t--)
    {
    	cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}