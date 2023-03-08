#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 20, M = 20;
ll n, q, a[N], spt[M][N], lg2[N];

ll f(int i, int j) { // do the main operation here
	return spt[i - 1][j] + spt[i - 1][j + (1 << (i - 1))];
}

void build() {
	lg2[1] = 0;
	for (int i = 2; i < N; i++)
		lg2[i] = lg2[i / 2] + 1;
	for (int i = 0; i < n; i++)
		spt[0][i] = a[i];
	for (int i = 1; i < M; i++) {
		for (int j = 0; j + (1 << i) <= n; j++) {
			spt[i][j] = f(i, j);
		}
	}
}

ll querySum(int l, int r) {
	ll sum = 0;
	for (int i = M - 1; i >= 0; i--) {
		if ((1 << i) <= r - l + 1) {
			sum += spt[i][l];
			l += (1 << i);
		}
	}

	return sum;
}

ll queryMin(int l, int r) {
	int k = lg2[r - l + 1];
	return min(spt[k][l], spt[k][r - (1 << k) + 1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];

	build();

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << querySum(l - 1, r - 1) << '\n';
	}
}