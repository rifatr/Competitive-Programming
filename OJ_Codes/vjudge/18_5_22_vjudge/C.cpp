#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll M = 1e6 + 90, mod = 2e9 + 63, base1 = 1e9 + 21, base2 = 1e9 + 181;
ll pw1[M], pw2[M];

const int N = 1e5 + 10;
int n, m;
vector <ll> hp1[N], hp2[N];
string s[N], t;
map <ll, ll> cnt;

void pwcal() {
	pw1[0] = pw2[0] = 1;
	for (ll i = 1; i < M; i++) {
		pw1[i] = (pw1[i - 1] * base1) % mod;
		pw2[i] = (pw2[i - 1] * base2) % mod;
	}
}

void init(int k) {
	hp1[k].pb(0), hp2[k].pb(0);
	for (int i = 1; i <= m; i++) {
		hp1[k].pb((hp1[k].back() * base1 + s[k][i - 1]) % mod);
		hp2[k].pb((hp2[k].back() * base2 + s[k][i - 1]) % mod);
	}
}

pair <ll, ll> Hash(int k, int l, int r) {
	if (l > r) return {0, 0};

	ll has1 = (hp1[k][r] - hp1[k][l - 1] * pw1[r - l + 1]) % mod;
	if (has1 < 0) has1 += mod;
	ll has2 = (hp2[k][r] - hp2[k][l - 1] * pw2[r - l + 1]) % mod;
	if (has2 < 0) has2 += mod;

	return {has1, has2};
}

ll new_hash(int k, int i, char c) {
	auto h = Hash(k, 1, i - 1);
	ll hash1 = (h.first * base1 + c) % mod;
	ll hash2 = (h.second * base2 + c) % mod;

	h = Hash(k, i + 1, m);
	hash1 = (hash1 * pw1[m - i] + h.first) % mod;
	hash2 = (hash2 * pw2[m - i] + h.second) % mod;

	return (hash1 << 32) | hash2;
}

ll total_hash(int k) {
	return (hp1[k][m] << 32) | hp2[k][m];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	pwcal();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		init(i);
		// cnt[s[i]]++;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		// t = s[i];
		// cout << i << ' ' << s[i] << '\n';

		for (int j = 0; j < m; j++) {
			for (char c = 'a'; c <= 'z'; c++) {
				if (c == s[i][j]) continue;

				ll new_string = new_hash(i, j + 1, c);

				// t[j] = c;
				// ans += cnt[t];
				if (cnt.find(new_string) != cnt.end()) {
					ans += cnt[new_string];
					// cout << t << ' ' << cnt[t] << '\n';
				}
				// t[j] = s[i][j];
			}
		}
		cnt[total_hash(i)]++;
	}

	cout << ans << '\n';
	return 0;
}