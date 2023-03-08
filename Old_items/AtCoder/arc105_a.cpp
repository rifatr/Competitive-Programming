#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[4];

	for(int i = 0; i < 4; i++)
		cin >> a[i];

	sort(a, a + 4);

	string res = "No";

	if((a[0] + a[1] + a[2] == a[3]) or (a[0] + a[3] == a[2] + a[1]))
		res = "Yes";
	
	cout << res << endl;

	return 0;
}
