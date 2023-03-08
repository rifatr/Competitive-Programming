#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int tc; cin >> tc;
	for(int cs = 1; cs <= tc; cs++) {
		int a[10];
		for(int i = 0; i < 9; i++) cin >> a[i];

		int x = accumulate(a, a + 9, 0) - a[0] - a[1];
        cout << "Case " << cs << ": " << a[0] - x << '\n';
	}
}
