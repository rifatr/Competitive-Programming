#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int n, m, a, b, q, x, y;

    scanf("%d %d", &n, &m);

    vector <int> v1, v2;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        v1.push_back(x);
        v2.push_back(y);
    }
    scanf("%d", &q);

    for(int i = 0; i < q; i++)
    {
        int flag = 0;
        scanf("%d %d", &a, &b);
        for(int j = 0; j < m; j++)
        {
            if(a == v1[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            for(int j = 0; j < m; j++)
            {
                if(b == v2[j])
                {
                    flag = 1;
                    break;
                }
                else
                    flag = 0;
            }
        }
        if(flag == 1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
