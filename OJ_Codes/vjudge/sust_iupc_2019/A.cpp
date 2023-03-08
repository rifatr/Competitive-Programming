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
	int tc; cin >> tc; cin.ignore();
	int cs = 1;

	while (tc--) {
		string st;
		getline(cin, st);
		// for (char &c : st) if (!isletter(c)) c = ' ';

		stringstream ss(st);
		map <string, bool> mp;
		string s;
		while (ss >> s) {
			while (s.size() and !isletter(s.back())) s.pop_back();
			reverse(s.begin(), s.end());
			while (s.size() and !isletter(s.back())) s.pop_back();
			reverse(s.begin(), s.end());

			if (allupper(s) and s.size() == 3) mp[s] = 1;
		}

		// for (auto z : mp) cout << z.first << ' ' << z.second << endl;

		printf("Case %d: ", cs++);
		if (mp.size() == 1 and mp["CSE"])
			printf("SUST CSE Carnival\n");
		else if (mp.size() == 3 and mp["CSE"] and mp["EEE"] and mp["SWE"])
			printf("SUST Tech Fest\n");
		else
			printf("Festival of SUST\n");
	}
}