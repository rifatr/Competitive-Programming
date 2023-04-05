// Time: 2023-04-04 06:21:07 Problem: C - Number of Palindromes
// URL: https://vjudge.net/contest/551698#problem/C

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

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

const int N = 1e3 + 10;
const char CH = 'a';

struct pal_tree {
	int n, node, t;
	string s;
	vector <int> len, link, cnt;
	vector <vector<int>> tree;
	
	pal_tree(string &ss) {
		s = "0" + ss; n = s.size();
		len.resize(n + 2); link.resize(n + 2);
		cnt.resize(n + 2);
		tree.resize(n + 2, vector <int> (26));
		
		len[1] = -1, len[2] = 0;
		link[1] = link[2] = 1;
		node = t = 2;
	
		for(int i = 1; i < n; i++) add(i);
		for(int i = node; i > 2; i--) cnt[link[i]] += cnt[i];
	}
	
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
	
};

// find total number of palindrome substring (not distinct)

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;
	
	pal_tree pt(s);
	int res = 0;
	for(int i = pt.node; i > 2; i--) res += pt.cnt[i];
	print(res);

	return 0;
}
