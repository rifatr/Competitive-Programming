#include <bits/stdc++.h>

using namespace std;

char lower(char c) {
	return c >= 'A' and c <= 'Z' ? (char) (c + 32) : c;
}

int main() {
	int n; cin >> n; cin.ignore();
	string ans;
	getline(cin, ans);

	map <char, string> morse;
	for (char c = 'a'; c <= 'z'; c++) cin >> morse[c];
	for (char c = '0'; c <= '9'; c++) cin >> morse[c];

	map <char, int> duration;
	for (auto &z : morse) {
		int d = 0;
		for (char c : z.second) d += c == '.' ? 1 : 3;
		duration[z.first] = d;
	}
	cout << duration.size() << '\n';
	// for (auto z : duration) cout << z.first << ' ' << z.second << endl;

	set <pair <int, string>> st;
	for (auto z : morse) st.insert({duration[z.first], z.second});
	for (auto z : st) cout << z.second << '\n';


	int due = 0;

	map <char, int> cnt;
	for (char c : ans) if (c != ' ') cnt[lower(c)]++;

	for (auto z : cnt) {
		due += z.second * duration[z.first];
		cout << z.first << ' ' << z.second << ' ' << duration[z.first] << ' ' << due << '\n';
	}

	/*for (char c : ans) {
		if (c != ' ') {
			due += duration[lower(c)];
			cout << c << ' ' << lower(c) << ' ' << due << endl;
		}
	}*/

	cout << due << endl;
}

// vector <string> code{'.', '..', '...', '_', '....', '_.', }