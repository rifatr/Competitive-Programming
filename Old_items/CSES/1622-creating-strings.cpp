#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int main()
{
	string s;
	cin >> s;

	sort(all(s));
	vector <string> ans;

	do
	{
		ans.push_back(s);
	}
	while (next_permutation(all(s)));

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << '\n';
	}
}