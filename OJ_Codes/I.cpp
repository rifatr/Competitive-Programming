#include <bits/stdc++.h>

using namespace std;

set<pair<int, string>>v;
int get_count(string s)
{

	int cnt = 0;
	for (auto i : s)
	{
		if (i == '.') cnt += 2;
		else cnt += 4;
	}
	return  cnt;
}
void solve(int cnt, string s)
{
	if (cnt == 10)
	{
		if (s.size()) v.insert({get_count(s), s});
		return;
	}
	solve(cnt + 1, s);
	solve(cnt + 1, s + '.');
	solve(cnt + 1, s + '-');
}

char lower(char c) {
	return c >= 'A' and c <= 'Z' ? (char) (c + 32) : c;
}

bool comp(pair <char, int> &a, pair <char, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	solve(0, "");
	/*//sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (auto i : v)
	{
		cout << i.first << " " << i.second << endl;
	}*/

	int tc; cin >> tc; cin.ignore();
	int cs = 1;

	while (tc--) {
		string s; getline(cin, s);

		map <char, int> cnt;
		for (char c : s) if (c != ' ') cnt[lower(c)]++;

		vector <pair <char, int>> vv;
		for (auto z : cnt) vv.push_back(z);
		sort(vv.begin(), vv.end(), comp);

		map <char, string> morse;
		auto it = v.begin();
		for (auto z : vv) {
			auto k = *it;
			morse[z.first] = k.second;
			it++;
		}

		for (char c = 'a'; c <= 'z'; c++) cout << morse[c] << '\n';
		for (char c = '0'; c <= '9'; c++) cout << morse[c] << '\n';
	}

	return 0;
}