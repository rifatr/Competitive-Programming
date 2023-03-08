#include<bits/stdc++.h>

using namespace std;

int bin_to_dec(string bin)
{
    int decimal = 0;
    //int len = bin.size();
    int power = 7;

    for(int i = 0; i < 7; i++)
    {
        decimal += (bin[i] - '0') * pow(2, power);
        power--;
    }

    return decimal;
}

int main()
{
    string bin, temp;
    int i, j, k, t, dec[4], x, flag;

//    cout << bitset(12);

    cin  >> t;

    for(int z = 1; z <= t; z++)
    {

        scanf("%d.%d.%d.%d", &dec[0], &dec[1], &dec[2], &dec[3]);
        getchar();
        cin >> bin;
        getchar();

        //cout << dec[0] << dec[1] << dec[2] << dec[3];

        //cout << bin << endl;

        for(i = 0, x = 0; i < 35; x++)
        {
            for(j = i, k = 0; k < 8; j++, k++) {
                temp[k] = bin[j];
            }

            cout << temp << endl;

            int num = bin_to_dec(temp);

           // cout << num << endl;

            flag = 0;

            if(num != dec[x]) {
                flag = 1;
                break;
            }

            i += 9;
//        stringstream strg;
//
//        strg << num;
//
//        string ndb = strg.str();
//
//        cout << ndb << endl;
//
//        bindec += ndb;
//        int l = bindec.size();
////        if(i < 23)
////            bindec[i + 8] = '.';
        }

        cout << "Case " << z << ": ";

        if(flag == 0)
            cout << "Yes\n";
        else
            cout << "No\n";

        bin.clear();
    }

    return 0;
}
