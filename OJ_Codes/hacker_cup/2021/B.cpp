// Problem: B: Xs and Os
// Contest: Facebook Coding Competitions - Facebook Hacker Cup 2021 Qualification Round
// Time: 2021-08-28 23:31:37
// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B


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
sob > void print(T x[], int n) {for(int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ':'\n');}

using namespace std;

const ll inf = 1e18;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int tc, t = 1;
	cin >> tc;
	
	while (tc--)
	{
		ll n;
		cin >> n;
		string grid[n];
		lop(n) cin >> grid[i];
		
		ll col[n], row[n];
		lop(n) col[i] = row[i] = inf;
		
		//row calculation
		lop(n) {
			ll cnt = 0;
			lopj(n) {
				if(grid[i][j] == 'X') continue;
				if(grid[i][j] == '.') cnt++;
				else {
					cnt = inf;
					break;
				}
			}
			row[i] = min(row[i], cnt);
		}
		
		//column calculation
		lop(n) {
			ll cnt = 0;
			lopj(n) {
				if(grid[j][i] == 'X') continue;
				if(grid[j][i] == '.') cnt++;
				else {
					cnt = inf;
					break;
				}
			}
			col[i] = min(col[i], cnt);
		}
		
		Case(t++);
		
		ll cost = inf;
		lop(n) cost = min({cost, row[i], col[i]});
		if(cost == inf) {
			print("Impossible");
			continue;
		}
		
		set <vpll> st;
		lop(n) {
			// dbg(i)
			if(row[i] == cost) {
				vpll vp;
				lopj(n) if(grid[i][j] == '.') vp.pb({i, j});
				st.insert(vp);
				// for(auto z : vp) print(z.ff, z.ss);
			}
			if(col[i] == cost) {
				vpll vp;
				lopj(n) if(grid[j][i] == '.') vp.pb({j, i});
				st.insert(vp);
				// for(auto z : vp) print(z.ff, z.ss);
			}
		}
		
		ll cnt = st.size();
		print(cost, cnt);
	}
	
	return 0;
}
