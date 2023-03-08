#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case #" << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)
#define loop(i, a, b) for (int i = a; i < b; i++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifdef rifat
#include <debug.hpp>
#else
#define dbg(x)
#define ddbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const int N = 1e6 + 10;
int n, q, cnt[26][N];
string s;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		cin >> s;
		n = s.size();

		lop(n) {
			lopj(26) {
				cnt[j][i + 1] = cnt[j][i] + (s[i] - 'a' == j);
			}
		}

		auto cal = [&] (int l1, int r1, int l2, int r2) {
			int c = 0;
			lop(26) {
				c += abs(cnt[i][r1] - cnt[i][l1 - 1] - cnt[i][r2] + cnt[i][l2 - 1]);
			}
			return c;
		};

		int ans = 0;
		cin >> q;
		while (q--) {
			int l, r;
			cin >> l >> r;
			if (l % 2 != r % 2) continue;

			int md = (r + l) / 2;
			if (cal(l, md, md + 1, r) == 1) ans++;
			else if (cal(l, md - 1, md, r) == 1) ans++;
		}

		Case(cs++);
		print(ans);
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