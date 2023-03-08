#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)

int main()
{

    int x, test, n;

    cin >> test;

    loop(k, 0, test)
    {
        cin >> x;

        int s1, s2, sum, res, s;
        s = s1 = s2 = sum = res = 0;

        lop(x - 1)
        {
            cin >> n;

            sum += n;

            if(sum > res)
            {
                res = sum;
                s2 = i;
                s1 = s;
            }

            else if(sum == res)
            {
                if(i - s > s2 - s1)
                    s1 = s, s2 = i;
            }

            if(sum < 0)
                sum = 0, s = i + 1;
        }

        if(res == 0)
            printf("Route %d has no nice parts\n", k + 1);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", k + 1, s1 + 1, s2 + 2);
    }

    return 0;
}
