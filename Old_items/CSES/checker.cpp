#include<bits/stdc++.h>

using namespace std;

#define lop(n) for(int i = 0; i < n; i++)

bool pal(string s)
{
	int n = s.size();
	for (int i = 0, j = n - 1; i <= j; i++, j--)
		if (s[i] != s[j])
			return 0;
	return 1;
}

int main()
{
	string s, t;
	cin >> s;

	if (s == "NO_SOLUTION" or pal(s))
		cout << "AC\n";
	else cout << "WA\n";

	return 0;
}