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

#define fread           freopen("Back to the 8-Queens input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             (const int) 1e9+7
#define PI              acos(-1.0)
#define inf             (1 << 30)
#define N               (const int) 1e5+5


using namespace std;

int row[8], rw[8], ans;

bool check(int r, int c)
{
	loop(q, 0, c)
		if(row[q] == r or abs(row[q] - r) == abs(q - c))
			return false;

	return true;
}

void set_queen(int c)
{
	if(c == 8)
	{
		int p = 0;

		loop(i, 0, 8)
			if(row[i] + 1 != rw[i])
				p++;

		ans = min (ans, p);

//		lop(8) cout << rw[i] << ' '; cout << endl;
//		lop(8) cout << row[i] << ' '; cout << endl;
//		cout << p << ' ' << ans << endl;
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

//    fread;

    int t = 0;

    while(scanf("%d %d %d %d %d %d %d %d", &rw[0], &rw[1], &rw[2], &rw[3], &rw[4], &rw[5], &rw[6], &rw[7]) == 8)
    {
        mem0(row);
        ans = inf;

        set_queen(0);

        cout << "Case " << ++t << ": ";
        cout << ans << '\n';
    }

    return 0;
}
