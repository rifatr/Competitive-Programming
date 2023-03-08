// Time: 2022-08-25 11:35:24	Problem: F. Number of Connected Components 
// URL: https://algo.codemarshal.org/contests/ICPCDH2016/problems/F

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

const int N = 1e5 + 10, M = 1e6 + 10;
int par[M];//, id[M];
vin pd[M], id[M];

void precal() {
    for(int i = 2; i < M; i++) {
        if(pd[i].size()) continue;
        for(int j = i; j < M; j += i)
            pd[j].pb(i);
    }
}

int findpar(int x) {
    return par[x] = par[x] == x ? x : findpar(par[x]);
}
void uni(int u, int v) {
    par[findpar(u)] = findpar(v);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	precal();

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		int a[n], cnt = 0;
		lop(n) cin >> a[i], cnt += a[i] == 1;
		
		iota(par, par + M, 0);
		lop(n) {
		    for(int &x : pd[a[i]])
		        uni(a[i], x);
		}
		set <int> st;
		lop(n) st.insert(findpar(a[i]));
		Case(cs++);
		print(st.size() + max(0, cnt - 1));
	}

	return 0;
}
