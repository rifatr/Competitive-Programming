#include "bits/stdc++.h"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "
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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int tc;
	cin >> tc;
	
	for(int tt = 1; tt <= tc; tt++)
	{		
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.size();
		
		map <char, deque <int>> remap, remap2;
		int k = 1;
		lop(n) remap[s1[i]].pb(k++);
		// for(auto it : remap) print(it.ff, it.ss);
		remap2 = remap;
		
		vin x, y;
		lop(n) {
			x.pb(remap[s1[i]].front());
			remap[s1[i]].pop_front();
		}
		lop(n) {
			y.pb(remap2[s2[i]].back());
			remap2[s2[i]].pop_back();
		}
		
		ddbg(x) ddbg(y)
		
		map <char, vector <char>> nxt;
		lop(n - 1) {
			nxt[x[i]].pb(x[i + 1]);
		}
		
		auto check = [&] (char a, char b) {
			for(char ch : nxt[a]) {
				if(ch == b) return 1;
			}
			return 0;
		};
		
		int res = n;
		lop(n - 1) {
			if(check(y[i], y[i + 1])) res--;
		}
		
		Case(tt);
		print(res);
	}
	
	return 0;
}

/* Infos
~ 4 Direction
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
~ 8 Direction
int dr[] = {1,-1,0,0,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1,1,-1};
~ Knight Direction
int dr[] = {1,-1,1,-1,2,2,-2,-2};
int dc[] = {2,2,-2,-2,1,-1,1,-1};
~ Hexagonal Direction
int dr[] = {2,-2,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1};
~ bitmask operations
int Set(int n, int pos) { return n = n | (1 << pos); }
int reset(int n, int pos) { return n = n & ~(1 <<
pos); }
bool check(int n, int pos) { return (bool)(n & (1 <<
pos)); }
bool isPower2(int x) { return (x && !(x & (x - 1)));
}
ll LargestPower2<=x(ll x) { for(int i = 1; i <= x / 2;
i *= 2) x = x | (x >> i); return (x + 1) / 2;}
*/