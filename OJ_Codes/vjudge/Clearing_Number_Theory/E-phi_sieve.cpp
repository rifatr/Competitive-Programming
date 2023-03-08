// Time: 2022-06-05 16:47:58	Problem: E - Mathematically Hard 
// URL: https://vjudge.net/contest/498440#problem/E

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

const int N = 5e6 + 20;
bitset <N> mark;
int phi[N];
unsigned ll score[N];

void phi_sieve() {
    for(int i = 2; i < N; i++)
        phi[i] = i;
    for(int i = 2; i < N; i++) {
        if(!mark[i]) {
            for(int j = i; j < N; j += i) {
                mark[j] = 1;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

void cal() {
    for(int i = 2; i < N; i++) {
        score[i] = (long long)phi[i] * phi[i];
        score[i] += score[i - 1];
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	phi_sieve();
	cal();

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		int l, r;
		cin >> l >> r;
		
		Case(cs++);
		print(score[r] - score[l - 1]);
	}

	return 0;
}
