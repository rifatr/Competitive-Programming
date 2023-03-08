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

	double a, b, c;
	cin >> a >> b >> c;

	double s = a + b + c;
	double x = (100.0 - a) * (a / s);
	double y = (100.0 - b) * (b / s);
	double z = (100.0 - c) * (c / s);

	cout << fixed << setprecision(7) << x + y + z << '\n';

	return 0;
}
