#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case #" << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "\t", dbg(y);
#define dbg3(x, y, z) cout << #x << " = " << x << "\t", dbg2(y, z);
#define ddbg(x) cout << #x << " = [ "; for(auto z : x) cout << z << ' '; cout << "]\n";
#else
#define dbg(x)
#define adbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#define ddbg(x)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

vin nxt[26];
bool vis[26];
ll level[26];

void bfs(int s) 
{
	queue <int> q;
	memset(vis, 0, sizeof vis);
	memset(level, -1, sizeof level);
	level[s] = 0;
	vis[s] = 1;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(int v : nxt[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, t = 1;
	cin >> tc;

	while (tc--)
	{
		string s;
		cin >> s;
		int n = s.size();

		int cnt[26] = {0};
		for (char ch : s) cnt[ch - 'A']++;

		int k;
		cin >> k;
		lop(k) {
			char a, b;
			cin >> a >> b;
			nxt[a - 'A'].pb(b - 'A');
		}

		ll ans = 1e18;
		lop(26) {
			ll sum = 0;
			lopj(26) {
				if (i == j or !cnt[j]) continue;

				bfs(j);
				
				if (level[i] == -1) {
					sum = -1;
					break;
				}
				
				sum += level[i] * cnt[j];
			}
			
			if (sum != -1) ans = min(ans, sum);
		}

		Case(t++);
		print(ans == 1e18 ? (ll) - 1 : ans);
		lop(26) nxt[i].clear();
	}

	return 0;
}
