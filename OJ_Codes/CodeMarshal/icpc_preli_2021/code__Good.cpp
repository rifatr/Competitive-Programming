/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
#include <bits/stdc++.h>
#define lli long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define powr(x,n,p) for(int axy=0 ; axy<p ; axy++){x=x*n;}
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define nl cout<<"\n"
#define fr0(n,q) for(q=0 ; q<n ; q++)
#define fr1(n,q) for(q=1 ; q<=n ; q++)
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define lst(x) x[x.size()-1]
#define llst(x) x[x.size()-2]
#define md 1000000007
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=x|(1LL<<y)
#define pi acos(-1)
#define inf (1LL<<60)
#define N  205
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

// #define map unordered_map
#define ll int

// map < pair<ll,ll>,bool > obs;
vector <vector <bool>> obs;
map < pair<ll, ll>, vector < pair < pair <ll, ll> , lli > > > tun;
// map < pair<ll, ll>, vector < ll > tuna;


// map < pair< pair<ll, ll> , ll > , ll > d;
vector <vector <vector <lli>>> d;
// ll d[100][100][10];

ll dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
ll dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};
lli c[8], n, m, p, q, sx, sy, ex, ey;
priority_queue < pair < pair<lli, ll> , pair <ll, ll> > > qq;

inline void job(ll x, ll y, ll dir) {
	ll nx = x + dx[dir - 1];
	ll ny = y + dy[dir - 1];

	if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= m && obs[nx][ny] == 0)) return;

	// if (!d.count({{nx, ny}, dir})) d[ {{nx, ny}, dir}] = inf;

	if (d[nx][ny][dir] > d[x][y][dir]) {
		d[nx][ny][dir] = d[x][y][dir];

		qq.push({{ -d[nx][ny][dir], dir}, {nx, ny}});

	}

	// if (!d.count({{nx, ny}, 0})) d[ {{nx, ny}, 0}] = inf;

	if (d[nx][ny][0] > d[x][y][dir]) {
		d[nx][ny][0] = d[x][y][dir];

		qq.push({{ -d[nx][ny][0], 0}, {nx, ny}});

	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t, tc = 1;

	cin >> t;

	while (t--) {

		obs.clear();
		tun.clear();
		d.clear();

		// fill(d.begin(), d.end(), inf);

		ll i, j;

		cin >> n >> m >> p >> q;
		obs.resize(n + 3, vector <bool> (m + 3));
		d.resize(n + 3, vector < vector <lli>> (m + 3, vector <lli> (9, inf)));


		cin >> sx >> sy >> ex >> ey;

		for (i = 0 ; i < 8 ; i++) cin >> c[i];

		for (i = 1 ; i <= p ; i++) {
			ll ux, uy, vx, vy, w;
			cin >> ux >> uy >> vx >> vy >> w;

			tun[ {ux, uy}].pb({{vx, vy}, w});
		}

		for (i = 1 ; i <= q ; i++) {
			ll x, y;
			cin >> x >> y;

			// obs[{x,y}]=true;
			obs[x][y] = true;

		}




		d[sx][sy][0] = 0;

		qq.push({{0, 0}, {sx, sy}});

		while (!qq.empty()) {

			ll x = qq.top().second.first;
			ll y = qq.top().second.second;
			ll dir = qq.top().first.second;

			qq.pop();

			if (dir) job(x, y, dir);
			else {
				for (i = 0 ; i < 8 ; i++) {
					ll nx = x + dx[i];
					ll ny = y + dy[i];



					if (!(nx >= 1 && nx <= n && ny >= 1 && ny <= m && obs[nx][ny] == 0)) continue;



					// if (!d.count({{nx, ny}, i + 1})) d[ {{nx, ny}, i + 1}] = inf;

					if (d[nx][ny][i + 1] > d[x][y][0] + c[i]) {
						d[nx][ny][i + 1] = d[x][y][0] + c[i];

						qq.push({{ -d[nx][ny][i + 1], i + 1}, {nx, ny}});
						// qq.ppush({{-d[nx][ny][i + 1], i + 1}, {nx, ny}});

					}

					// if (!d.count({{nx, ny}, 0})) d[ {{nx, ny}, 0}] = inf;

					if (d[nx][ny][0] > d[x][y][0] + c[i]) {
						d[nx][ny][0] = d[x][y][dir] + c[i];

						qq.push({{ -d[nx][ny][0], 0}, {nx, ny}});

					}
				}

				ll sz = tun[ {x, y}].size();

				for (i = 0 ; i < sz ; i++) {
					ll nx = tun[ {x, y}][i].first.first;
					ll ny = tun[ {x, y}][i].first.second;
					lli ww = tun[ {x, y}][i].second;


					// if (!d.count({{nx, ny}, 0})) d[ {{nx, ny}, 0}] = inf;

					if (d[nx][ny][0] > d[x][y][0] + ww) {
						d[nx][ny][0] = d[x][y][0] + ww;

						qq.push({{{ -d[nx][ny][0]}, 0}, {nx, ny}});

					}

				}



			}




		}

		cout << "Case " << tc++ << ": ";

		if (d[ex][ey][0] != inf) cout << d[ex][ey][0];
		else cout << "-1";

		nl;


	}




	return 0;

}
