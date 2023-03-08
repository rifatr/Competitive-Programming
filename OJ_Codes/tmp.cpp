#include <bits/stdc++.h>

using namespace std;

bool allupper(string &s) {
	for (char c : s) if (c < 'A' or c > 'Z') return 0;
	return 1;
}

bool isletter(char c) {
	return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z');
}

int main() {
	vector <string> vs;
	string s;
	while (cin >> s) {
		cout << (char) 34 << s << (char) 34 << ", ";
	}


}