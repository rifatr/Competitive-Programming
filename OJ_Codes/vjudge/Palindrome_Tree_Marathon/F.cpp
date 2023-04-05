// Time: 2023-04-04 15:42:26 Problem: F - The Problem to Slow Down You
// URL: https://vjudge.net/contest/551698#problem/F

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

const int N = 4e5 + 10;
const char CH = 'a';
int tree[N][30], len[N], link[N], cnt[N], cnt2[N], node, t, n;
string s;

inline int up(int x, int p) {
	while(s[p - len[x] - 1] != s[p]) x = link[x];
	return x;
}

void add(int p) {
	t = up(t, p);
	int x = up(link[t], p), c = s[p] - CH;
	if(!tree[t][c]) {
		tree[t][c] = ++node;
		len[node] = len[t] + 2;
		link[node] = len[node] == 1 ? 2 : tree[x][c];
	}
	t = tree[t][c];
	cnt[t]++;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		string a, b;
		cin >> a >> b;
		
		s = "0" + a + "{}" + b;
		n = s.size();
		len[1] = -1, len[2] = 0;
		link[1] = link[2] = 1;
		node = t = 2;
		
		for(int i = 1; i <= a.size(); i++) add(i);
		for(int i = node; i > 2; i--) {
			cnt[link[i]] += cnt[i];
			cnt2[i] = cnt[i];
			cnt[i] = 0;
		}
		
		cnt[1] = cnt[0] = 0;
		for(int i = a.size() + 1; i < n; i++) add(i);
		for(int i = node; i > 2; i--) cnt[link[i]] += cnt[i];
		
		ll res = 0;
		loop(i, 3, node + 1) res += (ll)cnt[i] * cnt2[i];
		
		Case(cs++);
		print(res);
		lop(n + 5) {
			cnt2[i] = cnt[i] = 0;
			lopj(30) tree[i][j] = 0;
		}
	}

	return 0;
}