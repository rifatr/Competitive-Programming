#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 1e6 + 6;
int a[N];
vector <int> mx, mn;
multiset <int> window;

void input()
{
	//for (auto &z : window) cout << z << ' ';
	//cout << '\n';

	multiset <int> :: iterator it = window.begin();
	mn.push_back(*it);

	it = window.end(); it--;
	mx.push_back(*it);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < k; i++)
		window.insert(a[i]);
	input();

	for (int i = k; i < n; i++)
	{
		window.insert(a[i]);
		window.erase(a[i - k]);

		input();
	}

	n = n - k + 1;
	for (int i = 0; i < n; i++)
	{
		if (i) printf(" ");
		printf("%d", mn[i]);
	}
	puts("");
	for (int i = 0; i < n; i++)
	{
		if (i) printf(" ");
		printf("%d", mx[i]);
	}
	puts("");

	return 0;
}