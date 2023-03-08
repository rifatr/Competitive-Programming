#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6 + 10, mod = 2e9 + 63, base1 = 1e9 + 21, base2 = 1e9 + 181;
ll pw1[N], pw2[N], hp1[N], hp2[N], hs1[N], hs2[N], n, q;
string s;

void pw_cal() {
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < N; i++) {
		pw1[i] = (pw1[i - 1] * base1) % mod;
		pw2[i] = (pw2[i - 1] * base2) % mod;
	}
}

void init() {
	hp1[0] = hp2[0] = hs1[n + 1] = hs2[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		hp1[i] = (hp1[i - 1] * base1 + s[i - 1]) % mod;
		hp2[i] = (hp2[i - 1] * base2 + s[i - 1]) % mod;
	}

	for (int i = n; i > 0; i--) {
		hs1[i] = (hs1[i + 1] * base1 + s[i - 1]) % mod;
		hs2[i] = (hs2[i + 1] * base2 + s[i - 1]) % mod;
	}
}

ll hashp(int l, int r) {
	ll hash1 = (mod + hp1[r] -  hp1[l - 1] * pw1[r - l + 1]) % mod;
	if (hash1 < 0) hash1 += mod;
	ll hash2 = (mod + hp2[r] -  hp2[l - 1] * pw2[r - l + 1]) % mod;
	if (hash2 < 0) hash2 += mod;

	return (hash1 << 32) | hash2;
}

ll hashs(int l, int r) {
	ll hash1 = (hs1[l] -  hs1[r + 1] * pw1[r - l + 1]) % mod;
	if (hash1 < 0) hash1 += mod;
	ll hash2 = (hs2[l] -  hs2[r + 1] * pw2[r - l + 1]) % mod;
	if (hash2 < 0) hash2 += mod;

	return (hash1 << 32) | hash2;
}

bool ispal(int l, int r) {
	int mid = (r + l) / 2;
	ll x = hashp(l, mid), y = hashs(mid, r);
	return x == y;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q >> s;

	pw_cal();
	init();

	while (q--) {
		int l, r; cin >> l >> r;

		if (ispal(l, r)) {
			cout << "Budada\n";
			continue;
		}

		int x = r - l - 1;
		if (x & 1) cout << "Putata\n";
		else cout << "Budada\n";
	}

	return 0;
}