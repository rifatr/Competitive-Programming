#include <bits/stdc++.h>

using namespace std;

string vow = "AEIOUaeiou";

bool ck(char c) {
	return count(vow.begin(), vow.end(), c);
}

int main() {
	int a, b, k;
	cin >> a >> b >> k;

	int x = 0;
	for (int i = a; i <= b; i++)
		for (int j = i; j <= b; j++)
			x += i * j <= k;

	cout << x << '\n';

	return 0;
}