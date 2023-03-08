// Time: 2022-12-03 22:24:00	Problem: Static Range Sum Queries 
// URL: https://cses.fi/problemset/task/1646

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

const ll N = 2e5 + 20, M = 20;
ll n, q, a[N], spt[M][N];

ll f(int i, int j) {
    return spt[i - 1][j] + spt[i - 1][j + (1 << (i - 1))];
}

void build() {
    for(int i = 0; i < n; i++) 
        spt[0][i] = a[i];
    for(int i = 1; i < M; i++) {
        for(int j = 0; j + (1 << i) <= n; j++) {
            spt[i][j] = f(i, j);
        }
    }
}

ll query(int l, int r) {
    ll sum = 0;
    for(int i = M - 1; i >= 0; i--) {
        if((1 << i) <= r - l + 1) {
            sum += spt[i][l];
            l += (1 << i);
        } 
    }  
    
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	lop(n) cin >> a[i];
	
	build();
	
	while(q--) {
	    int l, r;
	    cin >> l >> r;
	    print(query(l - 1, r - 1));
	}

	return 0;
}
