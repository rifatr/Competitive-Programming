#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, k, t, dec[4], x, flag;
    char bin[4][8];

    cin  >> t;

    for(int z = 1; z <= t; z++)
    {

        scanf("%d.%d.%d.%d", &dec[0], &dec[1], &dec[2], &dec[3]);
        scanf("%s.%s.%s.%s", bin[0], bin[1], bin[2], bin[3]);

        for(i = 0; i < 4; i++)
        {
            bitset <8> a(dec[i]);

            flag = 0;

            cout << bin[i] << '\n';

            for(int j = 0; j < 8; j++)
            {
                if(a[j] != bin[i][j])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 1)
                break;
        }

        cout << "Case " << z << ": ";

        if(flag == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

