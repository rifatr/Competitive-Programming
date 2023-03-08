#include <bits/stdc++.h>
#include <testlib.h>

using namespace std;

const int N = 1e5;

int main() {
	freopen("output.txt", "w", stdout);

	int t = rnd.next(N, N);
	println(t);

	while (t--) {
		println(N * 10 - t);
	}
}