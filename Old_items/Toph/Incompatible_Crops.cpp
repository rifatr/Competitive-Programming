#include <bits/stdc++.h>

using namespace std;

string grid[30];
int R, C, dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

bool check(int x, int y)
{
	if(x < 0 or y < 0 or x >= R or y >= C or grid[x][y] == '.')
		return 1;
	return 0;
}

int fnd(int x, int y)
{
	int s = 0;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(grid[i][j] == '*')
				continue;

			bool f = 1;
			for(int k = 0; k < 4; k++)
			{
				int ii = i + dr[k], jj = j + dc[k];

				if(!check(ii, jj)) f = 0;
			}

			s += f;
		}
	}

	return s;
}
			
int main() 
{
	cin >> R >> C;

	for(int i = 0; i < R; i++)
		cin >> grid[i];

	cout << fnd(0, 0) << '\n';

	return 0;
}
