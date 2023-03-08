#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, i, j, k, x, y, z, inp;
    vector <long long> a, b;

    scanf("%lld", &t);

    while(t--)
    {
        scanf("%lld", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &inp);
            a.push_back(inp);
        }
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &inp);
            b.push_back(inp);
        }

        int flag = 0;
        if(b[n - 1] >= a[n - 1])
        {
            for(i = 0; i < n; i++)
            {
                x = a[i] - b[i];
                if(x > 0)
                {
                    for(j = i + 1; j < n; j++)
                    {
                        if(b[j] > a[j])
                        {
                            //x *= -1;
                            y = b[j] - a[j];
                            if(y >= x)
                            {
                                b[i] += x;
                                b[j] -= x;
                                //cout << "done " << b[i] << "\t" << b[j] << i << "-" << j << endl;
                                break;
                            }
                            else
                            {
                                b[i] += y;
                                b[j] -= y;
                                x = a[i] - b[i];
                                //cout << "position " << b[i] << "\t" << b[j] << i << "-" << j << endl;
                            }
                        }
                    }
                }
            }
            for(i = 0; i < n; i++)
            {
                if(b[i] < a[i])
                {
                    flag = 1;
                    //cout << b[i] << "\t" << a[i] << "\t" <<i;
                    break;
                }
            }
        }
        else
            flag = 1;

        if(flag == 0)
            printf("Yes\n");
        else
            printf("No\n");

        a.clear();
        b.clear();
    }

    return 0;
}
