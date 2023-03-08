#include <iostream>

using namespace std;

int main() {
	long long x, y, odd, even, tt;

	cin >> tt;

	while(tt--) {

	cin >> x >> y;

	odd = abs((x * x) + x - (y * y));
	even = abs((y * y) + y - (x * x));

	cout << min(odd, even) << endl;
	}

	return 0;
}

