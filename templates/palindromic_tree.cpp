#include <bits/stdc++.h>
using namespace std;
const char CH = 'a'; // base character

struct pal_tree {
	int n, node, t; string s;
	vector <int> len, link, cnt;
	vector <vector<int>> tree;
	
	pal_tree(string &ss) {
		s = "0" + ss; n = s.size(); // ss is 0-based but s is 1-based string
		cnt.resize(n + 2); // cnt[i] = count of pal. substring at node i in string s
		len.resize(n + 2); link.resize(n + 2);
		tree.resize(n + 2, vector <int> (26));
		
		len[1] = -1, len[2] = 0; // len[i] = length of palindrome substring at node i
		link[1] = link[2] = 1; // link[i] = suffix link of node i
		node = t = 2;
	
		for(int i = 1; i < n; i++) add(i);
		for(int i = node; i > 2; i--) cnt[link[i]] += cnt[i];
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
		cnt[t]++;
	}
};