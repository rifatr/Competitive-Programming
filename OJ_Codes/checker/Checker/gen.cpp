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
	for (int i = 0; i < n; i++) {
		cout << rand(l, r) << (i < n - 1 ? ' ' : '\n');
	}
}

//generate a string of lowercase letters of length n
void String(int n) {
	for (int i = 0; i < n; i++) {
		cout << (char) (rand(65, 70));
	}
	cout << ' ';
}

void cf1658D(int n) {
	vector <int> a(n);
	iota(a.begin(), a.end(), 0);
	shuffle(a.begin(), a.end(), rng);

	int x = rand(0, 1 << 7);
	println(0, n - 1, x);
	lop(n) a[i] ^= x;
	println(a);
}

const ll N = 1e3;

int main(int argc, char* argv[]) {
	int tc = rand(1, 1);
	println(tc);

	while (tc--) {
		int n = rand(3, 8);
		println(n);
		Array(n, 0, 100);
	}
}
