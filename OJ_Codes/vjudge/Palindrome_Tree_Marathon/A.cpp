// Time: 2023-04-04 04:58:33 Problem: A - The Number of Palindromes
// URL: https://vjudge.net/contest/551698#problem/A

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
const char CH = 'a';
int tree[N][26], len[N], link[N];

struct pal_tree {
	int n, node, t;
	string s;
	
	pal_tree(string &ss) {
		s = "0";
		s += ss;
		n = s.size() - 1;
		memset(tree, 0, sizeof tree);
		len[1] = -1, len[2] = 0;
		link[1] = link[2] = 1;
		node = t = 2;
	
		for(int i = 1; i <= n; i++) {
			add(i);
		}
	}
	
	inline int up(int x, int p) {
		while(s[p - len[x] - 1] != s[p]) x = link[x];
		return x;
	}
	
	void add(int p) {
		t = up(t, p);
		int x = up(link[t], p), c = s[p] - CH;
		if(!tree[t][c]) {
			tree[t][c] = ++node;
			len[node] = len[t] + 2;
			link[node] = len[node] == 1 ? 2 : tree[x][c];
		}
		t = tree[t][c];
	}
	
};

// find total number of distinct palindrome substring

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		string s;
		cin >> s;
		pal_tree pt(s);
		
		cout << "Case #" << cs++ << ": ";
		cout << pt.node - 2 << '\n';
	}

	return 0;
}