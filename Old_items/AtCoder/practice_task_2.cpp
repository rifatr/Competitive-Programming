#include<bits/stdc++.h>

using namespace std;

char ask(char a, char b)
{
	cout << "? " << a << ' ' << b << endl;

	char z;

	cin >> z;

	return z;
}

int main()
{
	int n, q;

	cin >> n >> q;

	string s;

	for(int i = 0; i < n; i++)
		s += 'A' + i;

	for(int i = 0; i < n; i++)
	{
		int sp = 0;

		for(int j = 0; j < n - i - 1; j++)
		{
			char z = ask(s[j], s[j + 1]);

			q--;

			if(z == '>')
				swap(s[j], s[j + 1]), sp++;
		}

		if(!sp) break;
	}

	cout << "! " << s << endl;

	cout << q << endl;
}