#include<bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d", &a)
#define lop() for(int i = 0; i < 8; i++)
#define lop2() for(int j = 0; j < 8; j++)
#define pt(a) printf("%c", a)
#define pnl printf("\n")

int main()
{
    int tt;

    sc(tt);

    while(tt--)
    {
        int k, x, n;

        sc(k);
        k--;

        lop()
        {
            lop2()
            {
                if(i == 0 and j == 0)
                    pt('O');

                else if(k) {
                    pt('.');
                    k--;
                }

                else
                    pt('X');
            }
            pnl;
        }
    }

    return 0;
}
