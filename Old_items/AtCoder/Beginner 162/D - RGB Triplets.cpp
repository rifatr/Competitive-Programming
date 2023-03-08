#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k, c = 0, r, g, b;
    string sen;

    cin >> n;
    cin.ignore();

    cin >> sen;

    int l = sen.size();

//    r = g = b = 0;
//    for(i = 0; i < l; i++)
//    {
//        if(sen[i] == 'R')
//            r++;
//        else if(sen[i] == 'G')
//            g++;
//        else if(sen[i] == 'B')
//            b++;
//    }
//
//    cout << r << "\t" << g << "\t" << b << endl;

    for(i = 0; i < l - 2; i++)
    {
        for(j = i + 1; j < l - 1; j++)
        {
            if(sen[i] == sen[j])
                continue;

            for(k = j + 1; k < l; k++)
            {
                if(sen[j] != sen[k] && sen[i] != sen[k])
                {
                    if(j - i != k - j)
                        c++;
                }
            }
        }
    }

    cout << c << "\n";

    return 0;
}
