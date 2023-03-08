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
		cout << (char) ('a' + rand(0, 25));
	cout << '\n';
}

void String(int n, char l, char r) {
	for (int i = 0; i < n; i++)
		cout << (char) rand(l, r);
	cout << '\n';
}

const ll N = 1e12;

ll pwr(ll n, ll p) {
	ll x = 1;
	lop(p) x *= n;
	return x;
}

int main(int argc, char* argv[]) {
	// registerGen(argc, argv, 1);

	ll t = rand(1, 1);
	// cout << t << endl;

	while (t--)
	{
		int n = rand(1, 10), q = rand(1, 10);
		println(n, q);
		Array(n, 6, 20);
		while (q--) {
			int op = rand(1, 3);
			if (op == 1) {
				int x = rand(1, n), y = rand(1, 20);
				println(op, x, y);
			}
			if (op == 2) {
				int x = rand(1, n), y = rand(1, n);
				println(op, x, y);
			}
			if (op == 3) {
				int x = rand(1, n), y = rand(1, n), z = rand(1, 20);
				println(op, x, y, z);
			}
		}
		// int prm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

		// int n = rand(2, 10) , a = rand(1, 100), b = rand(1, 100);
		// if (a > b) swap(a, b);
		// println(n);
		// Array(n, 1, 10);

		// int n = 40;
		// String(n, 'A', 'Z');

		// int n = rand(1, 11), m = rand(1, 30);
		// if (n & 1) n++;
		// println(n);

		// lop(n) {
		// 	int u = rand(1, n), v = rand(1, n);
		// 	println(u, v);
		// }

		// Array(n, 1, 30);
		// String(n, '0', '9');
	}

	return 0;
}

