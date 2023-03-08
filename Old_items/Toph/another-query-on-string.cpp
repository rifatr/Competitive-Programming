#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

const int N = 1e5 + 9;
int n, q, bit[26][N], op, l, r;
string s;
char ch;

void edit(char ch, int pos, int val)
{
	int x = ch - 'a';

	while (pos <= n)
	{
		bit[x][pos] += val;
		pos += pos & -pos;
	}
}

int sum(char ch, int pos)
{
	int s = 0, x = ch - 'a';

	while (pos)
	{
		s += bit[x][pos];
		pos -= pos & -pos;
	}

	return s;
}

int main(int argc, char const *argv[])
{
	cin >> n >> q >> s;

	lop(n) edit(s[i], i + 1, 1);

	while (q--)
	{
		cin >> op;

		if (op == 1)
		{
			cin >> l >> ch;
			edit(s[l - 1], l, -1);
			s[l - 1] = ch;
			edit(ch, l, 1);
		}
		else
		{
			cin >> l >> r >> ch;
			cout << sum(ch, r) - sum(ch, l - 1) << '\n';
		}
	}

	return 0;
}