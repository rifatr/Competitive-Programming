#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll linf = 2e18;
const int inf = 1e9;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> g(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back(make_pair(b, c));
	}
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>> qu;
		vector<int> cost(n, inf);
		vector<bool> seeked(n, false);

		pair <int, int> now = make_pair(0, i);
		for (auto v : g[now.second]) {
			chmin(cost[v.first], v.second);
			qu.push(make_pair(-cost[v.first], v.first));
		}

		while (!qu.empty()) {

			now = qu.top();
			qu.pop();
			if (seeked[now.second] == true) continue;
			seeked[now.second] = true;
			for (auto v : g[now.second]) {
				if (chmin(cost[v.first], cost[now.second] + v.second)) {
					qu.push(make_pair(-cost[v.first], v.first));
				}
			}
			if (seeked[i] == true) break;
		}
		if (cost[i] == inf) ans.push_back(-1);
		else ans.push_back(cost[i]);
	}

	for (int i = 0; i < n; i++) cout << ans[i] << endl;

	return 0;
}