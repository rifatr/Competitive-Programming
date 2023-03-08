#include<iostream>
#include<string>

using namespace std;

int main()
{
    int i = 1, t;

    while(cin >> t and t)
    {
        string a[t], b[t];

        for(int j = 0; j < t; j++)
            cin >> a[j];

        int m = 0, n = t - 1;
        for(int j = 0; j < t; j++)
        {
            if(j & 1)
            {
                b[n] = a[j];
                n--;
            }

            else
            {
                b[m] = a[j];
                m++;
            }
        }

        cout << "SET " << i << '\n';
        for(int j = 0; j < t; j++)
            cout << b[j] << '\n';

        i++;
    }
}
