#include<bits/stdc++.h>

using namespace std;

int bin_to_dec(int bin)
{
    int decimal = 0;
    int temp = bin;
    int power = 1;

    while(temp)
    {
        int ld = temp % 10;
        temp /= 10;

        decimal += ld * power;

        power *= 2;
    }

    return decimal;
}

int main()
{
    int i, j, k, t, dec[4], bin[4], x, flag;

    //cout << bin_to_dec(101);

    cin  >> t;

    for(int z = 1; z <= t; z++)
    {

        scanf("%d.%d.%d.%d", &dec[0], &dec[1], &dec[2], &dec[3]);
        scanf("%d.%d.%d.%d", &bin[0], &bin[1], &bin[2], &bin[3]);



        //cout << dec[0] << dec[1] << dec[2] << dec[3];

        for(i = 0; i < 4; i++)
        {
            int num = bin_to_dec(bin[i]);

            //cout << num << endl;

            flag = 0;

            if(num != dec[i]) {
                flag = 1;
                break;
            }
        }

        cout << "Case " << z << ": ";

        if(flag == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
