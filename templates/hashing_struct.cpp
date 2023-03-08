#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MAX_N = 1e6 + 10, mod = 2e9 + 63, base1 = 1e9 + 21, base2 = 1e9 + 181;
ll pw1[MAX_N], pw2[MAX_N];
void pw_calc() {
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		pw1[i] = (pw1[i - 1] * base1) % mod;
		pw2[i] = (pw2[i - 1] * base2) % mod;
	}
}

struct Hash {
	string s;
	int slen = (int) s.size(); //initialize again after taking input()
	ll h1[MAX_N], h2[MAX_N];
	void init() {
		h1[0] = h2[0] = 0;
		for (int i = 1; i <= slen; i++) {
			h1[i] = (h1[i - 1] * base1 + s[i - 1]) % mod;
			h2[i] = (h2[i - 1] * base2 + s[i - 1]) % mod;
		}
	}
	inline ll hashVal(int l, int r) {
		ll hsh1 = (h1[r] - h1[l - 1] * pw1[r - l + 1]) % mod;
		if (hsh1 < 0) hsh1 += mod;
		ll hsh2 = (h2[r] - h2[l - 1] * pw2[r - l + 1]) % mod;
		if (hsh2 < 0) hsh2 += mod;
		return (hsh1 << 32) | hsh2;
	}
} hs;
/* call pw_calc() for calculating powers less than MAX_N
* hs.init() will calculate the double hashes
* hs.hashVal(l,r) will return [l,,r] (1 indexed) merged double hash value
*/

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	pw_calc();

	cin >> hs.s;
	hs.slen = (int) hs.s.size();
	hs.init();

	cout << hs.hashVal(1, 2);
}