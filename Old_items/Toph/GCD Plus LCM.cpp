#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ll t, a, b, x, y;

	scanf("%lld", &t);

	while(t--) {
		scanf("%lld %lld", &a, &b);

		x = __gcd(a,b);
		y = lcm(a,b);

		if(x + y == a + b)
			printf("true\n");
		else
			printf("false\n");
		}

	return 0;
}

