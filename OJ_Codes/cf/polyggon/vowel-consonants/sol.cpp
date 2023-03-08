#include <bits/stdc++.h>

using namespace std;

string vow = "AEIOUaeiou";

bool ck(char c) {
	return count(vow.begin(), vow.end(), c);
}

int main() {
	string s;
	cin >> s;

	for (char &z : s) if (ck(z)) cout << z;
	cout << '\n';
	for (char &z : s) if (!ck(z)) cout << z;
	cout << '\n';

	return 0;
}