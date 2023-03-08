#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int f = 0, o = 0, p = n;
	stack <char> st;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'f') st.push(s[i]);
		else if (s[i] == 'o' and !st.empty()) st.push(s[i]);
		else if (s[i] == 'x')
		{
			if (!st.empty() and st.top() == 'o')
			{
				st.pop();
				if (!st.empty() and st.top() == 'f')
				{
					st.pop();
					p -= 3;
				}
				else
				{
					while (!st.empty()) st.pop();
				}

			}
			else
			{
				while (!st.empty()) st.pop();
			}
		}
		else
		{
			while (!st.empty()) st.pop();
		}

	}

	cout << p << '\n';

	return 0;
}
