// Problem: B. Scenes From a Memory
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// Time: 2021-08-31 18:51:34
// URL: https://codeforces.com/contest/1562/problem/B


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
	
	while (tc--)
	{
		int n;
		string s;
		cin >> n >> s;
		
		if(n == 1) {
			print(n); 
			print(s);
			continue;
		}
		
		int cnt[10] = {0};
		lop(n) cnt[s[i] - '0']++;
		
		auto check = [&] () {
			for(auto z : s) {
				int p = z - '0';
				if(p == 1 or p == 4 or p == 6 or p == 9 or p == 8)
					return p;
			}
			return 0;
		};
		auto check2 = [&] () {
			lop(10) {
				if(cnt[i] > 1) return i;
			}
			return 0;
		};
		auto check3 = [&] (int p) {
			if(p == 2) return 0;
			if(p < 2 or p % 2 == 0) return 1;
			for(ll i = 3; i * i <= p; i += 2) {
				if(p % i == 0) return 1;
			}
			return 0;
		};
		
		if(check()) {
			print(1);
			print(check());
		}
		else if(check2()){
			print(2);
			int x = check2() * 10 + check2();
			print(x);
		}
		else {
			int ans = 7777;
			for(int i = 1; i < (1 << n); i++) {
				int x = 0;
				for(int j = 0; j < n; j++) {
					if(i & (1 << j)) {
						x *= 10;
						x += (s[j] - '0');
					}
				}
				if(check3(x)) {
					ans = min(ans, x);
					dbg2(x, ans)
				}
			}
			
			int x = ans, p = 0;
			while(x) {
				x /= 10;
				p++;
			}
			print(p);
			print(ans);
		}
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
int reset(int n, int pos) { return n = n & ~(1 << pos); }
bool check(int n, int pos) { return (bool)(n & (1 << pos)); }
bool isPower2(int x) { return (x && !(x & (x - 1))); }
ll LargestPower2<=x(ll x) { for(int i = 1; i <= x / 2; i *= 2) x = x | (x >> i); return (x + 1) / 2;}
*/