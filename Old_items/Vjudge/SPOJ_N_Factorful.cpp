#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef long long ll;

const int N = 1e6+6, P = 10;
int pf[N+1];
int pfs[P+1][N+1];

void sieve()
{
	for (int i = 2; i <= N; i += 2)
		pf[i]++;

	for(int i = 3; i <= N; i += 2)
	{
		if(!pf[i])
			for(int j = i; j <= N; j += i)
				pf[j]++;
	}
}

void calc()
{
	for(int i = 0; i <= P; i++)
	{
		for(int j = 1; j <= N; j++)
			pfs[i][j] = pfs[i][j - 1] + (pf[j] == i);
	}
}
int main()
{
	#ifdef ONLINE_JUDGE
		auto start = high_resolution_clock::now();
		freopen("/home/rifat/input.txt", "r", stdin);
		freopen("/home/rifat/output.txt", "w", stdout);
	#endif

	sieve();
	calc();

	int tt, a, b, n;

    cin >> tt;

    while(tt--)
    {
        cin >> a >> b >> n;

        cout << pfs[n][b] - pfs[n][a - 1] << '\n';
    }


	#ifdef ONLINE_JUDGE
    	auto stop = high_resolution_clock::now();
    	auto duration = duration_cast<milliseconds>(stop - start);
    	cout << "\nTime: " << duration.count() << "ms" << endl;
	#endif

	return 0;
}
