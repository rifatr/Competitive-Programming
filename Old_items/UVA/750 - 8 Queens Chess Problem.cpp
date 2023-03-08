#include<bits/stdc++.h>

#define ll              long long
#define pb              push_back
#define ff              first
#define ss              second
#define mp              make_pair

#define scan(a)         scanf("%d", &a)
#define scanl(a)        scanf("%lld", &a)
#define scand(a)        scanf("%lf", &a)
#define scan2(a, b)     scanf("%d %d", &a, &b)
#define scanl2(a, b)    scanf("%lld %lld", &a, &b)
#define scand2(a, b)    scanf("%lf %lf", &a, &b)

#define yes             cout << "yes\n"
#define no              cout << "no\n"
#define Case(i)         cout << "Case " << int(i) << ": "

#define lop(n)          for(int i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)
#define loop(k, a, b)   for(int k = a; k < b; k++)
#define lopr(n, a)      for(int i = n; i >= a; i--)
#define loopr(j, b, a)  for(int j = b; j >= a; j--)

#define all(x)          x.begin(), x.end()
#define sorta(x)        sort(x.begin(), x.end())
#define sortd(x)        sort(x.rbegin(), x.rend())
#define mem0(a)         memset(a, 0, sizeof(a))
#define mem1(a)         memset(a, -1, sizeof(a))

#define vin             vector <int>
#define vll             vector <ll>
#define vst             vector <string>
#define pll             pair <ll, ll>
#define pss             pair <string, string>
#define vpll            vector <pll>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             (const int) 1e9+7
#define PI              acos(-1.0)
#define inf             (1 << 61)
#define N               (const int) 1e5+5


using namespace std;

int row[8], a, b, line;

bool check(int r, int c)
{
	loop(q, 0, c)
		if(row[q] == r or abs(row[q] - r) == abs(q - c))
			return false;

	return true;
}

void set_queen(int c)
{
	if(c == 8 and row[b] == a)
	{
		cout << setw(2) << ++line << "      " << row[0] + 1;

		loop(i, 1, 8)
			cout << " " << row[i] + 1;

		cout << '\n';
	}

	loop(r, 0, 8)
	{
		if(check(r, c))
		{
			row[c] = r;
			set_queen(c + 1);
		}
	}
}

int main()
{
    fastio;

    int tt;

    cin >> tt;

    while(tt--)
    {
        cin >> a >> b;
        a--, b--;

        mem0(row);

        cout << "SOLN       COLUMN\n";
        cout << setw(2) << '#' << "      " << "1 2 3 4 5 6 7 8\n\n";

        set_queen(0);

        line = 0;

        if(tt)
        cout << '\n';
    }

    return 0;
}
