#include <bits/stdc++.h>

using namespace std;

const int N = 1e5, M = 26;
int trie[N][M], nnode;
bool isword[N];

void reset(int k) {
	for (int i = 0; i < M; i++)
		trie[k][i] = -1;
}

void Insert(string &s) {
	int n = s.size(), node = 0;
	for (int i = 0; i < n; i++) {
		if (trie[node][s[i] - 'a'] == -1) {
			trie[node][s[i] - 'a'] = ++nnode;
			reset(nnode);
		}

		node = trie[node][s[i] - 'a'];
	}

	isword[node] = 1;
}

bool Search(string &s) {
	int n = s.size(), node = 0;
	for (int i = 0; i < s.size(); i++) {
		if (trie[node][s[i] - 'a'] == -1)
			return 0;
		node = trie[node][s[i] - 'a'];
	}

	return isword[node];
}

int main() {
	reset(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Insert(s);
	}

	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;

		cout << Search(s) << endl;
	}
}