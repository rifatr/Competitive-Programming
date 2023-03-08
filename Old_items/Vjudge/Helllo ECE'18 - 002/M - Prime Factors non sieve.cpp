#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int i, j, z, x, p = 0;

    for(i = 2; i <= 100000; i++)
    {
        //printf("%d:", i);

        x = i;

        if(x % 2 == 0)
        {
            while(x % 2 == 0) {
                x /= 2;
               // p++;
            }

            //printf(" 2");
        }

        int limit = sqrt(x * 1.0);
        for(j = 3; j <= limit; j += 2)
        {
            if(x % j == 0) {
                while(x % j == 0) {
                    x /= j;
                    //p++;
                }
                //printf(" %d", j);
            }
           // p++;
        }

        //if(x > 2)
           // printf(" %d", x);

        //printf("\n");
    }

    //std::cout << p << std::endl;

    return 0;
}


