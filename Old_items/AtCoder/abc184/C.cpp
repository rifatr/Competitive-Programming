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

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ans;
	if (a == c and b == d) ans = 0;
	else if ((a + b == c + d) or (a - b == c - d) or (abs(a - c) + abs(b - d) <= 3)) ans = 1;
	else if (a == b or c == d) ans = 2;
	else ans = 3;

	cout << ans << '\n';

	return 0;
}
