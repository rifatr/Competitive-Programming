#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test,n;
    string line;
    vector <string> mat;

    cin >> test;
    cin.ignore();
    cin.ignore();

    while(test--)
    {
        while(1)
        {
            getline(cin, line);
            if(line.size() == 0)
                break;

            mat.push_back(line);
            n = line.size();
        }

        int colsum[n + 1][n + 1];

        loop(i, 0, n + 1)
            loop(j, 0, n + 1)
            {
                if(i == 0 or j == 0)
                    colsum[i][j] = 0;

                else
                    colsum[j][i] = colsum[j - 1][i] + (mat[j - 1][i - 1] - '0');
            }

//        loop(i, 0, n + 1) {
//            loop(j, 0, n + 1)
//                cout << colsum[i][j] << '\t';
//        cout << endl;
//      }

        int res = 0, sum, s;

        loop(a, 1, n + 1)
            loop(b, a, n + 1)
            {
                sum = s = 0;
                loop(i, 1, n + 1)
                {
                    sum += colsum[b][i] - colsum[a - 1][i];

                    int saiz = (b - a + 1) * (i - s);
//                    printf("a = %d b = %d i = %d sum = %d saiz = %d s = %d res = %d\n", a, b, i, sum, saiz, s, res);

                    if(sum >= saiz)
                        res = max(res, saiz);

                    else
                        sum = 0, s = i;

//                    printf("a = %d b = %d i = %d sum = %d saiz = %d s = %d res = %d\n", a, b, i, sum, saiz, s, res);
                }
            }

        cout << res << '\n';

        if(test > 0)
            cout << '\n';

        mat.clear();
    }



    return 0;
}
