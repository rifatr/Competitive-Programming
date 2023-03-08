#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	string s;

	cin >> n >> x >> s;
	for (char &z : s)
	{
		if (z == 'o') x++;
		else x--;

		x = max(x, 0);
	}

	cout << x << '\n';

	return 0;
}
