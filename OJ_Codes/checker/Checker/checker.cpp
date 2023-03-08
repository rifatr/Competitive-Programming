#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

#define lop(n) for(int i = 0; i < n; i++)

void cf1658D() {
	//taking input from STDIN
	int l, r, xx;
	cin >> l >> r >> xx;
	int n = r - l + 1;
	int inara[n];
	for (int i = 0; i < n; i++) cin >> inara[i];

	//taking output
	FILE *output = fopen("ouf", "r");
	int x;
	fscanf(output, "%d", &x);

	//checking ouput
	set <int> st;
	for (int i = 0; i < n; i++)
		st.insert(inara[i] ^ x);

	if (st.size() != n or *--st.end() >= n) {
		printf("WA\n");
		for (auto z : st) cout << z << ' ';
		cout << endl;
	}
}

void ccBRKNLIFE() {
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;

	FILE *output = fopen("ouf", "r");
	char s[n];
	fscanf(output, "%s", s);
	if (strlen(s) == 2 and s[0] == '-') return;
	for (int i = 0; i < n; i++) {
		if (a[i] == '?' and (s[i] > 'e' or s[i] < 'a')) {
			cout << "WA\n";
			return;
		}
		if (a[i] != '?' and s[i] != a[i]) {
			cout << "WA\n";
			return;
		}
	}

	int i = 0, j = 0;
	while (i < n and j < m) {
		if (s[i] != b[j]) i++;
		else i++, j++;
	}

	if (j == m) cout << "WA\n";
}

void cf1686C() {
	int n; cin >> n;
	int ara[n]; lop(n) cin >> ara[i];

	FILE *output, *answer;
	output = fopen("ouf", "r");
	answer = fopen("ans", "r");

	char oo[10], aaa[10];
	fscanf(output, "%s", oo);
	fscanf(answer, "%s", aaa);
	string o = oo, aa = aaa;

	if (o != aa) {
		cout << "output is " << o << " but answer will be " << aa << '\n';
		return;
	}
	if (o == "NO") return;

	deque <int> outara(n);
	lop(n) fscanf(output, "%d", &outara[i]);
	outara.push_back(outara[0]); outara.push_front(outara[n - 1]);
	for (int i = 1; i < n; i++) {
		if (outara[i] > outara[i + 1] and outara[i] > outara[i - 1]);
		else if (outara[i] < outara[i + 1] and outara[i] < outara[i - 1]);
		else {
			cout << "mismatch at index (1-based) " << i << '\n';
			return;
		}
	}
}

int main()
{
	// FILE *ou, *an;
	// ou = fopen("ouf", "r");
	// an = fopen("ans", "r");

	int t; cin >> t; //taking input from STDIN
	for (int z = 1; z <= t; z++)
	{
		//int xo , yo, xa, ya;
		//fscanf(ou, "%d %d", &xo, & yo); // take input from output file
		//fscanf(an, "%d %d", &xa, & ya); // take input from judge sol file


		// ccBRKNLIFE();
		// continue;
		cf1686C();
		continue;

		/*		int n; cin >> n;
				string s[n];
				lop(n) cin >> s[i];

				char oo[100], aaa[100];
				fscanf(ou, "%s", oo);
				fscanf(an, "%s", aaa);

				string o = oo, aa = aaa, im = "IMPOSSIBLE";

				if (aa == im and o != im) {
					cout << "it will be IMPOSSIBLE\n";
					return 0;
				}
				if (aa != im and o == im) {
					cout << "it will be " << aa << '\n';
					return 0;
				}
				if (aa == im and o == im) {
					// cout << "it will be " << aa << '\n';
					continue;
				}

				bool vis[26] = {0};
				int m = o.size();
				for (int i = 0; i < m; i++) {
					if (vis[o[i] - 'A']) {
						cout << o << " is not a corrent answer. Correct answer will be " << aa << '\n';
						return 0;
					}

					vis[o[i] - 'A'] = 1;
					while (i < m - 1 and o[i + 1] == o[i]) i++;
				}*/


		// int n; cin >> n;
		// int out[n], in[n];
		// for (int i = 0; i < n; i++) cin >> in[i];

		// for (int i = 0; i < n; i++) fscanf(ou, "%d", &out[i]);
		// for (int i = 0; i < n; i++) out[i] *= (i + 1);
		// sort(out, out + n);

		// for (int i = 0; i < n; i++) {
		// 	if (in[i] != out[i]) {
		// 		printf("Case %d, wanted %d, got %d\n", z, in[i], out[i]);
		// 	}
		// }

		//if(xo + yo != xa + ya)
		//printf("Case %d, wanted %d, got %d", z, xa + ya, xo + yo);
	}

	printf("ac\n");
}
