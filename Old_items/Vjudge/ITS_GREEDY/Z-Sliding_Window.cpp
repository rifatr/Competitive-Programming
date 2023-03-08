#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

const int N = 1e6 + 6;
int a[N];

int main()
{
	int n, k, i;
	scanf("%d %d", &n, &k); k--;

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	vector <int> mx, mn;
	deque <int> dx, dn;

	for (i = 0; i < n; i++)
	{
		while (!dx.empty() and a[dx.front()] < a[i]) dx.pop_front();
		while (!dn.empty() and a[dn.front()] > a[i]) dn.pop_front();

		dx.push_front(i);
		dn.push_front(i);

		if (i >= k)
		{
			mx.push_back(a[dx.back()]);
			mn.push_back(a[dn.back()]);
			if (dn.back() <= i - k) dn.pop_back();
			if (dx.back() <= i - k) dx.pop_back();
		}
	}

	n = n - k;
	for (i = 0; i < n; i++)
	{
		if (i) printf(" ");
		printf("%d", mn[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if (i) printf(" ");
		printf("%d", mx[i]);
	}
	printf("\n");

	return 0;
}