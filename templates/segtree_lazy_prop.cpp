// Time: 2023-05-15 23:17:28 Problem: E. Assignment and Minimum
// URL: https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/E

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 10, NOP = -1;
ll n, m, tree[4 * N], lazy[4 * N];

void propagate(int i) {
	lazy[2 * i] = lazy[2 * i + 1] = lazy[i];
	tree[2 * i] =  lazy[i];
	tree[2 * i + 1] = lazy[i];

	lazy[i] = NOP;
	return;
}

void update(int i, int l, int r, ll x, int left, int right) {
	if (l > right or r < left) return;
	if (left <= l and r <= right) {
		tree[i] = x;
		lazy[i] = x;
		return;
	}

	if (lazy[i] != NOP) propagate(i);

	int md = (l + r) >> 1, lft = i << 1, rgt = lft | 1;
	update(lft, l, md, x, left, right);
	update(rgt, md + 1, r, x, left, right);
	tree[i] = min(tree[lft], tree[rgt]);
}

ll query(int i, int l, int r, int p, int q) {
	if (l > q or r < p) return 2e9;
	int md = (l + r) >> 1, lft = i << 1, rgt = lft | 1;

	if (lazy[i] != NOP and l != r) {
		propagate(i);
		tree[i] = min(tree[lft], tree[rgt]);
	}
	if (p <= l and r <= q) return tree[i];

	ll x = query(lft, l, md, p, q), y = query(rgt, md + 1, r, p, q);
	return min(x, y);
}

void update(int l, int r, ll x) {
	update(1, 1, n, x, l, r);
}
ll query(int l, int r) {
	return query(1, 1, n, l, r);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(lazy, lazy + 4 * N, NOP);

	cin >> n >> m;
	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			int l, r, x; cin >> l >> r >> x;
			update(l + 1, r, x);
		}
		else {
			int p, q; cin >> p >> q;
			cout << (query(p + 1, q)) << '\n';
		}
	}

	return 0;
}
