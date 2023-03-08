#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc, cs = 1;
	cin >> tc;

	while (tc--) {
		int r, c;
		cin >> r >> c;
		string s[r];
		for (int i = 0; i < r; i++) cin >> s[i];

		int grid[r + 5][c + 5], iscorner[r + 5][c + 5][4];
		memset(iscorner, 0, sizeof iscorner);
		memset(grid, 0, sizeof grid);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				grid[i + 1][j + 1] = s[i][j] - '0';

		// for (int i = 0; i <= r + 1; i++) {
		// 	for (int j = 0; j <= c + 1; j++)
		// 		cout << grid[i][j];
		// 	cout << '\n';
		// }

		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				if (!grid[i][j]) continue;

				if (!grid[i][j - 1] and !grid[i - 1][j]) iscorner[i][j][0] = 1; //upper left corner
				if (!grid[i][j + 1] and !grid[i - 1][j]) iscorner[i][j][1] = 1; //upper right corner
				if (!grid[i][j - 1] and !grid[i + 1][j]) iscorner[i][j][2] = 1; //lower left
				if (!grid[i][j + 1] and !grid[i + 1][j]) iscorner[i][j][3] = 1; //lower right
			}

		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				if (iscorner[i][j][0] and iscorner[i - 1][j - 1][3]) iscorner[i][j][0]--; //upper left crossing
				if (iscorner[i][j][1] and iscorner[i - 1][j + 1][2]) iscorner[i][j][1]--; //upper right crossing
				if (iscorner[i][j][2] and iscorner[i + 1][j - 1][1]) iscorner[i][j][2]--; //lower left
				if (iscorner[i][j][3] and iscorner[i + 1][j + 1][0]) iscorner[i][j][3]--;
			}

		int ans = 0;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				if (!grid[i][j]) continue;
				// if (!grid[i][j + 1] or !grid[i][j - 1] or !grid[i + 1][j] or !grid[i - 1][j]) continue;
				if (iscorner[i][j][0] or iscorner[i][j][1] or iscorner[i][j][2] or iscorner[i][j][3]) continue;

				if (grid[i - 1][j] and grid[i][j - 1] and !grid[i - 1][j - 1]) {
					ans++;
					// cout << "upper left inner corner " << i << ' ' << j << '\n';
				} //upper left inner corner
				else if (grid[i + 1][j] and grid[i][j - 1] and !grid[i + 1][j - 1]) {
					ans++;
					// cout << "lower left inner corner" << i << ' ' << j << '\n';
				}
				else if (grid[i + 1][j] and grid[i][j + 1] and !grid[i + 1][j + 1]) {
					ans++;
					// cout << "upper right inner corner" << i << ' ' << j << '\n';
				}
				else if (grid[i - 1][j] and grid[i][j + 1] and !grid[i - 1][j + 1]) {
					ans++;
					// cout << "lower right inner corner" << i << ' ' << j << '\n';
				}
				// cout << ans << ' ' << i << ' ' << j << '\n';
				/*if (grid[i + 1][j + 1] or grid[i + 1][j - 1] or grid[i + 1][j - 1] or grid[i - 1][j + 1]) {
					ans++;
					cout << i << ' ' << j << '\n';
				}*/
			}

		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				for (int k = 0; k < 4; k++)
					ans += iscorner[i][j][k];

		cout << "Case " << cs++ << ": " << ans << '\n';
	}

	return 0;
}