#include <bits/stdc++.h>

using namespace std;

int ck(bitset <32> bt) {
	int c = bt.count();
	return !!(c & 1);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n; 
	while(cin >> n) {
		int k = 0;
		for(int i = 1; i < 1<<n; i++) 
			k += ck(i);

		cout << n << " -> " << k << endl;
	}
}
