#include <bits/stdc++.h>

using namespace std;

#define yes printf("Yes\n")
#define no printf("No\n")

int main(int argc, char const *argv[])
{
	int t = 1, tt;
	scanf("%d", &tt);

	while (tt--)
	{
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int m;
		scanf("%d",  &m);
		printf("Case %d:\n", t++);

		while (m--)
		{
			int a, b;
			scanf("%d %d", &a, &b);

			if (a >= x1 and a <= x2 and b >= y1 and b <= y2)
				yes;
			else
				no;
		}
	}

	return 0;
}