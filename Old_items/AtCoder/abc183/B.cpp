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

	double s1, s2, g1, g2;
	cin >> s1 >> s2  >> g1 >> g2;

	double diff = g1 - s1;
	double ans = diff / (s2 + g2);
	ans *= s2;


	cout << fixed << setprecision(8) << s1 + ans << '\n';

	return 0;
}
