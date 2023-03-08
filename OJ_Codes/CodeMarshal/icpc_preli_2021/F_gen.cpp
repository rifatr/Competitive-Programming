#include <bits/stdc++.h>
#include <testlib.h>

using namespace std;

#define ll long long
#define lop(n) for(int i = 0; i < n; i++)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// return a random number in [l, r] range
ll rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r)(rng);
}

//generate an array of length n where each element in [l, r] range
void Array(ll n, ll l, ll r) {
	for (int i = 0; i < n; i++)
		cout << rand(l, r) << (i < n - 1 ? ' ' : '\n');
}
void distinct_array(int n, int l, int r) {
	set <int> st;
	while (st.size() != n) {
		st.insert(rand(l, r));
	}
	vector <int> a(st.begin(), st.end());
	// do not shuffle if you want increasing array
	shuffle(a.begin(), a.end(), rng);

	println(a);
}

//generate a string of lowercase letters of length n
void String(int n) {
	for (int i = 0; i < n; i++)
		cout << (char) ('A' + rand(0, 25));
	cout << '\n';
}

void String(int n, char l, char r) {
	for (int i = 0; i < n; i++)
		cout << (char) rand(l, r);
	cout << '\n';
}

const ll N = 5, K = 20;
#define pb push_back

ll pwr(ll n, ll p) {
	ll x = 1;
	lop(p) x *= n;
	return x;
}

int main(int argc, char* argv[]) {
	// registerGen(argc, argv, 1);

	ll t = rand(1, 1);
	cout << t << endl;

	while (t--)
	{
		vector <pair <int, int>> vt;
		int n = rand(1, N), m = rand(1, N), p = rand(1, n), q = rand(1, n * m);
		println(n, m, p, q);

		int sx = rand(1, n), sy = rand(1, m), dx = rand(1, n), dy = rand(1, m);
		println(sx, sy, dx, dy);
		vt.pb({sx, sy}); vt.pb({dx, dy});

		Array(8, 1, K);

		lop(p) {
			sx = rand(1, n), sy = rand(1, m), dx = rand(1, n), dy = rand(1, m);
			int w = rand(1, K);
			println(sx, sy, dx, dy, w);
			vt.pb({sx, sy}); vt.pb({dx, dy});
		}
		lop(q) {
			int x = rand(1, n), y = rand(1, m);
			if (count(vt.begin(), vt.end(), pair <int, int> {x, y})) {
				q--;
				continue;
			}
			println(x, y);
		}
	}

	return 0;
}

